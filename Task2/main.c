/**************************************************
* Название: main.c                                *
* Задание: Одномерные массивы                     *
* Автор: Д. Л. Валиев, СПбГТИ (ТУ), 2023          *
**************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>
#include <math.h>
#include "info.h"
#include "random.h"
#include "inputs.h"
#define SIZE 30

int GetSequenceElement(int num, int arr[]) 
{
  return arr[num - 1] + arr[num - 2];
}

bool IsValid(int num1, int num2)
{
  if (fabs(num1) <= 1597 && fabs(num2) <= 2584)
  {
    return true;
  }
  puts("Некорректный ввод!");
  return false;
}

int main(void) 
{
  setlocale(LC_CTYPE, "RU");

  ShowInfo(2, 2, 5);

  // хренение элементов последовательности в массиве
  int sequence[SIZE] = { 0 };
  enum menu { MANUAL = 1, RANDOM = 2, EXIT = 3 };
  enum menu userChoice;

  // вывод пунктов меню
  puts("1 - Ввести значения вручную");
  puts("2 - Заполнить псевдослучайными значениями");
  puts("3 - Завершить работу");

  do 
  {
    puts("Введите пункт меню");
    userChoice = GetInt();

    switch (userChoice) 
    {
      case MANUAL:
        // запись в массив sequence первого и второго элементов последовательности
        do
        {
          printf("Введите первый элемент последовательности в диапазоне [-1597; 1597]\n");
          sequence[0] = GetInt();
          printf("Введите второй элемент последовательности в диапазоне [-2584; 2584]\n");
          sequence[1] = GetInt();
        } while (!IsValid(sequence[0], sequence[1]));

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
      case RANDOM:
        // запись в массив sequence первого и второго элементов последовательности
        sequence[0] = GetRandomInt() % 1597;
        sequence[1] = GetRandomInt() % 2584;

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
