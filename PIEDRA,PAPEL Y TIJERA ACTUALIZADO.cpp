// PIEDRA, PAPEL Y TIJERA
#include<iostream>
#include<cmath>
using namespace std;
short evaluar(short op1, short op2);
string traducir(short op);
void imprimir(short op1, short op2);
void detGanador(short resultado, short op1, short op2);

int main() 
{
	int opcion1, opcion2;
	int resultado;
	cout << "PIEDRA, PAPEL O TIJERA" << endl;
	cout << "Opciones:" << endl;
	cout << "1 -> Piedra ()" << endl;
	cout << "2 -> Papel []" << endl;
	cout << "3 -> Tijera 8<" << endl;
	
	do {
		cout << "Jugador 1 - Elige una opcion (1-3): ";
		cin >> opcion1;
	} while (opcion1 < 1 || opcion1 > 3);
	
	do {
		cout << "Jugador 2 - Elige una opcion (1-3): ";
		cin >> opcion2;
	} while (opcion2 < 1 || opcion2 > 3);
	resultado = evaluar(opcion1, opcion2);
	imprimir(opcion1, opcion2);
	detGanador(resultado, opcion1, opcion2);
	return 0;
}
short evaluar(short op1, short op2)
{
	short resp;
	if (op1 == op2)
		resp = 0;
	else if ((op1 == 1 && op2 == 3) ||
		(op1 == 2 && op2 == 1) || 
		(op1 == 3 && op2 == 2))   
		resp = 1;
	else
		resp = -1;
	return resp;
}
string traducir(short op)
{
	cout<<endl;
	switch(op)
	{
	case 1: return "()";  
	case 2: return "[]"; 
	case 3: return "8<";
	default: return "INCORRECTO";
	}
}

void imprimir(short op1, short op2)
{
	string jugada1, jugada2;
	jugada1 = traducir(op1);
	jugada2 = traducir(op2);	
	cout<< jugada1 << " vs " << jugada2 <<endl;
}
void detGanador(short resultado, short op1, short op2)
{
	cout << "\nRESULTADO: ";
	if (resultado == 0)
	{
		cout<<"EMPATE ambos jugadores eligieron "<< traducir(op1)<<endl;
	}
	else if (resultado == 1)
	{
		cout << "GANA JUGADOR 1"<<endl;;
		if (op1 == 1) cout << "Piedra () rompe a la Tijera 8<";
		else if (op1 == 2) cout << "Papel [] envuelve a la Piedra ()";
		else cout << "Tijera 8< corta el Papel []";
	}
	else 
	{
		cout << "GANA JUGADOR 2"<<endl;
		if (op2 == 1) cout << "Piedra () rompe a la Tijera 8<";
		else if (op2 == 2) cout << "Papel [] envuelve a la Piedra ()";
		else cout << "Tijera 8< corta el Papel []";
	}
}
