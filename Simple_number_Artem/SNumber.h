#pragma once
#include <iostream>
#include <locale>
#include <math.h>
#include <string>
#include <vector>
using namespace std;

class SNumber {
public:
	//
	// ������������ � ����������
	//
	
	// ����������� �� ���������
	SNumber();
	// ����������� int
	SNumber(int a);
	// ����������� long int
	SNumber(long int a);
	// ����������� string
	SNumber(string str);
	// ����������� ������ ������� ����������
	SNumber(int* a,int N);
	// ����������� ������ ������� ����������
	SNumber(vector<int> a);
	// ����������� �����������
	SNumber(SNumber const& a);
	// ����������
	~SNumber();

	//
	// ������
	//
	
	// ������ ����� � ���������� (����������) ����
	void Print();
	// ������ ����� � ���� ������� ����������
	void PrintSNumber();;
	// ��������
	SNumber& Add(SNumber const& T);
	// ��������
	SNumber Add(SNumber const& T) const;
	// ��������
	SNumber Add(SNumber T) const;
	// �������� � int
	SNumber Add(int a);
	// �������� c string
	SNumber Add(string str);
	// ���������
	SNumber& Mlp(SNumber const& T);
	// ���������
	SNumber Mlp(SNumber const& T) const;
	// ���������
	SNumber Mlp(SNumber T) const;
	// ��������� � int
	SNumber Mlp(int a);
	// ��������� � string
	SNumber Mlp(string str);

	//
	// ���������
	//

	SNumber& operator=(SNumber const& R);
	SNumber& operator=(int a);
	SNumber& operator=(long int a);

	SNumber operator+(SNumber T)const;
	SNumber operator+(int a);
	SNumber operator+(long int a);

	SNumber operator*(SNumber T)const;
	SNumber operator*(int a);
	SNumber operator*(long int a);
private:
	// ������ ������� ����������
	vector<int> pd_;

	// ������������ ����� �� ������� ���������
	void Factorize(int x);
	// �������� ����� �� ��������
	bool IsPrime(int x);
	// �������� ������� �� ������� ���������
	bool VectorIsPrime();
	// �� ������� ������� ���������� � �����
	long int InDec(SNumber a);
	// �� ������� ������� ���������� � �����
	long int InDec(vector<int> a);
};