#include <iostream> 
#include <stdexcept> 
using namespace std;

class ClassB; 
class SwapData { 
public: 
  virtual void swapPrivateData(ClassB &objB) = 0;
  virtual ~SwapData() {} 
}; 

class ClassA : public SwapData { 
private: 
  int dataA; 
public: 
  ClassA(int val) : dataA(val) {} 
  friend void swapPrivateData(ClassA &objA, ClassB &objB); // Friend function declaration 
  void display() { 
  cout << "ClassA: DataA = " << dataA << endl; 
} 
void swapPrivateData(ClassB &objB) override; 
}; 
 
class ClassB : public SwapData { 
private: 
  int dataB; 
public: 
  ClassB(int val) : dataB(val) {} 
  friend void swapPrivateData(ClassA &objA, ClassB &objB); // Friend function declaration 
  void display() { 
  cout << "ClassB: DataB = " << dataB << endl; 
} 
  void swapPrivateData(ClassA &objA) override; // Override virtual function 
}; 

void swapPrivateData(ClassA &objA, ClassB &objB) { 
  int temp = objA.dataA; 
  objA.dataA = objB.dataB; 
  objB.dataB = temp; 
} 

void ClassA::swapPrivateData(ClassB &objB) { 
  swapPrivateData(*this, objB); 
} 

void ClassB::swapPrivateData(ClassA &objA) { 
  swapPrivateData(objA, *this); // Invoking friend function for swapping 
} 
int main() { 
   ClassA objA(10); 
   ClassB objB(20); 
   cout << "Before swapping:" << endl; 
   objA.display(); 
   objB.display(); 
   objA.swapPrivateData(objB); 
   cout << "\nAfter swapping:" << endl; 
   objA.display(); 
   objB.display(); 
   return 0; 
} 
