#include <iostream>
using namespace std;

struct Pointer {
    int valor;
};

void naoSomaGlobal(Pointer p) {
    p.valor = p.valor + 7;  // Isso não afeta o objeto original
}

void somaGlobal(Pointer*& p) {
    p->valor = p->valor + 7;  // Isso afeta o objeto original
}

void somaStack(Pointer* p) {
    p->valor = p->valor + 7;  // Isso afeta o objeto original
}

int main() {
    Pointer p;
    Pointer p3;
    Pointer* p1 = new Pointer();
    
    p.valor = 12;   // Inicializa 'p' com 12
    p3.valor = 3;   // Inicializa 'p3' com 3
    p1 = &p;        // Faz 'p1' apontar para 'p'  

    naoSomaGlobal(p);  // Chamada por valor (não modifica 'p')
    naoSomaGlobal(*p1); // Chamada por valor (não modifica 'p')

    // Exibir valores após as chamadas
    cout << "Valor de p após naoSomaGlobal: " << p.valor << endl;  // Saída: 12
    cout << "Valor de p3: " << p3.valor << endl;  // Saída: 3
    
    somaGlobal(p1);  // Chamada por referência (modifica 'p')
    somaStack(&p3);  // Chamada por referência (modifica 'p')
    cout << "Valor de p3: " << p3.valor << endl;  // Saída: 3

    cout << "Valor de p após somaGlobal: " << p.valor << endl;  // Saída: 19

    delete p1;  // Libera a memória alocada
    return 0;
}
