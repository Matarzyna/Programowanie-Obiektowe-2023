
#include "FunkcjeMenu.h"
#include "ClassGracz.h"

#define m 100
#define rozm 15
using namespace std;
void ranking(string nazwa) {
	//Zapis  imienia wygranej osoby do pliku Ranking.txt z aktualnym czasem
	ofstream plik("Ranking.txt", ios::app | ios::out);
	if (plik.good())
	{
		time_t czas;
		struct tm * aktualnyCzas;

		time(&czas);
		aktualnyCzas = localtime(&czas);
		plik << asctime(aktualnyCzas) << " wygrana: " << nazwa << endl;
	}
	else
		cout << "Nie udalo sie otworzyc pliku z rekordami\n";
}

void wypisz_ranking() {
	//wypisanie rankingu na konsoli
	ifstream plik("Ranking.txt", ios::in);
	string linijka;
	if (plik.good())
	{
		while (!plik.eof())
		{
			getline(plik, linijka);
			cout << linijka << endl;
		}
	}
	else
	{
		cout << "Nie udalo sie otwotrzyc pliku z rekordami\n";
	}
}

void PRO(plansza *p, int ile_graczy) {
	//rozpoczecie trybu gry pro
	komputer k;
	p->wypisz();
	cout << "Wykonaj pierwszy ruch.\nhint: pierwszy ruch w trybie PRO zaczyna sie w polu < H - 8 >\n";
	char litera;
	int liczba;

	do {
		litera = podajwiersz();
	} while (litera != 'H');

	do {
		liczba = podajkolumne();
	} while (liczba != 8);

	p->ruch('X', litera, liczba);

	if (ile_graczy == 2)//dwie osoby
	{
		cout << "Pierwszy ruch bialych:\n";
		p->wypisz();

		do {
			litera = podajwiersz();
			liczba = podajkolumne();
		} while (!(p->poloz_kamien(litera, liczba)));
		p->ruch('O', litera, liczba);
		system("cls");
	}
	else
	{ //ruch komputera
		k.ruch(p);
	}
	p->wypisz();
	cout << "Drugi ruch czarnych:\nHINT:Nie mozna polozyc kamienia w obrebie pola 5x5 na srodku planszy\n";


	do {
		litera = podajwiersz();
		do {
			liczba = podajkolumne();
		} while ((liczba >= 6 && liczba <= 10) && (litera >= 'F' && litera <= 'J'));	

	} while (!(p->poloz_kamien(litera, liczba)));
	system("cls");
	p->ruch('X', litera, liczba);
	p->wypisz();
};
void swap2(plansza *p, int ile_graczy)
{
	//rozpoczêcie trybu gry swap2
	komputer k('O');
	char litera;
	int liczba;
	if (ile_graczy == 1)
	{//gra vs komputer
		p->wypisz();
		cout << "W tym trybie podajesz pola na kolejno 1. X, 2. O, 3.X\nNastepnie komputer ustawi O i X. Powodzenia :)\n\n";
		//pierwszy X
		do {
			litera = podajwiersz();
			liczba = podajkolumne();
		} while (!(p->poloz_kamien(litera, liczba)));
		p->ruch('X', litera, liczba);
		system("cls");
		p->wypisz();

		//pierwsze O
		cout << "Poloz O" << endl;
		do {
			litera = podajwiersz();
			liczba = podajkolumne();
		} while (!(p->poloz_kamien(litera, liczba)));
		p->ruch('O', litera, liczba);
		system("cls");
		p->wypisz();

		//drugi X
	
		do {
			litera = podajwiersz();
			liczba = podajkolumne();
		} while (!(p->poloz_kamien(litera, liczba)));
		p->ruch('X', litera, liczba);
		system("cls");

		//komputer kladzie O i X;
		k.ruch(p);
		komputer k('X');
		k.ruch(p);
		p->wypisz();
	}
	else
	{//czlowiek vs czlowiek
		p->wypisz();
		cout << "W tym trybie 1. osoba podaje pola na: 1. X, 2. O, 3.X\n";
		//pierwszy X

		do {
			litera = podajwiersz();
			liczba = podajkolumne();
		} while (!(p->poloz_kamien(litera, liczba)));
		p->ruch('X', litera, liczba);
		p->wypisz();

		//pierwsze O
		cout << "Poloz O" << endl;
		do {
			litera = podajwiersz();
			liczba = podajkolumne();
		} while (!(p->poloz_kamien(litera, liczba)));
		p->ruch('O', litera, liczba);
		p->wypisz();

		//drugi X
		cout << "Poloz X" << endl;
		do {
			litera = podajwiersz();
			liczba = podajkolumne();
		} while (!(p->poloz_kamien(litera, liczba)));
		p->ruch('X', litera, liczba);
		p->wypisz();


		cout << "Teraz 2.osoba ustawia O i X\n";
		//drugie O
		cout << "Poloz O" << endl;
		do {
			litera = podajwiersz();
			liczba = podajkolumne();
		} while (!(p->poloz_kamien(litera, liczba)));
		p->ruch('O', litera, liczba);
		p->wypisz();

		//trzeci X
		cout << "Poloz X" << endl;
		do {
			litera = podajwiersz();
			liczba = podajkolumne();
		} while (!(p->poloz_kamien(litera, liczba)));
		p->ruch('X', litera, liczba);
		p->wypisz();

		cout << "Teraz wg. zasad pierwsza osoba ma prawo wybrac czy chce pozostac przy X czy zmienic swoj symbol na O. Dogadajcie sie :)\n";
	}
}
int main()
{
	srand(unsigned(time));
	plansza *gra = nullptr;
	int wybor = 0;
	int tryb_gry = 2;
	int ile_graczy = 2;
	string nazwa, n_pliku;
	fstream plik;
	czlowiek krzyzyk('X');
	czlowiek kolko('O');
	komputer bot('O');

	switch (wybor = Nowa_czy_tablica())
	{
	case 1:
	
		//nowa gra -> zapytaj o tryb gry -> ilosc graczy
	
		gra = new plansza();
		tryb_gry = wybor_trybu();
		ile_graczy = wybor_graczy();
		
		if (tryb_gry == 2) //wybrany tryb pro
		{
			PRO(gra, ile_graczy);
			gra->wypisz();
		}
		else if (tryb_gry == 3) // wybrany tryb swap2
		{
			swap2(gra, ile_graczy); 
			gra->wypisz();
			
		}
		else //wybrany tryb standard
		{
			//pierwszy jest ruch iksa, aby potem mozna bylo polaczyc wszystkie tyby w jednej petli
			gra->wypisz();
			cout << endl << "Ruch: X" << endl;
			krzyzyk.ruch(gra);
			gra->wypisz();
		}
		break;
	case 2:
		wypisz_ranking();
		return 0;
		break;
	case 3:
		//WYJSCIE
		return 0;
		break;
	}
	//max jest 225 ruchow w standard
	for(int i=0;i<223;++i)
	{
		//zawsze w tym momencie bedzie kolej kolka
		if (ile_graczy == 1) // gdy jeden gracz
		{
			
			if (bot.ruch(gra)) {
				gra->wypisz();
				bot.wygrana();
				delete gra;
				exit(EXIT_SUCCESS);
			}
			gra->wypisz();
			cout <<endl<< "Ruch: X\n";
			if (krzyzyk.ruch(gra))
			{
				gra->wypisz();
				krzyzyk.wygrana();
				nazwa = Pobierz_nick();
				ranking(nazwa);
				delete gra;
				exit(EXIT_SUCCESS);
			}
			gra->wypisz();
		}
		else//gdy jest dwoch graczy
		{
			cout <<endl<< "Ruch: O\n";
			if (kolko.ruch(gra))
			{
				gra->wypisz();
				kolko.wygrana();			
				nazwa = Pobierz_nick();
				ranking(nazwa);
				delete gra;
				exit(EXIT_SUCCESS);
			}
			gra->wypisz();
			cout << "Ruch: X\n";
			if (krzyzyk.ruch(gra))
			{
				gra->wypisz();
				krzyzyk.wygrana();
				nazwa = Pobierz_nick();
				ranking(nazwa);
				delete gra;
				exit(EXIT_SUCCESS);
			}
			gra->wypisz();
		}
		//wtedy plansza pe³na i nikt nie wygra³
		if (tryb_gry == 2 && i == 221) break; //max 222 ruchy w PRO
		if (tryb_gry == 3 && i == 219) break; //max 220 ruchy w swap2
	}
	gra->wypisz();
	delete gra;
	cout <<endl<< "Nikt nie wygra³ :(" << endl;
	return 0;
	
}