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
				totalCubo = pow((i+1),3.0); 
				if (j!=i)
				  sumaNumeros += std::to_string(contador) + "+";
				else
				  sumaNumeros += std::to_string(contador) + "=" + std::to_string(totalCubo);									contador+=2;

			}
			cout<<sumaNumeros<<endl;
		}

	}
}//fin metodo ejercicio 1. 

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
	
	//el cuadrado de la hipotenusa es igual a la suma del cuadrado de los catetos SI ES UN TRIANGULO RECTO.
	hipotenusaCalculado = pow(hipotenusa,2);
	cateto1Calculado = pow(cateto1,2);
	cateto2Calculado = pow (cateto2, 2);
	sumaCatetos = cateto1Calculado + cateto2Calculado;

	if (sumaCatetos == hipotenusaCalculado)
		cout<<"Es un triangulo rectangulo."<<endl;
	else
		cout<<"No es un triangulo rectangulo."<<endl;
	
	//la formula de los cosenos 
	//calcular angulo 1, osea del lado 1
	angulo1 = asin(((cateto1Calculado*-1) + cateto2Calculado + hipotenusaCalculado)/(2*cateto2*hipotenusa));
	angulo2 = acos(((cateto2Calculado*-1) + cateto1Calculado + hipotenusaCalculado)/(2*cateto1*hipotenusa));
	angulo1 = (angulo1*180.0)/pi;
	angulo2 = (angulo2*180.0)/pi;
	angulo3 = 180-angulo1-angulo2;
	//	angulo3 = (angulo3*180.0)/pi;
	

	s = (cateto1+cateto2+hipotenusa)/2;
	area = sqrt (s*(s-cateto1)*(s-cateto2)*(s-hipotenusa));

	cout<<"El angulo 1 del lado 1 es: "<<angulo1<<endl;
	cout<<"El angulo 2 del lado 2 es: "<<angulo2<<endl;
	cout<<"El angulo 3 de la hipotenusa es: "<<angulo3<<endl;
	cout<<"El area del triangulo es: "<<area<<endl;
}//fin metodo 2


int main (){
	int opcion = 0;
	while (opcion != 4){
		switch (opcion = menu()){
			case 1:
				//funcion que llama primer ejercicio
				ejercicio1();
			break;

			case 2:
				//funcion que llama segundo ejercico
				ejercicio2();
			break;

			case 3:
				//funcion que llama tercer ejercicio
			break;

		}//end switch

	 }//end while opcion menu

	return 0;

};//fin main
