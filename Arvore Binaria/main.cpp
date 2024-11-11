#include <iostream>
#include <iomanip>
#include <queue>
#include <cmath>
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

void percorreHorizontal(deque<pair<int, Node*>> fila){
    if (fila.size() == 0){
        return;   
    }
    
    int profundidade = fila.front().first;
    Node* no = fila.front().second;
    
    if (!no){
        cout << "Vazio";
    }

    fila.pop_front();
    cout << "[" << profundidade << ":" << no->valor << "],";
    if (no->esquerda) fila.push_back(make_pair(profundidade+1, no->esquerda));
    if (no->direita) fila.push_back(make_pair(profundidade+1, no->direita));
    percorreHorizontal(fila);
}


Node* retirar(Node*& raiz){
    if (!raiz){
        cout  << endl << "arvore vazia" << endl;
        return nullptr;
    }
    
    Node* raizAntiga = raiz;

    if (!raiz->esquerda && !raiz->direita){
        raiz = nullptr;
        return raizAntiga;
    }

    if (!raiz->esquerda){
        raiz = raiz->direita;
        return raizAntiga;
    }

    if(!raiz->direita){
        raiz = raiz->esquerda;
        return raizAntiga;
    }
    
    Node* paiMaior = nullptr;
    Node* maior = raiz->direita;
    while(maior->esquerda){
        paiMaior = maior;
        maior = maior->esquerda;
    }
    
    if(paiMaior){
        paiMaior->esquerda = maior->direita;
        maior->esquerda = raiz->esquerda;
        maior->direita = raiz->direita;
    }else{
        maior->esquerda = raiz->esquerda;
    }
    
    raiz = maior;
    
    return raizAntiga;
}


void inverte(Node* raiz){
    if (!raiz){
        return;
    }
    inverte(raiz->esquerda);
    Node* aux = raiz->esquerda;
    raiz->esquerda = raiz->direita;
    raiz->direita = aux;
    inverte(raiz->direita);
    
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
    inserir(raiz, new Node(40));
    inserir(raiz, new Node(1));
    printMenorMaior(raiz);
    cout << endl;
    printMaiorMenor(raiz);
    cout << endl;
    Node* encontrado = buscaPorValor(raiz, 11, 1);

    if (encontrado == nullptr) {
        cout << "NOT FOUND";  
    } 
    cout << "Encontrado: " << encontrado->valor << endl;

    deque<pair<int, Node*>> fila;
    fila.push_back(make_pair(0, raiz));
    cout << "Original das ruas:" << endl;
    percorreHorizontal(fila);
    cout << endl;   
    inverte(raiz);
    fila.clear();
    fila.push_back(make_pair(0, raiz));
    cout << "Invertido:" << endl;
    percorreHorizontal(fila);
    cout << endl;
    Node* raiz2 = nullptr;
    inserir(raiz2, new Node(50));
    inserir(raiz2, new Node(30));
    inserir(raiz2, new Node(70));
    inserir(raiz2, new Node(20));
    inserir(raiz2, new Node(40));
    inserir(raiz2, new Node(60));
    inserir(raiz2, new Node(90));
    
    fila.clear();
    fila.push_back(make_pair(0, raiz2));
    cout << endl;
    percorreHorizontal(fila);
    cout << endl;   
    Node* retirado = retirar(raiz2);
    cout << "retirado: " << retirado->valor;
    cout << endl; 
    
    fila.clear();
    fila.push_back(make_pair(0, raiz2));
    percorreHorizontal(fila);
    return 0;
}