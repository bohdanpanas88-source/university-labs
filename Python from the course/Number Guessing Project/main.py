import random
from art import logo

def function_play_game(number, ran_number):
    while not number == 0:
        user_guess_input = input("Make a guess: ")

        if not user_guess_input.isdigit():
            print("Guess again.")
            number -= 1
            print(f"You have {number} attempts remaining to guess the number.")
        elif int(user_guess_input) == ran_number:
            print(f"You got it! The answer was {ran_number}.")
            return
        elif int(user_guess_input) > ran_number:
            print("Too high!")
            print("Guess again.")
            number -= 1
            print(f"You have {number} attempts remaining to guess the number.")
        elif int(user_guess_input) < ran_number:
            print("Too low!")
            print("Guess again.")
            number -= 1
            print(f"You have {number} attempts remaining to guess the number.")

    print("I'll definitely be lucky next time! Try again.")
    return

def function_difficulty(ch_dif):
    while True:
        if ch_dif == "easy":
            print("You have 10 attempts remaining to guess the number.")
            return 10
        elif ch_dif == "hard":
            print("You have 5 attempts remaining to guess the number.")
            return 5
        else:
            ch_dif = input("Please, input difficulty. Type 'easy' or 'hard': ").lower()

def function_continuous(p_again):
    while True:
        if p_again == "y":
            print("\n" * 20)
            return True
        elif p_again == "n":
            print("Thank you for playing. Goodbye!")
            return False
        else:
            p_again = input("Input 'y' if you want continuous the game or 'n' if you want exit: ").lower()

def game_run():
    loop_game = True
    while loop_game:
        print(logo)
        print("Welcome to the Number Guessing Game!")

        random_number = random.randint(1, 101)

        print(f"This is random number: {random_number}")
        print("I'm thinking of a number between 1 and 100.")
        chose_difficulty = input("Choose a difficulty.Type 'easy' or 'hard': ").lower()

        difficulty_numbers = function_difficulty(chose_difficulty)
        function_play_game(difficulty_numbers,random_number)
        play_again = input("Do you want to play again? (y/n): ").lower()
        loop_game = function_continuous(play_again)



game_run()
