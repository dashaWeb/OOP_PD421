#pragma once
#include <iostream>
using std::string;
class Pupil; // prototype

class Teacher {
public:
	void setMarkMath(Pupil& pupil, size_t math);
	void setMarkEnglish(Pupil& pupil, size_t english);
};



class Pupil {
public:
	Pupil(const string& name, const size_t& math = 0, const size_t& english = 0);
	Pupil() = default;
	void print() const;

	/*friend void Teacher::setMarkMath(Pupil& pupil, size_t math);
	friend void Teacher::setMarkEnglish(Pupil& pupil, size_t english);*/
	friend class Teacher;
private:
	string name = "Noname";
	size_t math = 0;
	size_t english = 0;
};