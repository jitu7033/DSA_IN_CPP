#include<bits/stdc++.h>
using namespace std;


class clss{
public:
	int a = 10;
};

// int main(){
// 	clss obj;
// 	clss* ptr;
// 	ptr = &obj;
// 	cout<<obj.a<<endl;
// 	cout<<ptr->a<<endl;

// }

// question 
class A{
public:
	int a,b;
	A(int a, int b){
		this->a = a;this->b = b;

	}
	int getSum(){
		return a+b;
	}
};

int main(){
	A obj1(3,7);
	A *ptr;
	ptr = &obj1;
	// (ptr->a) = 5;
	(*ptr).a = 5;
	cout<<obj1.getSum()<<endl;
}

