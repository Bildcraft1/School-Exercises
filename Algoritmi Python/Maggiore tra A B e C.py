# coding=utf-8
# Maggiore tra A e B

# Valori di Input
a = int(input("Inserisci il primo numero: "))
b = int(input("Inserisci il secondo numero: "))
c = int(input("Insersci il terzo numero: "))

if a > b and a > c:
    print("Il valore maggiore è A")

elif a==b and b==c:
    print("I tre valori sono uguali")

elif b > c:
    print("Il valore maggiore è B")

else: 
    print("Il valore maggiore è C")
   
