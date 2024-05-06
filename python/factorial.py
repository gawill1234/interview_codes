import sys

if __name__ == "__main__":

    print("Enter an integer: ")
    n = int(input())
    print(n)

    # show error if the user enters a negative integer
    if (n < 0):
        print("Error! Factorial of a negative number doesn't exist.")
    else:
        i = 1
        factorial = 1
        while (i <= n):
           factorial *= i
           i += 1
        print("Factorial of ", n, " = ", factorial)

    sys.exit(0)
