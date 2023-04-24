#include <cstdio>
#include <iostream>
#define ile 3
using namespace std;

class trapez_rownoramienny {
private:

	double dolnyW[2];

	double gornaP;
	double dolnaP;
	double wysokosc;

public:
	void set_trapez(double W[], double h, double a, double b)
	{
		dolnyW[0] = W[0];
		dolnyW[1] = W[1];

		if (h <= 0)
		{
			printf("Wysokosc nie moze byc wartoscia mniejsza badz rowna 0. Przyjmuje wartosc domyslna ( 5 )\n");
			wysokosc = 5;
		}
		else
		{
			wysokosc = h;
		}

		if (a <= 0)
		{
			printf("Podstawa nie moze byc wartoscia mniejsza badz rowna 0. Przyjmuje wartosc domyslna ( 4 )\n");
			gornaP = 4;
		}
		else
		{
			gornaP = a;
		}

		if (b <= 0)
		{
			printf("Podstawa nie moze byc wartoscia mniejsza badz rowna 0. Przyjmuje wartosc domyslna ( 10 )\n");
			dolnaP = 10;
		}
		else
		{
			dolnaP = b;
		}

	}
	void info_trapez()
	{
		double r = 0.5 * abs(gornaP - dolnaP);


		printf("\nLewy dolny wierzcholek: (%.2lf,%.2lf)\n", dolnyW[0], dolnyW[1]);
		printf("Lewy gorny wierzcholek: (%.2lf,%.2lf)\n", dolnyW[0] + r, dolnyW[1] + wysokosc);
		printf("Prawy gorny wierzcholek: (%.2lf,%.2lf)\n", dolnyW[0] + r + gornaP, dolnyW[1] + wysokosc);
		printf("Prawy dolny wierzcholek: (%.2lf,%.2lf)\n", dolnyW[0] + dolnaP, dolnyW[1]);


		r *= r;
		double h = wysokosc * wysokosc;
		printf("Dlugosc gornej podstawy: %.2lf\n", gornaP);
		printf("Dlugosc dolnej podstawy: %.2lf\n", dolnaP);
		printf("Wysokosc: %.2lf\n", wysokosc);
		printf("Dlugosc ramion: %.2lf\n", sqrt(h + r));
		printf("Pole powierzchni: %.2lf\n", 0.5*(gornaP+dolnaP)*wysokosc);
	}
	void przerzuc_trapez(double n)
	{
		dolnyW[0] += (2 * (n - dolnyW[0]));
		dolnyW[0] -= dolnaP;
	}
	void skaluj(double k)
	{
		if (k <= 0)
		{
			printf("Podano zerowy lub ujemny wspolczynnik skali. Nie robie nic\n");
			return;
		}
		gornaP *= k;
		dolnaP *= k;
		wysokosc *= k;
	}
};

class prostokat {
private:
	double wierzcholek[2];
	double podstawa;
	double bok;
public:
	void pierwsza(double w[2], double a, double b)
	{
		//nadaj wartosci 
		wierzcholek[0] = w[0];
		wierzcholek[1] = w[1];

		if (a > 0)
		{
			podstawa = a;
		}
		else
		{
			printf("Podstawa nie moze miec dlugosci mniejszej lub rownej zero, przyjmuje wartosc domyslna 5 \n");
			podstawa = 5;
		}

		if (b > 0)
		{
			bok = b;
		}
		else
		{
			printf("Bok nie moze miec dlugosci mniejszej lub rownej zero, przyjmuje wartosc domyslna 10 \n");
			bok= 10;
		}
	}
	void druga()
	{
		//wypisz wartosci pol + oblicz pole pow
		printf("\nWspolrzedne lewego dolnego wierzcholka: (%.2lf , %.2lf)\n", wierzcholek[0], wierzcholek[1]);
		printf("Dlugosc podstawy: %.2lf\n", podstawa);
		printf("Dlugosc boku: %.2lf\n", bok);
		printf("Pole powierzchni: %.2lf\n\n", bok*podstawa);

	}
	void trzecia(double n)
	{
		//symetria wzgledem prostej x=n
		wierzcholek[0] += (2 * (n - wierzcholek[0])); //lewy -> prawy wierzch
		wierzcholek[0] -= podstawa; //prawy - podstawa = lewy W
	}
	void czwarta(double k)
	{
		//skaluj o wspolczynnik skali k
		if (k <= 0)
		{
			printf("Podano zerowy lub ujemny wspolczynnik skali. Nie robie nic\n");
			return;
		}

		podstawa *= k;
		bok *= k;
		
	}
	/*void piata(prostokat * drugi)
	{
		podstawa += drugi->podstawa;
		bok += drugi->bok;
	}*/
};




