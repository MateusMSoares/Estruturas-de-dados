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
        lista.adicionaPrimeiroNo(m5);
        lista.adicionaPrimeiroNo(m6);
        lista.adicionaPrimeiroNo(m7);

        System.out.println("Adicionando m1 antes do nó m7 (primeiro nó)");
        lista.adicionarAntesNoEspecifico(m7, m1);
        lista.imprimirLista();

        lista.buscarPorPosicao(2);

        System.out.println("Adicionando m2 após o nó m5 (último nó)");
        lista.adicionarAposNoEspecifico(m5, m2);
        lista.imprimirLista();

        System.out.println("Adicionando m3 antes do nó m7");
        lista.adicionarAntesNoEspecifico(m7, m3);
        lista.imprimirLista();

        System.out.println("Deletando o nó m1 (primeiro nó)");
        lista.deletarNo(m1);
        lista.imprimirLista();

        System.out.println("Deletando o nó m2 (último nó)");
        lista.deletarNo(m2);
        lista.imprimirLista();

        System.out.println("Deletando o nó m6 (nó intermediário)");
        lista.deletarNo(m6);
        lista.imprimirLista();

        System.out.println("Adicionando m4 como último nó");
        lista.adicionarUltimoNo(m4);
        lista.imprimirLista();

        // Adicionada antes do primeiro
        lista.adicionarAntesNoEspecifico(m7, m1);
        // Adicionada apos ultimo
        lista.adicionarAposNoEspecifico(m5, m2);
        // Adiciona entre nos
        lista.adicionarAntesNoEspecifico(m7, m3);

        lista.imprimirLista();
        // Deleta primeiro no
        lista.deletarNo(m1);
        // Deleta ultimo no
        lista.deletarNo(m2);
        // Deleta entre nos
        lista.deletarNo(m6);
        //Insere por ultimo
        lista.adicionarUltimoNo(m4);
        lista.imprimirLista();

    }
}
