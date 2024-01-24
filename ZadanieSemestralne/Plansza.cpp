#include "Plansza.h"
class plansza;

plansza::plansza() {
	for (int i = 0; i < 15; ++i)
		for (int j = 0; j < 15; ++j)
		{
			tablica[i][j] = '+';
		}

};


void plansza::wypisz() {
	//wypisanie planszy
	system("cls");
	char litera = 'A';
	cout << " KM ";
	for (int i = 0; i < 15; ++i)
	{
		if (i < 10)
			cout << "| ";
		else cout << "|";
		cout << right << (i + 1);

	}
	cout.width(20);

	cout << endl;
	for (int i = 0; i < 15; ++i)
	{
		cout.width(3);
		cout << right << (char)(litera + i);
		cout << '|';
		for (int j = 0; j < 15; ++j)
		{
			cout.width(3);
			cout << internal << tablica[i][j];
		}
		cout << endl;
	}
};

bool plansza::poloz_kamien(char wiersz, int kolumna) {
	//sprawdzenie czy w danym miejscu nie ma ju¿ po³o¿onego kamienia
	int w = wiersz - 'A';
	if (tablica[w][kolumna-1] != '+')
	{
		cout << "To nie jest poprawne miejsce! Sprobuj ponownie\n";
		return 0;
	}
	else
		return 1;
	

}
bool plansza::czy_wygrana(char wiersz, int kolumna, char kolor)
{
	//sprawdzenie czy sa spelnione warunki na wygrana
	//wiersz - litera 
	// kolumna - nr 
	//kolor - kszta³t X albo O

	int ile_w_rzedzie = 0;
	int nr_kolumny = kolumna - 1;
	int nr_wiersza = wiersz - 'A';
	//check wiersz: [-]
	for (int i = 0; i < 15; ++i)
	{
		if (tablica[nr_wiersza][i] == kolor)
		{
			ile_w_rzedzie += 1;

			if (ile_w_rzedzie == 5 && i == 14) 
				return 1;

			if (ile_w_rzedzie == 5 && tablica[nr_wiersza][i + 1] != kolor)
				return 1;
		}
		else
			ile_w_rzedzie = 0;
	}
	//sprawdzanie kolumny [|]
	for (int i = 0; i < 14; ++i)
	{
		if (tablica[i][nr_kolumny] == kolor)
		{
			ile_w_rzedzie += 1;

			if (ile_w_rzedzie == 5 && i == 14)
				return 1;

			if (ile_w_rzedzie == 5 && tablica[i+1][nr_kolumny] != kolor) //jesli 5 w linii to zwyciestwo
				return 1;
		}
		else
			ile_w_rzedzie = 0;
	}
	//sprawdzenie przekatnej [\]
	ile_w_rzedzie = 0;
	for (int i = nr_wiersza-5, j = nr_kolumny -5; i < 15 && j < 15; ++i, ++j)
	{
		if (i < 0 || j < 0)
			continue;

		if (tablica[i][j] == kolor)
		{
			ile_w_rzedzie += 1;

			if (ile_w_rzedzie == 5 && (i == 14 || j == 14))
				return 1;

			if (ile_w_rzedzie == 5 && tablica[i + 1][j + 1] != kolor) //jesli 5 w linii to zwyciestwo
				return 1;
		}
		else
			ile_w_rzedzie = 0;
	}
	ile_w_rzedzie = 0;
	//sprawdzanie przekatnej [/]
	for (int i = nr_wiersza - 5, j = nr_kolumny + 5; i < 15 && j>=0; ++i, --j)
	{
		if (i < 0 || j >14)
			continue;

		if (tablica[i][j] == kolor)
		{
			ile_w_rzedzie += 1;

			if (ile_w_rzedzie == 5 && (i == 14 || j==0))
				return 1;

			if (ile_w_rzedzie == 5 && tablica[i + 1][j-1] != kolor) //jesli 5 w linii to zwyciestwo
				return 1;
		}
		else
			ile_w_rzedzie = 0;
	}

	return 0;
			
		
};
void plansza::ruch(char nr_kamienia, char wiersz, int kolumna) {
	//ustawienie kamienia na planszy
	//nr_kamienia to symbol - X albo O
	int w = (int)(wiersz - 'A');
	
	tablica[w][kolumna - 1] = nr_kamienia;
}
