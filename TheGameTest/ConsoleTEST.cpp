// ConsoleTEST.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <ctime>

using namespace std;


int main()
{

	const int rows = 10;
	//const int cols = 10;

	
	int sapper[rows][rows];
	int B[rows][rows];
	int count = 0;
	srand(time(0));																			// "zerno" dlya randoma
	while (count < 10)
	{

		for (int i = 0; i < rows; i++)														// zapolnenie massiva + random
		{
			for (int j = 0; j < rows; j++)
			{
				int k = rand() % 10;
				if (k == 1 && count < 10)
				{
					sapper[i][j] = 1;
					count++;
				}
				else if (sapper[i][j] != 1)
				{
					sapper[i][j] = 0;
				}
			}

		}
	}
	for (int i = 0; i < rows; i++)															// vivod massiva v konsol
	{
		for (int j = 0; j < rows; j++)
		{
			cout << sapper[i][j]<< ' ';
		}
		cout << endl;

	}
	cout << endl;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			int a = 0;
			if (sapper[i][j] == 1) { a++; }
			if (sapper[i][j - 1] == 1 && j > 0) { a++; }
			if (sapper[i][j + 1] == 1 && j < rows) { a++; }
			if (sapper[i - 1][j] == 1 && i > 0) { a++; }
			if (sapper[i + 1][j] == 1 && i < rows) { a++; }
			if (sapper[i - 1][j - 1] == 1 && i > 0 && j > 0) { a++; }
			if (sapper[i - 1][j + 1] == 1 && i > 0 && j < rows) { a++; }
			if (sapper[i + 1][j - 1] == 1 && i < rows && j > 0) { a++; }
			if (sapper[i + 1][j + 1] == 1 && i < rows && j < rows) { a++; }
			B[i][j] = a;
			cout << B[i][j] << ' ';
		}
		cout << endl;
	}
	
}


