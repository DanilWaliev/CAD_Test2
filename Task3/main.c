#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <float.h> //��� ��������� DBL_MAX
#include "inputs.h"
#include "info.h"
#include "random.h"

#define N_SIZE 5
#define M_SIZE 4

// ���� ������� � ����������
void GetDoubleMatrix(int rows, int columns, double matrix[][M_SIZE])
{
  for (int i = 0; i < rows; i++)
  {
    printf("������� %d �������� %d ������:\n", columns, i+1);

    for (int j = 0; j < columns; j++)
    {
      matrix[i][j] = GetDouble();
    }
  }
}

// ���������� ������� ���������� �������
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

// ����� ����������� ������� �� �����
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

// ������������ ����������� �������� ������ � ������, ���������� ����������� ���������� ����� �������
int MaxToFirst(int rows, int columns, double matrix[][M_SIZE]) 
{
  double max_value = DBL_MIN;
  int max_index = 0;
  int counter = 0;

  for (int i = 0; i < rows; i++)
  {
    // ����� ����������� �������� ������ � ��� �������
    for (int j = 0; j < columns; j++)
    {
      if (matrix[i][j] > max_value)
      {
        max_value = matrix[i][j];
        max_index = j;
      }
    }


    if (max_index != 0) ++counter;

    // ������ ������� ������������ ������� � ������� � ������
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
  int Scg = 0; // ����������� ���������� �����

  puts("1 - ������ ������ �������\n2 - ��������� ���������� �������\n3 - ��������� ������ ���������");

  // ����������� ����
  do
  {
    puts("������� ����� ����:");
    userChoice = GetInt();
    switch (userChoice)
    {
      case MANUAL:
        GetDoubleMatrix(N_SIZE, M_SIZE, matrix);
        puts("�������� �������:");
        ShowMatrix(N_SIZE, M_SIZE, matrix);
        Scg = MaxToFirst(N_SIZE, M_SIZE, matrix);
        puts("���������� �������:");
        ShowMatrix(N_SIZE, M_SIZE, matrix);
        printf("����������� ���������� �����:%d\n", Scg);
        break;
      case RANDOM:
        GetRandomDoubleMatrix(N_SIZE, M_SIZE, matrix);
        puts("����������� ���������� ������� �������:");
        ShowMatrix(N_SIZE, M_SIZE, matrix);
        Scg = MaxToFirst(N_SIZE, M_SIZE, matrix);
        puts("���������� �������:");
        ShowMatrix(N_SIZE, M_SIZE, matrix);
        printf("����������� ���������� �����:%d\n", Scg);
        break;
      case EXIT:
        return EXIT_SUCCESS;
      default:
        puts("������ ������ � ���� ���!");
    }
  }  
  while (userChoice != EXIT);
}
