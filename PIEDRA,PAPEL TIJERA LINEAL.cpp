#include <iostream>
using namespace std;

int main()
{
	int jugador1, jugador2;
	int resultado;
	string jugada1, jugada2;
	cout << "Piedra, Papel o Tijera" << endl;
	cout << "Jugador 1 (1=Piedra, 2=Papel, 3=Tijera): ";
	cin >> jugador1;
	cout << "Jugador 2 (1=Piedra, 2=Papel, 3=Tijera): ";
	cin >> jugador2;
	cout<<endl;
	
	switch(jugador1)
	{
	case 1: jugada1 = "()"; break;
	case 2: jugada1 = "[]"; break;
	case 3: jugada1 = "8<"; break;
	default: jugada1 = "invalido";
	}
	
	switch(jugador2)
	{
	case 1: jugada2 = "()"; break;
	case 2: jugada2 = "[]"; break;
	case 3: jugada2 = "8<"; break;
	default: jugada2 = "invalido";
	}
	cout << jugada1 << " vs " << jugada2 << endl;
	
	if (jugador1 == jugador2)
		resultado = 0;
	else if ((jugador1 == 1 && jugador2 == 3) ||
		(jugador1 == 2 && jugador2 == 1) ||
		(jugador1 == 3 && jugador2 == 2))
		resultado = 1;
	else
		resultado = 2;
	
	if (resultado == 0)
		cout << "Empate" << endl;
	else if (resultado == 1)
		cout << "Gana el Jugador 1" << endl;
	else
		cout << "Gana el Jugador 2" << endl;
	
	return 0;
}
