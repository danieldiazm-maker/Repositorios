#include <iostream>
using namespace std;

int main() {
    int m[2][3] = {{1,2,3},{4,5,6}};

    int (*p)[3] = m; //apunta a la direcion de valores

    for (int (*fila)[3] = p; fila < p + 2; ++fila) { //p representa direccion
        for (int* col = *fila; col < *fila + 3; ++col) {//*fila es una direccion
            cout << *col << " "; //imprime el valor
        }
        cout << endl;
        cout<<(*fila)[2];
        cout<<endl;
    }
    
}
/* 
m[i][j] == *(*(m + i) + j)
int (*p)[10];                // Puntero a un arreglo de 10 enteros   
int* p[10];                  // Un arreglo de 10 punteros a entero
int (*(*p)[5])[3];           // Un puntero a un arreglo de 5 punteros, 
                               donde cada uno de esos 5 punteros apunta a un arreglo de 3 enteros
(*p)              // p es un puntero.
(*p)[5]           // Apunta a un arreglo de 5 elementos.
(*(*p)[5])        // Esos 5 elementos son, a su vez, punteros.
(*(*p)[5])[3]     // Cada uno de esos punteros apunta a un arreglo de 3 enteros.

*/
