/*
 * fast_sqrt.h
 *
 * Very fast, branchless software sqrt approximation for IEEE 754 floats
 * 
 * Copyright (c) 2026 Christian Henrichsen
 * Licensed under the MIT Licsense. See LICENSE file in repository root
*/

#ifndef FAST_SQRT_H
#define FAST_SQRT_H

#define PRECISION 0.001f
#define ITER_MAX 100

static inline float fast_sqrt(float n);

#endif
