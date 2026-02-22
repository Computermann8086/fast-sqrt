# fast-sqrt

Very fast, branchless software sqrt approximation for IEEE 754 floats with configurable precision.

## Features

- Very fast software-only sqrt
- Branchless estimation
- Adaptive Newton-Raphson iterations for efficient convergence
- Configurable precision via the 'PRECISION' macro
- Returns NaN for negative inputs as per the IEEE 754 standard
- Inline, library-free and portable

## Usage

'''c
#include "fast_sqrt.h"

float x = 123.456f;
float y = fast_sqrt(x);
