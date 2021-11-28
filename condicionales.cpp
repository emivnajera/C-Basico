#include <iostream>

using namespace std;

int main() {
int age = 0;

cout<<"Ingrese su Edad"<<endl;
cin>>age;

if (age < 18){ //Condicional If Estructura: if ('CONDICION'){'INTRUCCIONES'} o if ('CONDICION'){'INTRUCCIONES'} else {'INSTRUCCIONES'} o if ('CONDICION'){'INTRUCCIONES'} else if {'INTRUCCIONES'} (Una o mas Veces) else {'INSTRUCCIONES'}
cout<<"Usted No Puede Votar";
}else if (age > 81){
cout<<"Usted No Puede Votar";
}else{
cout<<"Usted Puede Votar";
}

}