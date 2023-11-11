/**************************************************
* Название: main.c                                *
* Задание: Одномерные массивы                     *
* Автор: Д. Л. Валиев, СПбГТИ (ТУ), 2023          *
**************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "functions.h"
#define SIZE 30

double GetSequenceElement(int num, int arr[]) 
{
  return arr[num - 1] + arr[num - 2];
}

int main(void) 
{
  setlocale(LC_CTYPE, "RU");

  ShowInfo(2, 2, 5);

  // хренение элементов последовательности в массиве
  int sequence[SIZE] = { 0 };
  enum menu { START = 1, EXIT = 2 };
  enum menu userChoice;

  // вывод пунктов меню
  puts("1 - Выполнить программу");
  puts("2 - Завершить работу");

  do 
  {
    puts("Введите пункт меню");
    userChoice = GetInt();

    switch (userChoice) 
    {
      case START:
        // запись в массив sequence первого и второго элементов последовательности
        printf("Введите первый элемент последовательности: ");
        sequence[0] = GetInt();
        printf("Введите второй элемент последовательности: ");
        sequence[1] = GetInt();

        // заполнение массива числами, по заданной последовательности
        for (int i = 2; i < SIZE; i++)
        {
          sequence[i] = GetSequenceElement(i, sequence);
        }

        // вывод элементов полученного массива
        for (int i = 0; i < SIZE; i++)
        {
          printf("%d элемент последовательности = %d\n", i + 1, sequence[i]);
        }

        break;
      case EXIT:
        return EXIT_SUCCESS;
      default:
        puts("Такого пункта в меню нет");
    }
  } while (userChoice != EXIT);
}