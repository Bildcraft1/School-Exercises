# Calcolare l'area e il perimetro di un triangolo dati i due cateti

# Importo le librerie necessarie
import math

print("Calcolo dell'area di un triangolo rettangolo noti i due cateti\n")

# Variabili di Input
c1 = float(input("Digita il primo cateto: "))

while c1 <= 0:
    print("\nMisura del cateto 1 errata: deve essere positivo. ")
    c1 = float(input("Riprova: "))
else:
    print("\nCateto 1 corretto")

c2 = float(input("\nDigita il secondo cateto: "))

while c2 <= 0:
    print("\nMisura del cateto 2 errata: deve essere positivo. ")
    c2 = float(input("Riprova: "))
else:
    print("\nCateto 2 corretto")

# Formula da applicare
area = (c1*c2)/2

perimetro = c1 + c2 + math.sqrt(c1**2 + c2**2)

print("\nIl perimetro di un triangolo rettangolo dato Cateto 1 =",c1,"e Cateto 2 =",c2,"vale:", area)
print("e il suo perimetro vale ",perimetro)
