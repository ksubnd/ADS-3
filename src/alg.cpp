// Copyright 2025 NNTU-CS
#include <iostream>
#include <cstdint>
#include "alg.h"

unsigned int collatzLen(uint64_t num) {
  unsigned int len = 1;
  while (num > 1) {
    if (num % 2 == 0)
      num = num / 2;
    else
      num = num * 3 + 1;
    len += 1;
  }
  return len;
}

uint64_t collatzMaxValue(uint64_t num) {
  uint64_t max = num;
  while (num > 1) {
    if (num % 2 == 0)
      num = num / 2;
    else
      num = num * 3 + 1;
    if (num > max)
      max = num;
  }
  return max;
}

unsigned int seqCollatz(unsigned int* maxlen,
                        uint64_t lbound,
                        uint64_t rbound) {
  *maxlen = 0;
  unsigned int max = 0;
  for (uint64_t num = lbound; num <= rbound; num++) {
    unsigned int len = collatzLen(num);
    if (len > *maxlen) {
      *maxlen = len;
      max = num;
    }
  }
  return max;
}
