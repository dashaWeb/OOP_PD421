#pragma once

class Food
{
public:
	// static - глобальний існуючий ресурс, видно буде (public) через імя класу (Food::MAX_WEIGHT)
	static const size_t MAX_WEIGHT = 2000;
	static size_t counter; // декларація статичного поля, Треба визначати це поле на глобальному рівні, дя багатофайлового проєкту - .cpp
	const char* getName() const // unmutable this
	{
		return this->name; // компілятор функції визначені у класі намагається робити inline
	}
	const size_t& getKkal() const;
	const size_t& getWeight() const;

	void setName(const char* name);
	void setKkal(const size_t& kkal);
	void setWeight(const size_t& weight);

	void print() const;

	// with 4 params прототип
	Food(const char* name = "Nofood", const size_t& kkal = 0, const size_t& weight = 0); // in 1 ctor = 4 ctors (default and other)
	Food(const Food& other); // copy ctor
	void operator =(const Food& other); // this (left operand) a = b (other,right)
	static size_t getCounter(); // статичний метод повязаний не з обєктом, повязаний з класом, не отримує this
	~Food();

private:
	char* name = nullptr;
	size_t kkal;
	size_t weight;
	int id_ = ++counter;
};

inline const size_t& Food::getKkal() const
{
	return this->kkal;
}

inline const size_t& Food::getWeight() const
{
	return this->weight;
}
inline void Food::setKkal(const size_t& kkal)
{
	this->kkal = kkal;
}

inline void Food::setWeight(const size_t& weight)
{
	this->weight = weight;
}
inline size_t Food::getCounter() // статичний метод може працювати зі статичними полями
{
	return counter;
}