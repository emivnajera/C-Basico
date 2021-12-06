#include <iostream>

using namespace std;

int main() {
    char letter = 'A';
    char *puntero = &letter;
    cout<<letter<<endl;
    cout<<(int *)&letter<<endl;
    cout<<*puntero<<endl;
    cout<<&puntero<<endl;
}
