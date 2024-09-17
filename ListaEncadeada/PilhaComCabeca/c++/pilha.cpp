#include <iostream>
using namespace std;

struct Operacao{
    int numero;
    Operacao* proximo;
};

class Fila{
    private:
        Operacao* cabeca = nullptr;

    public:
        Fila(){
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
    Fila fila;
    fila.empilhar(1);
    fila.empilhar(2);
    fila.empilhar(3);
    fila.empilhar(4);
    fila.empilhar(5);
    fila.print();
    int deletado = fila.desimpilhar();
    cout << "Deletado: " << deletado << endl;
    fila.print();

    return 0;
}