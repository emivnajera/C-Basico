#include <iostream>

using namespace std;

int main() {
int a = 2;
int b = 3;
int c = 0;

//Para la division se usan flotantes debido a que los  resultados no siempre son enteros.
float d = 7.0;
float e = 6.0;
float f;

//Operadores Aritmeticos
c = a+b;
cout<<"Operador +: "<<c<<endl;

c = a-b;
cout<<"Operador -: "<<c<<endl;

c = a*b;
cout<<"Operador *: "<<c<<endl;

f = d/e;
cout<<"Operador /: "<<f<<endl;

c=a%b;
cout<<"Operador &: "<<c<<endl;


//Operadores Comparativos
bool result;

result = a == b;
cout<<"Operador ==: "<<result<<endl;

result = a < b;
cout<<"Operador <: "<<result<<endl;

result = a > b;
cout<<"Operador >: "<<result<<endl;

result = a >= b;
cout<<"Operador >=: "<<result<<endl;

result = a <= b;
cout<<"Operador <=: "<<result<<endl;

//Incrementos y Decrementos
int n1 = 0;
int n2 = 3;


cout<<n1<<endl;
n1++;//aumento en 1 el valor de la varibable equivalente a n1 = n1 +1
cout<<n1<<endl;

cout<<n2<<endl;
n2--;
cout<<n2<<endl;//disminuyo en 1 el valor de la varibable equivalente a n2 = n2 -1


//Operadores Logicos
bool var1 = true;
bool var2 = false;

result = var1 && var2;
cout<<"Operador And: "<<result<<endl;

result = var1 || var2;
cout<<"Operador Or: "<<result<<endl;

result = !var1;
cout<<"Operador Not: "<<result<<endl;


//Otros Operadores

cout<<sizeof(a)<<endl;//Sizeof devuielve el valor en bytes de la variable
}