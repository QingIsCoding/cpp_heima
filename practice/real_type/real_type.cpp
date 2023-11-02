#include <iostream>
using namespace std;

int main(){
	float f1 = 3.14f;
	double d1 = 3.14;
	float f2 = 3.1415926f;
	double d2 = 3.1415926;
	float f3 = 3e2;
	float f4 = 3e-2;
	cout << "f1:" << f1 << endl;
	cout << "d1:" << d1 << endl;
	cout << "f2:" << f2 << endl;
	cout << "d2:" << d2 << endl;
	cout << "sizeof(float):" << sizeof(float) << endl;
	cout << "sizeof(double):" << sizeof(double) << endl;
	cout << "f3:" << f3 << endl;
	cout << "f4:" << f4 << endl;
	return 0;
}
