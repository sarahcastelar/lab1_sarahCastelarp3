#include <iostream>
#include <string>
#include <math.h>


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
			break;

			case 3:
				//funcion que llama tercer ejercicio
			break;

		}//end switch

	 }//end while opcion menu

	return 0;

};//fin main
