import cs50


def main():
    n = getCard()
    check(n)


def check(digits):
    candidate = 0
    if len(digits) == 15 and digits[0] == '3' and (digits[1] == '4' or digits[1] == '7'):
        candidate = 1
    elif len(digits) == 16 and digits[0] == '5' and (digits[1] == '1' or digits[1] == '2' or digits[1] == '3' or digits[1] == '4' or digits[1] == '5'):
        candidate = 2
    elif digits[0] == '4':
        candidate = 3

    digits = digits[::-1] # reverse string
    if candidate:
        sum = 0
        for i in range(len(digits)):
            if i & 1:
                if digits[i] >= '5':
                    sum = sum + 1 + (2 * int(digits[i])) % 10
                else:
                    sum += 2 * int(digits[i])
            else:
                sum += int(digits[i])
        if sum % 10 == 0:
            if candidate == 1:
                print("AMEX")
            elif candidate == 2:
                print("MASTERCARD")
            elif candidate == 3:
                print("VISA")
        else:
            print("INVALID")
    else:
        print("INVALID")


def getCard():
    n = cs50.get_string("Number: ")
    return n


main()
