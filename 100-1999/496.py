#Run Time: 0.020
while True:
    try:
        list_A = input().split()
    except EOFError:
        break

    list_B = input().split()

    set_A = set(list_A)
    set_B = set(list_B)

    lengthOfA_join_B = len(set_A & set_B)
    if lengthOfA_join_B == len(set_A) and lengthOfA_join_B == len(set_B):
        print("A equals B")
    elif lengthOfA_join_B == len(set_A):
        print("A is a proper subset of B")
    elif lengthOfA_join_B == len(set_B):
        print("B is a proper subset of A")
    elif lengthOfA_join_B == 0:
        print("A and B are disjoint")
    else:
        print("I'm confused!")
