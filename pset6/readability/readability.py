import cs50


def main():
    input = cs50.get_string("Text: ")
    cntLetter = countLetter(input)
    cntWord = countWord(input)
    cntSentence = countSentence(input)
    L = 100.0 * cntLetter / cntWord
    S = 100.0 * cntSentence / cntWord
    idx = (int)(0.0588 * L - 0.296 * S - 15.8 + 0.5)
    if idx >= 16:
        print("Grade 16+")
    elif idx < 1:
        print("Before Grade 1")
    else:
        print("Grade %d" % idx)


def countLetter(s):
    cnt = 0
    for c in s:
        if c.isalpha():
            cnt += 1
    return cnt


def countWord(s):
    cnt = 0
    for c in s:
        if c == ' ':
            cnt += 1
    return cnt + 1


def countSentence(s):
    cnt = 0
    for c in s:
        if c == '.' or c == '!' or c == '?':
            cnt += 1
    return cnt


main()
