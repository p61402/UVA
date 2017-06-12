# Run Time: 0.060
a = [1] * 1001
num = 1
for i in range(1, 1001):
    num *= i
    a[i] = num

while True:
    try:
        x = int(input())
    except EOFError:
        break
    print(str(x) + "!")
    print(a[x])
