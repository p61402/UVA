# Run Time: 0.080
if __name__ == "__main__":

    transition_dict = {"+y": {"+x": "+y", "-x": "-y", "+y": "-x", "-y": "+x", "+z": "+z", "-z": "-z"},
                       "-y": {"+x": "-y", "-x": "+y", "+y": "+x", "-y": "-x", "+z": "+z", "-z": "-z"},
                       "+z": {"+x": "+z", "-x": "-z", "+y": "+y", "-y": "-y", "+z": "-x", "-z": "+x"},
                       "-z": {"+x": "-z", "-x": "+z", "+y": "+y", "-y": "-y", "+z": "+x", "-z": "-x"}}

    while True:
        lengthOfWire = int(input())

        if lengthOfWire == 0:
            break

        command = input().split()
        command.insert(0, "nothing")

        pos = "+x"
        for i in range(1, lengthOfWire):
            if command[i] == "No":
                continue
            pos = transition_dict[command[i]][pos]

        print(pos)
