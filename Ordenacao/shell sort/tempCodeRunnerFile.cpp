for (int i = gap; i < t; i++){
            int temp = lista[i];
            int j;

            for (j = i; j >= gap && lista[j - gap] > lista[j]; j -= gap){
                lista[j] = lista[j - gap];
            }
            lista[j] = temp;
        