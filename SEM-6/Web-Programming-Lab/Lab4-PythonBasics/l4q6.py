def power(x, n):
    pow = 1
    for i in range(n):
        pow = pow * x
    return pow

if __name__ == '__main__':
    x = 2
    n = 3
    print(power(x, n))