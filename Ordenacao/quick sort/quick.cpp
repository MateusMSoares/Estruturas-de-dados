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

int conquista(vector<int> &v, int inicio, int fim) {
    int indexPivo = inicio + (fim - inicio) / 2;
    swap(v[indexPivo], v[fim]);
    int valPivo = v[fim];
    int i = inicio;

    for (int j = inicio; j < fim; j++){
        if (v[j] < valPivo){
            swap(v[i], v[j]);
            i++;
        }
    } 
    swap(v[i], v[fim]);
    return i;
}

void divide(vector<int> &lista, int inicio, int fim){
    if(inicio < fim){        
        int posicaoPivo = conquista(lista, inicio, fim);
        divide(lista, inicio, posicaoPivo-1);
        divide(lista, posicaoPivo+1, fim);
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
   vector<int> v = {2, 4, 6, 1, 8, 1, 3, 5, 9, 2};
   vector<int> vr = criaListaAleatoria(10000000);
   vector<int> vri = criaLista(10000000);

    divide(v, 0, v.size() - 1);
    // print(v);
    // cout << endl;

    cout << "Quick:" << endl;
    auto start = high_resolution_clock::now();
    divide(vri, 0, vri.size() - 1);
    auto end = high_resolution_clock::now();
    chrono::duration<double> tempo = end - start; 
    cout << "Tempo de execucao invertido: " << tempo.count() << " segundos" << endl;
    
    auto start1 = high_resolution_clock::now();
    divide(vr, 0, vr.size() - 1);
    auto end1 = high_resolution_clock::now();
    chrono::duration<double> tempo1 = end1 - start1; 
    cout << "Tempo de execucao aleatorio: " << tempo1.count() << " segundos" << endl;   
    return 0;
}