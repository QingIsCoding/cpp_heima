#include <iostream>
#include <fstream>
using namespace std;

void test01()
{
	ofstream ofs;
	ofs.open("test.txt",ios::out);
	ofs << "name: zhangsan" << endl;
	ofs << "sex: man" << endl;
	ofs << "age: 18" << endl;
	ofs.close();
}

int main()
{
	test01();
	return 0;
}
