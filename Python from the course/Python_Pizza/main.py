print("Welcome to Python Pizza Deliveries!")
size = input("What size pizza do you want? S, M or L: ")
pepperoni = input("Do you want pepperoni on your pizza? Y or N: ")
extra_cheese = input("Do you want extra cheese? Y or N: ")

final_price = 0

if size == "S":
    final_price += 15
    if pepperoni == "Y":
        final_price += 2
elif size == "M":
    final_price += 20
    if pepperoni == "Y":
        final_price += 3
elif size == "L":
    final_price += 25
    if pepperoni == "Y":
        final_price += 3
else:
    print("Sorry. You type the wrong inputs!")



if extra_cheese == "Y":
    final_price += 1

print(f"Your final bill is: ${final_price}.")
