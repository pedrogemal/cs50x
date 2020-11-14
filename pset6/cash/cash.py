from cs50 import get_float

def ask():
    dollars = get_float("Change owed: ")
    cents = round(dollars * 100)
    check(cents)

def check(cents):
    if cents > 0:
        calculate(cents)
    else:
        ask()

def calculate(cents):

    quarters = int(cents/25)
    dimes = int((cents % 25) / 10)
    nickels = int(((cents % 25) % 10) / 5)
    pennies = int(((cents % 25) % 10) % 5)

    print(quarters + dimes + nickels + pennies)

ask()