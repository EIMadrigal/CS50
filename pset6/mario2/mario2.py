from cs50 import get_int


def main():
    n = getProperInt()
    for i in range(1, n + 1):
        for j in range(1, n + i + 3):
            if (j >= n + 1 - i and j >= 1 and j <= n) or (j >= n + 3 and j <= 2 * n + 2 and j <= i + n + 2):
                print("#", end="")
            else:
                print(" ", end="")
        print()


def getProperInt():
    while True:
        n = get_int("Height: ")
        if n > 0 and n < 9:
            break
    return n


main()
