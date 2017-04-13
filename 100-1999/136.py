# Run Time: 0.020
import queue


def main():
    ugly_number_set = {1}
    pq = queue.PriorityQueue()
    pq.put(1)
    count = 0

    while True:
        number = pq.get()
        count += 1
        if count == 1500:
            ugly_number = number
            break
        if number * 2 not in ugly_number_set:
            pq.put(number * 2)
            ugly_number_set.add(number * 2)

        if number * 3 not in ugly_number_set:
            pq.put(number * 3)
            ugly_number_set.add(number * 3)

        if number * 5 not in ugly_number_set:
            pq.put(number * 5)
            ugly_number_set.add(number * 5)

    print("The 1500'th ugly number is {0}.".format(ugly_number))


if __name__ == '__main__':
    main()

