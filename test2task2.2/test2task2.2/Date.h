#pragma once

// ��������� ����
typedef struct Date Date;

// ����������� ����
void printDate(Date* date);

// ������� ���� � �����
Date* readFromFile(char fileName[]);

// ������ ����
void getDate(Date* date, int* day, int* month, int* year);