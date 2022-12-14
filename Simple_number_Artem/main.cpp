#include "SNumber.h"

int main() 
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));

	int a[3] = { 2,2,5 };
	vector<int> b = { 2,2,7 };

	SNumber p = 20,
		p1("15"),
		p2(-10),
		p3(a,3),
		p4(b),
		p5(5);

	p.PrintSNumber();
	cout << "--------------" << endl;
	p1.PrintSNumber();
	cout << "--------------" << endl;
	p2.PrintSNumber();
	cout << "--------------" << endl;
	p3.PrintSNumber();
	cout << "--------------" << endl;
	p4.PrintSNumber();
	cout << "--------------" << endl;
	p4.Print();
	cout << "--------------" << endl;
	p5.Add(p).Print();
	cout << "--------------" << endl;
	p5.Add(10).Add(p5).Print();
	cout << "--------------" << endl;
	p.Mlp(p).Print();
	cout << "--------------" << endl;
	p.PrintSNumber();
	cout << "--------------" << endl;
	p5 = 5;
	p = p5 + p5;
	p.Print();
	cout << "--------------" << endl;
	p.Deduct(15).Print();
	cout << "--------------" << endl;
	p = 5;
	p1 = 5;
	cout << "p = "; p.Print();
	cout << "p1 = "; p1.Print();
	if (p > p1)
		cout << "p > p1" << endl;
	if (p < p1)
		cout << "p < p1" << endl;
	if (p >= p1)
		cout << "p >= p1" << endl;
	if (p <= p1)
		cout << "p <= p1" << endl;
	if (p == p1)
		cout << "p == p1" << endl;
	if (p != p1)
		cout << "p != p1" << endl;
	cout << "--------------" << endl;
	p++;
	p1++;
	p.Print();
	p1.Print();
	cout << "--------------" << endl;
	p--;
	p1--;
	p.Print();
	p1.Print();
	cout << "--------------" << endl;
	cout << p << endl;
	return 0;
}