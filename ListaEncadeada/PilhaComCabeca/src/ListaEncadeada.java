public class ListaEncadeada {
    private No cabeca;

    public ListaEncadeada() {
       this.cabeca = null;
    }

    public void adicionaPrimeiroNo(Musica musica){
        No musicaAdiconado = new No(musica, null);
        No proximo = cabeca.getProximo();

        
        if (proximo == null){
            cabeca.setProximo(musicaAdiconado);
            return;
        }
        musicaAdiconado.setProximo(proximo);
        cabeca.setProximo(musicaAdiconado);
    }

    public void adicionarAposNoEspecifico(Musica musica, Musica musicaEscolhida){
        No atual = cabeca.getProximo();

        if (atual == null){
            System.out.println("Não há itens na lista");
            return;
        }

        while (atual.getMusica().getNome() != musica.getNome()){
            if (atual.getProximo() == null) {
                System.out.println("Não encontrado musica " + musicaEscolhida.getNome());
                return;
            }
            atual = atual.getProximo();
        }
        No proximo = atual.getProximo();
        atual.setProximo(new No(musicaEscolhida, proximo));
    }

    public void adicionarAntesNoEspecifico(Musica musica, Musica musicaEscolhida){
        No musicaAdiconado = new No(musicaEscolhida, null);
        No atual = cabeca.getProximo();
        No anterior = null;
        if (atual == null){
            System.out.println("Não há itens na lista");
            return;
        }
        
        while (atual.getMusica().getNome() != musica.getNome()){

            if(atual.getProximo() == null) {
                System.out.println("Não encontrado musica " + musicaEscolhida.getNome());
                return;
            }
            anterior = atual;
            atual = atual.getProximo();
        }

        if (anterior == null){
            cabeca.setProximo(musicaAdiconado);
            musicaAdiconado.setProximo(atual);
            return;
        }
        anterior.setProximo(musicaAdiconado);
        musicaAdiconado.setProximo(atual);      
    }

    public void deletarNo(Musica musica){
        No atual = cabeca.getProximo();;
        No anterior = null;

        if (atual == null){
            System.out.println("Não há itens na lista");
            return;
        }

        while(atual.getMusica().getNome() != musica.getNome()){
            if (atual.getProximo() == null) {
                System.out.println("Não Encontrado " + musica.getNome() + " Não sendo possivel deletar.");
                return;
            }
            anterior = atual;
            atual = atual.getProximo();
        }

        if (anterior == null){
            cabeca.setProximo(atual.getProximo());
            return;
        }
       
        No proximo = atual.getProximo();
        anterior.setProximo(proximo);
    }

    public void adicionarUltimoNo(Musica musica) {
        No musicaInserida = new No(musica, null);
        No atual = cabeca.getProximo();
       
        if (atual == null){
            System.out.println("Não há itens na lista");
            return;
        }

        while (atual.getProximo() != null) {
            atual = atual.getProximo();
        }

        atual.setProximo(musicaInserida);

        
    }

    public void buscarPorPosicao(int posicaoSelecionada){
        No atual = cabeca.getProximo();
        int contadorzinho = 1;

        if (atual == null){
            System.out.println("AU AU não tem musica, my friend!");
            return;
        }
        while (contadorzinho != posicaoSelecionada) {

            if(atual.getProximo() == null){
                System.out.println("Acabou tudinho");
                return;
            }
            atual = atual.getProximo();
            contadorzinho++;
        }
        System.out.println("Musica encontrada: " + atual.getMusica().getNome());
    }

    public void imprimirLista() {
        No atual = cabeca.getProximo();
        int contador = 1;
        System.out.println("");
        System.out.println("MUSICA DA CABEÇA:");
        System.out.println(cabeca.getMusica());
        System.out.println("PONTEIRO DA CABEÇA:");
        System.out.println(cabeca.getProximo());
        System.out.println("");

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
