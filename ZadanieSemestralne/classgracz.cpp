#include "ClassGracz.h"
char zapytaj_wiersz(void) {
	//pobranie nr wiersza od uzytkownika i kontrola czy jest poprawny
	char wiersz;
	do {
		cout << "Podaj wiersz: (A-O)\n";
		cin >> wiersz;
		if (islower(wiersz))
		{
			wiersz = toupper(wiersz);
		}
		if (wiersz<'A' || wiersz>'O')
			cout << "To nie jest poprawny nr wiersza! Popraw\n";
	} while (wiersz<'A' || wiersz>'O');
	return wiersz;
};

int zapytaj_kolumne(void) {
	//pobranie nr kolumny od uzytkownika z kontrola wejscia
	int liczba = 0;
	do {
		liczba = 0;
		cout << "Podaj numer kolumny: (1-15)\n";
		cin >> liczba;
		if (liczba < 1 || liczba>15)
			cout << "To nie jest poprawny numer kolumny! Popraw\n";
	} while (liczba < 1 || liczba>15);
	return liczba;
};

gracz::gracz() { ksztalt = 'X'; };
gracz::gracz(char kolor) {
	if (kolor == 'X')
		ksztalt = 'X';
	else
		ksztalt = 'O';
};

//czlowiek
void czlowiek::wygrana() {
	//wiadomosc z wygrana
	cout << endl << "***********************" << endl;
	cout << endl << ksztalt << " wygrywa! Gratulacje :)"<<endl;
	cout << endl << "***********************" << endl;
};

czlowiek::czlowiek(char kolor) :gracz(kolor) { ; };
void czlowiek::set_kamien(char kolor) {
	if (kolor == 'X')
		ksztalt = 'X';
	else
		ksztalt = 'O';
}
bool czlowiek::ruch(plansza *a)
{
	//ruch czlowieka
	int liczba;
	char litera;
	do {
		//pobieranie adresu az do skutku
		litera = zapytaj_wiersz();
		liczba = zapytaj_kolumne();
	} while (!a->poloz_kamien(litera, liczba));
	//polozenie kamienia
	a->ruch(ksztalt, litera, liczba);

	//sprawdzenie czy ten ruch skutkuje wygrana
	if (a->czy_wygrana(litera, liczba, ksztalt))
		return 1;
	else
		return 0;
	
}
//komputer 
komputer::komputer() {
	ksztalt = 'O';
};

void komputer :: set_kamien(char kolor) {
	if (kolor == 'X')
		ksztalt = 'X';
	else
		ksztalt = 'O';
}

komputer::komputer(char kolor) :gracz(kolor) { ; };


bool komputer::ruch(plansza *p)
{
	//ruch komputera 
	//kontrola powoduje ze pseudolosowe liczby nigdy nie najd¹ na zajête pole
	char wiersz = 'A';
	int kolumna;
	do{
		wiersz = 'A';
		kolumna = 0;

		int los = rand() % 15;
		wiersz += los;
		los = rand() % 15;
		kolumna = los;
	} while (!(p->poloz_kamien(wiersz, kolumna)));
	p->ruch(ksztalt, wiersz, kolumna);
	//sprawdzenie warunkow na wygrana
	if (p->czy_wygrana(wiersz, kolumna, ksztalt))
		return 1;
	else return 0;
};

void komputer::wygrana() {
	printf("\nPrzegrales... Wygrywa komputer\n");
}