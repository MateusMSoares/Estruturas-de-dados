#include <iostream>
#include <deque>
using namespace std;

struct Node{
    int valor;
    Node* esquerda;
    Node* direita;

    Node(int novoValor) : valor(novoValor), esquerda(nullptr), direita(nullptr) {} 
};

void inserir(Node*& raiz, Node* noInserido){
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

void printMaiorMenor(Node* raiz){
    if (!raiz){
        return;
    } 
    printMaiorMenor(raiz->direita);
    cout << raiz->valor << " ";
    printMaiorMenor(raiz->esquerda);
}

Node* buscaPorValor(Node* raiz, int valor, int profundidade){
    if (!raiz){
        return nullptr;
    }

    if (raiz->valor == valor){
        cout << "profundidade: " << profundidade << " ";
        return raiz;
    }
    
    if(valor < raiz->valor){ 
        return buscaPorValor(raiz->esquerda, valor, profundidade + 1);
    }else{
        return buscaPorValor(raiz->direita, valor, profundidade + 1);
    }
    return nullptr;
}

void percorreHorizontal(deque<Node*> fila){
    if (fila.size() < 1){
        return;   
    }
    Node* no = fila.front();
    cout << no->valor << " ";
    fila.pop_front();
    if (no->esquerda) fila.push_back(no->esquerda);
    if (no->direita) fila.push_back(no->direita);
    percorreHorizontal(fila);
}

Node* retirar(Node* raiz){
    
}

int main(){
    Node* raiz = nullptr;
    inserir(raiz, new Node(20));
    inserir(raiz, new Node(45));
    inserir(raiz, new Node(50));
    inserir(raiz, new Node(15));
    inserir(raiz, new Node(10));
    inserir(raiz, new Node(9));
    inserir(raiz, new Node(8));
    inserir(raiz, new Node(7));
    inserir(raiz, new Node(18));
    inserir(raiz, new Node(19));
    inserir(raiz, new Node(7));
    inserir(raiz, new Node(55));
    inserir(raiz, new Node(11));
    inserir(raiz, new Node(35));
    inserir(raiz, new Node(1));
    printMenorMaior(raiz);
    cout << endl;
    printMaiorMenor(raiz);
    cout << endl;
    Node* encontrado = buscaPorValor(raiz, 1, 1);

    if (encontrado == nullptr) {
        cout << "NOT FOUND";  
    } 
    cout << "Encontrado: " << encontrado->valor << endl;
    cout << endl;

    deque<Node*> fila;
    fila.push_back(raiz);
    percorreHorizontal(fila);

    return 0;
}