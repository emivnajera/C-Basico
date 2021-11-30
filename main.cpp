//Area de Librerias
#include <iostream>  //Libreria Usada para Ingresar o mostrar datos en la terminal de comandos

using namespace std;

int main() { // Declaracion de la funcion main
//Todo el codigo del programa va dentro del main

//Declaracion de Variables
int age =  0; //Tipo de dato entero
const char letter = 'a' ;//Constante de tipo Caracter

cout << "Hola Mundo"<<"\n"; //\n es un salto de linea

cout << age<<"\n"; //Se imprime el valor de edad

age = 18; //se actualizo el valor de la edad

int age_list[] = {18, 19,20,21,24};//Declarando una lista de enteros


cout << age_list[0] << endl; // Se imprime el primer elemento de la lista
cout << age_list[1] << endl;// Se imprime el segundo elemento de la lista


age_list[1] = 25;//Se modifica el valor del indice 1 del array

cout << age_list[1] << endl;
cout << age<<endl;//Se imprime el valor de edad de nuevo
cout << letter<<endl; //Se imprima la letra
}