#include "stdafx.h"
#include <stdlib.h>

#define SIZE 8
#define INF 99999

void findAllPairShortestPath(int **, int **);
void findPath(int **, int, int);
void generate(int **);
void initialize(int **, int **);
void print(int **);
void useExampleData(int **);

int main()
{
	int i, j;

	//Data for gen
	int **datagen;
	datagen = (int**)malloc(SIZE * sizeof(int*));
	for (i = 0; i < SIZE; i++)
	{
		datagen[i] = (int*)malloc(SIZE * sizeof(int));
	}

	//generate data
	//generate(datagen);
	useExampleData(datagen);

	//Print datagen
	print(datagen);
	
	//start time
	system("@echo Start %time%");

	//Data for receiving from datagen
	//Path for collect path
	int **data, **path;
	data = (int**)malloc(SIZE * sizeof(int*));
	path = (int**)malloc(SIZE * sizeof(int*));
	for (i = 0; i < SIZE; i++)
	{
		data[i] = (int*)malloc(SIZE * sizeof(int));
		path[i] = (int*)malloc(SIZE * sizeof(int));
	}

	//Data for collect path
	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
			path[i][j] = j;
		}
	}

	//copy datagen to data
	initialize(datagen, data);

	//Find Shortest Path
	findAllPairShortestPath(data,path);

	//Finishtime
	system("@echo Finish %time%");

	//Print AllPairShortestPath
	print(data);

	//Print Path
	findPath(path, 1, 7);

	getchar();
	return 0;
}

void findAllPairShortestPath(int **graph,int **path)
{
	for (int k = 0; k < SIZE; k++)
	{
		for (int i = 0; i < SIZE; i++)
		{
			for (int j = 0; j < SIZE; j++)
			{
				if (graph[i][k] + graph[k][j] < graph[i][j])
				{
					graph[i][j] = graph[i][k] + graph[k][j];
					path[i][j] = path[i][k];
				}
			}
		}
	}
}

void generate(int **data)
{
	int i, j, r;

	for (i = 0; i < SIZE; i++)
	{
		data[i][i] = 0;
		for (j = i + 1; j < SIZE; j++)
		{
			r = (rand() % 20) + 1;
			if (r == 19)
				data[i][j] = INF;
			else
				data[i][j] = r;
			data[j][i] = data[i][j];
		}
	}
}

void initialize(int **sour, int **dest)
{
	int i, j;

	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
		{
			dest[j][i] = sour[i][j];
		}
	}
}

void print(int **distance)
{
	printf("Shortest distances\n");

	for (int i = 0; i < SIZE; ++i)
	{
		for (int j = 0; j < SIZE; ++j)
		{
			if (distance[i][j] == INF)
				printf("%7s", "INF");
			else
				printf("%7d", distance[i][j]);
		}
		printf("\n");
	}
}

void useExampleData(int **data) 
{
	int example[SIZE][SIZE] = {
		{ 0,1,9,3,INF,INF,INF,INF },
		{ 1,0,INF,1,INF,3,INF,INF },
		{ 9,INF,0,INF,INF,3,10,INF },
		{ 3,1,INF,0,5,INF,INF,8 },
		{ INF,INF,INF,5,0,2,2,1 },
		{ INF,3,3,INF,2,0,INF,INF },
		{ INF,INF,10,INF,2,INF,0,4 },
		{ INF,INF,INF,8,1,INF,4,0 }
	};
		
	int i, j;

	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
		{	
			data[i][j] = example[i][j];
		}
	}
}

void findPath(int** shortestpath, int u, int v) 
{
	if (shortestpath[u][v] == NULL)
		printf("[]");

	printf("[%d]",u);
	while (u != v) {
		u = shortestpath[u][v];
		printf("[%d]",u);
	}
}
