#include <iostream>
#include <fstream>
#include <string>
#include <streambuf>

using namespace std;


int main(int argc, char const *argv[])
{
    ifstream iFile("aa.xlsx");
	string   readStr((std::istreambuf_iterator<char>(iFile)),  std::istreambuf_iterator<char>()); 
	cout <<  readStr.c_str();

    return 0;
}
