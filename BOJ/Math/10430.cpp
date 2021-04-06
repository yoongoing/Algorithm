#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int A,B,C;
	cin>>A>>B>>C;
	int a = (A+B) % C;
	int b = ((A%C) + (B%C)) % C;
	int c = (A*B) % C;
	int d = ((A%C) * (B%C)) % C;

	cout<<a<<endl;
	cout<<b<<endl;
	cout<<c<<endl;
	cout<<d<<endl;

	return 0;
}