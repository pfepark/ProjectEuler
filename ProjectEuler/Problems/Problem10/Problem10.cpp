// Problem10.cpp : Defines the entry point for the console application.
//

/*
Summation of primes
Problem 10
The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

Find the sum of all the primes below two million.
*/

#include "stdafx.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <assert.h>

const int twoMiilion = 2000000;

// Primality test
bool IsPrime(const int number)
{
	if (number <= 1)
		return false;

	if (number <= 3)
		return true;

	if (number % 2 == 0 || number % 3 == 0)
		return false;

	size_t i = 5;
	while (i * i <= number)
	{
		if (number % i == 0 || number % (i + 2) == 0)
			return false;

		i += 6;
	}

	return true;
}

int main()
{
	assert(IsPrime(2));
	assert(IsPrime(3));
	assert(IsPrime(4) == false);
	assert(IsPrime(5));

	std::vector<__int64> M2(twoMiilion);
	for (size_t i = 0; i < M2.capacity(); i++)
	{
		M2[i] = i + 1;
	}

	__int64 totalPrime = std::accumulate(M2.begin(), M2.end(),(__int64)0, [](__int64 total, int number)
	{
		return total += IsPrime(number) ? number : 0;
	}
	);

	std::cout << totalPrime;
		
    return 0;
}

