#Prime Conjecture Project
#This program will display the twin primes between 1 - 10000
import PrimeCalc

def main():
    gap = -1
    pair_n = -1
    set_range = -1

    while gap <= 1 and pair_n <= 1 and set_range <= 2:
        gap = int(input("Gap between two prime numbers: "))
        pair_n = int(input("numbers in pair:"))
        set_range = int(input("the range: "))

    a = PrimeCalc.PrimeC()
    a.calc(gap, pair_n, set_range)
    a.display()


main()
