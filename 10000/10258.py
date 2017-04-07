def max_solved(c):
    maximum = 0
    for value in c.values():
        if value > maximum:
            maximum = value
    return maximum


def min_solved(c):
    minimum = 999999
    for value in c.values():
        if value < minimum:
            minimum = value
    return minimum


def exist_contestant(c):
    if c not in contestant_solved_problems:
        contestant_solved_problems[c] = []
        contestant_times[c] = 0
        penalty_times[c] = {}


num_of_test_cases = int(input())
input()
for test_case in range(num_of_test_cases):

    contestant_solved_problems = {}
    contestant_times = {}
    penalty_times = {}

    while True:
        try:
            contestant, problem, time, state = input().split()
        except:
            break

        contestant = int(contestant)
        problem = int(problem)
        time = int(time)

        if state == "C":
            exist_contestant(contestant)
            if problem not in contestant_solved_problems[contestant]:
                contestant_solved_problems[contestant].append(problem)
            else:
                continue

            if problem not in penalty_times[contestant]:
                penalty_times[contestant][problem] = 0
            else:
                penalty_times[contestant][problem] += 20

            contestant_times[contestant] += time + penalty_times[contestant][problem]

        elif state == "I":
            exist_contestant(contestant)

            if problem not in penalty_times[contestant]:
                penalty_times[contestant][problem] = 0
            else:
                penalty_times[contestant][problem] += 20

        else:
            exist_contestant(contestant)

    for user in contestant_solved_problems.keys():
        contestant_solved_problems[user] = len(contestant_solved_problems[user])

    contestant_solved_problems = dict(sorted(contestant_solved_problems.items(), key=lambda x: x[0]))

    min_solved_problems = min_solved(contestant_solved_problems)

    while True:
        max_solved_problems = max_solved(contestant_solved_problems)
        wait_dict = {}
        for user in contestant_solved_problems:
            if contestant_solved_problems[user] == max_solved_problems:
                wait_dict[user] = contestant_times[user]

        wait_list = sorted(wait_dict.items(), key=lambda x: x[1])

        for element in wait_list:
            index = element[0]
            print("{0} {1} {2}".format(index, contestant_solved_problems[index], contestant_times[index]))
            del contestant_solved_problems[index]

        if max_solved_problems == min_solved_problems:
            break

    if test_case != num_of_test_cases - 1:
        print()

