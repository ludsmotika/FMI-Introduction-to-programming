#include <iostream>



int findKBitInNumber(int n, int k)
{
	int mask = 1;
	mask <<= k;

	return ((mask & n) == 0 ? 0 : 1);
}

int second(int x, int m, int n)
{
	x >>= n - 1;

	int mask = 1;
	mask <<= m;
	mask -= 1;

	return x & mask;
}

void swapValues(int& a, int& b)
{
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}

void swapBitOnPPosition(int& n, int position, int newBit)
{

	int mask = 1;
	mask << position;

	if (newBit)
	{
		n | mask;
	}
	else
	{
		~mask;
		n & mask;
	}
}


int main()
{
	int n;
	int p;
	int bit;
	std::cin >> n;
	std::cin >> p;
	std::cin >> bit;

	swapBitOnPPosition(n, p, bit);
	std::cout << n;
}
