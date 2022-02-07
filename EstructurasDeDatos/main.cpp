#include<iostream>
#include<string>
 
 using namespace std;

 struct Persona{
    string nombre;
    int edad;
 };

 int main (){
    //Con Objetos
    Persona p = Persona();
    p.nombre = "Emiliano";
    p.edad = 21;
    cout<<p.nombre<<endl;
    cout<<p.edad;

    //Con Punteros
   Persona *pp = new Persona();
    pp->nombre = "Emiliano";
    pp->edad = 21;
    cout<<pp->nombre<<endl;
    cout<<pp->edad;
 }