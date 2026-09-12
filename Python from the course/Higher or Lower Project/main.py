from art import logo, vs
from game_data import data
import random

USER_SCORE = 0

print(logo)

def game_over():
    print(logo)
    print(f"Sorry, that's wrong. Final Score: {USER_SCORE}")
    return 0


def comparison(in_user, f_blogger, s_blogger):
    global USER_SCORE
    if f_blogger['follower_count'] > s_blogger['follower_count']:
        if 'A' == in_user:
            USER_SCORE += 1
            print(f"\n" * 20)
            print(logo)
            print(f"You right! Current score: {USER_SCORE}")
            return True
        else:
            print(f"\n" * 20)
            print(logo)
            print(f"Sorry, that's wrong. Final Score: {USER_SCORE}")
            return False
    if s_blogger['follower_count'] > f_blogger['follower_count']:
        if 'B' == in_user:
            print(f"\n" * 20)
            print(logo)
            USER_SCORE += 1
            print(f"You right! Current score: {USER_SCORE}")
            return True
        else:
            print(f"\n" * 20)
            print(logo)
            print(f"Sorry, that's wrong. Final Score: {USER_SCORE}")
            return False


def function_game():
    first_blogger = random.choice(data)
    continue_game = True
    while continue_game:
        second_blogger = random.choice(data)

        print(f"Compare A: {first_blogger['name']}, a {first_blogger['description']}, from {first_blogger['country']}")
        print(vs)
        print(f"Against B: {second_blogger['name']}, a {second_blogger['description']}, from {second_blogger['country']}")
        input_user = str(input("Who was more followers? Type 'A' or 'B' ")).upper()
        continue_game = comparison(input_user, first_blogger, second_blogger)
        first_blogger = second_blogger

function_game()
