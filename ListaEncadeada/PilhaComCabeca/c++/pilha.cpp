#include <iostream>
using namespace std;

struct Operacao{
    int numero;
    Operacao* proximo;
};

class Pila{
    private:
        Operacao* cabeca = nullptr;

    public:
        Pila(){
            cabeca = new Operacao;
            cabeca->proximo = nullptr;
        }

        void empilhar(int numeroOperacao){
            Operacao* operacaoAdc = new Operacao;
            operacaoAdc->numero = numeroOperacao;
            operacaoAdc->proximo = nullptr;

            if (cabeca->proximo == nullptr){
                cabeca->proximo = operacaoAdc;
                return;
            }

            Operacao* topoAtual = cabeca->proximo;
            operacaoAdc->proximo = topoAtual;
            cabeca->proximo = operacaoAdc;

        }

        int desimpilhar(){
            if (cabeca->proximo == nullptr)
            {
                cout << "Pilha vazia" << endl;
                return -1;
            }        
            Operacao* deletado;
            Operacao* proximo = cabeca->proximo->proximo;
            deletado = cabeca->proximo;
            cabeca->proximo = proximo;
            return deletado->numero;  
        }

    void print(){
            if (cabeca->proximo == nullptr){
                cout << "Fila vazia" << endl;
                return;
            }
            Operacao* op = cabeca->proximo;
            while (op != nullptr){
                cout << op->numero << endl;
                op = op->proximo;
            }        
        }

};

int main(){
    Pila pilha;
    pilha.empilhar(1);
    pilha.empilhar(2);
    pilha.empilhar(3);
    pilha.empilhar(4);
    pilha.empilhar(5);
    pilha.print();
    int deletado = pilha.desimpilhar();
    cout << "Deletado: " << deletado << endl;
    pilha.print();

    return 0;
}