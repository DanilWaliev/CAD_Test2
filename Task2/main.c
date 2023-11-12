/**************************************************
* ��������: main.c                                *
* �������: ���������� �������                     *
* �����: �. �. ������, ������ (��), 2023          *
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
  puts("������������ ����!");
  return false;
}

int main(void) 
{
  setlocale(LC_CTYPE, "RU");

  ShowInfo(2, 2, 5);

  // �������� ��������� ������������������ � �������
  int sequence[SIZE] = { 0 };
  enum menu { MANUAL = 1, RANDOM = 2, EXIT = 3 };
  enum menu userChoice;

  // ����� ������� ����
  puts("1 - ������ �������� �������");
  puts("2 - ��������� ���������������� ����������");
  puts("3 - ��������� ������");

  do 
  {
    puts("������� ����� ����");
    userChoice = GetInt();

    switch (userChoice) 
    {
      case MANUAL:
        // ������ � ������ sequence ������� � ������� ��������� ������������������
        do
        {
          printf("������� ������ ������� ������������������ � ��������� [-1597; 1597]\n");
          sequence[0] = GetInt();
          printf("������� ������ ������� ������������������ � ��������� [-2584; 2584]\n");
          sequence[1] = GetInt();
        } while (!IsValid(sequence[0], sequence[1]));

        // ���������� ������� �������, �� �������� ������������������
        for (int i = 2; i < SIZE; i++)
        {
          sequence[i] = GetSequenceElement(i, sequence);
        }

        // ����� ��������� ����������� �������
        for (int i = 0; i < SIZE; i++)
        {
          printf("%d ������� ������������������ = %d\n", i + 1, sequence[i]);
        }

        break;
      case RANDOM:
        // ������ � ������ sequence ������� � ������� ��������� ������������������
        sequence[0] = GetRandomInt() % 1597;
        sequence[1] = GetRandomInt() % 2584;

        // ���������� ������� �������, �� �������� ������������������
        for (int i = 2; i < SIZE; i++)
        {
          sequence[i] = GetSequenceElement(i, sequence);
        }

        // ����� ��������� ����������� �������
        for (int i = 0; i < SIZE; i++)
        {
          printf("%d ������� ������������������ = %d\n", i + 1, sequence[i]);
        }

        break;
      case EXIT:
        return EXIT_SUCCESS;
      default:
        puts("������ ������ � ���� ���");
    }
  } while (userChoice != EXIT);
}
