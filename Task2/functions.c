#include <stdio.h>

int GetInt(void)
{
  int input = 0;

  while (!scanf("%d", &input))
  {
    while (getchar() != '\n');
    puts("Некорректный ввод");
  }

  while (getchar() != '\n');

  return input;
}

double GetDouble(void)
{
  double input = 0.0;

  while (!scanf("%lf", &input))
  {
    while (getchar() != '\n');
    puts("Ошибка ввода. Введите вещественное число.");
  }

  while (getchar() != '\n');

  return input;
}

void ShowInfo(int test, int task, int version)
{
  puts("Валиев Данил Ленарович");
  puts("Группа: 4304");
  printf("Контрольная работа %d\n", test);
  printf("Задание %d\n", task);
  printf("Вариант %d\n\n", version);
}