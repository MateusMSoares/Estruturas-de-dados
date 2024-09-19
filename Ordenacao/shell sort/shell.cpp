#include <iostream>
using namespace std;


void print(int lista[], int t){
    for (int i = 0; i < t; i++){
        if (i == t-1){
            cout << lista[i] << "." << endl;
            return;
        }
        cout << lista[i] << ", ";
    }
    
}

int* shell_sort(int lista[], int t){

    for (int gap = t/2; gap > 0; gap /=2){

        for (int i = gap; i < t; i++){
            int temp = lista[i];
            int j;

            for (j = i; j >= gap && lista[j - gap] > lista[j]; j -= gap){
                lista[j] = lista[j - gap];
            }
            lista[j] = temp;
        }
    }
    return lista;   
}

int main(){
    int t = 5;
    int lista[t] = {3, 5, 1, 8, 6};
    // int lista[t] = {3, 5, 7, 8, 6, 10, 9, 2, 4, 1};
    int* listaOrdenada = shell_sort(lista, t);
    print(listaOrdenada, t);

    return 0;
}