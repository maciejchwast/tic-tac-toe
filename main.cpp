#include <iostream>
using namespace std;

string plansza[3][3];

void powitanie() {
	cout << "Witaj w grze w kolko i krzyzyk. Gre rozpoczyna zawsze kolko." << endl;
}

void setup() {
	for (int b = 0; b < 3; b++) {
		for (int a = 0; a < 3; a++) {
			plansza[b][a] = "--";
		}
	}
}
void PokazPlansze() {
	cout << plansza[0][0] << "|" << plansza[1][0] << "|" << plansza[2][0] << endl;
	cout << "========" << endl;
	cout << plansza[0][1] << "|" << plansza[1][1] << "|" << plansza[2][1] << endl;
	cout << "========" << endl;
	cout << plansza[0][2] << "|" << plansza[1][2] << "|" << plansza[2][2] << endl;
}

void ruch(bool gracz){
	int wiersz, kolumna;
	cout<<"Gracz " << (int)gracz + 1<< ", twoj ruch!" << endl;
	cout << "Podaj gdzie chcesz postawic swoj znak wpisujac najpierw kolumne a potem wiersz" << endl;
	cin >> wiersz;
	cin >> kolumna;
	if (gracz == true && plansza[wiersz-1][kolumna-1] != "X " && plansza[wiersz - 1][kolumna - 1] != "O ") {
		plansza[wiersz-1][kolumna-1] = "X ";
	}
	else if (gracz == false && plansza[wiersz - 1][kolumna - 1] != "X " && plansza[wiersz - 1][kolumna - 1] != "O ") {
		plansza[wiersz-1][kolumna-1] = "O ";
	}
	else if (plansza[wiersz - 1][kolumna - 1] != "X " || plansza[wiersz - 1][kolumna - 1] != "O ") {
		cout << "Niewlasciwe wspolzedne!" << endl;
		ruch(gracz);
	}
}
bool wygrana() {
	for (int i = 0; i < 3; i++) {
		if (plansza[i][0] == plansza[i][1] && plansza[i][1] == plansza[i][2] && plansza[i][0] != "--") {
			if (plansza[i][0] == "X ") {
				cout << "Wygral gracz 2 !!! Gratulacje!";
			}
			else if (plansza[i][0] == "O ") {
				cout << "Wygral gracz 1 !!! Gratulacje!";
			}
			return false;
			break;
		}
		if (plansza[0][i] == plansza[1][i] && plansza[1][i] == plansza[2][i] && plansza[0][i] != "--") {
			if (plansza[0][i] == "X ") {
				cout << "Wygral gracz 2 !!! Gratulacje!";
			}
			else if (plansza[0][i] == "O ") {
				cout << "Wygral gracz 1 !!! Gratulacje!";
			}
			return false;
			break;
			}
	}
	if (plansza[0][0] == plansza[1][1] && plansza[1][1] == plansza[2][2] && plansza[0][0] != "--") {
		if (plansza[1][1] == "X ") {
			cout << "Wygral gracz 2 !!! Gratulacje!";
		}
		else if (plansza[1][1] == "O ") {
			cout << "Wygral gracz 1 !!! Gratulacje!";
		}
		return false;
	}
	else if (plansza[0][2] == plansza[1][1] && plansza[1][1] == plansza[2][0] && plansza[0][2] != "--") {
		if (plansza[1][1] == "X ") {
			cout << "Wygral gracz 2 !!! Gratulacje!";
		}
		else if (plansza[1][1] == "O ") {
			cout << "Wygral gracz 1 !!! Gratulacje!";
		}
		return false;
	}
	else
		return true;

}

int main()
{
	setup();
	bool gracz = 0;
	do {
		ruch(gracz);
		PokazPlansze();
		gracz = !gracz;
	} while (wygrana() == true);
	system("pause");
}
