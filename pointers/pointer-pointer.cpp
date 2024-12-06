#include <iostream>
#include <iomanip>
#include <queue>
#include <cmath>
using namespace std;

struct Node{
    int valor;
    Node* proximo;

    Node(int novoValor){
        valor = novoValor;
        proximo = nullptr;
    } 
};

void inserirReferenciaPonteiro(Node*& raiz, Node* noInserido){
    if (!raiz){
        raiz = noInserido; 
        return;
    }
    inserirReferenciaPonteiro(raiz->proximo, noInserido);
     
}

void inserirPonteiroPonteiro(Node** raiz, Node* noInserido){
    if(!(*raiz)){
        (*raiz) = noInserido;
        return;
    }
    inserirPonteiroPonteiro(&((*raiz)->proximo), noInserido);
}

void inserirPonteiro(Node* raiz, Node* noInserido){
    if (!raiz){
        noInserido->valor = 99;
        raiz = noInserido; 
        return;
    }
    inserirPonteiro(raiz->proximo, noInserido);
     
}

void copiaPorValor(Node no){
    no.valor = 10;
    cout << endl << "dentro da copia: " << no.valor << endl;
}


void print(Node* raiz){
   
   while (raiz){
        if (!raiz->proximo){
            cout << raiz->valor << endl;
            return;
        }    
        cout << raiz->valor << " - > ";
        raiz = raiz->proximo;
   }
}


int main(){
    Node* raiz = nullptr;
    inserirReferenciaPonteiro(raiz, new Node(70));
    inserirPonteiroPonteiro(&raiz, new Node(66));

    Node* testePonteiro = new Node(55);
    inserirPonteiro(raiz, testePonteiro);
    
    print(raiz);
    cout << endl;
    cout << "teste ponteiro: " << testePonteiro->valor;
    copiaPorValor(*testePonteiro);
    cout << "teste2 ponteiro: " << testePonteiro->valor;
    return 0;
}