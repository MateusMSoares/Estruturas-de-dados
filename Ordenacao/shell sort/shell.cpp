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
    vector<int> lista3h = criarLista(10000);
    vector<int> lista3s = criarLista(10000);

    vector<int> Hibbard3 = gerarSequenciaHibbard(lista3h.size());
    vector<int> sedgewick3 = gerarSequenciaSedgewick(lista3s.size());

    cout << endl;
       
    auto start5 = high_resolution_clock::now();
    shell_sort(lista3s, sedgewick3);
    auto stop5 = high_resolution_clock::now();
    auto duration5 = duration_cast<microseconds>(stop5 - start5);
    cout << "Tempo de execucao para lista3 (Sedgewick): " << duration5.count() << " microseconds" << endl;

    auto start6 = high_resolution_clock::now();
    shell_sort(lista3h, Hibbard3);
    auto stop6 = high_resolution_clock::now();
    auto duration6 = duration_cast<microseconds>(stop6 - start6);
    cout << "Tempo de execucao para lista3 (Hibbard): " << duration6.count() << " microseconds" << endl;

    return 0;
}