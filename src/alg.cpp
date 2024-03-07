// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
  if (n == 0)
    return 1;
  else
  {
		double temp = value;
	  for (uint16_t i = 1; i < n; i++) {
	  	value *= temp;
	  }
		return value;
	}
}
uint64_t fact(uint16_t n) {
	uint64_t fac = 1;
	for (int i = 2; i <= n; i++) {
 		fac *= i;
	}
	return fac;
}
double calcItem(double x, uint16_t n) {
	return pown(x, n) / fact(n);
}
double expn(double x, uint16_t count) {
	double exp = 0;
	for (uint16_t i = 0; i <= count; i++) {
		exp += calcItem(x, i);
	}
	return exp;
}
double sinn(double x, uint16_t count) {
	double sin = 0;
	for (uint16_t i = 1; i <= count; i++) {
		if (i % 2 == 0)
			sin -= calcItem(x, 2*i-1);
		else
			sin += calcItem(x, 2*i-1);
	}
	return sin;
}
double cosn(double x, uint16_t count) {
	double cos = 0;
	for (uint16_t i = 1; i <= count; i++) {
		if (i % 2 == 0)
			cos -= calcItem(x, 2*i-2);
		else
			cos += calcItem(x, 2*i-2);
	}
	return cos;
}
