#include <iostream>
using namespace std;


int* insert_sort(int lista[], int t){
    for (int i = 1; i < t; i++){
        int temp = lista[i];
        int j = i  - 1;
        while (j >= 0 && lista[j] > temp){
            lista[j + 1] = lista[j];
            j--;
        }
        lista[j+1] = temp;
    }     
    return lista;
};

void print(int lista[], int n) {
    cout << "Array: ";
    for (int i = 0; i < n; i++){
        if (i == n - 1){
            cout << lista[i] << "." << endl; 
            return;
        }
        cout << lista[i] << ", ";
    }
}

int main(){
    int n = 5;
    int lista[n] = {6, 5, 9, 8, 1};
    int* listaSortida = insert_sort(lista, n);
    cout << "teste";
    print(listaSortida, n);

    return 0;
}   