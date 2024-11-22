//#include <iostream>
//#include <exception>
//using namespace std;
//
//void funEx(int& value)
//{
//	try
//	{
//		if (value < 0)
//			throw exception("Error value < 0");
//	}
//	catch (const std::exception& ex)
//	{
//		cout << "Inner Catch has worked" << endl;
//		cout << ex.what() << endl; // частково обробити виняток
//		throw; // re-throw - перевикидання винятку "наверх" (у більш зовнішній catch)
//	}
//	value *= 2;
//}
//
//int main()
//{
//	int number = -10;
//	cout << "Number :: " << number << endl;
//	try
//	{
//		funEx(number);
//		cout << "Number :: " << number << endl;
//	}
//	catch (int ex)
//	{
//		cout << "Caught int exception" << endl;
//	}
//	catch (const exception& ex)
//	{
//		cout << "Outer catch has worked" << endl;
//		cout << ex.what() << endl; // обробили виняток повністю
//	}
//}