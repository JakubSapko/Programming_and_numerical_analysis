#include <iostream>
#include <vector>
using namespace std;

class Napis
{
private:
	char* str;
	int length;
public:
	Napis(const char* txt="")
	{
		length =strlen(txt);
		str = new char[length];
		strcpy(str, txt);
	}
	Napis(const Napis& s)
	{
		length =s.getLength();
		str = new char[length];
		const char* st = s.getStr();
		strcpy(str, st);
	}
	~Napis()
	{
		if(str)
			delete str;
	}
	void setStr(const char* txt)
	{
		if(str)
			delete str;
		length =strlen(txt);
		str = new char[length];
		strcpy(str, txt);
	}
	const char* getStr() const {return str;}
	int getLength() const {return length;}
	friend std::ostream& operator<<(std::ostream &os,  Napis& w);
	bool operator==(const Napis& s)
	{
		if(length != s.getLength())
			return false;
		else
		{
			for(int ii=0; ii<length; ii++)
			{
				if(str[ii] != s.getStr()[ii])
					return false;
			}
			return true;
		}
	}
	bool operator!=(const Napis& s){return !(*this==s);}
	bool operator<(const Napis &s)
	{
		double min = length < s.getLength() ? length : s.getLength();
		for(int ii=0; ii<min; ii++)
		{
			if(str[ii] != s.getStr()[ii])
			{
				if(str[ii] < s.getStr()[ii])
					return true;
				else
					return false;
			}
		}
		if(length < s.getLength())
			return true;
		else
			return false;
	}
	bool operator<=(const Napis &s)
	{
		return (*this)==s || (*this)<s;
	}
	bool operator>(const Napis &s)
	{
		return !((*this) <= s);
	}
	bool operator>=(const Napis &s)
	{
		return (*this)>s || (*this)==s; 
	}

	Napis operator+(const Napis &s)
	{
		int l1 = length;
		int l2 = s.getLength();
		const char* st = s.getStr();
		char* txt = new char[l1+l2];
		for(int ii=0; ii<l1+l2; ii++)
		{
			if(ii<l1)
				txt[ii] = str[ii];
			else
				txt[ii] = st[ii-l1];
		}
		Napis n(txt);
		delete[] txt;
		return n;
	}
	
};

ostream& operator<<(ostream &os,  Napis& w)
{
	os << w.getStr();
	return os;
};

int main()
{
	Napis n1;
	n1.setStr("krowa");
	Napis n2("kruk");
	Napis n3("kruki");

	vector<Napis> v;
	v.push_back(n1);
	v.push_back(n2);
	v.push_back(n3);
	for(auto iter=v.begin(); iter!=v.end(); ++iter)
	{
		for(auto iter2=v.begin(); iter2!=v.end(); ++iter2)
		{
			cout << *iter << " " << *iter2 << " "
			<< ((*iter) == (*iter2)) << " "
			<< ((*iter) != (*iter2)) << " "
			<< ((*iter) > (*iter2)) << " "
			<< ((*iter) <= (*iter2)) << " "
			<< ((*iter) < (*iter2)) << " "
			<< ((*iter) >= (*iter2)) << endl;
		}
	}
	Napis n4 = n1+n2;
	cout<< n4 << endl;
	return 0;
}