#include <bitset>		// The power, speed and memory handling in one place

void STL() {
	const int N = 20;		// const
	string s = "000111";
	bitset<N> x(s);			// 00000000000000000111
	x.set();				// 11111111111111111111
	x.flip();				// 00000000000000000000

	x = 10;					// 00000000000000001010
	x |= 3;					// 00000000000000001011
	x = (x<<3);				// 00000000000001011000
	x = ~x;					// 11111111111110100111
	x.set(15, 0);			// 11110111111110100111
	x.set(15);				// 11111111111110100111
	x.flip(0);				// 11111111111110100110
	x.count();				// Returns the number of bits that are set.
	x.any();				// Returns true if any bits are set.
	x.none();				// Returns true if no bits are set.
	x.test(15);
	x.to_ulong();			// Returns an unsigned long represent mask

	// The most interesting
	if(x[2] == 0)
		;

	x[0] = 1;	// Set bit from most right to 1
	x[N-1] = 0;	// Set bit from most left to 0

	cout<<x<<"\n";			// display a string of N bits
}

void PrintAllSubsetsAllOnes(int len)
{
 	int mask = (1<<len)-1;		// mask = 1111 for len = 4;

 	for (int i = mask; i >= 0 ; i = i - 1)
		printNumber(i, len);
}

// So we decrease -1 to get next. Do u remember effect of X-1?
/*
11111
11110
11101
11100
11011
11010
11001
11000
10111
10110
10101
10100
10011
10010
10001
10000
01111
01110
01101
01100
01011
01010
01001
01000
00111
00110
00101
00100
00011
00010
00001
00000
*/

void printNumber(int n, int len)
{
	if(!len)
		return ;

	printNumber(n>>1, len-1);	// remove last bit
	cout<<(n&1);						// print last bit
}

// Let's count bits

int countNumBits1(int mask) {	// O(bits Length)
	int ret = 0;	//1101001 -> 110100 -> 11010 -> 1101 -> 110 -> 11 -> 1 -> 0
	while (mask) {
		if(mask&1)
			ret++;
		mask >>= 1;
	}
	return ret;
}

// Get bit
int getBit(int num, int idx) {
  return ((num >> idx) & 1) == 1;		// 110100, idx = 4  -->  110 & 1 = 0
}

int setBit1(int num, int idx) {
	return num | (1<<idx);
}

int setBit0(int num, int idx) {
	return num & ~(1<<idx);				// 110100, idx = 3  -->  110100 & ~000100 = 110100 & 111011
}

int flipBit(int num, int idx) {
	return num ^ (1<<idx);
}

int countNumBits2(int mask) {	//	O(bits Count)		__builtin_popcount
	int ret = 0;
	while (mask) 	{
		mask &= (mask-1);
		++ret;	// Simply remove the last bit and so on
	}
	return ret;
}

int grayCode(int i) {
	return i ^ (i>>1);
}

void printAllSubsetsGray(int len)
{
	for (int i = 0; i < (1<<len)-1; ++i)
	{
		printNumber(i, len );
		cout<<"\t\t";

		printNumber( grayCode(i), len );

		cout<<"\t"<<__builtin_popcount(grayCode(i));
		cout<<"\n";
	}
}
