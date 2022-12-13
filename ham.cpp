#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <stdio.h>
#include <Windows.h>

bool hasCycle;
FILE *F2;
char F2name[20], copy;

void printgraph(int graph[5][5])// вывод матрицы смежности на экран
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			printf_s("%d \t", graph[i][j]);
		}
		printf_s("\n");
	}
}

bool isSafe(int v, int graph[5][5], std::vector<int> path, int pos) //фунцкия проверки вершины на наличие в гамильтоновом цикле 
{
	if (graph[path[pos - 1]][v] == 0)//проврека на смежность ранее добавленной вершины с проверяемой
	{
		return false;//если они несмежны
	}

	for (int i = 0; i < pos; i++)//исключение повтора вершины в массиве 
	{
		if (path[i] == v)
		{
			return false;//если она уже была в гамильтоновом пути
		}
	}
	return true;
}

void FindHamCycle(int graph[5][5], int pos, std::vector<int> path, bool visited[], int N, int versh) //
{
	if (pos == N) //если все вершины просмотрены
	{
		if (graph[path[path.size() - 1]][path[0]] != 0)//если последняя веришна смежна с начальной, вывод на экран гамильтонового цикла
		{

			path.push_back(versh);
			F2 = fopen(F2name, "a+");
			for (int i = 0; i < path.size(); i++)
			{
				printf_s("%d->", path[i] + 1);
				fprintf(F2, "%d->", (path[i] + 1));
			}
			printf_s("\b\b");
			printf_s("  ");
			printf_s("\n");
			fprintf(F2, "\n");
			path.pop_back();


			hasCycle = true;
		}
		return;
	}


	for (int v = 0; v < N; v++)//просмотр разных вершин на наличие в гамильтоновом цикле
	{
		if (isSafe(v, graph, path, pos) && !visited[v])//проверка данной вершины на наличие в гамильтоновом цикле
		{

			path.push_back(v);
			visited[v] = true;


			FindHamCycle(graph, pos + 1, path, visited, N, versh);//рекурсия для проверки других вершин


			visited[v] = false; 
			path.pop_back();
		}
	}
}

void hamCycle(int graph[5][5], int N, int versh, FILE* F1)//начало алгоритма поиска гамильтонового цикла в графе
{
	SetConsoleCP(1251);
	printf_s("Введите имя файла, в который будет записан ответ: ");
	scanf_s("%s", &F2name, 20);
	F1 = fopen("F1.txt", "r");
	F2 = fopen(F2name, "w+");
	fprintf(F2, "Матрица смежности:\n");
	while ((copy = getc(F1)) != EOF)
	{
		putc(copy, F2);
	}
	fprintf(F2, "\n");
	fprintf(F2, "Гамильтоновые циклы\n");
	printf_s("Гамильтоновые циклы\n");

	hasCycle = false;

	std::vector<int> path;
	path.push_back(versh);

	bool visited[5];

	for (int i = 0; i < N; i++)
	{
		visited[i] = false;
	}

	visited[versh] = true;
	
	FindHamCycle(graph, 1, path, visited, N, versh);//вызов фунцкии поиска гамильнового цикла

	if (!hasCycle) {

		printf_s("не найдены");
		return;
	}
	fclose(F2);
}

void printgraph(int** graph, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf_s("%d \t", graph[i][j]);
		}
		printf_s("\n");
	}
}

bool isSafe(int v, int** graph, std::vector<int> path, int pos)
{
	if (graph[path[pos - 1]][v] == 0)
	{
		return false;
	}

	for (int i = 0; i < pos; i++)
	{
		if (path[i] == v)
		{
			return false;
		}
	}
	return true;
}

void FindHamCycle(int** graph, int pos, std::vector<int> path, bool visited[], int N, int versh)
{
	if (pos == N)
	{


		if (graph[path[path.size() - 1]][path[0]] != 0)
		{

			path.push_back(versh);

			for (int i = 0; i < path.size(); i++)
			{
				printf_s("%d->", path[i] + 1);
			}
			printf_s("\b\b");
			printf_s("  ");
			printf_s("\n");


			path.pop_back();


			hasCycle = true;
		}
		return;
	}


	for (int v = 0; v < N; v++)
	{
		if (isSafe(v, graph, path, pos) && !visited[v])
		{

			path.push_back(v);
			visited[v] = true;


			FindHamCycle(graph, pos + 1, path, visited, N, versh);


			visited[v] = false;
			path.pop_back();
		}
	}
}

void hamCycle(int** graph, int N, int versh)
{

	hasCycle = false;

	std::vector<int> path;
	path.push_back(versh);

	bool* visited = (bool*)malloc(N*sizeof(bool));

	for (int i = 0; i < N; i++)
	{
		visited[i] = false;
	}

	visited[versh] = true;

	FindHamCycle(graph, 1, path, visited, N, versh);

	if (!hasCycle) {

		printf_s("не найдены\n");
		return;
	}

}

