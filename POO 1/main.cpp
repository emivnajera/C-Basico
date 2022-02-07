#include<iostream>
#include<string>
 
 using namespace std;

class Persona {
public:
    string nombre = "Emiliano";
    int edad = 21;

    void saludar(){
        cout<<"Hola Mundo"<<endl;
    }
};

 int main (){
     Persona p = Persona();
     cout << p.nombre << endl;
    p.saludar();
 }