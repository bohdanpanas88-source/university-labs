from encodings import undefined
import random

from art import logo
print(logo)

def add(n1, n2):
    return n1 + n2

# TODO write other three functon: subtract, multiply, and divide.

def subtract(n1, n2):
    return n1 - n2

def multiply(n1, n2):
    return n1 * n2

def divide(n1, n2):
    return n1 / n2

# TODO add this four function into a dictionary as the values. Keys = "+", "-", "*", "/".

list_of_operation = {
    "+": add,
    "-": subtract,
    "*": multiply,
    "/": divide,
}



# TODO use the dictionary operations to perform the calculation.
# print(list_of_operation["+"](2,4))

def calculate(value):
    list_numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9, 0]

    print("\n+\n-\n*\n/\n")
    operation = str(input("Pick an operation: "))
    second_number = str(input("What is your second number: "))
    equel = ""
    for number in  list_numbers:
         if not number == list_numbers:
            equel = "NaN"
    for number in list_numbers:
        if not number == list_numbers:
            equel = "Nan"

    if not equel == "NaN":
        if not operation == "+" and not operation == "-" and not operation == "*" and not operation == "/" :
            equel = "Nan"
            operation = "Undefined"
        else:
            equel = float(list_of_operation[operation](float(value), float(second_number)))
    print(f"{value} {operation} {second_number} = {equel}\n")
    return equel

first_number = str(input("What is your first number: "))

ret_number = calculate(first_number)



temp = 1
while  temp == 1:

    contin = ""
    temp2 = 1
    while temp2 == 1:
        contin = input(f"Type 'y to continue calculating with {ret_number} or type 'n' to end calculation: ").lower()
        if  contin == "y" or contin == "n":
            temp2 = 0

    if contin == "n":
        temp = 0
    elif not ret_number == "NaN" and not contin == "n":
        calculate(ret_number)
    else:
        print("Value Nan. The calculation end.")
        temp = 0
