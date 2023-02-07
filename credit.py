import sys


def main():
    while True:
        # get input from user and define input as an integer
        number = input("Number: ")
        n = int(number)

        # count the amount of integers from the number given
        counter = len(number)

        # if number given does not equate to a card number the print invalid
        if counter != 13 and counter != 15 and counter != 16:
            print("INVALID")
            sys.exit()

        # use modulus(%) and division(//) operators to get last and second last digit
        # declaration of integers as odd and even starting from the back to separate the two patterns
        odd = 0
        even = 0
        i = n
        sum = 0

        # use while loop to continue looping the calculation to get the subsequent patterns
        while i > 0:
            mod_odd = i % 10
            i = i // 10
            odd = odd + mod_odd

            mod_even = i % 10
            i = i // 10
            mod_even = mod_even * 2
            even = even + (mod_even % 10) + (mod_even // 10)

        # add the final numbers in the calculation loop to get the final sum for the algorithm
        sum = odd + even

        # if second digit does not equal to 0 then print invalid to avoid error
        if sum % 10 != 0:
            print("INVALID")
            sys.exit()

        # get first two digits
        first = int(number[0])
        second = int(number[1])

        # if first digit is 4, then VISA
        if first == 4:
            print("VISA")

        # if first digit is 3 and second digit is either 4 or 7 then AMEX
        elif (first == 3) and (second == 4 or second == 7):
            print("AMEX")

        # if first digit is 5 and second digit is between 1 to 5 then MASTERCARD
        elif (first == 5) and (second > 0 and second < 6):
            print("MASTERCARD")

        # else print invalid to avoid error
        else:
            print("INVALID")

        sys.exit()


main()