#include <iostream>
#include <iomanip>
#include <queue>
#include <cmath>
using namespace std;

struct Node{
    int valor;
    Node* esquerda;
    Node* direita;

    Node(int novoValor){
        valor = novoValor;
        esquerda = nullptr;
        direita = nullptr;
    }  
};

void inserir(Node* raiz, Node* noInserido){
    if (!raiz){
        raiz = noInserido; 
        return;
    }

    if (noInserido->valor < raiz->valor){
        inserir(raiz->esquerda, noInserido);
    } else if(noInserido->valor > raiz->valor){
        inserir(raiz->direita, noInserido);
    }
}


void printMenorMaior(Node* raiz){
    if (!raiz){
        return;
    } 
    printMenorMaior(raiz->esquerda);
    cout << raiz->valor << " ";
    printMenorMaior(raiz->direita);
}



int main(){
    Node* raiz = nullptr;
    inserir(raiz, new Node(20));
    inserir(raiz, new Node(45));
    printMenorMaior(raiz);
 
    return 0;
}