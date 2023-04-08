# Import 'get_float' function from cs50
from cs50 import get_float


def main():

    # Ask how many cents the customer is owed
    cents = get_cents()

    # Calculate the number of quarters to give the customer
    quarters = calculate_quarters(cents)
    cents -= quarters * 25

    # Calculate the number of dimes to give the customer
    dimes = calculate_dimes(cents)
    cents -= dimes * 10

    # Calculate the number of nickels to give the customer
    nickels = calculate_nickels(cents)
    cents -= nickels * 5

    # Calculate the number of pennies to give the customer
    pennies = calculate_pennies(cents)

    # Print total number of coins to give the customer
    print(quarters + dimes + nickels + pennies)


# Function for getting the input from the user
def get_cents():
    while True:
        cents = get_float("Change owed: ")
        if not cents <= 0.00:
            cents *= 100
            return cents


# Function to calculate how many quarter coins are needed
def calculate_quarters(cents):
    quarters = 0
    while cents >= 25:
        cents -= 25
        quarters += 1
    return quarters


# Function to calculate how many dime coins are needed
def calculate_dimes(cents):
    dimes = 0
    while cents >= 10:
        cents -= 10
        dimes += 1
    return dimes


# Function to calculate how many nickel coins are needed
def calculate_nickels(cents):
    nickels = 0
    while cents >= 5:
        cents -= 5
        nickels += 1
    return nickels


# Function to calculate how many penny coins are needed
def calculate_pennies(cents):
    pennies = 0
    while cents >= 1:
        cents -= 1
        pennies += 1
    return pennies


# 'Prototype' function to call main
main()