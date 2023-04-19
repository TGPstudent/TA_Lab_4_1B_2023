//TA_Lab_4_1B_2023.c Робота з динамічною пам’яттю. З двох векторів утворити третій заповнивши його різницею елементів первинних масивів.(Генерація масивів випадковими числами.)

#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

void Input_Gener_Arr(int N, int *C);
void Out_Arr(int N, int *C);

int main(void)
{	//Мова консолі українська
	system("chcp 1251");
	setlocale(LC_CTYPE, "ukr");
	system("cls");

	int n;
	//Введення з консолі кількості елементів
	do
	{
		printf("\n Введiть кiлькiсть елементiв в векторах, які необхідно опрацювати N="); scanf("%d", &n);
		if (n <= 1) printf("\n Введене некоректне число менше 1. Спробуйте ще раз!");
	} while (n <= 1);

	//Виділення пам'яті та введення вектору А
	int *a = (int*)calloc(n, sizeof(int));
	if (a == NULL)
	{
		printf("Збiй при виділення динамічної памяті для масиву А");
		return 1;
	}
	else Input_Gener_Arr(n, a);//Генеруємо вектор а
	
	printf("\n Згенеровано вектор А");
	printf("\n Для продовження натисніть будь-яку кнопку...\n");
	int getch(); getch();
	
	//Виділення пам'яті та введення вектору b
	int *b = (int*)calloc(n, sizeof(int));
	if (b == NULL)
	{
		printf("Збiй при виділення динамічної памяті для масиву В");
		return 1;
	}
	else Input_Gener_Arr(n, b);//Генеруємо вектор b
	printf("\n Згенеровано вектор B");
	printf("\n Для продовження натисніть будь-яку кнопку...\n");
	int getch(); getch();

	system("cls");
	
	//Виділення пам'яті та обрахунок вектору Rez
	int *Rez = (int*)calloc(n, sizeof(int));
	if (Rez == NULL)
	{
		printf("Збiй при виділення динамічної памяті для масиву результатів");
		return 1;
	}
	else
	{
		for (int i = 0; i < n; i++)
			*(Rez + i) = *(a + i) - *(b + i);
	}

	//Виведення результатыв в консоль
	printf("\n Програма обраховує різницю елементів двох векторів, \n які містять випадкові числа з діапазону[-100 ; 100]\n");
	printf("\n Згенеровано вектор А={");
	Out_Arr(n, a);
	printf(" Згенеровано вектор B={"); 
	Out_Arr(n, b);
	printf(" Вeктор результатів: REZ={");
	Out_Arr(n, Rez);

	free(a); free(b); free(Rez);

	int getch(); getch();
	return 0;
}

//Функція - генератор масиву розміром N випадковими числами від Low до High
void Input_Gener_Arr(int N, int *C)
{
	const int Low = -100, High = 100;
	srand((unsigned int)time(NULL));
	for (int i = 0; i < N; i++)
		*(C + i) = Low + rand() % (High - Low + 1);
}

//Функція виведення одномірного масиву на екран розміром N
void Out_Arr(int N, int *C)
{
	int *Last = C + (N - 1);
	for (C; C <= Last; C++)
		printf("%d, ", *C);
	printf("\b\b};\n");
}

