public class App {
    public static void main(String[] args) throws Exception {
        
        Musica m1 = new Musica("m1 -Do the evolution - Pearl jam", 3.00);
        Musica m2 = new Musica("m2 -Jamming - Bob Marley", 4.20);
        Musica m3 = new Musica("m3 -Angeles - Elliot Smith", 3.05);

        Pilha pilha = new Pilha();
        pilha.inserir(m3);
        pilha.inserir(m2);
        pilha.inserir(m1);
        pilha.imprimirLista();
        pilha.retirar();
        pilha.imprimirLista();
      

    }
}
