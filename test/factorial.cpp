//
// Created by steve on 11/15/17.
//
#include "factorial.h"

int factorial(int n) {
  int result = 1;
  for (int i = 2; i <= n; i++) {
    result *= i;
  }
  return result;
}