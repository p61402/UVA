# Run Time: 2.190
def main():
    while True:
        turn = input()
        if turn == "-1":
            break

        print("Round {0}".format(turn))

        answer = input()
        guess = input()
        answer_dict = {}
        for c in answer:
            if c in answer_dict.keys():
                answer_dict[c] += 1
            else:
                answer_dict[c] = 1
        correct = len(answer)
        wrong_times = 0
        state = "not_finished"

        has_guessed = []
        for char in guess:
            if char in has_guessed:
                continue
            elif char in answer_dict.keys() and answer_dict[char] != 0:
                correct -= answer_dict[char]
                answer_dict[char] = 0
                has_guessed.append(char)
            else:
                wrong_times += 1
                has_guessed.append(char)

            if correct == 0:
                state = "win"
                break

        if wrong_times >= 7:
            state = "lose"

        if state == "win":
            print("You win.")
        elif state == "lose":
            print("You lose.")
        else:
            print("You chickened out.")


if __name__ == "__main__":
    main()
