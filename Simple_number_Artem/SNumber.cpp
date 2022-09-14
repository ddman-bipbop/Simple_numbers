#include "SNumber.h"
SNumber& SNumber::operator=(SNumber const& R)
{
    if (&R == this) return *this;
    pd_.clear();
    for (size_t i = 0; i < R.pd_.size(); i++)
    {
        pd_.push_back(R.pd_.at(i));
    }
    return *this;
}



SNumber& SNumber::operator=(long int a)
{
    SNumber R(a);
    return *this = R;
}



SNumber& SNumber::operator=(int a)
{
    SNumber R(a);
    return *this = R;
}



SNumber SNumber::operator+(SNumber T) const
{
    T.Add(*this);
    return T;
}



SNumber SNumber::operator+(int a)
{
    SNumber R(a);
    return R.Add(*this);
}



SNumber SNumber::operator+(long int a)
{
    SNumber R(a);
    return R.Add(*this);
}



SNumber SNumber::operator*(SNumber T) const
{
    T.Mlp(*this);
    return T;
}



SNumber SNumber::operator*(int a)
{
    SNumber R(a);
    return R.Mlp(*this);
}



SNumber SNumber::operator*(long int a)
{
    SNumber R(a);
    return R.Mlp(*this);
}



SNumber SNumber::operator-(SNumber T) const
{
    T.Deduct(*this);
    return T;
}



SNumber SNumber::operator-(int a)
{
    SNumber R(a);
    return R.Deduct(*this);
}



SNumber SNumber::operator-(long int a)
{
    SNumber R(a);
    return R.Deduct(*this);
}



bool SNumber::operator<(SNumber const& T)
{
    return InDec(*this) < InDec(T);
}



bool SNumber::operator<=(SNumber const& T)
{
    return InDec(*this) <= InDec(T);
}



bool SNumber::operator>(SNumber const& T)
{
    return InDec(*this) > InDec(T);
}



bool SNumber::operator>=(SNumber const& T)
{
    return InDec(*this) >= InDec(T);
}



bool SNumber::operator==(SNumber const& T)
{
    return InDec(*this) == InDec(T);
}



bool SNumber::operator!=(SNumber const& T)
{
    return InDec(*this) != InDec(T);
}



SNumber SNumber::operator++()
{
    //++a
    long int temp = InDec(*this);
    temp++;
    *this = temp;
    SNumber T(temp);
    return T;
}



SNumber SNumber::operator++(int)
{
    //a++
    long int temp = InDec(*this);
    SNumber T(temp);
    temp++;
    *this = temp;
    return T;
}



SNumber SNumber::operator--()
{
    //--a
    long int temp = InDec(*this);
    temp--;
    *this = temp;
    SNumber T(temp);
    return T;
}



SNumber SNumber::operator--(int)
{
    //a--
    long int temp = InDec(*this);
    SNumber T(temp);
    temp--;
    *this = temp;
    return T;
}



ostream& operator<<(ostream& out, SNumber const& T)
{
    for (size_t i = 0; i < T.pd_.size(); i++)
    {
        out << T.pd_.at(i) << "  ";
    }
    out << endl;
    return out;
}



SNumber& SNumber::Add(SNumber const& T)
{
    return *this = InDec(*this) + InDec(T);
}



SNumber SNumber::Add(SNumber const& T) const
{
    SNumber R(*this);
    R.Add(T);
    return R;
}



SNumber SNumber::Add(SNumber T) const
{
    T.Add(*this);
    return T;
}



SNumber SNumber::Add(int a)
{
    SNumber R(a);
    R.Add(*this);
    return R;
}



SNumber SNumber::Add(string str)
{
    SNumber R(str);
    R.Add(*this);
    return R;
}



