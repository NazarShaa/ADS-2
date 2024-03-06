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
	uint64_t sin = x - calcItem(x, 3);
	for (uint16_t i = 5; i < count; i+=2) {
		sin += calcItem(x, i);
	}
	return sin;
}
double cosn(double x, uint16_t count) {
	uint64_t cos = x - calcItem(x, 2);
	for (uint16_t i = 4; i < count; i += 2) {
		cos += calcItem(x, i);
	}
	return cos;
}
