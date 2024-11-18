//#include <iostream>
//#include <string>
//using namespace std;
//
//void funInt(const int& value)
//{
//	//++value;
//	++const_cast<int&>(value);
//	int& ref = const_cast<int&>(value);
//	ref++;
//}
//
//void funString(const string& text)
//{
//	//++text[0];
//	++const_cast<string&>(text)[0];
//	string& ref = const_cast<string&>(text);
//	ref += "!!!";
//}
//
//class Person
//{
//public:
//	Person(const string& name = "NoName",const size_t& age = 0)
//		:name(name),age(age)
//	{}
//	const string& getName() const
//	{
//		//name[0] = "*";
//		if (tolower(name[0]))
//		{
//			string& refName = const_cast<string&>(name);
//			refName[0] = toupper(refName[0]);
//		}
//		return name;
//	}
//	const size_t& getAge() const
//	{
//		//this->age = 22; error -> const method
//		Person* changeThis = const_cast<Person*>(this);
//		changeThis->age++;
//		changeThis->name += "*";
//		return age;
//	}
//private:
//	string name;
//	size_t age;
//};
//
//int main()
//{
//	int number = 1000;
//	cout << "Number :: " << number << endl;
//	funInt(number);
//	cout << "Number :: " << number << endl;
//	cout << "\n\n";
//
//	string test = "======";
//	cout << test << endl;
//	funString(test);
//	cout << test << endl;
//
//	cout << "\n\n =====================================\n";
//	Person person("dmytro", 22);
//	cout << person.getName() << endl;
//	cout << person.getAge() << endl;
//	cout << person.getAge() << endl;
//	cout << person.getName() << endl;
//
//}