#ifndef stdio
#include <stdio.h>
#endif

#ifndef locale
#include <locale.h>
#endif

int GetInt(void)
{
  int input = 0;

  while (!scanf("%d", &input))
  {
    while (getchar() != '\n');
    puts("������������ ����");
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
    puts("������ �����. ������� ������������ �����.");
  }

  while (getchar() != '\n');

  return input;
}
