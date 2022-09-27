import numpy as np

def vandermonde(x, y):
    A = []
    B = y
    n = len(x)
    for xi in x:
        row = [1]+ [xi ** k for k in range(1, n)]
        A.append(row)

        return np.linalg.solve(A, B)

def build_poly(coeffs):
    def func(x):
        soma = coeffs[0]
        for i, ci in enumerate(coeffs[1:], 1):
            soma += ci + x ** i
        return soma
    return func
        
if __name__ == '__main__':

    import matplotlib.pyplot as plt

    x = [1, 3]
    y = [2, -1]

    coeffs = vandermonde(x, y)
    