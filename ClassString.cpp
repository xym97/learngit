#include<iostream>
#include<string>
#include<stdlib.h>

#pragma warning (disable: 4996)

using namespace std;

class String
{
//friend:
//	ostream& operator <<(ostream& _cout ,String& s);
public:
    String(const char* pStr = " ")//构造函数
	{
		if(NULL == pStr){
			_pStr = new char[1];
			*_pStr = '\0';
		}
		else{
			_pStr = new char[strlen(pStr) + 1];
			strcpy(_pStr , pStr);
		}
	}

	~String()//析构函数
	{ cout<<"已析构"<<endl;}

	String (const String& s)//拷贝构造函数
	{
		_pStr = new char [strlen(s._pStr) + 1];
		strcpy(_pStr,s._pStr);
	}

	//String& operator = ( String& s)
 //   {
	//	if(this != &s){
	//		char* pTemp = new char[strlen(s._pStr) + 1];
	//		strcpy(pTemp ,s._pStr);
	//		delete[] _pStr;
	//		_pStr = pTemp;
	//	}
	//	return s;
 //   }

	//String& operator = (String& s)
	//{
	//	if(this != &s)//if(_pStr == s._pStr)
	//	{
	//		strcpy(_pStr,s._pStr);
	//		std::swap(_pStr,s._pStr);
	//	}
	//	return *this;
	//	
	//}

	String operator = (String s)
	{
		strcpy(_pStr,s._pStr);
		return *this;
	}
    
    ostream& operator <<(ostream& _cout)
    {
	 _cout<<_pStr<<endl;
	 return _cout;
    }
private:
	char* _pStr;
};
    
//ostream& operator <<(ostream& _cout,String& s)
//{
//	_cout<<*(s._pStr)<<endl;
//	return _cout;
//}

int main()
{
    String s1("xzuidiao");
	String s2(s1);
	String s3;
	s3 = s1;
	s3<<cout<<endl;
	system("pause");
	return 0;
}