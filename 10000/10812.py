"""
Ranking	Submission	Run Time	Language	Submission Date
4242	19085230	0.000	    PYTH3	    2017-03-31 13:59:52
"""
numOfcases = int(input())

for i in range(numOfcases):
    z1, z2 = input().split()
    z1 = float(z1)
    z2 = float(z2)
    x = int(0.5 * (z1 + z2))
    y = int(z1 - x)
    if (z1 + z2) % 2 == 0 and z1 >= z2:
        print("{0} {1}".format(x, y))
    else:
        print("impossible")
