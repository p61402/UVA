def main():
    while True:
        try:
            string = input()
            print(string)
        except EOFError:
            break

if __name__ == "__main__":
    main()
