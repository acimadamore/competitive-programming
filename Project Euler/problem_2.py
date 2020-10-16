fib_prev_prev, fib_prev, fib_act = 1, 2, 0

even_sum = 2

while fib_act < 4E6:
    if fib_act % 2 == 0:
        even_sum += fib_act

    fib_act = fib_prev_prev + fib_prev

    fib_prev_prev, fib_prev = fib_prev, fib_act

print(even_sum)
