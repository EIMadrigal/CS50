from cs50 import get_float


def main():
    change = getCash() * 100
    num = 0
    while change:
        if change >= 25:
            change -= 25
        elif change >= 10:
            change -= 10
        elif change >= 5:
            change -= 5
        else:
            change -= 1
        num += 1
    print(num)


def getCash():
    while True:
        money = get_float("Change owed: ")
        if money > 0:
            break
    return money


main()
