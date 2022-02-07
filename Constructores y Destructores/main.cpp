#include<iostream>
#include<string>
 
 using namespace std;

class Persona {
private:
    string nombre;
    int edad;
public:
    Persona(string nombre, int edad);
    void saludar(){
        cout<<nombre<<endl;
    }
    static int numero_personas;
};

int Persona::numero_personas = 0;
Persona::Persona(string nombre, int edad){
        this->nombre = nombre;
        this->edad = edad;
        numero_personas++;
    }


 int main (){
     Persona p1 = Persona("Emiliano",21);
     Persona p2 = Persona("Jose",22);

     p1.saludar();
     p2.saludar();
     cout<<Persona::numero_personas<<endl;
 }