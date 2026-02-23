#include "fast_sqrt.h"

static inline float fast_sqrt(float n){
  if(n <= 0){
    return *(float*)&(unsigned long){0x7FC00000U}; // return NaN
  }

  float est = n;
  long nf;

  nf = *(long*)&est;
  nf = (((nf >> 1) << 23) - 0x3F7A7EFA)^0x80000000U;
  est = *(float*)&nf;

  float est_prev = est+2*PRECISION;
  int iter = 0;
  while(*(float*)&(long){(*(long*)&(float){est_prev-est})&~(1UL << 31)} > PRECISION && iter++ < ITER_MAX){  // the same as fabs(est_prev - est) but without the function call
    est_prev = est;
    est = 0.5F*(est + (n/est));
  }
  return est;
}
