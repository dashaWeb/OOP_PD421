#include <iostream>
#include <string>
using namespace std;

// 2.5.2020
// 02.05.2020

const size_t MIN_POWER = 50;
const size_t MAX_POWER = 100;

const size_t MAX_SPEED_LOW = 100;
const size_t MAX_SPEED_UP = 350;

const double MIN_VOLUME = 0.7;
const double MAX_VOLUME = 6;


struct Date
{
	size_t day, month, year;
	string getDate()
	{
		return (day < 10 ? "0" : "") + to_string(day) + "." + (month < 10 ? "0" : "") + to_string(month) + "." + to_string(year);
	}
};

// public - доступ відкритий, видимі поля та методи за межами класу
// private - доступ закритий, доступ до полів та методів лише в серидині класу
// protected - захищений, доступ до полів та мнтодів лише в середині класу та у класах наслідників


class Car {
private:
	string brand = "NoBrand";
	string color = "None";
	size_t power = MIN_POWER;
	size_t max_speed = MAX_SPEED_LOW;
	double volume = MIN_VOLUME;
	Date date{};

public:
	Car() // default ctor
	{

	}
	//Car(const string& brand, const string& color, const Date& date) 
	//{
	//	this->brand = brand; // this - неявний вказівник на обєкт Car
	//	this->color = color;
	//	this->date = date;
	//}
	/*Car(const string& brand, const string& color, const Date& date)
		:brand{ brand }, color{ color }, date{date}
	{}*/
	Car(const string& brand, const string& color, const Date& date)
		:date{ date }
	{
		setBrand(brand);
		setColor(color);
	}
	void setBrand(const string& brand) // задача сетера - присвоїти значення для поля
	{
		/*if (brand.empty() || brand == " ")
		{
			cout << "Error" << endl;
		}
		else {
			this->brand = brand;
		}*/

		/*if (brand.empty() || brand == " ")
		{
			cout << "Error" << endl;
			return;
		}

		this->brand = brand;*/

		if (!brand.empty() && brand != " ")
			this->brand = brand;
	}
	void setColor(const string& color)
	{
		if (!color.empty() && color != " ")
			this->color = color;
	}
	void setPower(const size_t& power)
	{
		if (power >= MIN_POWER and power <= MAX_POWER)
			this->power = power;
	}
	string getBrand() // задача гетера - повертати значення поля
	{
		return this->brand;
	}
	void print()
	{
		cout << "============= " << this->brand << " ================" << endl;
		cout << "\t Color  :: " << this->color << endl;
		cout << "\t Power  :: " << this->power << endl;
		cout << "\t Volume :: " << this->volume << endl;
		cout << "\t Speed  :: " << this->max_speed << endl;
		cout << "\t Date   :: " << this->date.getDate() << endl;
	}
	void input()
	{
		cout << "\t\t Brand  :: "; getline(cin, this->brand);
		cout << "\t\t Color  :: "; getline(cin, this->color);
		cout << "\t\t Power  :: "; cin >> this->power;
		cout << "\t\t Volume :: "; cin >> this->volume;
		cout << "\t\t Speed  :: "; cin >> this->max_speed;
		cout << "\t\t Date   :: "; cin >> this->date.day >> this->date.month >> this->date.year;
	}

};

int main()
{
	Car mazda;
	Car ford("Ford", "White", {02,05,2020});
	
	cout << "Brand :: " << ford.getBrand() << endl;
	ford.setBrand("Ford 2");
	cout << "Brand :: " << ford.getBrand() << endl;
	ford.setBrand(" ");
	cout << "Brand :: " << ford.getBrand() << endl;
	mazda.input();
	mazda.print();
}
