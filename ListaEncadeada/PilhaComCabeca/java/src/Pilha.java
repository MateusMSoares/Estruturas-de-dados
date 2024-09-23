public class Pilha {
    private No topo;

    public void inserir(Musica musica){
        No noInserido = new No(musica, null);
        
        if (topo == null) {
            topo = noInserido;
            return;
        }

       No proximo = topo;
       topo = noInserido;
       topo.setProximo(proximo);

    }

    public Musica retirar(){
        if (topo == null) {
            System.out.println("VAZIO");
            return null;
        }

        No noRetirado = topo;
        No proximo = topo.getProximo();
        topo = proximo;

        return noRetirado.getMusica();
    }

    public void imprimirLista() {
        No atual = topo;
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
