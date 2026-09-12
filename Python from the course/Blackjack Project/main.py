import random
from art import logo

def computer_cards_function(computer_sum, computer_card, cards):

    gaps = 2
    while computer_sum < 17:
        computer_card[gaps] = random.choice(cards)

        if computer_card[gaps] == 11:
            computer_card[gaps] = ace_check(summ = computer_sum, value = computer_card[gaps])
            computer_sum += computer_card[gaps]
        else:
            computer_sum += computer_card[gaps]
        gaps += 1

    return computer_sum

def my_cards_function(my_sum, mine_card, cards, computer_card):

    gaps = 2
    value = True
    while value and my_sum < 21:
        mine_card[gaps] = random.choice(cards)

        if mine_card[gaps] == 11:
            mine_card[gaps] = ace_check(summ = my_sum, value = mine_card[gaps])
            my_sum += mine_card[gaps]
        else:
            my_sum += mine_card[gaps]

        if my_sum < 21:
            print(f"Your cards: [{mine_card[0]}, {mine_card[1]}], current score: {my_sum} ")
            print(f"Computer's first card: {computer_card[0]}")

            get_or_pass = (input("Type 'y' to get another card, type 'n' to pass: "))
            if get_or_pass == 'n':
                value = False
            gaps += 1
    return my_sum

def comparison(computer_sum, my_sum):
    if computer_sum <= 21:
        if computer_sum == my_sum:
            print("draw")
        elif computer_sum > my_sum:
            print("You lose!")
        elif computer_sum < my_sum:
            print("You win!")
    else:
        print("You win!")

def ace_check(summ, value):
    temp_sum = summ + value
    if temp_sum > 21:
        return 1
    else:
        return  11

def game_blackjack():
    print(logo)

    cards = [11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10]
    mine_cards = [0, 0, "", "", "", "", ""]  # trash
    computer_card = [0, 0, "", "", "", "", ""]  # trash

    my_sum = 0
    computer_sum = 0

    for card in range(0, 2):
        mine_cards[card] = random.choice(cards)

        if mine_cards[card] == 11:
            mine_cards[card] = ace_check(summ = my_sum, value = mine_cards[card])
            my_sum += mine_cards[card]
        else:
            my_sum += mine_cards[card]

        computer_card[card] = random.choice(cards)
        if computer_card[card] == 11:
            computer_card[card] = ace_check(summ = computer_sum, value = computer_card[card])
            computer_sum += computer_card[card]
        else:
            computer_sum += computer_card[card]

    print(f"Your cards: [{mine_cards[0]} {mine_cards[1]}], current score: {my_sum} ")
    print(f"Computer's first card: {computer_card[0]}")

    get_or_pass = (input("Type 'y' to get another card, type 'n' to pass: "))
    if get_or_pass == 'y':
        my_sum = my_cards_function(my_sum = my_sum,mine_card = mine_cards, cards = cards, computer_card = computer_card)
        if my_sum > 21:
            print(f"Your cards: [{mine_cards[0]}, {mine_cards[1]}, {mine_cards[2]} {mine_cards[3]} {mine_cards[4]}], final score: {my_sum} ")
            print(f"Computer's cards: [{computer_card[0]} {computer_card[1]}], final score: {computer_sum} ")

            print("You lose!")
        elif my_sum <= 21:
            if computer_sum < 17:
                computer_sum = computer_cards_function(computer_sum = computer_sum, computer_card = computer_card , cards = cards)

            print(f"Your cards: [{mine_cards[0]}, {mine_cards[1]}, {mine_cards[2]} {mine_cards[3]} {mine_cards[4]}], final score: {my_sum} ")
            print(f"Computer's cards: [{computer_card[0]} {computer_card[1]} {computer_card[2]} {computer_card[3]} {computer_card[4]}], final score: {computer_sum} ")

            comparison(computer_sum = computer_sum, my_sum = my_sum)
    else:
        computer_sum = computer_cards_function(computer_sum=computer_sum, computer_card=computer_card, cards=cards)

        print(f"Your cards: [{mine_cards[0]}, {mine_cards[1]}, {mine_cards[2]}], final score: {my_sum} ")
        print(f"Computer's cards: [{computer_card[0]} {computer_card[1]} {computer_card[2]} {computer_card[3]} {computer_card[4]}], final score: {computer_sum} ")

        comparison(computer_sum=computer_sum, my_sum=my_sum)

value_while = True
while value_while:
    play_game = input("Do you want to play a game of Blackjack? Type 'y' or 'n': ")
    if play_game == "y":
            game_blackjack()
    elif  play_game == "n":
        print("Thank you for playing. Goodbye!")
        value_while = False
    else:
        print("Please enter 'y' or 'n': ")
