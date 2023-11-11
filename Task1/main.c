/**************************************************
* Название: main.c                                *
* Задание: Рекуррентные последовательности        *
* Автор: Д. Л. Валиев, СПбГТИ (ТУ), 2023          *
**************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <float.h> //для получения DBL_MAX

// функция, задающая последовательность
double GetSequenceElement(int n) 
{
  if (n == 1) 
  {
    return 0.5;
  }
  else if (n == 2)
   {
    return 0.27;
  }
  else 
  {
    double current = 0.0; // хранение i элемента последовательности 
    double prev1 = 0.27;  // хранение i-1 элемента последовательности
    double prev2 = 0.5;   // хренение i-2 элемента последовательности

    for (int i = 3; i < n + 1; i++) 
    {
      // вычисление значения для i элемента последовательности
      current = 2 * sin(prev1) - 3 * cos(prev2);

      // для следующей итерации i-1 элемент становится i-2, i элемент становится i-1
      prev2 = prev1;   
      prev1 = current;
    }

    return current;
  }
}

void showInfo(void) 
{
  puts("Валиев Данил Ленарович");
  puts("Группа: 4304");
  puts("Контрольная работа 2");
  puts("Задание 1");
  puts("Вариант 5\n");
}

int main(void) 
{
  setlocale(LC_CTYPE, "RU");

  showInfo();

  // хранение значения наименьшего элемента последовательности
  double seqMin = DBL_MAX;  
  // хранение индекса наименьшего элемента последовательности
  int seqMin_index = -1;

  // поиск циклом for
  for (int i = 1; i <= 70; i++)
   {
    if (GetSequenceElement(i) < seqMin) 
    {
      seqMin = GetSequenceElement(i);
      seqMin_index = i;
    }
  }

  printf("Значение наименьшего элемента последовательности: %f\n", seqMin);
  printf("Индекс наименьшего элемента последовательности: %d\n", seqMin_index);

  return EXIT_SUCCESS;
}
