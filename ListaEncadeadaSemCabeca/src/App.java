public class App {
    public static void main(String[] args) throws Exception {
        
        Musica m1 = new Musica("m1 -Do the evolution - Pearl jam", 3.00);
        Musica m2 = new Musica("m2 -Jamming - Bob Marley", 4.20);
        Musica m3 = new Musica("m3 -Angeles - Elliot Smith", 3.05);
        Musica m4 = new Musica("m4 -Stairway to Heaven - Led Zeppelin", 8.02);
        Musica m5 = new Musica("m5 -Hey Jude - The Beatles", 7.11);
        Musica m6 = new Musica("m6 -Smells Like Teen Spirit - Nirvana", 5.01);
        Musica m7 = new Musica("m7 -Billie Jean - Michael Jackson", 4.54);
        ListaEncadeada lista = new ListaEncadeada();
        System.out.println("Adicionando m5 como primeiro nó");
        lista.adicionaPrimeiroNo(m5);
        lista.imprimirLista(); // Exibe a lista após a adição do primeiro nó

        System.out.println("Adicionando m7 após o nó m5");
        lista.adicionarAposNoEspecifico(m5, m7);
        lista.imprimirLista(); // Exibe a lista após a adição do nó m7

        System.out.println("Adicionando m1 após o nó m5");
        lista.adicionarAposNoEspecifico(m5, m1);
        lista.imprimirLista(); // Exibe a lista após a adição do nó m1

        System.out.println("Deletando o nó m5 (primeiro nó)");
        lista.deletarNo(m5);
        lista.imprimirLista(); // Exibe a lista após a deleção do nó m5

        System.out.println("Deletando o nó m7 (último nó)");
        lista.deletarNo(m7);
        lista.imprimirLista(); // Exibe a lista após a deleção do nó m7

        System.out.println("Adicionando m2 antes do nó m1 (primeiro nó)");
        lista.adicionarAntesNoEspecifico(m1, m2);
        lista.imprimirLista(); // Exibe a lista após a adição do nó m2

        System.out.println("Deletando o nó m1 (último nó)");
        lista.deletarNo(m1);
        lista.imprimirLista(); // Exibe a lista após a deleção do nó m1

    }
}
