import csv
from sys import argv, exit


def main():
    database, seq = pre()
    dicSeq = cnt(seq, database[0][1:])
    match(dicSeq, database)


def pre():
    if len(argv) != 3:
        print("missing command-line argument")
        exit(1)

    with open(argv[1], "r") as csvFile:
        reader = csv.reader(csvFile)
        dic = [row for row in reader]

    with open(argv[2], "r") as file:
        seq = file.read()
    return dic, seq


def cnt(s, STR):
    dicSeq = {}
    for st in STR:
        dicSeq[st] = 0
        l = len(st)
        for i in range(len(s)):
            j = i
            curLen = 0
            while s[j:j + l] == st:
                curLen += 1
                j += l
            dicSeq[st] = max(curLen, dicSeq[st])
    return dicSeq


def match(dicSeq, database):
    listSeq = []
    for k in dicSeq:
        listSeq.append(str(dicSeq[k]))
    for row in database:
        if listSeq == row[1:]:
            print(row[0])
            exit(0)
    print("No match")


main()
