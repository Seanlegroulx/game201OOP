#include <iostream>

using namespace std;

class Box {
public:
	int length;
	int width; 
	int height;


	int getvolume() {
		return length * width * height;

	}

	void setlength(int L) {
		length = L;
	}



	void setwidth(int W) {
		width = W;
	}


	void setheight(int H) {
		height = H;
	}
};


int main() {

	Box box1;
	Box box2;

	box1.setlength(10);
	box1.setwidth(10);
	box1.setheight(10);

	cout << box1.getvolume() << endl;

	system("pause");


	box2.setlength(20);
	box2.setwidth(30);
	box2.setheight(5);

	cout << box2.getvolume() << endl;

	system("pause");
	return 0;
}