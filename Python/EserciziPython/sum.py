def multiply_or_addition(n1, n2):
    product = (int(n1) * int(n2))
    if (product <= 100):
        return product
    else:
        return int(n1) + int(n2)


number1 = input("Inserisci il primo numero:")
number2 = input("Inserisci il secondo numero:")

print(f"Il risultato è {multiply_or_addition(number1, number2)}")

