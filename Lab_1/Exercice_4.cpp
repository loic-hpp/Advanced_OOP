#include <iostream>
#include <string>
#include <vector>
#define max(x,y) (((x) >= (y)) ? (x) : (y))
#define min(x,y) (((x) <= (y)) ? (x) : (y))
using namespace std;

int cross(int a, int b) {//replace by 0 to cross
	if (a % 2 == 0 && b % 2 == 0)
		b = 0;
	return b;
}

int russianMultiplication(int a, int b) {
	int result=0, c; //result of the operation
	//c is an intermediate variable to ensure that a is the minand b the max
	vector <int>valuesA, valuesB; //vectors that will contain the iterations
	c = min(a, b);
	b = max(a, b);
	a = c;
	valuesA.push_back(a);//adding initial values
	valuesB.push_back(b);
	while (a!=1)// while a is different of 1 we divide by 2
	{
		a = a / 2;
		b = b * 2;
		valuesA.push_back(a);
		valuesB.push_back(b);
	}
	int i = 0;
	for (int value : valuesA) {//cross values to cross in valeursB
		valuesB[i]=cross(value, valuesB[i]);
		result += valuesB[i];
		i++;
	}
	return result;
}

struct TestMul
{
	int a, b, c;
	TestMul(int a1, int b1, int c1) : a(a1), b(b1), c(c1) //constructor with 3 parameters
	{
	}
	TestMul(int a1,int b1)//constructor with 2 parameters
	{
		a = a1; b = b1; c = russianMultiplication(a1,b1);
	}
};

int main() {
	int testCounter=0;
	TestMul realValues[3] = { TestMul(10,5), TestMul(37,129), TestMul(17,7)};
	TestMul expectedValue[3] = {TestMul(10,5,50), TestMul(37,129,4773), TestMul(17,7,119)};
	for (int i = 0; i < 3; i++) {
		if (realValues[i].c == expectedValue[i].c)
			testCounter++;
	}
	cout << testCounter << "/3 tests passent" << endl;

	return 0;
}