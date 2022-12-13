#define _CRT_SECURE_NO_WARNINGS
#include "menu.h"
#include "ham.h"
#include <iostream>
#include <vector>
#include <conio.h>
#include <Windows.h>
#include <time.h>
using namespace std;

FILE* F1;
char F1name[20] = ("F1.txt");

void gif()
{
	int graph[5][5];
	char name[10];

	printf_s("Введите имя файла (F1.txt) -> ");
	scanf_s("%s", &name, 10);
	
	if (strcmp(name, F1name) == 0)
	{
		if (F1 = fopen(F1name, "r"))
		{
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					fscanf(F1, "%d", &graph[i][j], 5, 5);
				}
			}

			printf_s("Матрица смежности\n");
			printgraph(graph);

			int versh;
			printf_s("Введите начальную вершину от 1 до %d -> ", 5);
			do
			{
				scanf_s("%d", &versh);
				if (versh < 1 || versh > 5)
				{
					printf_s("Неправильный ввод, введите вершину заново -> ");
				}
			} while (versh < 1 || versh > 5);

			versh--;
			hamCycle(graph, 5, versh, F1);
			fclose(F1);
		}
		else
		{
			printf_s("Файла нет ");
		}
	}
	else
	{
		printf_s("Такого файла не существует\n");
	}
}

void rg()
{
	srand(time(NULL));
	
	int n, versh;
	printf("Введите размер матрицы смежности -> ");
	scanf_s("%d", &n);
	int** graph = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++)
	{
		graph[i] = (int*)malloc(n * sizeof(int));
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			graph[i][j] = rand() % 2;
			if (i == j)
			{
				graph[i][j] = 0;
			}
			graph[j][i] = graph[i][j];
		}
	}
	
	printf("Матрица смежности\n");
	printgraph(graph, n);

	printf_s("Введите начальную вершину от 1 до %d -> ", n);
	do
	{
		scanf_s("%d", &versh);
		if (versh < 1 || versh > n)
		{
			printf_s("Неправильный ввод, введите вершину заново -> ");
		}
	} while (versh < 1 || versh > n);

	versh--;

	printf_s("Гамильтоновые циклы\n");
	hamCycle(graph, n, versh);
}

int main()
{
	SetConsoleOutputCP(1251);

	menu();

	while (true)
	{
		int s = _getch();
		switch (s)
		{
			case '1': rg(); break;
			case '2': gif(); break;
			case '3': return 0; 
		}
	}
}

