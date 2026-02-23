#include "fast_sqrt.h"

static inline float fast_sqrt(float n){
  if(n <= 0){
    return *(float*)&(unsigned long){0x7FC00000U}; // return NaN
  }

  float est = n;
  float n2 = n*0.5F; 
  const float onenhalf = 1.5f;
  long nf;

  nf = *(long*)&est;
  /*
  * Original Bit Hack
  * nf = (((nf >> 1) << 23) - 0x3F7A7EFA)^0x80000000U;
  */
  nf = ((nf&~0x7F800000U | ((((int)((nf & 0x7F800000U) >> 23)-127)>>1) & 0xff)<<23)-0x3F7A7EFA)^0x80000000U; // I swear, this is just black magic at this point
  est = *(float*)&nf;

  float est_prev = est+2*PRECISION;
  int iter = 0;
  while(*(float*)&(long){(*(long*)&(float){est_prev-est})&~(1UL << 31)} > PRECISION && iter++ < ITER_MAX){  // the same as fabs(est_prev - est) but without the function call
    est_prev = est;
    //est = 0.5F*(est + (n/est)); // Normal Newton
    est = (onenhalf - n2*est*est);
  }
  return est*n;
}
