public class ListaEncadeada {
    private No primeiro;

    public ListaEncadeada() {
    }

    public void adicionaPrimeiroNo(Musica musica) {
        if (primeiro == null){
            primeiro = new No(musica, primeiro);
            return;
        } 
    }

    public void adicionarAposNoEspecifico(Musica musica, Musica musicaEscolhida){
        No atual = primeiro;
        if (atual == null){
            System.out.println("A lista está vazia");
            return;
        }
        while (atual.getMusica().getNome() != musica.getNome()){
            if (atual.getProximo() == null) {
                System.out.println("Não Encontrado elemento " + musica.getNome() + " Não sendo possivel adicionar depois dele.");
                return;
            }
            atual = atual.getProximo();
        }
        No proximo = atual.getProximo();
        atual.setProximo(new No(musicaEscolhida, proximo));
    }

    public void adicionarAntesNoEspecifico(Musica musica, Musica musicaEscolhida){
        No atual = primeiro;
        No anterior = null;
        if (atual == null){
            System.out.println("A lista está vazia");
            return;
        }

        while (atual.getMusica().getNome() != musica.getNome()) {
            if (atual.getProximo() == null) {
                System.out.println("Não Encontrado elemento " + musica.getNome() + " Não sendo possivel adicionar antes dele.");
                return;
            }
            anterior = atual;
            atual = atual.getProximo();
        }

        if (anterior == null){
            No novoprimeiroNo = new No(musicaEscolhida, atual);
            primeiro = novoprimeiroNo;
            return;
        }

        anterior.setProximo(new No(musicaEscolhida, atual));
    }

    public void deletarNo(Musica musica){
        No atual = primeiro;
        No anterior = null;

        if (atual == null){
            System.out.println("A lista está vazia");
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
            primeiro = atual.getProximo();
            return;
        }
       
        No proximo = atual.getProximo();
        anterior.setProximo(proximo);
    }

    public void adicionarUltimoNo(Musica musica) {
        No atual = primeiro;
        if(atual == null){
            primeiro = new No(musica, null);
        } else {
            while(atual.getProximo() != null){
                atual = atual.getProximo();
            }
            atual.setProximo(new No(musica, null));
        }
    }

    public void imprimirLista() {
        No atual = primeiro;
        int contador = 1;
        System.out.println("");
        System.out.println("Lista sem cabeça eu to maluco:");
        System.out.println(atual);
        System.out.println("");
        if (atual == null){
            System.out.println("A lista está vazia");
            return;
        }
        while(atual != null){
            System.out.println("Posicao: " + contador + ": " + atual.getMusica().toString());
            if (atual.getProximo() != null) {
                System.out.println("->*Proximo: " + atual.getProximo().getMusica().toString());
                // System.out.println(" ");
            }else{
                System.out.println("---------------------------------------------//-------------------------------------------"); 
            }
            atual = atual.getProximo();
            contador++;
        }
    }
}
