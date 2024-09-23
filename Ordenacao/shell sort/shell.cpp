#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;

void shell_sort(vector<int>& lista, vector<int>& gaps){
    int size = lista.size();

    for (int gap : gaps){
        for (int i = gap; i < size; i++){
            int aux = lista[i];
            int j = i;

            while (j >=gap && lista[j - gap] > aux){
                lista[j] = lista[j - gap];
                j -=gap;
            }
            lista[j] = aux;              
        }     
    }
}

void reverseSequencia(vector<int>& lista){
    int size = lista.size();
    for (int i = 0; i < size / 2; i++) {
        int aux = lista[i];
        lista[i] = lista[size - 1 - i];
        lista[size - 1 - i] = aux;
    }
    
}

vector<int> gerarSequenciaSedgewick(int t){
    vector<int> gaps;
    int k = 0;
    while (true){
       int gap = 9 *(1 << (2*k)) - 9 *(1 << k) + 1;
       if (gap < t){
        gaps.push_back(gap);
       }else{
        break;
       }
       k++;
       
    }
    
    reverseSequencia(gaps);
    return gaps;   
}

vector<int> gerarSequenciaHibbard(int t){
    vector<int> gaps;
    for (int k = 1; (1 << k) - 1 < t; k++) {
        gaps.push_back((1 << k) - 1); // 2^k - 1
    }
    reverseSequencia(gaps);
    return gaps;

}

vector<int> gerarSequenciaKnuth(int t){
    vector<int> gaps;
    int h = 1;
    while (h < t){
        gaps.push_back(h);
        h = (3 * h) + 1;
    }
    
    reverseSequencia(gaps);
    return gaps;

}

void print(vector<int>& lista){
    int t = lista.size();
    for (int i = 0; i < t; i++){
        if (i == t-1){
            cout << lista[i] << "." << endl;
            return;
        }
        cout << lista[i] << ", ";
    }  
}

vector<int> criarLista(int tamanho){
    vector<int> vec;
    for (int i = tamanho; i > 0; i--){
        vec.push_back(i);
    }
    return vec;
}

int main(){
    vector<int> lista1 = criarLista(100000);
    vector<int> lista2 = criarLista(100000);
    vector<int> lista3 = criarLista(100000);

    vector<int> hibbard = gerarSequenciaHibbard(lista1.size());
    vector<int> sedgewick = gerarSequenciaSedgewick(lista2.size());
    vector<int> knuth = gerarSequenciaKnuth(lista3.size());

    cout << "Hibbard sequence: " << endl;
    print(hibbard);
    cout << endl;
    cout << "sedgewick sequence: " << endl;
    print(sedgewick);
    cout << endl;
    cout << "knut sequence: " << endl;
    print(knuth);
    cout << endl;
       


    // auto start1 = high_resolution_clock::now();
    // shell_sort(lista2, hibbard);
    // auto stop1 = high_resolution_clock::now();
    // auto duration1 = duration_cast<microseconds>(stop1 - start1);
    // cout << "Tempo de execucao para lista (Hibbard): " << duration1.count() << " microseconds" << endl;

    auto start2 = high_resolution_clock::now();
    shell_sort(lista3, knuth);
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(stop2 - start2);
    cout << "Tempo de execucao para lista (knut): " << duration2.count() << " microseconds" << endl;

    // auto start = high_resolution_clock::now();
    // shell_sort(lista1, sedgewick);
    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << "Tempo de execucao para lista (Sedgewick): " << duration.count() << " microseconds" << endl;

    return 0;
}