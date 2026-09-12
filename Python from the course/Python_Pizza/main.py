print(r'''
*******************************************************************************
          |                   |                  |                     |
 _________|________________.=""_;=.______________|_____________________|_______
|                   |  ,-"_,=""     `"=.|                  |
|___________________|__"=._o`"-._        `"=.______________|___________________
          |                `"=._o`"=._      _`"=._                     |
 _________|_____________________:=._o "=._."_.-="'"=.__________________|_______
|                   |    __.--" , ; `"=._o." ,-"""-._ ".   |
|___________________|_._"  ,. .` ` `` ,  `"-._"-._   ". '__|___________________
          |           |o`"=._` , "` `; .". ,  "-._"-._; ;              |
 _________|___________| ;`-.o`"=._; ." ` '`."\ ` . "-._ /_______________|_______
|                   | |o ;    `"-.o`"=._``  '` " ,__.--o;   |
|___________________|_| ;     (#) `-.o `"=.`_.--"_o.-; ;___|___________________
____/______/______/___|o;._    "      `".o|o_.--"    ;o;____/______/______/____
/______/______/______/_"=._o--._        ; | ;        ; ;/______/______/______/_
____/______/______/______/__"=._o--._   ;o|o;     _._;o;____/______/______/____
/______/______/______/______/____"=._o._; | ;_.--"o.--"_/______/______/______/_
____/______/______/______/______/_____"=.o|o_.--""___/______/______/______/____
/______/______/______/______/______/______/______/______/______/______/_____ /
*******************************************************************************
''')
print("Welcome to Treasure Island.")
print("Your mission is to find the treasure.")

where_go = input("Type \"left\" or \"right\"").lower()
if where_go == "right" or where_go == "r":
    print("Fall into a hole.\n\tGame Over")
elif where_go == "left" or where_go == "l":
    what_do = input("Type swim or wait: ").lower()
    if what_do == "swim":
        print("Attacked by trout.\n\tGame Over.")
    elif what_do == "wait" or what_do == "w":
        which_dor = input("Which door you chose? red, blue or yellow: ").lower()
        if which_dor == "red" or which_dor == "r":
            print("Burned by fire.\n\tGame Over.")
        elif which_dor == "blue" or which_dor == "b":
            print("Eaten by beasts.\n\tGame Over.")
        elif which_dor == "yellow" or which_dor == "y":
            print("\tYou Win!")
        else:
            print("\tGame Over")
    else:
        print("Attacked be trout.\n\tGame Over.")
else:
    print("Game Over!")
