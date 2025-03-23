#!/usr/bin/python3

print("Exemplo de Algoritmo b)\n")

n1 = input("Digite o primeiro número: ")
n2 = input("Digite o segundo número: ")

if (n2 == '0'):
    print("Impossível dividir um número por 0.")

else:
    d = int(n1) // int(n2)
    print("\nO resultado da divisão é:", d) 