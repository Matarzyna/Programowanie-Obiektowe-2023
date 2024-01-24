#pragma once
#include "Plansza.h"


class gracz {
protected:
	char ksztalt; //X albo O
public:
	gracz();
	gracz(char);
	virtual void wygrana() = 0;
	virtual bool ruch(plansza*) = 0;
	virtual void set_kamien(char) = 0;
	int get_kamien() { return ksztalt; }
};

class czlowiek : public gracz {
public:
	czlowiek(char);
	bool ruch(plansza*);
	void set_kamien(char);
	void wygrana();
};

class komputer : public gracz {
public:
	komputer();
	komputer(char);
	
	bool ruch(plansza*);
	void set_kamien(char);
	void wygrana();
};