#include<iostream>
#include<string>
 
 using namespace std;


 int main (){
    union numero_letra {
         int numero;
         char letra;
    };
    numero_letra x = {'A'};
    cout<<"X como un numero: "<<x.numero<<endl;
    cout<<"X como un letra: "<<x.letra<<endl;

    enum dias_semana {lunes, martes, miercoles};

    dias_semana dia = martes;
    cout << dia;
 }