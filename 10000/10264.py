# Run Time: 0.310
def main():
    while True:
        try:
            n = int(input())
        except EOFError:
            break

        corners_weight = []
        for i in range(2 ** n):
            corners_weight.append(int(input()))

        potency = [0 for x in range(2 ** n)]
        for i in range(2 ** n):
            for j in range(n):
                neighbor = i ^ (1 << j)
                potency[i] += corners_weight[neighbor]

        max_potency = 0
        for i in range(2 ** n):
            for j in range(n):
                neighbor = i ^ (1 << j)
                max_potency = max(max_potency, potency[i] + potency[neighbor])

        print(max_potency)


if __name__ == "__main__":
    main()
