#include "Pupil_Teacher.h"

void Teacher::setMarkMath(Pupil& pupil, size_t math)
{
	pupil.math = math;
}

void Teacher::setMarkEnglish(Pupil& pupil, size_t english)
{
	pupil.english = english;
}

Pupil::Pupil(const string& name, const size_t& math, const size_t& english)
	:name(name),math(math),english(english)
{
}

void Pupil::print() const
{
	std::cout << "Name Pupil ----> " << name << std::endl;
	std::cout << "\t Math :: " << math << "\n\t English :: " << english << std::endl;

}
