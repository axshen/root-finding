#!/usr/bin/env python3

import random
import numpy as np
import matplotlib.pyplot as plt


def f(x):
    noise = 0.1
    return np.sqrt(2 * x + 3) - 3 + noise * random.random()


x = np.arange(0, 10, 0.1)
y = [f(val) for val in x]


plt.plot(x, y)
plt.show()