SNumber& SNumber::Deduct(SNumber const& T)
{
    long int temp =  InDec(T) - InDec(*this);
    if (temp  < 0) 
    { 
        this->pd_.clear();
        this->pd_.push_back(1);
        return *this;
    }
    else
        *this = InDec(T) - InDec(*this);
    return *this;
}



SNumber SNumber::Deduct(SNumber const& T) const
{
    SNumber R(*this);
    R.Deduct(T);
    return R;
}



SNumber SNumber::Deduct(SNumber T) const
{
    T.Deduct(*this);
    return T;
}



SNumber SNumber::Deduct(int a)
{
    SNumber R(a);
    R.Deduct(*this);
    return R;
}



SNumber SNumber::Deduct(string str)
{
    SNumber R(str);
    R.Deduct(*this);
    return R;
}



SNumber& SNumber::Mlp(SNumber const& T)
{
    return *this = InDec(*this) * InDec(T);
}



SNumber SNumber::Mlp(SNumber const& T) const
{
    SNumber R(*this);
    R.Mlp(T);
    return R;
}


SNumber SNumber::Mlp(SNumber T) const
{
    T.Mlp(*this);
    return T;
}



SNumber SNumber::Mlp(int a)
{
    SNumber R(a);
    R.Mlp(*this);
    return R;
}



SNumber SNumber::Mlp(string str)
{
    SNumber R(str);
    R.Mlp(*this);
    return R;
}


SNumber::SNumber(SNumber const& a)
{
    pd_.clear();
    for (size_t i = 0; i < a.pd_.size(); i++)
    {
        pd_.push_back(a.pd_.at(i));
    }
}



SNumber::SNumber(vector<int> a)
{
    pd_.clear();
    if (!VectorIsPrime()) { pd_.push_back(1); return; }
    for (size_t i = 0; i < a.size(); i++)
    {
        pd_.push_back(a.at(i));
    }
}



SNumber::SNumber(int* a, int N)
{
    pd_.clear();
    if (!VectorIsPrime()) { pd_.push_back(1); return; }
    for (size_t i = 0; i < N; i++)
    {
        pd_.push_back(a[i]);
    }
}



SNumber::SNumber(string str)
{
    Factorize(stoi(str));
}



SNumber::SNumber(long int a)
{
    Factorize(a);
}



SNumber::SNumber(int a)
{
    Factorize(a);
}



SNumber::SNumber()
{
    pd_.push_back(1);
}



SNumber::~SNumber()
{
    pd_.clear();
}



void SNumber::Print()
{
    long long int a = 1;
    for (size_t i = 0; i < pd_.size(); i++)
    {
        a *= pd_.at(i);
    }
    cout << a << endl;
}



void SNumber::PrintSNumber()
{
    for (size_t i = 0; i < pd_.size(); i++)
    {
        cout << pd_.at(i) << "  ";
    }
    cout << endl;
}



long int SNumber::InDec(SNumber a)
{
    long int temp = 1;
    for (size_t i = 0; i < a.pd_.size(); i++)
    {
        temp *= a.pd_.at(i);
    }
    return temp;
}




long int SNumber::InDec(vector<int> a)
{
    long int temp = 1;
    for (size_t i = 0; i < a.size(); i++)
    {
        temp *= a.at(i);
    }
    return temp;
}




bool SNumber::VectorIsPrime()
{

    for (size_t i = 0; i < pd_.size(); i++)
    {
        if (!IsPrime(pd_.at(i))) return false; 
    }
    return true;
}




bool SNumber::IsPrime(int x)
{
    for (int i = 2; i <= sqrt(x); i++) {
        if (x % i == 0) {
            return false;
        }
    }

    return true;
}



void SNumber::Factorize(int x)
{
    if (x <= 0) 
    {
        pd_.push_back(1);
        return;
    }

    for (int i = 2; i <= sqrt(x); i++) {
        while (x % i == 0) {
            pd_.push_back(i);
            x /= i;
        }
    }

    if (x != 1) {
        pd_.push_back(x);
    }

}