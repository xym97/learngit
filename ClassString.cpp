#include<iostream>
#include<string>
#include<stdlib.h>

#pragma warning (disable: 4996)

using namespace std;

//class String
//{
////friend:
////	ostream& operator <<(ostream& _cout ,String& s);
//public:
//    String(const char* pStr = " ")//���캯��
//	{
//		if(NULL == pStr){
//			_pStr = new char[1];
//			*_pStr = '\0';
//		}
//		else{
//			_pStr = new char[strlen(pStr) + 1];
//			strcpy(_pStr , pStr);
//		}
//	}
//
//	~String()//��������
//	{ cout<<"������"<<endl;}
//
//	String (const String& s)//�������캯��
//		:_pStr(new char [strlen(s._pStr) + 1])
//	{
//		strcpy(_pStr,s._pStr);
// 	}
//
//	//String& operator = ( String& s)//�������캯��
// //   {
//	//	if(this != &s){
//	//		char* pTemp = new char[strlen(s._pStr) + 1];
//	//		strcpy(pTemp ,s._pStr);
//	//		delete[] _pStr;
//	//		_pStr = pTemp;
//	//	}
//	//	return s;
// //   }
//
//	//String& operator = (String& s)//��ֵ���������
//	//{
//	//	if(this != &s)//if(_pStr == s._pStr)
//	//	{
//	//		strcpy(_pStr,s._pStr);
//	//		std::swap(_pStr,s._pStr);
//	//	}
//	//	return *this;
//	//	
//	//}
//
//	String operator = (String s)
//	{
//		strcpy(_pStr,s._pStr);
//		return *this;
//	}
//    
//    ostream& operator <<(ostream& _cout)
//    {
//	 _cout<<_pStr<<endl;
//	 return _cout;
//    }
//private:
//	char* _pStr;
//};
//    
////ostream& operator <<(ostream& _cout,String& s)
////{
////	_cout<<*(s._pStr)<<endl;
////	return _cout;
////}
//
//int main()
//{
//    String s1("xzuidiao");
//	String s2(s1);
//	String s3;
//	s3 = s1;
//	s2<<cout<<endl;
//	system("pause");
//	return 0;
//}

class String
{
//friend:
//	ostream& operator <<(ostream& _cout ,String& s);
public:
    String (const char* pStr = " ",int count = 1)
		/*:*_pCount(count)*///���캯��
	{
		_pCount = &count;
		*_pCount = count;
		if(NULL == pStr){
			_pStr = new char[1];
			*_pStr = '\0';
		}
		else{
			_pStr = new char[strlen(pStr) + 1 + 4];
			strcpy(_pStr , pStr);
		}
		++(*_pCount);
	}



	~String()
	{
		if(0 == --*_pCount && NULL != _pStr){
			delete[] _pStr;
			delete _pCount;
			_pStr = NULL;
			_pCount = NULL;
		}
	}

	String (const String& s)
		:_pStr(s._pStr)
	{
		*_pCount++;
	}

	String& operator = (const String& s)
	{
		if(_pStr != s._pStr){
			if(0 == --*_pCount){
				delete[]  _pStr;
				delete _pCount;
			}
			_pStr = s._pStr;
			_pCount = s._pCount;
			return *this;
		}
	}
    
    ostream& operator <<(ostream& _cout)
    {
	 _cout<<_pStr<<endl;
	 return _cout;
    }
private:
	char* _pStr;
	int*  _pCount;
};
  

int main()
{
    String s1("xzuidiao");
	String s2(s1);
	/*String s3;
	s3 = s1;*/
	s2<<cout<<endl;
	system("pause");
	return 0;
}

//class String
//{
////friend:
////	ostream& operator <<(ostream& _cout ,String& s);
//public:
//    String(const char* pStr = " ",int a = 1)//���캯��
//		:count(a)
//	{
//		if(NULL == pStr){
//			_pStr = new char[1];
//			*_pStr = '\0';
//		}
//		else{
//			_pStr = new char[strlen(pStr) + 1 + 4];
//			strcpy(_pStr , pStr);
//		}
//	}
//
//		int GetRef()
//	{
//		return *((int*)_pStr - 1);
//	}
//
//	~String()//��������
//	{
//		if(0 == GetRef() && NULL != _pStr){
//			delete[] _pStr;
//			delete (int*)(_pStr - 1);
//			//(int*)(_pStr - 1) = NULL;
//			_pStr = NULL;
//		}
//	}
//
//	String (const String& s)//�������캯��
//		:_pStr(new char [strlen(s._pStr) + 1])
//	{
//		strcpy(_pStr,s._pStr);
// 	}
//
//	//String& operator = ( String& s)//�������캯��
// //   {
//	//	if(this != &s){
//	//		char* pTemp = new char[strlen(s._pStr) + 1];
//	//		strcpy(pTemp ,s._pStr);
//	//		delete[] _pStr;
//	//		_pStr = pTemp;
//	//	}
//	//	return s;
// //   }
//
//	//String& operator = (String& s)//��ֵ���������
//	//{
//	//	if(this != &s)//if(_pStr == s._pStr)
//	//	{
//	//		strcpy(_pStr,s._pStr);
//	//		std::swap(_pStr,s._pStr);
//	//	}
//	//	return *this;
//	//	
//	//}
//
//	String& operator = (String& s)
//	{
//		if(_pStr != s._pStr){
//			if(0 == GetRef()){
//				delete[] _pStr;
//				delete (int*)(_pStr - 1);
//			}
//			_pStr = s._pStr;
//		}
//		return *this;
//	}
//    
//    ostream& operator <<(ostream& _cout)
//    {
//	 _cout<<_pStr<<endl;
//	 return _cout;
//    }
//private:
//	int count;
//	char* _pStr;
//};
//    
////ostream& operator <<(ostream& _cout,String& s)
////{
////	_cout<<*(s._pStr)<<endl;
////	return _cout;
////}
//
//int main()
//{
//    String s1("xzuidiao");
//	String s2(s1);
//	String s3(s2);
//	//String s3;
//	s3 = s1;
//	s3<<cout<<endl;
//	system("pause");
//	return 0;
//}

//дʱ����
//char& operator[] (int index)
//{
//	 pTemp = new char[strlen(_pStr) +1 +4];
//	 pTemp += 4;
//	 strcpy(pTemp,_pStr);
//	  --GetRef();
//	 _pStr = pTemp;
//	 ++GetRef();
//	 return _pStr[index];
//}