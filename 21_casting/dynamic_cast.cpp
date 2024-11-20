#include <iostream>
#include <vector>
#include "Person.h"
using namespace std;

int main()
{
	Person ann("Anna");
	Student ivan("Ivan", "Design");
	Aspirant matviy("MAtviy", "CS", "AI");

	ann.print();
	ivan.print();
	matviy.print();


	Person* person = &ivan;
	person->print();

	cout << ">>>>>>>>>>>>\n\n";
	cout << "\n ------ Dynamic _ cast ---------------" << endl;

	Student* s = dynamic_cast<Student*>(person);
	if (s != nullptr)
	{
		s->learn();
	}
	else {
		cout << "Error cast Student" << endl;
	}
	Aspirant* a = dynamic_cast<Aspirant*>(person);
	if (a != nullptr)
	{
		a->WriteDymlom();
	}
	else
	{
		cout << "Error cast Aspirant" << endl;

	}

	vector<Person*> people{ &ann,&ivan,&matviy };
	for (auto& i : people)
	{
		i->print();
		s = dynamic_cast<Student*>(i);
		if (s != nullptr)
			s->learn();
		a = dynamic_cast<Aspirant*>(i);
		if (a != nullptr)
			a->WriteDymlom();
		cout << "___________________________________" << endl;
	}
}