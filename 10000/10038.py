"""
Ranking	Submission	Run Time	Language	Submission Date
21429	19090564	0.160	    PYTH3	    2017-04-01 12:05:49
"""
while True:
    try:
        num = input()
    except EOFError:
        break

    num_list = num.split()
    difference_list = []
    for i in range(1, int(num_list[0])):
        difference_list.append(abs(int(num_list[i]) - int(num_list[i+1])))

    isJoly = True
    for i in range(1, int(num_list[0])):
        if i not in difference_list:
            isJoly = False
            break

    if isJoly:
        print("Jolly")
    else:
        print("Not jolly")

    #print(num_list)
    #print(difference_list)
