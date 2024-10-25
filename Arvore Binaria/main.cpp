#include <iostream>
using namespace std;

struct Node{
    int valor;
    Node* esquerda;
    Node* direita;

    Node(int novoValor) : valor(novoValor), esquerda(nullptr), direita(nullptr) {} 
};

void inserir(Node*& raiz, int valorNo){
    Node* noInserido = new Node(valorNo);
    if (!raiz){
        raiz = noInserido;
        // cout << "inserido: " << noInserido->valor << endl; 
        return;
    }

    if (valorNo < raiz->valor){
        inserir(raiz->esquerda, valorNo);
    } else if(valorNo > raiz->valor){
        inserir(raiz->direita, valorNo);
    }

}

void print(Node* raiz){
    if (!raiz){
        return;
    } 
    print(raiz->esquerda);
    cout << raiz->valor << " ";
    print(raiz->direita);
}

void printMaiorMenor(Node* raiz){
    if (!raiz){
        return;
    } 
    printMaiorMenor(raiz->direita);
    cout << raiz->valor << " ";
    printMaiorMenor(raiz->esquerda);
}

void ordemDeEntrada(Node* raiz){
    if (!raiz){
        return;
    } 
    cout << raiz->valor << " ";
    ordemDeEntrada(raiz->direita);  
    ordemDeEntrada(raiz->esquerda);    
}

Node* buscaPorValor(Node* raiz, int valor){
    if (!raiz){
        return nullptr;
    }

    if (raiz->valor == valor){
        return raiz;
    }
    
    if(valor < raiz->valor){
        return buscaPorValor(raiz->esquerda, valor);
    }else{
        return buscaPorValor(raiz->direita, valor);
    }
    return nullptr;
}


int main(){
    Node* raiz = nullptr;
    inserir(raiz, 20);
    inserir(raiz, 45);
    inserir(raiz, 50);
    inserir(raiz, 15);
    inserir(raiz, 10);
    print(raiz);
    cout << endl;
    printMaiorMenor(raiz);
    cout << endl;
    ordemDeEntrada(raiz);
    cout << endl;
    Node* encontrado = buscaPorValor(raiz, 70);
    if (encontrado == nullptr) {
        cout << "NOT FOUND";  
    } 
    cout << "Encontrado: " << encontrado->valor;
    return 0;
}