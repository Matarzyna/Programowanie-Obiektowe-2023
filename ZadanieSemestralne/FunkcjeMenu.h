#pragma once
#define m 100
#define rozm 15
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <string>
#include <ctime>
#include <iostream>
#include <fstream>
#include <iostream>
using namespace std;


string Pobierz_nick()
{
	//Funkcja pobiera nick i go zwraca 
	string nazwa;
	while (getchar() != '\n');
	cout<<"Podaj nazwe gracza: ";
	cin >> nazwa;
	return nazwa;
};

int ile_graczy()
{
	//pobiera iloœæ graczy - 1 - komputer 2 - 2 graczy
	char wybor;
	cout << "Podaj ilosc graczy:\n1 - gra z komputerem\n2 - gra z przyjacielem\n";
	int ile;
	while ((scanf_s("%c", &wybor, 1)) != 1 || wybor < '1' || wybor > '2')
	{
		system("cls");
		cout << "To nie jest poprawna liczba. Popraw\n";
		cout << "Podaj ilosc graczy:\n1 - gra z komputerem\n2 - gra z przyjacielem\n";
	}

	system("cls");
	ile = (int)(wybor - '0');

	return ile;
};

int Nowa_czy_tablica()
{
	//menu glowne
	char wyborek;
	int wybor;
	cout << "************************";
	cout << "\n\t Gomoku\n";
	cout << "************************" <<endl;
	cout << "1 - Nowa gra\n";
	cout << "2 - Tablica wynikow\n";
	cout << "3 - Wyjdz z gry\n";
	cout << endl << "***Katarzyna*Michaluk***" << endl;
	while ((scanf_s("%c", &wyborek,1)) != 1 || wyborek < '1' || wyborek > '3')
	{
	
		system("cls");
		cout << "************************";
		cout << "\n\t Gomoku\n";
		cout << "************************" << endl;
		cout << "1 - Nowa gra\n";
		cout << "2 - Tablica wynikow\n";
		cout << "3 - Wyjdz z gry\n\n";
		cout << "To nie jest poprawny wybor. Popraw >:(\n";
	}
	system("cls");
	wybor = (int)(wyborek - '0');
	return wybor;
};

char podajwiersz(void) {
	char wiersz;
	//pobiera adres wiersza do ruchu
	do {
		while (getchar() != '\n') { ; }
		cout << "Podaj wiersz: (A-O)\n";
		cin >> wiersz;
		if (islower(wiersz))
		{
			//akceptowalne s¹ ma³e i du¿e litery
			wiersz=toupper(wiersz);
		}
		if (wiersz<'A' || wiersz>'O')
			cout << "To nie jest poprawny nr wiersza! Popraw\n";
	} while (wiersz<'A' || wiersz>'O');
	return wiersz;
};

int podajkolumne(void) {
	int liczba=0;
	//pobiera numer kolumny do polozenia symbolu
	do {
		while (getchar() != '\n') { ; }
		cout << "Podaj numer kolumny: (1-15)\n";
		cin >> liczba;
		if (liczba < 1 || liczba>15)
			cout << "To nie jest poprawny numer kolumny! Popraw\n";
	} while (liczba < 1 || liczba>15);
	return liczba;
};

int wybor_trybu(void) {
	//wybor trybu gry
	char wybor='1';
	int tryb_gry;
	do {
		
		while (getchar() != '\n') { ; }

		cout << "Wybierz tryb gry:\n1 - Standard\n2 - PRO\n3 - SWAP2\n";

		if (wybor < '1' || wybor > '3')
			cout << "To nie jest poprawny wybor" << endl;

		cin >> wybor;
		system("cls");
	} while (wybor < '1' || wybor > '3');
	tryb_gry = (int)(wybor - '0');

	return tryb_gry;
}

int wybor_graczy(void) {
	//ilosc graczy
	int ile_graczy;
	char wybor='1';
	do {	
		cout << "Podaj liczbe graczy:\n1 - gra z komputerem\n2 - gra z przyjacielem\n";

		if (wybor < '1' || wybor > '3')
			cout << "To nie jest poprawny wybor, popraw" << endl;

		cin >> wybor;
		system("cls");

	} while (wybor < '1' || wybor > '2');
	ile_graczy = (int)(wybor - '0');
	return ile_graczy;
}