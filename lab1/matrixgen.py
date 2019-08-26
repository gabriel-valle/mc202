import numpy as np
for i in range(50):
    arr = np.random.randint(-10e7, 10e7, 50)
    for i in arr:
        print(i, end=' ')
    print()