#include <iostream>
#include <vector>
#include <random>
using namespace std;

void print(vector<int> &lista){
    for (size_t i = 0; i < lista.size(); i++){
        cout << lista[i] << " ";
    }
    
}

void quickSort(vector<int> &lista, int inicio, int fim){
    if (inicio < fim){
        int pivo = lista[inicio + (fim - inicio) / 2];
        int i = inicio;
        int j = fim;

        while (i <= j){
            while (lista[i] < pivo){
                i++;
            }
            while (lista[j] > pivo){
                j--;
            }
            if (i <= j) {
                swap(lista[i], lista[j]);         
                i++;
                j--;
            }
        }      
        quickSort(lista, inicio, j);
        quickSort(lista, i, fim);
    }
}

vector<int> criaLista(int tamanho){
    random_device rd;
    mt19937 gen(rd());

    uniform_int_distribution<> distr(1, tamanho);

    vector<int> lista(tamanho);
    for (int i = 0; i < tamanho; ++i) {
        lista[i] = distr(gen);
    }

    return lista;

}

int main(){
    vector<int> v = criaLista(100000);
    quickSort(v, 0, v.size() - 1);
    cout << endl;
    for(size_t i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    
    return 0;
}