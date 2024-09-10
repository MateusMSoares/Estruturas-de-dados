#include <iostream>
#include <cstdlib>
using namespace std;

struct Musica
{
    string nome;
};


struct No 
{
    Musica musica;
    No* proximo;
};

struct Fila
{
    No* primeiro;
    No* ultimo;
};


void iniciarFila(Fila& fila){
    fila.primeiro = nullptr;
    fila.ultimo = nullptr;
};


void inserirNaFila(Fila& fila, Musica musicaSelecionada){
    cout << &fila << endl;
    No* noInserido = new No;
    noInserido->musica = musicaSelecionada;
    noInserido->proximo = nullptr;
    if(fila.primeiro == nullptr){
        fila.primeiro = noInserido;
        fila.ultimo = noInserido;
        return;
    }

    fila.ultimo->proximo = noInserido;
    fila.ultimo = noInserido;
}


void printFila(Fila& fila){
    cout << &fila << endl;
    No* atual = fila.primeiro;
    while(atual != nullptr){
        cout << "Musica: " << atual->musica.nome;
        if (atual->proximo != nullptr){
            cout << " Proximo: " << atual->proximo->musica.nome << "\n";
        }
        atual = atual->proximo;
    }
}

No* retirarDaFila(Fila& fila){
    cout << &fila << endl;
    if (fila.primeiro == nullptr){
        cout << "Fila vazia";
        return nullptr;
    }
    No* noRetirado = fila.primeiro;
    fila.primeiro = fila.primeiro->proximo;

    return noRetirado;
}

int main(){

    Fila* fila = new Fila;
    cout << "Endereco do ponteiro: " << &fila << endl;
    cout << "Endereco de referencia: " << fila << endl;
    iniciarFila(*fila);
    Musica m1;
    m1.nome = "m1";
    Musica m2;
    m2.nome = "m2";
    Musica m3;
    m3.nome = "m3";

    inserirNaFila(*fila, m3);
    inserirNaFila(*fila, m1);
    inserirNaFila(*fila, m2);
    inserirNaFila(*fila, m3);
    // printFila(*fila);
    cout << "\n";
    No* noRetirado = retirarDaFila(*fila);
    // printFila(*fila);
    cout << "\n";
    cout << "No retirado: " << noRetirado->musica.nome;

    delete noRetirado;

    return 0;
}