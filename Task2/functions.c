#include <stdio.h>

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

void ShowInfo(int test, int task, int version)
{
  puts("������ ����� ���������");
  puts("������: 4304");
  printf("����������� ������ %d\n", test);
  printf("������� %d\n", task);
  printf("������� %d\n\n", version);
}