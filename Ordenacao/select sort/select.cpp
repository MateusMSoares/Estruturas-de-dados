#include <iostream>
using namespace std;


void print(int lista[], int n) {
    cout << "Array: ";
    for (int i = 0; i < n; i++){
        if (i == 5){
            cout << lista[i];
            return;
        }
        cout << lista[i] << ", ";
    }
}

int* select_sort(int lista[], int n){
    for (int i = 0; i < n - 1; i++){
        int indiceMenor = i;
        for (int j = i+1; j < n; j++){
            if (lista[i] > lista[j]){
                if(lista[indiceMenor] > lista[j]){
                    indiceMenor = j;
                }
            }
        }
        int aux = lista[i];
        lista[i] = lista[indiceMenor];
        lista[indiceMenor] = aux;
        print(lista, n);
        cout << endl;
    }
    return lista;
}


int main(){

    int lista[6] = {7, 2, 8, 4 ,9, 3};
    cout << "Lista original: ";
    print(lista, 6);
    cout << endl;
    int* lista_ordenada = select_sort(lista, 6);
    cout << endl;
    print(lista_ordenada, 6);
    cout << endl;
    cout << "Endereco da lista: " << lista << endl;
    cout << "primeiro elemento: " << *lista << endl;
    cout << "Endereco dentro do ponteiro: " << lista_ordenada << endl;
    cout << "Endereco do ponteiro: " << &lista_ordenada << endl;

    return 0;
}