#include <iostream>
#include <vector>
#include <random>
#include <chrono>
using namespace std;
using namespace std::chrono;

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

vector<int> criaListaAleatoria(int tamanho){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distr(1, tamanho);
    vector<int> lista(tamanho);
    for (int i = 0; i < tamanho; ++i) {
        lista[i] = distr(gen);
    }
    return lista;
}

vector<int> criaLista(int tamanho){
    vector<int> vec;
    vec.reserve(tamanho);
    for (int i = tamanho; i > 0; i--){
        vec.push_back(i);
    }
    return vec;
}

int main(){
   vector<int> v = criaLista(1000000);
   vector<int> vr = criaListaAleatoria(1000000);

    // Medir o tempo de execução
    auto start = high_resolution_clock::now();
    quickSort(v, 0, v.size() - 1);
    auto end = high_resolution_clock::now();
    chrono::duration<double> tempo = end - start; 
    cout << "Tempo de execucao invertido: " << tempo.count() << " segundos" << endl;

    auto start1 = high_resolution_clock::now();
    quickSort(vr, 0, vr.size() - 1);
    auto end1 = high_resolution_clock::now();
    chrono::duration<double> tempo1 = end1 - start1; 

    cout << "Tempo de execucao aleatorio: " << tempo1.count() << " segundos" << endl;

    // print(v);

    
    return 0;
}