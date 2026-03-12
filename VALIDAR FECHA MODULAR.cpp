#include <iostream>
using namespace std;
bool EsBisiesto(int anio);
int ObtenerDiasDelMes(int mes, int anio);
bool EsFechaValida(int dia, int mes, int anio);
void EjecutarSimulacion(int cantidadRondas);

int main(int argc, char *argv[]) {
	int cantidadRondas;
	cout << "SIMULADOR DE SALTOS TEMPORALES" << endl;
	cout << "Ingresa la cantidad de saltos: ";
	cin >> cantidadRondas;
	cout << endl;
	EjecutarSimulacion(cantidadRondas);
	return 0;
}

bool EsBisiesto(int anio) {
	if ((anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0)) {
		return true;
	} else {
		return false;
	}
}

int ObtenerDiasDelMes(int mes, int anio) {
	if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12) {
		return 31;
	} else if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
		return 30;
	} else if (mes == 2) {
		if (EsBisiesto(anio) == true) {
			return 29;
		} else {
			return 28;
		}
	} else {
		return 0;
	}
}

bool EsFechaValida(int dia, int mes, int anio) {
	if (mes < 1 || mes > 12) {
		cout << "Mes invalido (debe ser 1-12)" << endl;
		return false;
	}
	
	int diasDelMes = ObtenerDiasDelMes(mes, anio);
	
	if (dia >= 1 && dia <= diasDelMes) {
		return true;
	} else {
		cout << "Dia invalido para el mes " << mes << " (maximo " << diasDelMes << " dias)" << endl;
		return false;
	}
}

void EjecutarSimulacion(int cantidadRondas) {
	int exitos = 0;
	int dia, mes, anio;
	cout << "Por cada salto ingresa: dia mes año" << endl;
	for (int i = 1; i <= cantidadRondas; i++) {
		cout << "\nSalto #" << i << "Fecha destino: ";
		cin >> dia >> mes >> anio;
		
		if (EsFechaValida(dia, mes, anio) == true) {
			cout << ">> RESULTADO: Salto temporal completado" << endl;
			exitos++;
		} else {
			cout << ">> RESULTADO: Falla catastrofica: Fecha inexistente" << endl;
		}
	}
	cout << "RESUMEN FINAL" << endl;
	cout << "Saltos exitosos: " << exitos << " / " << cantidadRondas << endl;
	
	if (exitos == cantidadRondas) {
		cout << "¡Todos los saltos fueron exitosos!" << endl;
	} else if (exitos == 0) {
		cout << "Ningun salto fue exitoso. Revisa la maquina." << endl;
	} else {
		cout << "Algunos saltos fallaron. Calibrando sistema..." << endl;
	}
}
