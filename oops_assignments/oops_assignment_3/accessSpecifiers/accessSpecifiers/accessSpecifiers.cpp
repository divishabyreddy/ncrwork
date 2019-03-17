#include<iostream>
using namespace std;
//creating the base class
class Base {
private:
	int privateVar1 = 10;
protected:
	int protectedVar2 = 20;
public:
	int publicVar3 = 30;
	//dislay function
	virtual void display() {
		cout << "in base class" << endl;
		cout << " x:" << privateVar1 << " y:" << protectedVar2 << " z:" << publicVar3 << endl;
	}

};
//deriving a class from base class in private mode 
class Derived1 :private Base {
public:
	void display() {
		cout << "in derived1 class" << endl;
		cout << "nothing will be printed as it is privately derived"<<endl;
		//	cout<<" x:"<<x<<" y:"<<y<<" z:"<<z<<endl;
	}
};
//deriving a class from base class in protected mode 
class Derived2 :protected Base {
public:
	void display() {
		cout << "in derived2 class" << endl;
		//cout<<" x:"<<x<<endl;    private member cannot be accessed in protected class
		cout << " y:" << protectedVar2 << " z:" << publicVar3 << endl;
	}

};
//deriving a class from base class in public mode 
class Derived3 :public Base {
public:
	void display() {
		cout << "in derived3 class" << endl;
		//cout<<" x:"<<x<<endl;
		// private member cannot be accessed in public class
		cout << " y:" << protectedVar2 << " z:" << publicVar3 << endl;

	}
};
int main() {
	Base baseObj;//creating a base class object
	baseObj.display();

	Derived1 derived1Obj;
	derived1Obj.display();
	Derived2 derived2Obj;
	derived2Obj.display();
	Derived3 derived3Obj;
	derived3Obj.display();
	system("pause");//to sto the console from closing
	return 0;
}