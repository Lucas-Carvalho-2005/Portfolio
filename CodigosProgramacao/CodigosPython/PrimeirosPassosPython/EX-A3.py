#!/usr/bin/python3

print(" --- EXEMPLO DE ALGORITMO C) --- \n")

N1 = input("Digite o valor da primeira nota: ")
N2 = input("Digite o valor da segunda nota: ")

M = ( float(N1) + float(N2) ) / 2

if M >= 7:
    print("\nO aluno está com média " + str(M) + " e está APROVADO.")

else:
    print("\nO aluno está com média " + str(M) + " e está REPROVADO.")