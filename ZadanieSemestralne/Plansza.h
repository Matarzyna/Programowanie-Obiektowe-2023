#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <string>
#include <ctime>
#include <iostream>
#include <fstream>

#define m 100
#define rozm 15
using namespace std;

class plansza {
private:

	char tablica[rozm][rozm];
public:
	plansza();
	void wypisz();
	bool poloz_kamien(char, int );
	bool czy_wygrana(char, int, char );
	void ruch(char, char, int);

};