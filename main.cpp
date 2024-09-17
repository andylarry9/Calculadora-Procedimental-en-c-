#include <iostream>
using namespace std;

/* 
Implementar una calculadora que permita sumar, restar, multiplicar y dividir 
dos números cualesquieras ingresados por teclado y muestre el resultado 
de la operación aritmética correspondiente.
 */
//Declaran los metodos de subtareas funciones y/o procedimientos
//<tipo de datos devuelve> <nombre del metodo> ([parametro1, parametro2, parametroN]);
int cargarMenu();
void operacionSumar(double pNum1, double pNum2);
double operacionRestar(double pNum1, double pNum2);
double operacionMultiplicar(double pNum1, double pNum2);
bool operacionDivision(double pNum1, double pNum2, double &pCociente);
bool adicionarNumeroArray(double pArrayNumeros[], int pDimension, int &pContadorNum, double pNum);
double operacionSumarListaNumeros(double pArrayNumeros[], int pContadorNum);

int main(int argc, char** argv) 
{
	//Esquema General de Ejecucion de Algoritmo
	//1. Declaracion de las variables
		int dimension = 100;
		//datos de entrada
		double num1, num2;
		double arrayNumeros[dimension];
		int contadorNum = 0;
		int cantNumerosASumar = 0;
		//datos de salida
		double suma, resta, multiplicacion, division;
		//datos auxiliares
		int opcion;	
		bool siDivision;
		bool siListaNoLLena = true;
	
	do{
		//subtarea cargar el menu de opciones y devolver la opcion digitada por usuario
		opcion = cargarMenu();
		//2. Entrada de los datos
		if (opcion != 5)
		{
			cout << "Digite el primer numero: ";
			cin >> num1;
			cout << "Digite el segundo numero: ";
			cin >> num2;
		}
		switch(opcion)
		{
			case 1://la suma
				operacionSumar(num1, num2);
				break;
			case 2: //la resta
				resta = operacionRestar(num1, num2);
				//4. Mostrar los resultados
				cout << num1 << " - " << num2 << " = " << resta << endl;
				break;
			case 3: //la multiplicacion
				multiplicacion = operacionMultiplicar(num1, num2);
				//4. Mostrar los resultados
				cout << num1 << " * " << num2 << " = " << multiplicacion << endl;
				break;
			case 4: //la division
				siDivision = operacionDivision(num1, num2, division);			
				if (siDivision) {
					//4. Mostrar los resultados
					cout << num1 << " / " << num2 << " = " << division << endl;
				}
				else{
					cout << "La division por cero no esta permitida. \n";					
				}
				break;
			case 5:
				contadorNum = 0;
				siListaNoLLena = true;
				cout << "Digite cuantos numeros desea sumar: ";
				cin >> cantNumerosASumar;
				for (int i = 0; i < cantNumerosASumar && siListaNoLLena; i++)
				{
					cout << "Digite el numero a sumar: ";
					cin >> num1;
					siListaNoLLena = adicionarNumeroArray(arrayNumeros, dimension, contadorNum, num1);					
				}
				suma = operacionSumarListaNumeros(arrayNumeros, contadorNum);
				cout << "La suma total de los numeros ingresados es: " << suma << endl;				
			case 6:
				return 0;
		}
		
		system("pause");
	}while(true);	
	return 0;
}

//Implementan los metodos de subtareas funciones y/o procedimientos
//<tipo de datos devuelve> <nombre del metodo> ([parametro1, parametro2, parametroN])
//{inicio
	//bloque de codigo a ejecutar una vez sea invocado el metodo.
//}fin

int cargarMenu()
{
	int opcion;
	do{
		system("cls");
		cout << "------ Menu Calculadora Estandar ------- \n";
		cout << "\t 1. Calcular la suma. \n";
		cout << "\t 2. Calcular la resta. \n";
		cout << "\t 3. Calcular la multiplicacion. \n";
		cout << "\t 4. Calcular la division. \n";
		cout << "\t 5. Sumar lista de numeros. \n";
		cout << "\t 6. Cerrar calculadora. \n";
		cout << "Digite la opcion 1-6 deseada: ";
		cin >> opcion;	//entrada del dato		
	}while(opcion < 1 || opcion > 6);
	
	return opcion;//ultima instruccion de cualquier metodo funcion.
}

void operacionSumar(double pNum1, double pNum2)
{
	double suma;
	//3. Procesamiento de los datos
	suma = pNum1 + pNum2;
	//4. Mostrar los resultados
	cout << pNum1 << " + " << pNum2 << " = " << suma << endl;	
}

double operacionRestar(double pNum1, double pNum2)
{
	double resta;
	//3. Procesamiento de los datos
	resta = pNum1 - pNum2;
	
	return resta;
}

double operacionMultiplicar(double pNum1, double pNum2)
{
	double multiplicacion;
	//3. Procesamiento de los datos
	multiplicacion = pNum1 * pNum2;
	
	return multiplicacion;
}

bool operacionDivision(double pNum1, double pNum2, double &pCociente)
{
	if (pNum2 != 0) {					
		pCociente = pNum1 / pNum2;
		return true;
	}
	
	return false;	
}

bool adicionarNumeroArray(double pArrayNumeros[], int pDimension, int &pContadorNum, double pNum)
{
	if (pContadorNum < pDimension)
	{
		pArrayNumeros[pContadorNum] = pNum;
		pContadorNum++;
		return true;
	}
	
	return false;	
}

double operacionSumarListaNumeros(double pArrayNumeros[], int pContadorNum)
{
	double sumatoria = 0;
	for(int i = 0; i < pContadorNum; i++)
	{
		double numero = pArrayNumeros[i];
		sumatoria += numero;
	}
	return sumatoria;
}