#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <float.h> //дл€ получени€ DBL_MAX
#include "inputs.h"
#include "info.h"
#include "random.h"

#define N_SIZE 5
#define M_SIZE 4

// ввод матрицы с клавиатуры
void GetDoubleMatrix(int rows, int columns, double matrix[][M_SIZE])
{
  for (int i = 0; i < rows; i++)
  {
    printf("¬ведите %d элемента %d строки:\n", columns, i+1);

    for (int j = 0; j < columns; j++)
    {
      matrix[i][j] = GetDouble();
    }
  }
}

// заполнение матрицы случайными числами
void GetRandomDoubleMatrix(int rows, int columns, double matrix[][M_SIZE])
{
  srand(time(NULL));

  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < columns; j++)
    {
      matrix[i][j] = GetRandomDouble();
    }
  }
}

// вывод выровненной матрицы на экран
void ShowMatrix(int rows, int columns, double matrix[][M_SIZE])
{
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < columns; j++)
    {
      printf("%.3f\t", matrix[i][j]);
    }
    puts("");
  }
}

// перестановка наибольшего элемента строки в начало, возвращает колличество измененных строк матрицы
int MaxToFirst(int rows, int columns, double matrix[][M_SIZE]) 
{
  double max_value = DBL_MIN;
  int max_index = 0;
  int counter = 0;

  for (int i = 0; i < rows; i++)
  {
    // поиск наибольшего элемента строки и его индекса
    for (int j = 0; j < columns; j++)
    {
      if (matrix[i][j] > max_value)
      {
        max_value = matrix[i][j];
        max_index = j;
      }
    }


    if (max_index != 0) ++counter;

    // мен€ем местами максимальный элемент в массиве с первым
    double temp = matrix[i][0];
    matrix[i][0] = max_value;
    matrix[i][max_index] = temp;

    max_value = DBL_MIN;
    max_index = 0;
  }

  return counter;
}

int main(void)
{
  setlocale(LC_CTYPE, "RU");

  ShowInfo(2, 3, 5);

  enum MENU {MANUAL = 1, RANDOM = 2, EXIT = 3};
  enum MENU userChoice;
  double matrix[N_SIZE][M_SIZE];
  int Scg = 0; // колличество измененных строк

  puts("1 - ¬вести данные вручную\n2 - «аполнить случайными числами\n3 - «авершить работу программы");

  // зацикленное меню
  do
  {
    puts("¬ведите пункт меню:");
    userChoice = GetInt();
    switch (userChoice)
    {
      case MANUAL:
        GetDoubleMatrix(N_SIZE, M_SIZE, matrix);
        puts("¬ведена€ матрица:");
        ShowMatrix(N_SIZE, M_SIZE, matrix);
        Scg = MaxToFirst(N_SIZE, M_SIZE, matrix);
        puts("»змененна€ матрица:");
        ShowMatrix(N_SIZE, M_SIZE, matrix);
        printf(" олличество измененных строк:%d\n", Scg);
        break;
      case RANDOM:
        GetRandomDoubleMatrix(N_SIZE, M_SIZE, matrix);
        puts("«аполненна€ случайными числами матрица:");
        ShowMatrix(N_SIZE, M_SIZE, matrix);
        Scg = MaxToFirst(N_SIZE, M_SIZE, matrix);
        puts("»змененна€ матрица:");
        ShowMatrix(N_SIZE, M_SIZE, matrix);
        printf(" олличество измененных строк:%d\n", Scg);
        break;
      case EXIT:
        return EXIT_SUCCESS;
      default:
        puts("“акого пункта в меню нет!");
    }
  }  
  while (userChoice != EXIT);
}
