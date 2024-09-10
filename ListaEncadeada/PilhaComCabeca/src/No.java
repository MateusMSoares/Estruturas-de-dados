public class No {
    private Musica musica;
    private No proximo;

    public No() {
        this.musica = null;
        this.proximo = null; 
    }

    public No(Musica musica, No proximo) {
        this.musica = musica;
        this.proximo = proximo; 
    }

    public Musica getMusica() {
        return musica;
    }

    public void setMusica(Musica musica) {
        this.musica = musica;
    } 

    public No getProximo() {
        return proximo;
    }

    public void setProximo(No proximo) {
        this.proximo = proximo;
    }

    @Override
    public String toString(){
        return "No{" +
                "Musica=" + musica +
                ", proximo=" + proximo +
                '}';
    }

}
