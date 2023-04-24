#include <cstdio>
#include <cmath>
//TO TEN NOWY PLIK TEGO UPLOADUJ
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


		printf("Lewy dolny wierzcholek: (%.2lf,%.2lf)\n", dolnyW[0], dolnyW[1]);
		printf("Lewy gorny wierzcholek: (%.2lf,%.2lf)\n", dolnyW[0] + r , dolnyW[1] + wysokosc);
		printf("Prawy gorny wierzcholek: (%.2lf,%.2lf)\n", dolnyW[0] +r +gornaP, dolnyW[1]+wysokosc);
		printf("Prawy dolny wierzcholek: (%.2lf,%.2lf)\n", dolnyW[0] + dolnaP, dolnyW[1]);


		r *= r;
		double h = wysokosc * wysokosc;
		printf("Dlugosc gornej podstawy: %.2lf\n", gornaP);
		printf("Dlugosc dolnej podstawy: %.2lf\n", dolnaP);
		printf("Wysokosc: %.2lf\n", wysokosc);
		printf("Dlugosc ramion: %.2lf\n", sqrt(h+r));
	}
	void przerzuc_trapez(double n)
	{
		dolnyW[0] += (2 * (n - dolnyW[0]));
		dolnyW[0] -= dolnaP;
	}
};

int main()
{
	double dolnyW[2];

	double gornaP;
	double dolnaP;
	double wysokosc;

	printf("Podaj wspolrzedna x lewego DOLNEGO wierzcholka:");
	scanf_s("%lf", &dolnyW[0]);
	printf("Podaj wspolrzedna y lewego DOLNEGO wierzcholka:");
	scanf_s("%lf", &dolnyW[1]);


	printf("Podaj dlugosc GORNEJ podstawy  trapezu:");
	scanf_s("%lf", &gornaP);
	printf("Podaj dlugosc DOLNEJ podstawy  trapezu:");
	scanf_s("%lf", &dolnaP);
	printf("Podaj WYSOKOSC  trapezu:");
	scanf_s("%lf", &wysokosc);

	putchar('\n');

	trapez_rownoramienny trapez;
	trapez.set_trapez(dolnyW, wysokosc, gornaP, dolnaP);
	trapez.info_trapez();
	putchar('\n');
	double n;
	printf("\nPodaj parametr n :");
	scanf_s("%lf", &n);

	putchar('\n');
	printf("\nTrapez po symetrii wzgledem osi x = %.2lf: \n", n);
	trapez.przerzuc_trapez(n);
	trapez.info_trapez();
	putchar('\n');
	printf("\nTrapez po ponownej symetrii wzgledem osi x = %.2lf: \n",n);
	trapez.przerzuc_trapez(n);
	trapez.info_trapez();

	return 0;
}