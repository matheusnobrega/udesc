import math

def newton(f, df, x0, n):
  for _ in range(n):
    x0 -= f(x0) / df(x0)
    yield x0

def f(x):
  return math.sqrt(2*9.81*x) * math.tanh( (math.sqrt(2*9.81*x)/2*8.74)*5.87 ) - 6.55 

def df(x):
  return (2.21472 * math.tanh(1.48746 * math.sqrt(x) - 6.55))/math.sqrt(x) + 3.29432 * pow(math.sech(1.48746 * math.sqrt(x) - 6.55),2)


x0 = 1.23
n = 10

resp = list(newton(f, df, x0, n))

iter = [1, 3, 5]



for i in iter:
  print(str(resp[i-1])+',', end="") 
