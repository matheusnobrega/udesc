import numpy as np
import math

def spline(x, y):
  n = len(x)
  a = {k:v for k, v in enumerate(y)}
  h = {k: x[k+1] - x[k] for k in range(n-1)}

  A = [[1] + [0] * (n-1)]
  for i in range(1, n-1):
    row = [0] * n
    row[i-1] = h[i-1]
    row[i] = 2*(h[i-1]+h[i])
    row[i+1] = h[i]
    A.append(row)
  A.append([0] * (n-1) + [1])

  B = [0]
  for k in range(1, n-1):
    row = 3 * (a[k+1] - a[k])/ h[k] - 3 * (a[k] - a[k-1])/ h[k-1]
    B.append(row)
  B.append(0)
  c = dict(zip(range(n),np.linalg.solve(A, B)))
  
  b = {}
  d = {}
  for k in range(n-1):
    b[k] = (1/h[k]) * (a[k+1] - a[k]) - (h[k]/3) * (2*c[k]+c[k+1])
    d[k] = (c[k+1] - c[k])/(3*h[k])

  s = {}
  eq = {}
  for k in range(n-1):
    eq[k] = f'{a[k]}{b[k]:+}*(x-{x[k]}){c[k]:+}*(x-{x[k]})**2{d[k]:+}*(x-{x[k]})**3'
    s[k] = {'coefs': [a[k], b[k], c[k], d[k]], 'domain': [x[k], x[k+1]]}



  for k, v in eq.items():
    print(f'eq{k}', v)

  for k, v in s.items():
    print(f's{k}', v)
  return s


def f(x):
  return 1/(1+ 25*x**2)

def func(x):
  return 3.663+2.2112934465771668*(x-4.729)-2.25190039203982*(x-4.729)**2+0.6708650414867005*(x-4.729)**3

x =  [0.381, 0.838, 1.489, 2.26, 2.705, 3.105, 3.798, 4.438, 4.729, 5.496, 6.245, 6.722]

y = [5.635, 4.899, 3.558, 3.026, 2.753, 2.954, 3.126, 3.024, 3.663, 4.337, 4.151, 4.205]


valores = [0.513, 0.515, 0.902, 3.521, 5.206]
s = spline(x, y)


print(func(valores[4]))
