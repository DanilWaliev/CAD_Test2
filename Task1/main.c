/**************************************************
* ��������: main.c                                *
* �������: ������������ ������������������        *
* �����: �. �. ������, ������ (��), 2023          *
**************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <float.h> //��� ��������� DBL_MAX

// �������, �������� ������������������
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
    double current = 0.0; // �������� i �������� ������������������ 
    double prev1 = 0.27;  // �������� i-1 �������� ������������������
    double prev2 = 0.5;   // �������� i-2 �������� ������������������

    for (int i = 3; i < n + 1; i++) 
    {
      // ���������� �������� ��� i �������� ������������������
      current = 2 * sin(prev1) - 3 * cos(prev2);

      // ��� ��������� �������� i-1 ������� ���������� i-2, i ������� ���������� i-1
      prev2 = prev1;   
      prev1 = current;
    }

    return current;
  }
}

void showInfo(void) 
{
  puts("������ ����� ���������");
  puts("������: 4304");
  puts("����������� ������ 2");
  puts("������� 1");
  puts("������� 5\n");
}

int main(void) 
{
  setlocale(LC_CTYPE, "RU");

  showInfo();

  // �������� �������� ����������� �������� ������������������
  double seqMin = DBL_MAX;  
  // �������� ������� ����������� �������� ������������������
  int seqMin_index = -1;

  // ����� ������ for
  for (int i = 1; i <= 70; i++)
   {
    if (GetSequenceElement(i) < seqMin) 
    {
      seqMin = GetSequenceElement(i);
      seqMin_index = i;
    }
  }

  printf("�������� ����������� �������� ������������������: %f\n", seqMin);
  printf("������ ����������� �������� ������������������: %d\n", seqMin_index);

  return EXIT_SUCCESS;
}
