/**************************************************
* ��������: main.c                                *
* �������: ���������� �������                     *
* �����: �. �. ������, ������ (��), 2023          *
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

  // �������� ��������� ������������������ � �������
  int sequence[SIZE] = { 0 };
  enum menu { START = 1, EXIT = 2 };
  enum menu userChoice;

  // ����� ������� ����
  puts("1 - ��������� ���������");
  puts("2 - ��������� ������");

  do 
  {
    puts("������� ����� ����");
    userChoice = GetInt();

    switch (userChoice) 
    {
      case START:
        // ������ � ������ sequence ������� � ������� ��������� ������������������
        printf("������� ������ ������� ������������������: ");
        sequence[0] = GetInt();
        printf("������� ������ ������� ������������������: ");
        sequence[1] = GetInt();

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