#include <iostream>
using namespace std;

class Rectangle : public Shape {
protected:
	virtual void draw() {
		cout << "Rectangle" << endl;
	}
};