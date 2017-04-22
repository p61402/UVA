a = [0] * 5
temp = [0] * 5
solution = []
current_index = 0
used = [False] * 5


def backtracking(i, s):

    if i == 5:
        if s == 23:
            return True
        else:
            return False

    return backtracking(i + 1, s + a[solution[current_index][i]]) or backtracking(i + 1, s - a[solution[current_index][i]]) or backtracking(i + 1, s * a[solution[current_index][i]])


def permutation(n):
    if n == 5:
        solution.append(temp.copy())
        return

    for j in range(5):
        if not used[j]:
            used[j] = True
            temp[n] = j
            permutation(n + 1)
            used[j] = False


permutation(0)

while True:
    line = input().split()
    a[0], a[1], a[2], a[3], a[4] = int(line[0]), int(line[1]), int(line[2]), int(line[3]), int(line[4])
    if a[0] == 0 and a[1] == 0 and a[2] == 0 and a[3] == 0 and a[4] == 0:
        break

    found = False

    for num in range(len(solution)):
        current_index = num
        if backtracking(1, a[solution[current_index][0]]):
            found = True
            break

    if found:
        print("Possible")
    else:
        print("Impossible")
