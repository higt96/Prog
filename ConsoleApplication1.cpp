// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//


#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <cstdio>
#include "windows.h";
using namespace std;

int main(int argc, char* argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_CTYPE, "ukr");
	char str[80];
	char buff[254];
	int n;
	n=0;
	char s;
	ifstream fin("help.txt");
	cout << fin.rdbuf()<< endl;
	fin.close(); // закрываем файл
		
	while (n != 1)
	{
		cin.getline(str,80);
		
		if (strlen(str) <= 1)
		{
			s = str[0];

			switch (s)
			{
		

			case 'f':
			{
				ifstream fin("text.txt");
				cout << fin.rdbuf();				
				fin.close(); // закрываем файл
				break;
			}

			case 'q':
			{
				n=1;
				break;
			}

			case 'j':
			{
				ofstream fout("text.txt", ios_base::trunc);
				fout.close(); // закрываем файл
				break;
			}
			
			}
		}
		else
		{
			ofstream fout("text.txt", ios_base::app);
			fout << str<< endl; // запись строки в файл
			fout.close(); // закрываем файл
			
			
		}
	}
}


