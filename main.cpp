#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

class DataManager {
 private:
  int* data;

 public:
  DataManager() { // no need for s here
    // no initilization need to init with s
    data = new int[5]; // can't allocate in stack as size unknown at compile time

    for (int i = 0; i < size; i++) {
      if (i % 2 == 0) data[i] = i * 2;
    }
  }

  void print() {
    for (int i = 0; i <= size; i++) {
      cout << data[i] << " ";
    }
    cout << endl;
  }

  int getValue(int index) {
    if (index < size) return data[index];

    return data[0];
  }

  ~DataManager() { delete[] data; } // data is a pointer to array so delete
};

void unsafeFunction() {
  char buffer[100];

  strcpy(buffer, "This is way too long for buffer"); // the buffer was too short

  cout << buffer << endl;
}

int globalVar = 0;

int compute(int x) {

  if (x > 10)
    return x * 2; // if get here the result is unused so no need for it 
  else if (x < 0)
    return x; // no initilzation to result here

  return x; // same as above 
}

void memoryLeakDemo() {
  int* leak1 = new int[100];
  int* leak2 = new int;

  leak1[0] = 10;
  *leak2 = 20;

  cout << leak1[0] + *leak2 << endl;  
  // memory leak no delete 
  delete [] leak1;delete leak2;

}

void vectorIssues() {
  vector<int> v;

  v.push_back(1);
  v.push_back(2);

  cout << v[10] << endl;

  v.clear();
  cout << v.front() << endl;
}

int main() {
  DataManager dm();

  dm.print();

  unsafeFunction();

  cout << compute(5) << endl;

  memoryLeakDemo();

  vectorIssues();

  DataManager dm2 = dm;

  cout << dm2.getValue(2) << endl;

  return 0;
}
