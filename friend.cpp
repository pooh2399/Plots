#include <iostream>
#include <string>
using namespace std;

class bus{
private:
	string name ="TestName";
	string num  = "170907110";
public: 
	void install();
	void allotment();
friend void printstatus( bus &obj);

};

void printstatus(bus &obj){
	obj.name="NewName";
	obj.num="New Number";
	cout<<obj.name<<endl;
	cout<<obj.num<<endl;
}

int main(){
	bus b1;
	printstatus(b1);
}