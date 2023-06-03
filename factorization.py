import sys

def factorize(number):
    factors = []
    divisor = 2

    while divisor <= number:
        if number % divisor == 0:
            factors.append(divisor)
            number //= divisor
        else:
            divisor += 1

    return factors

def factors(filename):
    with open(filename, 'r') as file:
        for line in file:
            number = int(line.strip())
            factors_list = factorize(number)
            factors_str = '*'.join(map(str, factors_list))
            print(f"{number}={factors_str}")

if __name__ == '__main__':
    if len(sys.argv) != 2:
        print("Usage: python factors.py <file>")
        sys.exit(1)

    filename = sys.argv[1]
    factors(filename)
