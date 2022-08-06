#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

const ll MOD = 1e9 + 7;

void binaryLeftShift() {
	// <<, all bits shifted to left by specified amount
	// similar to multiplying by 2

	int a = 1;
	a = a << 5;
	cout << a << "\n";
}


void binaryRightShift() {
	// <<, all bits shifted to right by specified amount
	// similar to divide by 2

	int a = 164;
	a = a >> 5;
	cout << a << "\n";
}

int getIthBit(int n, int i) {
	int mask = 1 << i;
	return (n & mask) > 0 ? 1 : 0;
}

int setIthBit(int n, int i) {
	int mask = (1 << i);
	return n | mask;
}

int clearIthBit(int n, int i) {
	int mask = ~(1 << i); // -> 11110111111
	return n & mask;
}

int updateIthBit(int n, int i, int v) {
	n = clearIthBit(n, i);
	int mask = v << i;
	return n | mask;
}

int clearLastIthBits(int n, int i) {
	int mask = ((~0) << i);
	return n & mask;
}

bool isPowerOfTwo(int n) {
	// if n is power of 2
	// eg 16 -> 10000
	// 16 - 1 = 5 -> 01111
	// So their and gives back 0
	return (n != 0) and ((n & (n - 1)) == 0);
}

// Log(N), as number N has log(N) bits
int countSetBits(int n) {
	int cnt = 0;

	while (n) {
		cnt += (n & 1);
		n = n >> 1;
	}

	return cnt;
}

int count_bits_hack(int n) {
	int ans = 0;
	while (n) {
		// removes the last set bit from the current number
		n = n & (n - 1);
		ans++;
	}
	return ans;
}

int fast_exponentiation(int base, int exp) {
	// iterate over the bits of exponent
	// multiply it to the answer when the last bit is 1

	int ans = 1;

	while (exp) {
		int last_bit = exp & 1;

		if (last_bit) {
			ans = ans * base;
		}

		base = base * base;
		exp = exp >> 1;
	}

	return ans;
}

int convertDecimalToBinary(int n) {
	int ans = 0;
	int base = 1;
	while (n) {
		int rem = n % 2;
		ans = ans + (rem * base);
		n /= 2;
		base *= 10;
	}

	return ans;
}

int convertBinaryToDecimal(int n) {
	int ans = 0;
	int base = 1;

	while (n) {
		int last_bit = n % 10;

		if (last_bit) {
			ans += base;
		}

		base *= 2;
		n = n / 10;
	}

	return ans;
}

int main() {

	// binaryLeftShift();
	// binaryRightShift();

	// cout << fast_exponentiation(10, 3) << "\n";

	cout << convertBinaryToDecimal(10000000) << "\n";


	// int a = 0;
	// negative numbers stored in 2's complement form
	// to get the magnitude, we first invert all the bits and add 1
	// to get the magnitude
	// cout << ~a << "\n";

	return 0;
}
