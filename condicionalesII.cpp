#include <iostream>

using namespace std;

int main() {
    int op = 0;
    cout<<"Ingrese una Opcion"<<endl;
    cin>>op;
    switch (op)
    {
    case 1:
        cout<<"Opcion 1";
        break;
    case 2:
        cout<<"Opcion 2";
        break;
    default:
        cout<<"Opcion no disponible";
        break;
    }
}

