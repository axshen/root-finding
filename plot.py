#!/usr/bin/env python3

import numpy as np
import matplotlib.pyplot as plt


def f(x):
    return (x - 1) * (x - 5) * (2 * x - 9) + 5


x = np.arange(0, 8, 0.1)
y = [f(val) for val in x]


plt.plot(x, y)
plt.show()
