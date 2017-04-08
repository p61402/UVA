# Run Time: 0.020
def main():
    convert_list = ["",
                    ["B", "F", "P", "V"],
                    ["C", "G", "J", "K", "Q", "S", "X", "Z"],
                    ["D", "T"],
                    ["L"],
                    ["M", "N"],
                    ["R"]]

    no_effect = ["A", "E", "I", "O", "U", "H", "W", "Y"]

    while True:
        try:
            word = input()
        except EOFError:
            break

        sound_ex = []
        previous_sound = 0
        for char in word:
            if char not in no_effect:
                for i in range(1, len(convert_list)):
                    if char in convert_list[i] and i != previous_sound:
                        sound_ex.append(i)
                        previous_sound = i
                        break
            else:
                previous_sound = 0

        for sound in sound_ex:
            print(sound, end="")
        print()


if __name__ == "__main__":
    main()
