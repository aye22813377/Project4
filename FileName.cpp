#include <iostream>
using namespace std;
class MyString
{
	char* str;
	int length;
	int size;
public:
	MyString()
	{
		size = 80;
		cout << "default  constructor , size="<< size <<endl;
		str = new char[size+1];
	}

	MyString(int size)
	{
		this->size = size;
		cout << "initialization  constructor , size=" <<this->size<< endl;
		str = new char[size+1];
	}

	MyString( const MyString &other)
	{
		size = other.size;
		length = other.length;
		cout << "copy constructor, size=" << size << endl;
		str = new char[size+1];
		for (int i{ 0 }; i < length+1; ++i)
		{
			str[i] = other.str[i];
		}
	}

	MyString(const char* str)
	{
		for (length = 0; str[length] != '\0'; ++length);
		cout << length << endl;
		size = length;
		this->str = new char[size+1];
		for (int i{ 0 }; i < size; ++i)
		{
			this->str[i] = str[i];
		}
		this->str[size] = '\0';
	}
	
	~MyString()
	{
		cout << "destructor size=" <<this->size<< endl;
		delete[] str;
	}

	int MyStrSize() const
	{
		return size;
	}

	int MyStrLen() const
	{
		return length;
	}

	void MyStrCpy(const MyString& obj)
	{
		if (size<obj.length)
		{
			char* newstr = new char[obj.length];
			delete[] str;
			str = newstr;
			size = obj.length;
		}
		for (int i{ 0 }; i < obj.length; ++i)
		{
			str[i] = obj.str[i];
		}
		length = obj.length;

	}

	int MyChr(char  c)
	{
		for (int i = 0; i < this->size; ++i)
		{
			if (str[i] == c)
			{
				return i;
			}
		}
		return  - 1;
	}

   void Input()
   {
	   cin.getline(str, size+1);
	   int i;
	   for (i = 0; str[i] != '\0'; ++i)
	   length = i;
   }

   void Output()
   {

	   for (int i = 0; i < length; ++i)
	   {
		   cout << str[i];
	   }
	   cout << endl;
   }

   void MyStrCat(const MyString& obj)
   {
	   if(length+obj.length > size)
	   {

		   char* newstr=new char[length+obj.length+1];
		   for (int i = 0; i < length; ++i)
		   {
			   newstr[i] = str[i];
		   }
		   delete[] str;
		   str = newstr;
		   size = length + obj.length;
	   }
	   for (int i = 0; i < obj.length+1; ++i)
	   {
		   str[length + i] = obj.str[i];
	   }
	   length += obj.length;
   }

   bool MyStrStr(const char* str)
   {
	   bool nextindex;
	   int firstindex= MyChr(str[0]);
	   if (firstindex == -1) return false;

	   do {
		   nextindex = false;
		   for (int i = 0; i < length - firstindex && str[i] != '\0'; ++i)
		   {
			   if (this->str[firstindex + i] != str[i])
			   {
				   nextindex = true;
				   i = length;
				   firstindex++;
			   }
		   }
		   if (!nextindex)
		   {
			   return true;
		   }
	   } while (nextindex);
   }

   int MyStrCmp(const MyString& other)
   {
	   int len = length < other.length?length:other.length;
	   for (int i = 0; i < len; ++i)
	   {
		   if (str[i] != other.str[i])
		   {
			   return str[i] < other.str[i] ? -1 : 1;
		   }
	   }
	   if (length != other.length)
	   {
		   return length < other.length ? -1 : 1;
	   }
	   return 0;
   }

   void MyDelChr(char c)
   {
	   int index = MyChr(c);
	
	   if(index == -1) return;

	   for (int i = index; index < length - 1; ++i)
	   {
		   str[i] = str[i + 1];
	   }
	   --length;
       
	   return MyDelChr(c);
   }

   MyString operator+(const MyString& other) const
   {
	   MyString first(*this);
	   first.MyStrCat(other);
	   return first;
   }
   MyString& operator+=(int count)
   {
	   char* newStr = new char[size + count];
	   for (int i = 0; i < length; ++i)
	   {
		   newStr[i] = str[i];
	   }
	   size += count;
	   delete[] str;
	   str = newStr;
   }
   MyString& operator-=(int count)
   {
	   size = size - count < 0 ? 0 : size - count;
	   if (length > size) length = size;
	   char* newStr = new char[size];
	   for (int i = 0; i < length; ++i)
	   {
		   newStr[i] = str[i];
	   }
	   delete[] str;
	   str = newStr;
   }

   friend ostream& operator<<(ostream& out,const MyString&str)
   {
	   for (int i = 0; i < str.length; ++i)
	   {
		   out << str.str[i];
	   }
	   return out;
   }
   friend istream& operator>>(istream& in,  MyString& str)
   {
	   in.getline(str.str, str.size+1);
	   for (str.length = 0; str.str[str.length] != '\0'; ++str.length);
	   return in;
   }
};





int main()
{
	cout << "Start main" << endl ;
	MyString name("hello world");
	auto name2 = MyString(10);
	cin >> name2;
	cout << name+name2 << endl;
	cout << "Finish main"<< endl;
}