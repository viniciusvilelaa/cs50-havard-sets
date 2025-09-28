def main():
    while True:
        n = float(input("Change owed: "))
        if n > 0:
            break

    n_regularized = round(n * 100)
    count = 0
    print(n_regularized)

    denominations = [25, 10, 5, 1]

    for coin in denominations:
        while n_regularized >= coin:
            n_regularized = n_regularized - coin
            count += 1

    print(count)


main()
