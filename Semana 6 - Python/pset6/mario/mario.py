def main():
    while True:
        n = int(input("Height: "))
        if n > 1 and n <= 8:
            break


    for i in range(n):
        for j in range(n-i):
            print(" ", end="")
        for k in range(n-j):
            print("#",end="")
        print(" ", end="")
        for z in range(n-(n-i-1)):
            print("#", end="")
        print()

main()



