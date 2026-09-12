CONTINUOUS = True

MENU = {
    "espresso": {
        "ingredients": {
            "water": 50,
            "coffee": 18,
        },
        "cost": 1.5,
    },
    "latte": {
        "ingredients": {
            "water": 200,
            "milk": 150,
            "coffee": 24,
        },
        "cost": 2.5,
    },
    "cappuccino": {
        "ingredients": {
            "water": 250,
            "milk": 100,
            "coffee": 24,
        },
        "cost": 3.0,
    }
}

resources = {
    "water": 300,
    "milk": 200,
    "coffee": 100,
    "money": 0
}



def preparation(water, coffee, milk, name):
    resources["water"] -= water
    resources["milk"] -= milk
    resources["coffee"] -= coffee
    print(f"Here is your {name} Enjoy!")

def audit_products(w,c,m):
    if w > resources["water"]:
        print("Sorry there is not enough water.")
        return False
    elif c > resources["coffee"]:
        print("Sorry there is not enough coffee.")
        return False
    elif m > resources["milk"]:
        print("Sorry there is not enough milk.")
        return False
    else:
        return True

def function_drinking(water, coffee, milk,cost,name):
    value = audit_products(water, coffee, milk)
    Sum = 0

    if value:
        print("Please insert coins.")
        quarters = int(input("How many quarters? ")) * 0.25
        dimes = int(input("How many dimes? ")) * 0.10
        nickles =  int(input("How many nickles? ")) * 0.05
        pennies = int(input("How many pennies? ")) * 0.01
        Sum = quarters + dimes + nickles + pennies
        if Sum >= cost:
            resources["money"] += cost
            print(f"Here is ${Sum - MENU[name]['cost']} in change.")
            preparation(water,coffee,milk,name)
        else:
            print("Sorry there is not enough money. Money refunded.")


def function_processing():
    global CONTINUOUS
    while CONTINUOUS:
        user_choice = str(input("What would you like? (espresso/latte/cappuccino): ")).lower()
        if user_choice == "report":
            print(f" Water: {resources['water']}ml \n"
                  f" Milk: {resources['milk']}ml \n"
                  f" Coffee: {resources['coffee']}ml \n"
                  f" Money: {resources['money']}")
        elif user_choice == "espresso":
            function_drinking(50,18, 0,1.5, 'espresso')
        elif user_choice == "latte":
            function_drinking(200,24, 150,2.5, 'latte')
        elif user_choice == "cappuccino":
            function_drinking(250,24, 100,3.0, 'cappuccino')
        elif user_choice == "off":
            CONTINUOUS = False
        else:
            print("Please enter a valid option")


function_processing()


