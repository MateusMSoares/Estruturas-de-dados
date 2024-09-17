#include <iostream>
using namespace std;


int* insert_sort(int lista[], int t){
   for (int i = 0; i < t - 1; i++){
        int j = i+1;
        while (j > 0 && lista[j] < lista[j-1]) {
			int aux = lista[j];
			lista[j] = lista[j-1];
			lista[j-1] = aux;
			j -= 1;
		}
   }
    return lista;
}


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
    int lista[10] = {6, 5, 9, 8, 1, 7, 10, 3, 4, 2};
    int n = 10;

    int* listaSortida = insert_sort(lista, n);
    print(listaSortida, n);

    return 0;
}   