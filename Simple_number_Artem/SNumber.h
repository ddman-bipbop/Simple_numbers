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
	// Конструкторы и деструктор
	//
	
	// Коснтруктор по умолчанию
	SNumber();
	// Конструктор int
	SNumber(int a);
	// Конструктор long int
	SNumber(long int a);
	// Конструктор string
	SNumber(string str);
	// Конструктор массив простых множителей
	SNumber(int* a,int N);
	// Конструктор вектор простых множителей
	SNumber(vector<int> a);
	// Конструктор копирования
	SNumber(SNumber const& a);
	// Деструктор
	~SNumber();

	//
	// Методы
	//
	
	// Печать числа в нормальном (десятичном) виде
	void Print();
	// Печать числа в виде простых множителей
	void PrintSNumber();;
	// Сложение
	SNumber& Add(SNumber const& T);
	// Сложение
	SNumber Add(SNumber const& T) const;
	// Сложение
	SNumber Add(SNumber T) const;
	// Сложение с int
	SNumber Add(int a);
	// Сложение c string
	SNumber Add(string str);
	// Умножение
	SNumber& Mlp(SNumber const& T);
	// Умножение
	SNumber Mlp(SNumber const& T) const;
	// Умножение
	SNumber Mlp(SNumber T) const;
	// Умножение с int
	SNumber Mlp(int a);
	// Умножение с string
	SNumber Mlp(string str);

	//
	// Операторы
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
	// Вектор простых множителей
	vector<int> pd_;

	// Факторизация числа на простые множители
	void Factorize(int x);
	// Проверка числа на простоту
	bool IsPrime(int x);
	// Проверка вектора на простые множители
	bool VectorIsPrime();
	// Из вектора простых множителей в число
	long int InDec(SNumber a);
	// Из вектора простых множителей в число
	long int InDec(vector<int> a);
};