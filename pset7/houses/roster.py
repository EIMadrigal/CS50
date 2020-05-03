import cs50
from sys import argv, exit


db = cs50.SQL("sqlite:///students.db")

if len(argv) != 2:
    print("missing command-line argument")
    exit(1)


rows = db.execute('''SELECT first, middle, last, birth FROM students
    WHERE house = ? order by last, first''', argv[1])
for row in rows:
    ans = row['first'] + ' '
    if row['middle'] != None:
        ans += row['middle'] + ' '
    ans += row['last'] + ', ' + "born " + str(row['birth'])
    print(ans)
