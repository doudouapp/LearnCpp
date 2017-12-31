#include <iostream>

int main() {
  using namespace std;
  cout << "Hello World!" << endl;

  int original = 30;
  cout << "original = " << original << endl;
  cout << "original is at address: " << hex << &original << endl;

  int& ref = original;
  cout << "ref is at address: " << hex << &ref << endl;

  int& ref2 = ref;
  cout << "ref2 is at address: "<< hex << &ref2 << endl;
  cout << "ref2 gets alue, ref2 = " << dec << ref2 << endl;

  return 0;
}


// 1. 在terminal 上 cd 到该文件目录
// 2. g++ HelloWorld.cpp
// 3. ./a.out
