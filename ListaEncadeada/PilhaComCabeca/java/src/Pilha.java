public class Pilha {
    private No cabeca;

    public void inserir(Musica musica){
        No noInserido = new No(musica, null);
        
        if (cabeca == null) {
            cabeca = noInserido;
            return;
        }

       No proximo = cabeca;
       cabeca = noInserido;
       cabeca.setProximo(proximo);

    }

    public Musica retirar(){
        if (cabeca == null) {
            System.out.println("VAZIO");
            return null;
        }

        No noRetirado = cabeca;
        No proximo = cabeca.getProximo();
        cabeca = proximo;

        return noRetirado.getMusica();
    }

    public void imprimirLista() {
        No atual = cabeca;
        int contador = 1;

        if (atual == null){
            System.out.println("Não há itens na lista");
            return;
        }

        while(atual != null){
            System.out.println("Posicao: " + contador + ": " + atual.getMusica().toString());
            contador++;
            if (atual.getProximo() != null) {
                System.out.println("->*Proximo: " + atual.getProximo().getMusica().toString());
                // System.out.println(" ");
            }else{
                System.out.println("---------------------------------------------//-------------------------------------------"); 
            }
            atual = atual.getProximo();
            
        }

    }
}
