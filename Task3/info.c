#ifndef stdio
#include <stdio.h>
#endif

#ifndef locale
#include <locale.h>
#endif

void ShowInfo(int test, int task, int version)
{
  puts("������ ����� ���������");
  puts("������: 4304");
  printf("����������� ������ %d\n", test);
  printf("������� %d\n", task);
  printf("������� %d\n\n", version);
}
