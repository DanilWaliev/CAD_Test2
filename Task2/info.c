#ifndef stdio
#include <stdio.h>
#endif

#ifndef locale
#include <locale.h>
#endif

void ShowInfo(int test, int task, int version)
{
  puts("Валиев Данил Ленарович");
  puts("Группа: 4304");
  printf("Контрольная работа %d\n", test);
  printf("Задание %d\n", task);
  printf("Вариант %d\n\n", version);
}
