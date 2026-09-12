from menu import Menu
from coffee_maker import CoffeeMaker
from money_machine import MoneyMachine

menu = Menu()
money_machine = MoneyMachine()
ingredients = CoffeeMaker()

is_on = True

ingredients.report()
money_machine.report()

while is_on:
    option = menu.get_items()
    choice = input(f"What would you like? ({option}):")
    if choice == "off":
        is_on = False
    elif choice == "report":
        ingredients.report()
        money_machine.report()
    else:
        drink = menu.find_drink(choice)
        if ingredients.is_resource_sufficient(drink):
            if money_machine.make_payment(drink.cost):
                ingredients.make_coffee(drink)from menu import Menu
from coffee_maker import CoffeeMaker
from money_machine import MoneyMachine

menu = Menu()
money_machine = MoneyMachine()
ingredients = CoffeeMaker()

is_on = True

ingredients.report()
money_machine.report()

while is_on:
    option = menu.get_items()
    choice = input(f"What would you like? ({option}):")
    if choice == "off":
        is_on = False
    elif choice == "report":
        ingredients.report()
        money_machine.report()
    else:
        drink = menu.find_drink(choice)
        if ingredients.is_resource_sufficient(drink):
            if money_machine.make_payment(drink.cost):
                ingredients.make_coffee(drink)
