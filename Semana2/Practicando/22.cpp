#include <iostream>
using namespace std;

bool mayor(int a, int b) { return a > b; } //bool == verdadero (1) o falso(0) a menos que demos condiciones
bool menor(int a, int b) { return a < b; } // con ? a : b;

int seleccionar(int a, int b, bool (*cmp)(int,int)) {
    return cmp(a,b) ? a : b;
}

int main() {
    cout << seleccionar(3,7,mayor) << endl;
    cout << seleccionar(3,7,menor) << endl;
}