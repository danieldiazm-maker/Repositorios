#include <iostream>
using namespace std;

int suma(int a, int b) { return a + b; }
int resta(int a, int b) { return a - b; }
int mult(int a, int b) { return a * b; }

/*
int *f(int,int);    //  función que retorna int*
int (*f)(int,int);  //  puntero a función
*/

int main() {
    int (*ops[3])(int,int) = {suma, resta, mult};

    for (int i = 0; i < 3; ++i) {
        cout << ops[i](10,5) << endl;
    }
}
/*
"ops es un arreglo de 3 punteros a funciones que reciben dos enteros y devuelven un entero".

Aquí tienes el desglose paso a paso para que no te pierdas:

ops[3]: Primero miramos el nombre y los corchetes. Esto nos dice que ops es un arreglo de 3 elementos.

(*ops[3]): El asterisco dentro del paréntesis indica que cada uno de esos 3 elementos es un puntero.

(int, int): Los paréntesis a la derecha indican a qué apuntan esos punteros: 
a funciones que toman dos parámetros int.

int (al inicio): Indica que esas funciones deben retornar un valor de tipo entero.

= {suma, resta, mult}: Inicializa el arreglo guardando las direcciones de memoria de las tres funciones.

*/


/*

Analice sin ejecutar:

int (*f[5])(int);
int (*(*pf)[3])(double);

*/