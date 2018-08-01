#include <iostream>
#include <string>
#include <math.h>
#define pi 3.1415926535897


using std::cout;
using std::endl;
using std:: cin;
using std::string;

int menu (){
   int opcion = 0;
   while (true){
  	cout<<"	MENU" << endl
	<< "1. Calculo de Cubos" << endl
	<< "2. Triangulo Recto" << endl
	<< "3. Serie" << endl
	<< "4. Salir" << endl
	<< "Ingrese una opcion: "<<endl;
	cin >> opcion;

	if (opcion < 1 || opcion > 4)
	   cout<<"Opcion incorrecta, intente de nuevo."<<endl;
	else 
	   return opcion;
   }
}

//METODO DEL PRIMER EJERCICIO.
//el primer for recorre los cubos de los numeros anteriores a n
//el segundo for simplemente va guardando en strings todos los numeros siguientes impares que se suman 
//.. para llegar al proximo cubo. 
void ejercicio1(){
	int n;
	cout<<"Ingrese cantidad de cubos a calcular: "<<endl;
	cin >> n;

	int contador = 3;
	double totalCubo = 0;
	string sumaNumeros = "";
	for (int i = 0; i < n; i++){
		sumaNumeros = std::to_string((i+1)) + "^3=";
		if (i==0)
			cout<<"1^3=1=1"<<endl;
		else {
			for (int j=0; j<i+1;j++){
				totalCubo = (int) pow((i+1),3.0); 
				int totalCubo2;
			        totalCubo2 = totalCubo; //sin decimales
				if (j!=i)
				  sumaNumeros += std::to_string(contador) + "+";
				else
				  sumaNumeros += std::to_string(contador) + "=" + std::to_string(totalCubo2);									contador+=2;
			}
			cout<<sumaNumeros<<endl;
		}
	}
}

//METODO DEL SEGUNDO EJERCICIO
void ejercicio2(){
	double cateto1, cateto2, hipotenusa, sumaCatetos=0,s = 0, area = 0;
        double	hipotenusaCalculado=0, cateto1Calculado=0, cateto2Calculado=0, angulo1=0,angulo2=0, angulo3=0;
	cout << "Ingrese dimension del primer cateto del triangulo: "<<endl;
	cin >> cateto1;
	cout<<"Ingrese dimension del segundo cateto del triangulo: "<<endl;
	cin >> cateto2;
	cout<< "Ingrese la dimension de la hipotenusa del triangulo: "<<endl;
	cin >> hipotenusa;
	
	//si el cuadrado de la hipotenusa es igual a la suma del cuadrado de los catetos, ES UN TRIANGULO RECTO.
	hipotenusaCalculado = pow(hipotenusa,2);
	cateto1Calculado = pow(cateto1,2);
	cateto2Calculado = pow (cateto2, 2);
	sumaCatetos = cateto1Calculado + cateto2Calculado;

	if (sumaCatetos == hipotenusaCalculado)
		cout<<"Es un triangulo rectangulo."<<endl;
	else
		cout<<"No es un triangulo rectangulo."<<endl;
	
	//la formula de los cosenos 
	//se calcula el angulo en radianes y luego se pasa a grados
	//todos los angulos de un triangulo suman 180 por eso el angulo 3 tiene esa formula.
	angulo1 = asin(((cateto1Calculado*-1) + cateto2Calculado + hipotenusaCalculado)/(2*cateto2*hipotenusa));
	angulo2 = acos(((cateto2Calculado*-1) + cateto1Calculado + hipotenusaCalculado)/(2*cateto1*hipotenusa));
	angulo1 = (angulo1*180.0)/pi;
	angulo2 = (angulo2*180.0)/pi;
	angulo3 = 180-angulo1-angulo2;
	

	s = (cateto1+cateto2+hipotenusa)/2;
	area = sqrt (s*(s-cateto1)*(s-cateto2)*(s-hipotenusa));

	cout<<"El angulo 1 del lado 1 es: "<<angulo1<<endl;
	cout<<"El angulo 2 del lado 2 es: "<<angulo2<<endl;
	cout<<"El angulo 3 de la hipotenusa es: "<<angulo3<<endl;
	cout<<"El area del triangulo es: "<<area<<endl;
}//fin metodo 2


void ejercicio3(){
	int n, contadorDivisores=0, contadorEspacio=0, sumaPrimos = 0;
	cout<<"Ingrese numero para calcular la suma de los divisores primos: "<<endl;
	cin >> n;
	
	//este for lo unico que hace es sacar la cuenta de cuantos divisores tiene el numero ingresado por el usuario.
	for(int i = 1; i <= n; i++){
		if (n%i ==0)
			contadorDivisores++;		
	}
	
	int arregloDivisores [contadorDivisores];

	//este for va ir guardando los divisores en el arreglo anteriormente declarado.
	for (int i = 1; i <= n; i++){
		if (n%i == 0){
			//que lo meta en el arreglo segun la posicion que le corresponde.
			arregloDivisores[contadorEspacio] = i;
			contadorEspacio++;
		}
	}

	for (int i = 0; i < contadorDivisores; i++){
		int temporal = arregloDivisores[i];
		int suma = 0, contador=0;
		suma = (n+temporal)/temporal;

		for(int i = 1; i < suma+1; i++){
			if (suma%i == 0){
				contador++;
			}
		}
		
		if (contador==2)
			sumaPrimos += suma;
	}
	cout<<"La suma de los primos segun la formula es: "<<sumaPrimos<<endl;
}	


int main (){
	int opcion = 0;
	while (opcion != 4){
		switch (opcion = menu()){
			case 1:
				ejercicio1();
			break;

			case 2:
				ejercicio2();
			break;

			case 3:
				ejercicio3();
			break;

		}
	 }
	return 0;
};
