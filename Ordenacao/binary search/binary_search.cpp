#include <iostream>
using namespace std;

void print(int lista[], int inicio, int final) {
    cout << "Array: ";
    for (int i = inicio; i < final; i++) {
        cout << lista[i] << ", ";
    }
    cout << endl;
}

int binary_search(int lista[], int inicio, int fim, int alvo){
    cout << "Inicio: " << inicio << endl;
    cout << "fim: " << fim << endl;
    int metade = (inicio + fim) / 2;
    print(lista, inicio, fim);
    cout << "Valor: " << lista[metade] << " Metade(indice): " << metade << endl;
    
    if (lista[metade] > alvo){
        return binary_search(lista, inicio, metade + 1, alvo);
    }

    if (lista[metade] < alvo){
        return binary_search(lista, metade -1, fim, alvo);
    }

    if (lista[metade] == alvo){
        return lista[metade];
    }else{
        return - 1;
    }    
}


int main() {
    int lista[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int alvo = 7;
    int inicio = 0;
    int fim = 9;
    int encontrado = binary_search(lista, inicio, fim, alvo);
    
    if (encontrado != -1) {
        cout << "Encontrado: " << encontrado << endl;
    }

    return 0;
}
