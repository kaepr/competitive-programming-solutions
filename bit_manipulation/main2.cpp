#include <bits/stdc++.h>
using namespace std;

/*
 6 >> 1
 move the bits of 6 to the right side once

 6 << 1
 move the bits of 6 to the left once

 1 = 2^0
 10 = 2^1
 100 = 2^2
 1000 = 2^3
 10000 = 2^4
 100000 = 2^5


 example
 1<<n generates 2^n ( as we shift 1 to n positions forward )


 other
 1<<n - 1, gives the number which has all bits set to 1

*/

void printBinary(int num) {
	string s = "";
	for (int i = 10; i >= 0; i--) {
		int x = 1 << i;
		if (num & (1 << i)) {
			cout << (  num & (1 << i))  << "\n";
			s += '1';
		} else {
			s += '0';
		}
	}
	cout << s << "\n";
}

int setBit(int num, int pos) {
	return num | (1 << pos);
}

int unsetBit(int num, int pos) {
	return num & ~(1 << pos);
}

int bitToggle(int num, int pos) {
	return num ^ (1 << pos);
}

int cntBits(int num) {
	int ans = 0;
	for (int i = 31; i >= 0; i--) {
		if (num & (1 << i)) {
			ans++;
		}
	}
	return ans;
}

int isOdd(int num) {
	if (num & 1) {
		return 1;
	} else {
		return 0;
	}
}

int divideBy2(int num) {
	// shifts position towards right
	return num >> 1;
}

int multiplyBy2(int num) {
	// shifts position towards left
	return num << 1;
}

int clear_lsb_till_pos(int num, int pos) {
	return num & (~((1 << (pos + 1)) - 1));
}

int clear_msb_till_pos(int num, int pos) {
	return num & ((1 << (pos + 1)) - 1);
}

int checkPower2(int num) {
	if (num == 0) {
		return 0;
	}

	if (num & (num - 1)) {
		return 0;
	} else {
		return 1;
	}
}

void xorrr() {
	//swap numberes
	int a = 4, b = 6;
	a = a ^ b;
	b = b ^ a;
	a = a ^ b;
	cout << a << " " << b << "\n";
}

int main() {
	int num = 6;
	printBinary(num);
	// num = setBit(num, 0);
	// printBinary(num);
	// num = unsetBit(num, 0);
	// printBinary(num);
	// num = bitToggle(num, 5);
	// printBinary(num);
	// cout << cntBits(num) << "\n";
	// cout << __builtin_popcount(num) << "\n";

	// num = 59;
	// printBinary(num);
	// num = clear_lsb_till_pos(num, 4);
	// printBinary(num);
	// num = 59;
	// printBinary(num);
	// num = clear_msb_till_pos(num, 3);
	// printBinary(num);

	// if (checkPower2(16)) {
	// 	cout << "yes\n";
	// }

	// if (!checkPower2(14)) {
	// 	cout << "not power of 2\n";
	// }

	// xorrr();



	return 0;
}