#pragma once

class Food
{
public:
	// static - ���������� �������� ������, ����� ���� (public) ����� ��� ����� (Food::MAX_WEIGHT)
	static const size_t MAX_WEIGHT = 2000;
	static size_t counter; // ���������� ���������� ����, ����� ��������� �� ���� �� ����������� ���, �� ��������������� ������ - .cpp
	const char* getName() const // unmutable this
	{
		return this->name; // ��������� ������� �������� � ���� ���������� ������ inline
	}
	const size_t& getKkal() const;
	const size_t& getWeight() const;

	void setName(const char* name);
	void setKkal(const size_t& kkal);
	void setWeight(const size_t& weight);

	void print() const;

	// with 4 params ��������
	Food(const char* name = "Nofood", const size_t& kkal = 0, const size_t& weight = 0); // in 1 ctor = 4 ctors (default and other)
	Food(const Food& other); // copy ctor
	void operator =(const Food& other); // this (left operand) a = b (other,right)
	static size_t getCounter(); // ��������� ����� ��������� �� � ������, ��������� � ������, �� ������ this
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
inline size_t Food::getCounter() // ��������� ����� ���� ��������� � ���������� ������
{
	return counter;
}