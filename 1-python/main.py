import sys, random
from time import *

n = 4096

# Generate matrices
A = [[random.random() for row in range(n)] for col in range(n)]
B = [[random.random() for row in range(n)] for col in range(n)]
C = [[0 for row in range(n)] for col in range(n)]

start_time = time()

for i in range(n):
  for j in range(n):
    for k in range(n):
      C[i][j] += A[i][k] * B[k][j]

end_time = time()

print('Execution time: %.6f seconds' % (end_time - start_time))
