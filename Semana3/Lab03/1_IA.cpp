#include <iostream>

using namespace std;

// 1. Detectar inicios de palabras
int separar_palabras(char* texto, char* palabras[]) {
    int i = 0;
    char* p = texto;
    while (*p != '\0') {
        // Lógica de "Flanco": ¿Soy el primer char no-espacio? o ¿Vengo de un espacio y yo no lo soy?
        if ((p == texto && *p != ' ') || (p > texto && *(p - 1) == ' ' && *p != ' ')) {
            *(palabras+i) = p;
            i++;
        }
        p++;
    }
    return i;
}

// 2. Medir longitud hasta el siguiente espacio o fin de cadena
int longitud_palabra(const char* p) {
    int longitud = 0;
    while (*p != '\0' && *p != ' ') {
        longitud++;
        p++;
    }
    return longitud;
}

// 3. Comparar palabras letra por letra (Manual)
int comparar_palabras(const char* a, const char* b) {
    while (*a != '\0' && *a != ' ' && *b != '\0' && *b != ' ') {
        if (*a != *b) return *a - *b; // Devuelve la diferencia ASCII
        a++;
        b++;
    }
    // Si llegamos aquí, verificamos quién terminó primero
    char finA = (*a == ' ' || *a == '\0') ? '\0' : *a;
    char finB = (*b == ' ' || *b == '\0') ? '\0' : *b;
    return finA - finB;
}

// 4. Distribuir en arreglos según longitud
void clasificar(char* palabras[], int n, char* cortas[], int& nc, char* largas[], int& nl) {
    nc = 0;
    nl = 0;
    for (int i = 0; i < n; i++) {
        if (longitud_palabra(*(palabras + i)) <= 3) {
            *(cortas + nc++) = *(palabras + i);
        } else {
            *(largas+ nl++) = *(palabras + i);
        }
    }
}

// 5. Ordenamiento Burbuja
void ordenar(char* v[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (comparar_palabras(v[j], v[j + 1]) > 0) {
                char* temp = v[j];
                *(v + j) = *(v + j + 1);
                *(v + j + 1) = temp;
            }
        }
    }
}

// 6. Impresión controlada (imprime hasta el espacio)
void imprimir_grupo(const char* titulo, char* v[], int n) {
    cout << titulo << ":" << endl;
    for (int i = 0; i < n; i++) {
        char* p = v[i];
        while (*p != '\0' && *p != ' ') {
            cout << *p;
            p++;
        }
        cout << endl;
    }
    cout << endl; // Espacio extra entre grupos
}

int main() {
    char texto[300] = "Daniel Diaz Mendoza aaa  ass  dsfasd dsddad ";
    char* palabras[60] = {0};
    char* cortas[60] = {0};
    char* largas[60] = {0};
    int n, nc, nl;

     //Ingresa las palabrass
     //Copia el texto dado

    // Proceso
    n = separar_palabras(texto, palabras); //Cantidad de palabras
    clasificar(palabras, n, cortas, nc, largas, nl);
    
    ordenar(cortas, nc);
    ordenar(largas, nl);

    // Salida
    cout << "\nSalida:" << endl;
    imprimir_grupo("Palabras cortas", cortas, nc);
    imprimir_grupo("Palabras largas", largas, nl);

    return 0;
}