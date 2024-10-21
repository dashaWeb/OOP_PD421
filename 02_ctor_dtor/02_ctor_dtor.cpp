#include <iostream>
using namespace std;

class City {
private:
	char* name = nullptr;
	char* country = nullptr;
	size_t population = 0;

	void copyStrField(char*& dest, const char* source) // source - звідки; dest - куди
	{
		if (dest != nullptr)
			delete[] dest;
		if (!isValid(source))
		{
			dest = new char[5];
			strcpy_s(dest, 5, "none");
			return;
		}
		size_t size = strlen(source) + 1;
		dest = new char[size];
		strcpy_s(dest, size, source);
	}
	inline bool isValid(const char* source) // невелика функція, без циклів, нерекурсивна, без складних розгалуджень
	{
		return source != nullptr and source[0] != '\0';
	}
public:
	City() // ctor default
		:City("None")
	{
	};
	City(const char* name)
		:City(name, "None")
	{

	}
	City(const char* name, const char* country)
		:City(name, country, 0)
	{

	}
	City(const char* name, const char* country, const size_t& population)
		:population{ population }
	{
		copyStrField(this->name, name);
		copyStrField(this->country, country);
	}

	void print() const //  не повинен змінювати стан обєкту (тобто жодне поле міняти не можна)
	{
		cout << "\t City       :: " << this->name << endl;
		cout << "\t Country    :: " << this->country << endl;
		cout << "\t Population :: " << this->population << endl;
	}
	const char* getNameCity() const // good style
	{
		return this->name;
	}
	const char* getCountry() const
	{
		return this->country;
	}
	const size_t& getPopulation() const
	{
		return this->population;
	}
	void setName(const char* name)
	{
		copyStrField(this->name, name);
	}
	void setCountry(const char* country)
	{
		copyStrField(this->country, country);
	}
	void setPopulation(const size_t& population)
	{
		this->population = population;
	}
	~City() // memory leak!!!
	{
		cout << "Dtor" << endl;
		if (this->name != nullptr)
			delete[] this->name;
		if (this->country != nullptr)
			delete[] this->country;
	}
};

int main()
{
	//City city("Rivne", "Ukraine", 244000);
	//city.print();
	//City city_2;
	//city_2.print();

	//cout << city.getNameCity() << endl;
	//auto copy = city.getNameCity();
	///*copy[0] = 'a'*/;
	//cout << copy << endl;
	//cout << city.getNameCity() << endl;

	City* city = new City("Lviv", "Ukraine", 721301);


	delete city;
}
