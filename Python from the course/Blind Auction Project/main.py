from art import logo
print(logo)

bids_dictionary = {}
# TODO-1: Ask the user for input

max_user_bid = 0
each_bid = True
one_tab = True

while each_bid:
    name_user = str(input("What is your name? "))

    # TODO-2: Save data into dictionary {name: price}

    bids_dictionary[name_user] = int(input("what is your bids? "))

    while one_tab:
        list_of_bids = bids_dictionary[name_user]
        max_user_name = ""
        one_tab = False

    # TODO-3: Whether if new bids need to be added

    value_yes_or_no = True
    while value_yes_or_no:
        another_user_bid = str(input("You need another user bid? (yes or no) ").lower())
        if another_user_bid == "no":
            each_bid = False
            value_yes_or_no = False
        elif another_user_bid == "yes":
            value_yes_or_no = False
        else:
            print("Error. Please enter yes or no.")
        print("\n" * 100)


# TODO-4: Compare bids in dictionary



for bid in bids_dictionary:
    if max_user_bid <= bids_dictionary[bid]:
        max_user_bid = bids_dictionary[bid]
        max_user_name = bid
print(f"Highest user bid {max_user_bid} is {max_user_name}")
