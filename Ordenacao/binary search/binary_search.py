def binary_search(lista, alvo):
    metade = len(lista) // 2
    print(f"Lista: {lista}")
    if metade == 0:
        print("Não encontrado")
        return;
    
    if lista[metade] > alvo:
        return binary_search(lista[:metade], alvo)
    
    if lista[metade] < alvo:
        return binary_search(lista[metade:], alvo)
    
    if lista[metade] == alvo:
        return lista[metade]
    

lista = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
alvo = 4

resultado = binary_search(lista, alvo)
print(f"Resultado: {resultado}")