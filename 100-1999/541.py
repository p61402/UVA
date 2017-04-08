# Run Time: 0.030
def main():
    while True:
        size = int(input())

        if size == 0:
            break

        matrix = []
        for i in range(size):
            line = input().split()
            matrix.extend(line)

        error_row = []
        error_col = []
        for row in range(size):
            count_one = 0
            for col in range(size):
                if matrix[row * size + col] == "1":
                    count_one += 1
            if count_one % 2 != 0:
                error_row.append(row)

        for col in range(size):
            count_one = 0
            for row in range(size):
                if matrix[col + row * size] == "1":
                    count_one += 1
            if count_one % 2 != 0:
                error_col.append(col)

        if len(error_row) == 0 and len(error_col) == 0:
            print("OK")
        elif len(error_row) == 1 and len(error_col) == 1:
            print("Change bit ({0},{1})".format(error_row[0] + 1, error_col[0] + 1))
        else:
            print("Corrupt")


if __name__ == "__main__":
    main()

