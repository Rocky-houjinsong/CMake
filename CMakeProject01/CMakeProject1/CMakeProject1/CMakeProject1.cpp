// CMakeProject1.cpp: 定义应用程序的入口点。
//

#include "CMakeProject1.h"
#include <fstream>

using namespace std;
void Func();  //Func 此处声明
int main()
{
	Func();// Func 此处调用
	std::ofstream file;
	file.open("tessssssssss.txt");
	file << "HelloWord.\n";
	file.close();

	cout << "Hello CMake." << endl;
	return 0;
}
