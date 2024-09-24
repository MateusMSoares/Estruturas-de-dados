#include <iostream>
#include <cstdlib>
using namespace std;

struct Pessoa {
    string nome;
    Pessoa* proximo;
};

void imprimirLista(Pessoa* inicio) {
    Pessoa* atual = inicio;
    while (atual != nullptr) {
        cout << atual->nome << " ";
        atual = atual->proximo;
    }
    cout << endl;
}

void enfileirar(Pessoa*& inicio, Pessoa*& fim, string nome){
    Pessoa* novaPessoa = new Pessoa();
    novaPessoa->nome= nome;
    novaPessoa->proximo = nullptr;

    if (inicio == nullptr){
        inicio = novaPessoa;
        fim = novaPessoa;
        return;
    }

    fim->proximo = novaPessoa;
    fim = novaPessoa;     
}

Pessoa* desenfileirar(Pessoa* inicio, Pessoa*& fim){
    Pessoa* pessoaRetirada;
    if (inicio == fim){
        pessoaRetirada = inicio;
        inicio = nullptr;
        fim = nullptr;
        return pessoaRetirada;
    }
    pessoaRetirada = inicio;
    inicio = inicio->proximo;
    return pessoaRetirada;
}

int main() {
    Pessoa* inicio = nullptr;
    Pessoa* fim = nullptr;

    enfileirar(inicio, fim, "m1");
    imprimirLista(inicio);
    enfileirar(inicio, fim, "m2");
    imprimirLista(inicio);
    enfileirar(inicio, fim, "m3");
    imprimirLista(inicio);

    Pessoa* pessoaRetirada = desenfileirar(inicio, fim);
    
    cout << "pessoa Saiu: " << pessoaRetirada->nome << endl;
    delete(pessoaRetirada);
    
    cout << "Fila aps desenfileirar: ";
    imprimirLista(inicio);

    return 0;
}




















