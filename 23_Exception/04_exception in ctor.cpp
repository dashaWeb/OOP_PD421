//#include <iostream>
//using namespace std;
//
//class Cat
//{
//public:
//	Cat(const char* name, int age)
//	{
//		setName(name);
//		try
//		{
//			setAge(age); // can throw
//		}
//		catch (...)
//		{
//			this->~Cat();
//			throw;
//		}
//	}
//
//	void setAge(int age)
//	{
//		if (age < 0)
//			throw invalid_argument("Error : Age < 0");
//		this->age = age;
//	}
//	void setName(const char* name)
//	{
//		if (this->name != nullptr)
//		{
//			delete[] this->name;
//		}
//		int size = strlen(name) + 1;
//		this->name = new char[size];
//		strcpy_s(this->name, size, name);
//	}
//	~Cat()
//	{
//		cout << "----------- Dtor done --------------" << endl;
//		delete[] name;
//	}
//private:
//	char* name = nullptr;
//	int age = 0;
//};
//
//int main()
//{
//	try
//	{
//		Cat cat("Barsik", -2);
//		cout << "Ok object created " << endl;
//	}
//	catch (const std::logic_error ex)
//	{
//		cout << "Message :: " << ex.what() << endl;
//	}
//}