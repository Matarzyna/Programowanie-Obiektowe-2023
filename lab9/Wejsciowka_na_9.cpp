#include <cstdio>
#include <cmath>

using namespace std;

class trapez_rownoramienny {
private:
	double gornyW[2];
	double dolnyW[2];

	double gornaP;
	double dolnaP;

public:
	void set_trapez(double A[], double B[], double gP)
	{
		gornyW[0] = A[0];
		gornyW[1] = A[1];

		dolnyW[0] = B[0];
		dolnyW[1] = B[1];

		gornaP = gP;
	


		//Gdy odcinki sa < lub = 0
		if (gP < 0)
		{
			printf("Nie da sie zbudowac trapezu z odcinka dlugosci <0, przyjmuje wartosc domyslna.");
			gornaP = abs(gP);
		}
		else if (gP == 0)
		{
			printf("Nie da sie zbudowac trapezu z odcinka dlugosci 0, przyjmuje wartosc domyslna.");
			gornaP = 10;
		}
		


		if (A[0] == B[0] && A[1] == B[1]) //wierzcholki sie pokrywaja
		{
			printf("Z podanych wierzcholkow nie da sie zbudowac trapezu rownoramiennego. Przyjmuje domyslne wspolrzedne lewego gornego wierzcholka: (%.2lf,%.2lf)\n",
				A[0] + 2, A[1] + 2);
			gornyW[0] = A[0];
			gornyW[1] = A[1];

			dolnyW[0] = B[0]+2;
			dolnyW[1] = B[1]+2;

			gornaP = gP;
		
		}
		else if (A[0] == B[0] || A[1]==B[1]) // k¹t prosty -> musi byc prostokat czyli obie podstawy musza byc rowne
		{
			gornyW[0] = A[0];
			gornyW[1] = A[1];

			dolnyW[0] = B[0];
			dolnyW[1] = B[1];

			gornaP = dolnaP = gP;
			
		}	


		double roznica = abs(gornyW[0] - dolnyW[0]);
		if (gornyW[0] >= dolnyW[0])
		{
			dolnaP = gornaP + 2 * (roznica);
		}
		else
		{
			dolnaP = gornaP - 2 * (roznica);
		}
		
	}
	void info_trapez()
	{
		printf("Lewy dolny wierzcholek: (%.2lf,%.2lf)\n", dolnyW[0], dolnyW[1]);
		printf("Lewy gorny wierzcholek: (%.2lf,%.2lf)\n", gornyW[0], gornyW[1]);
		printf("Prawy gorny wierzcholek: (%.2lf,%.2lf)\n", gornyW[0] + gornaP, gornyW[1] );
		printf("Prawy dolny wierzcholek: (%.2lf,%.2lf)\n", dolnyW[0] + dolnaP, dolnyW[1] );

		double wysokosc = gornyW[0] - dolnyW[0];
		wysokosc *= wysokosc;
		double  c = 0.5 * abs(gornaP - dolnaP);
		c *= c;
		printf("Dlugosc gornej podstawy: %.2lf\n", gornaP);
		printf("Dlugosc dolnej podstawy: %.2lf\n", dolnaP);
		printf("Dlugosc ramion: %.2lf\n", sqrt(c+wysokosc));
	}
	void przerzuc_trapez(double n)
	{
		gornyW[0] += (2 * (n - gornyW[0]));
		gornyW[0] -= gornaP;
		dolnyW[0] += (2 * (n - dolnyW[0]));
		dolnyW[0] -= dolnaP;
	}
};

int main()
{
	double gornyW[2];
	double dolnyW[2];

	double gornaP;
	double dolnaP;
	printf("Podaj wspolrzedna x lewego DOLNEGO wierzcholka:");
	scanf_s("%lf", &dolnyW[0]);
	printf("Podaj wspolrzedna y lewego DOLNEGO wierzcholka:");
	scanf_s("%lf", &dolnyW[1]);


	printf("Podaj wspolrzedna x lewego GORNEGO wierzcholka:");
	scanf_s("%lf", &gornyW[0]);
	printf("Podaj wspolrzedna y lewego GORNEGO wierzcholka:");
	scanf_s("%lf", &gornyW[1]);

	printf("Podaj dlugosc gornej podstawy  trapezu:");
	scanf_s("%lf", &gornaP);

	

	putchar('\n');
	trapez_rownoramienny trapez;
	trapez.set_trapez(gornyW, dolnyW, gornaP);
	trapez.info_trapez();
	putchar('\n');
	double n;
	printf("\nPodaj parametr n do przerzucenia trapezu wzgledem osi x=n: ");
	scanf_s("%lf", &n);

	putchar('\n');
	trapez.przerzuc_trapez(n);
	trapez.info_trapez();
	putchar('\n');
	trapez.przerzuc_trapez(n);
	trapez.info_trapez();

	return 0;
}