//#include <iostream>
//#include <string>
//#include <vector>
//
//using namespace std;
//
//int main()
//{
//	//string str = "121232421";
//	string str = "a1fg2123_2421";
//	try
//	{
//		int value = stoi(str);
//		cout << "Value :: " << value << " " << typeid(value).name() << endl;
//	}
//	catch (const std::exception& ex)
//	{
//		cout << "Caught :: " << typeid(ex).name() << endl;
//		cout << "Message :: " << ex.what() << endl;
//	}
//	cout << "\n\n ======================\n\n";
//	//str = "ABCD";
//	//try
//	//{
//	//	cout << "str[5] : " << str[5] << endl;
//
//	//}
//	//catch (...)
//	//{
//	//	/*cout << "Caught :: " << typeid(ex).name() << endl;*/
//	//	cout << "Message :: "   << endl;
//	//}
//
//	vector<int>v {1, 2, 3, 4, 5};
//	try
//	{
//		//cout << "v[10] :: " << v[10] << endl;
//		cout << "v.at(10):: " << v.at(10) << endl;
//	}
//	catch (const std::exception& ex)
//	{
//		cout << "Caught :: " << typeid(ex).name() << endl;
//		cout << "Message :: " << ex.what() << endl;
//	}
//}