int main()
{
	trapez_rownoramienny trapezy[ile];
	prostokat rekt[ile];
	//uzupelnianie trapezow przykladowe
	double W[2] = { 0, 0 };
	trapezy[0].set_trapez(W, 5, 4, 2);

	W[0] = 2.5; W[1] = 3.5;
	trapezy[1].set_trapez(W, 15, 24, 3);
	
	W[0] = 12.5; W[1] = 13.5;
	trapezy[2].set_trapez(W, 23, 2, 2.5);

	//uzupelnianie prostokatow przykladowe

	W[0] = -2.5; W[1] = -5;
	rekt[0].pierwsza(W, 10, 30);

	W[0] = -4; W[1] = -4.25;
	rekt[1].pierwsza(W, 12, 1);

	W[0] = 5.2; W[1] = 1.2;
	rekt[2].pierwsza(W, 2, 4);

	double gornaP, dolnaP, wysokosc;
	do {
		printf("Jaka figure chcesz zmodyfikowac?:\n\tt - trapez\n\tp - prostokat\n\n");
		if (getchar() == 't')
		{
			printf("Ktory trapez konkretnie? wybierz [ 1 - 3 ]\n"); 
			while (getchar() != '\n');
			int numer;
			scanf_s("%d", &numer);
			numer -= 1;

			while (getchar() != '\n');
			printf("Co chesz zrobic: \n\t1 - nadac wartosci\n\t3 - symetria wzgledem x=n\n");
			char funkcja = getchar();
			switch (funkcja)
			{
			case '1':

				printf("Podaj wspolrzedna x lewego DOLNEGO wierzcholka:");
				scanf_s("%lf", &W[0]);
				printf("Podaj wspolrzedna y lewego DOLNEGO wierzcholka:");
				scanf_s("%lf", &W[1]);
				printf("Podaj dlugosc GORNEJ podstawy  trapezu:");
				scanf_s("%lf", &gornaP);
				printf("Podaj dlugosc DOLNEJ podstawy  trapezu:");
				scanf_s("%lf", &dolnaP);
				printf("Podaj WYSOKOSC  trapezu:");
				scanf_s("%lf", &wysokosc);

				trapezy[numer].set_trapez(W, wysokosc, gornaP, dolnaP);
				trapezy[numer].info_trapez();

				break;

			case '3':
				double n;
				printf("Podaj parametr n:");
				scanf_s("%lf", &n);
				trapezy[numer].przerzuc_trapez(n);
				trapezy[numer].info_trapez();

				break;
			}
		}
		else
		{
			printf("Ktor prostokat konkretnie? wybierz [ 1 - 3 ]\n");
			int numer;
			scanf_s("%d", &numer);
			numer -= 1;
			while (getchar() != '\n');

			printf("Co chesz zrobic: \n\t1 - nadac wartosci\n\t3 - symetria wzgledem x=n\n\t4 - skalowanie wzgledem wspolczynnika k");
			char funkcja = getchar();
			switch (funkcja)
			{
			case '1':
				while (getchar() != '\n');
				printf("Podaj wspolrzedna x lewego DOLNEGO wierzcholka:");
				scanf_s("%lf", &W[0]);
				printf("Podaj wspolrzedna y lewego DOLNEGO wierzcholka:");
				scanf_s("%lf", &W[1]);
				printf("Podaj dlugosc  podstawy:");
				scanf_s("%lf", &gornaP);
				printf("Podaj dlugosc  boku:");
				scanf_s("%lf", &wysokosc);

				rekt[numer].pierwsza(W, gornaP, wysokosc);
				rekt[numer].druga();
				break;
			case '3':
				double n;
				while (getchar() != '\n');
				printf("Podaj parametr n:");
				scanf_s("%lf", &n);
				rekt[numer].trzecia(n);
				rekt[numer].druga();
				break;
			case '4':
				double k;
				while (getchar() != '\n');
				printf("Podaj wspolczynnik k:");
				scanf_s("%lf", &k);
				rekt[numer].czwarta(k);
				rekt[numer].druga();
				break;
			}
		}
		while (getchar() != '\n');
		printf("\nCzy chcesz zakonczyc modyfikowanie?\n Wcisnij 0 aby zakonczyc lub dowolny inny klawisz aby kontynuowac\n");
	} while (getchar() != '0');
	




	return 0;
}