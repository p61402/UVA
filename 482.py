numOfcases = int(input())

for n in range(numOfcases):
    input()
    index_array = input().split()
    value_array = input().split()
    #print(index_array)
    #print(value_array)
    for i in range(1, len(index_array) + 1):
        for index in index_array:
            if int(index) == i:
                print(value_array[index_array.index(index)])
                break
    if n != numOfcases - 1:
        print()
