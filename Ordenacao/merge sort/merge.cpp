#include <iostream>
#include <vector>
#include <random>
#include <chrono>
using namespace std;
using namespace std::chrono;

void print(vector<int>& vetor, string texto){
    cout << texto << ": ";
    for (size_t i = 0; i < vetor.size(); i++){
        cout << vetor[i] << " ";
    }
    cout << endl;
    
}

void merge(vector<int>& listaOriginal, int inicio, int meio, int fim) {
    int i = inicio;
    int j = meio + 1;
    int k = 0;

    vector<int> temp(fim - inicio + 1);
    
    while (i <= meio && j <= fim){
        if (listaOriginal[i] <= listaOriginal[j]){
            temp[k] = listaOriginal[i];
            i++;
        }else{
            temp[k] = listaOriginal[j];
            j++;
        }
        k++;
    }

    while (i <= meio){
        temp[k] = listaOriginal[i];
        i++;
        k++;
    }

    while (j <= fim){
        temp[k] = listaOriginal[j];
        j++;
        k++;
    }

    for (size_t l = 0; l < temp.size(); l++){
        listaOriginal[inicio + l] = temp[l];
    }   
}

void mergeSort(vector<int>& lista, int inicio, int fim){
    if (inicio < fim){
        int meio = inicio + (fim - inicio) / 2;
        mergeSort(lista, inicio, meio);
        mergeSort(lista, meio +1, fim);
        merge(lista, inicio, meio, fim);
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
    mergeSort(v, 0, v.size() - 1);
    auto end = high_resolution_clock::now();
    chrono::duration<double> tempo = end - start; 
    cout << "Tempo de execucao invertido: " << tempo.count() << " segundos" << endl;

    auto start1 = high_resolution_clock::now();
    mergeSort(vr, 0, vr.size() - 1);
    auto end1 = high_resolution_clock::now();
    chrono::duration<double> tempo1 = end1 - start1; 

    cout << "Tempo de execucao aleatorio: " << tempo1.count() << " segundos" << endl;

    return 0;
}