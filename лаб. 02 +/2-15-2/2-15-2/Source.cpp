#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <ctime>
#include <iostream>
int main()
{
	using namespace std;
	int i;
	FILE* F1;
	F1 = fopen("file.txt", "wt");
	if (!F1)
	{
		printf("Error!");
		return 0;
	}

	int bb;
	srand((unsigned)time(NULL));
	for (i = 1; i < 9; i++) {
		bb = rand() % 20;
		fprintf(F1, "%d\n", bb);
	}
	fclose(F1);

	int k = 0;
	
	FILE* finput;
	int s;
	finput = fopen("file.txt", "r+");

	while ((fscanf(finput, "%d", &s) != EOF))
	{
		if (!finput) break; 
		k++;
	}
	int* c = (int*)malloc(k * sizeof(int));
	rewind(finput); 

	FILE* F2;
	F2 = fopen("file2.txt", "wt");
	
	int k, t = 0;
	cin >> k;
	for (i = 0; i < 10; i++)
	{
		if (i >= (k - 1) && t != 4) {
			fscanf(finput, "%d", &c[i]);
			fprintf(F2, "%d\n", c[i]);
			t += 1;
		}
		else {
			fscanf(finput, "%d", &c[i]);
		}
	}
	fclose(finput); 

	free(c); 
	fclose(F2);
	printf("DONE!");
	return 0;
}