#include <iostream>
using namespace std;


// клас для позначення помилки ділення на 0
class DivByZeroException : public exception
{
public:
	DivByZeroException(const string& message = "Division by zero")
		:exception(message.data()) // c_str
	{
	}
};
// клас для позначення помилки ділення на велике число
class ToBigDivisorException : public overflow_error
{
	static const int LIMIT_UP = 1'000'000;
	double value;
public:
	ToBigDivisorException(const string& message = "Too big divisor", const double& value = LIMIT_UP)
		:overflow_error(message.data()), value(value)
	{
	}
	double getValue() const
	{
		return value;
	}
};

// клас для позначення помилки ділення на замале число < - 1000 000
class TooSmallDivisorException : public underflow_error
{
	static const int LIMIT_DOWN = - 1'000'000;
	double value;
public:
	TooSmallDivisorException(const string& message = "Too small divisor", const double& value = LIMIT_DOWN)
		:underflow_error(message), value(value)
	{
	}
	double getValue() const
	{
		return value;
	}
};

double divi(double a, double b)
{
	if (b == 0)
		throw DivByZeroException("Error : division by zero 2"); // викидаємо виняток(помилку) типу DivByZeroException
	if (b > 1'000'000)
		throw ToBigDivisorException("Too big number", b); // кидаємо виняток типу ToBigDivisorException
	if (b < -1'000'000)
		throw TooSmallDivisorException("Too small number", b); // кидаємо виняток типу TooSmallDivisorException

	return a / b;
}
int main()
{
	double a, b;
		cout << "Enter two number :: \n";
		while (cin >> a >> b) // доки читаються дані згідно формату
		{
			try
			{
				cout << a << " / " << b << " = " << divi(a, b) << endl;
	
			}
			catch (const DivByZeroException& ex)
			{
				cout << "Exception " << typeid(ex).name() << " was caught " << endl;
				cout << ex.what() << "\t Bad value :: " << 0 << endl;
			}
			catch (const ToBigDivisorException& ex)
			{
				cout << "Exception " << typeid(ex).name() << " was caught " << endl;
				cout << ex.what() << "\t Bad value :: " << ex.getValue() << endl;
			}
			catch (const TooSmallDivisorException& ex)
			{
				cout << "Exception " << typeid(ex).name() << " was caught " << endl;
				cout << ex.what() << "\t Bad value :: " << ex.getValue() << endl;
			}
			/*catch (const MyException& ex)
			{
				cout << "My Exception " << typeid(ex).name() << " was caught " << endl;
				cout << ex.what() << "\t Bad value :: " << ex.getValue() << endl;
			}*/
			catch (...) // default catch
			{
				cout << "Exception .... was caught. Error" << endl;
			}
		}
}