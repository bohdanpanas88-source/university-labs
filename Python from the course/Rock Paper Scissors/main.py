rock = '''
    _______
---'   ____)
      (_____)
      (_____)
      (____)
---.__(___)
'''

paper = '''
    _______
---'   ____)____
          ______)
          _______)
         _______)
---.__________)
'''

scissors = '''
    _______
---'   ____)____
          ______)
       __________)
      (____)
---.__(___)
'''

import random

my_choose = int(input("What do you choose? Type 1 for rock, 2 for paper, or 3 for scissors.\n"))
my_choose = my_choose - 1

if 0 <= my_choose <= 2:
    list_figures_name = ["rock", "paper", "scissors"]
    list_figures = [rock, paper, scissors]
    computer_choose = random.randint(1, 2)

    print("Your choose:\n")

    print(list_figures_name[my_choose])
    print(list_figures[my_choose])

    print("Computer choose:\n")
    print(list_figures_name[computer_choose])
    print(list_figures[computer_choose])

    if my_choose == 0:
        if computer_choose == 1:
            print("You lose!")
        elif computer_choose == 2:
            print("You win!")
        elif computer_choose == 0:
            print("Draw")
    if my_choose == 1:
        if computer_choose == 1:
            print("Draw")
        elif computer_choose == 2:
            print("You lose!")
        elif computer_choose == 0:
            print("You win!")
    if my_choose == 2:
        if computer_choose == 1:
            print("You win!")
        elif computer_choose == 2:
            print("Draw")
        elif computer_choose == 0:
            print("You lose!")
else:
    print("Error! Your enter invalid number or something else!")
