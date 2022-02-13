#include <iostream>
#include <string>

using namespace std;

class Animal{
protected: 
    string alimento;
    static int numero_animales;
public:
    Animal();
    ~Animal();
    static int getNumero();
    string getAlimento(){
        return alimento;
    };
    void comer(){
        cout<<"Este animal esta comiendo "<<alimento<<endl;
    };
};

int Animal::numero_animales = 0;

Animal::Animal()
{
    cout<< "Creando animal..."<<endl;
    numero_animales++;
}


Animal::~Animal()
{
    cout<<"Borrando Animal..."<<endl;
    numero_animales--;
}


int Animal::getNumero()
{
    return numero_animales;
}



class Herviboro : public Animal{
public:
    Herviboro():Animal(){
        this->alimento = "plantas";
    }
    void pastar(){
        cout<<"Este Animal esta Pastando"<<endl;
    }
};

class Carnivoro : public Animal{
public:
    Carnivoro():Animal(){
        this->alimento = "carne";
    }
    void cazar(){
        cout<<"Este animal esta cazando"<<endl;
    }
};


class Omnivoro : public Herviboro, public Carnivoro{
public:
    Omnivoro(): Herviboro(), Carnivoro() {

    }
};



int main(){
    Animal *a = new Animal();
    Herviboro *h = new Herviboro();
    Carnivoro *c = new Carnivoro();
    Omnivoro *o = new Omnivoro();

    cout << "Numero de Animales: "<<Animal::getNumero()<<endl;
    
    a->comer();

    h->pastar();
    h->comer();
    
    c->cazar();
    c->comer();

    o->Herviboro::comer();
    o->Carnivoro::comer();

    delete a;
    cout << "Numero de Animales: "<<Animal::getNumero()<<endl;
}