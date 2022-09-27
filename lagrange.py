import math

def lagrange(x, y):
  num = len(x)
  coefs = []
  for i in range(num):
    prod = 1
    for j in range(num):
      if i != j:
        prod *= (x[i] - x[j])
    ci = y[i] / prod
    coefs.append(ci)
  return coefs

def pl(t, x, coefs):
  soma = 0
  num = len(coefs)
  for i in range(num):
    prod = 1
    for j in range(num):
      if i != j:
        prod *= (t - x[j])
    prod *= coefs[i]
    soma += prod
  return soma

def poly(x, coefs):
  def f(t):
    return pl(t, x, coefs)
  return f

def func(x):
  return math.exp(-x**2)+math.cos(x)+3 #4 + math.sin(x) - x**2 / 30 #math.exp(math.cos(x)**2) + math.exp(-x**2) + math.log(x)

if __name__ ==  '__main__':
  x = [0.441, 0.744, 1.267, 1.883, 2.319, 2.763, 3.346, 3.906, 4.452, 5.153, 5.749, 5.982, 6.675]

  y = [func(xi) for xi in x]

  c = lagrange(x, y)
  lagr = poly(x, c)
  print(c)
