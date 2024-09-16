#include <iostream>
using namespace std;



// ele testa até encontrar um indice par e depois testa o indice -2 e indice -1
//alterando a posicao

int* insert_sort(int lista[], int t){
    for (int i = 0; i < t; i++){
        if (lista[i] > lista[i+1]){
            if(i != 0 && i % 2 == 0){
                if (lista[i - 2] > lista[i - 1]){
                    int aux = lista[i - 1];
                    lista[i - 1] = lista[i - 2];
                    lista[i - 2] = aux;
                }
            
            }
            int aux = lista[i + 1];
            lista[i + 1] = lista[i];
            lista[i] = aux;
        }   
    }

    return lista;
    
}


void print(int lista[], int n) {
    cout << "Array: ";
    for (int i = 0; i < n; i++){
        cout << lista[i] << ", ";
    }
}

int main(){
    int lista[10] = {6, 5, 4, 2, 3, 9, 8, 1, 7, 10};
    int n = 10;

    int* listaSortida = insert_sort(lista, n);
    print(lista, n);

    return 0;
}   