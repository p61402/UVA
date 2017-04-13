# Run Time: 0.010
def main():
    current_distance = 0
    is_beginning_time = True
    initial_hour, initial_minute, initial_second, speed = 0, 0, 0, 0
    prev_hour, prev_minute, prev_second, prev_speed = 0, 0, 0, 0
    while True:
        try:
            line = input()
            if len(line) > 8:
                initial_time, speed = line.split()
                initial_hour, initial_minute, initial_second = initial_time.split(":")
                initial_hour, initial_minute, initial_second = \
                    int(initial_hour), int(initial_minute), int(initial_second)
                speed = int(speed)

                if not is_beginning_time:
                    s = initial_second - prev_second
                    m = initial_minute - prev_minute
                    h = initial_hour - prev_hour
                    if s < 0:
                        s += 60
                        m -= 1
                    if m < 0:
                        m += 60
                        h -= 1
                    t = h + m/60 + s/3600
                    current_distance += t * prev_speed

                prev_hour, prev_minute, prev_second, prev_speed = initial_hour, initial_minute, initial_second, speed
                is_beginning_time = False
                continue
            else:
                elapse_time = line
                elapse_hour, elapse_minute, elapse_second = elapse_time.split(":")
                elapse_hour, elapse_minute, elapse_second = int(elapse_hour), int(elapse_minute), int(elapse_second)

                if is_beginning_time:
                    print(elapse_time, "0.00 km")
                    prev_hour, prev_minute, prev_second, prev_speed = elapse_hour, elapse_minute, elapse_second, 0
                    is_beginning_time = False
                    continue
        except EOFError:
            break

        s = elapse_second - initial_second
        m = elapse_minute - initial_minute
        h = elapse_hour - initial_hour

        if s < 0:
            s += 60
            m -= 1

        if m < 0:
            m += 60
            h -= 1

        h += m / 60 + s / 3600

        distance = current_distance + h * speed

        print(elapse_time, "{0:.2f}".format(distance), "km")


if __name__ == '__main__':
    main()
