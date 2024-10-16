#include <iostream>
#include <vector>
using namespace std;

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
    
    print(listaOriginal, "Lista original: ");
   
}

void mergeSort(vector<int>& lista, int inicio, int fim){
    if (inicio < fim){
        int meio = inicio + (fim - inicio) / 2;
        mergeSort(lista, inicio, meio);
        mergeSort(lista, meio +1, fim);
        merge(lista, inicio, meio, fim);
    }
}


vector<int> criarLista(int tamanho){
    vector<int> vec;
    vec.reserve(tamanho);
    for (int i = tamanho; i > 0; i--){
        vec.push_back(i);
    }
    return vec;
}


int main(){
    cout << "teste" << endl;
    vector<int> v = criarLista(1000);
    cout << v.size() << endl;
    mergeSort(v, 0, v.size() - 1);

    for (int num : v) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}