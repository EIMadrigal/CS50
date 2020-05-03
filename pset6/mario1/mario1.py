from cs50 import get_int


def main():
    h = get_positive_int()
    for i in range(1, h + 1):
        for j in range(1, h + 1):
            if i + j <= h:
                print(" ", end="")
            else:
                print("#", end="")
        print()


def get_positive_int():
    while True:
        n = get_int("Height: ")
        if n > 0 and n < 9:
            break
    return n


main()
