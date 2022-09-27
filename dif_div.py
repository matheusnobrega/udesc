#DIFERENÇA DIVIDIDAS
def dif_div(x, y):
  num = len(x)
  Y = [yi for yi in y]
  coefs = [y[0]]
  for j in range(num - 1):
    for i in range(num -1 - j):
      numer = Y[i + 1] - Y[i]
      denom = x[i + 1 + j] - x[i]
      div = numer/denom  
      Y[i] = div
    coefs.append(Y[0])
  return coefs

def func(x):
  return  math.cos(x + math.sqrt(math.log(x**2)))  #math.cos(x)**3 + 2* math.cos(x)**2 + 1 #1 /(1+ 25*x**2)

if __name__ ==  '__main__':
  x = [1.439, 1.833, 2.017, 2.325, 2.571, 2.678, 3.023, 3.251, 3.534, 3.588, 4.015, 4.191, 4.457, 4.632, 4.924]
  y = [func(xi) for xi in x]

  coefs = dif_div(x, y)
  print(coefs)
