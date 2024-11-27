#include <iostream>
#include <forward_list>
#include <list>
#include <string>
#include <set>
#include <algorithm>
#include <map>
using namespace std;

template <typename ContType>
void print(const ContType& cont, const string& prompt = "")
{
	cout << prompt << " :: ";
	for (const auto& el : cont)
	{
		cout << el << "\t";
	}cout << endl;
}


using id = size_t;
using name = string;

using title = string;
using author = string;

void print(map<id, name> list, const string& prompt = "")
{
	cout << prompt << endl;
	for (const auto& el : list)
	{
		cout << "[" << el.first << "] - " << el.second << "\n";
	}cout << endl;
}
void print(multimap<author, title> list, const string& prompt = "")
{
	cout << prompt << endl;
	for (const auto& el : list)
	{
		cout << "[" << el.first << "] - " << el.second << "\n";
	}cout << endl;
}
int main()
{
	forward_list<int> fl{ 10,23,45,-1,100,-55,10,-22,10,200 };
	print(fl, "Print forward list");
	fl.push_front(5);
	print(fl, "Print forward list after push_front");

	int index = 2;
	auto it = fl.begin();
	advance(it, index); // перемістити ітератор на index елементів вперед
	fl.insert_after(it, 77);
	print(fl, "Print forward list after insert");

	int value = 10;
	//cout << "Enter number :: "; cin >> value;

	it = find(fl.begin(), fl.end(), value);
	if (it != fl.end())
	{
		cout << value << " was found " << endl;
		auto tmpIt = it;
		tmpIt++;
		if (tmpIt != fl.end())
		{
			cout << "Will be deleted :: " << *tmpIt << endl;
			fl.erase_after(it);
		}
		else {
			cout << "Erase after " << value << " is impossible (because it is last element)" << endl;
		}
	}
	print(fl, "Print forward list after erase");

	cout << "\n==============================" << endl;
	fl.sort();
	print(fl, "Print sorted forward list");
	fl.sort(greater<int>());
	print(fl, "Print sorted desc forward list");

	fl.remove(10);
	print(fl, "Print forward list after remove");
	int bound = 50;
	fl.remove_if([bound](const auto& el) {return el < bound; });
	print(fl, "Remove elements < " + to_string(bound));

	/*system("pause");
	system("cls");*/

	forward_list<string> colors{ "red","yellow","blue","Orange","purple","Pink" };
	print(colors, "Colors :: ");
	colors.sort([](auto s1, auto s2) {return tolower(s1[0]) < tolower(s2[0]); });
	print(colors, "Colors :: ");
	cout << "\n\n ==================================================== \n";

	list<string> color(colors.begin(), colors.end());
	print(color, "Print list :: ");
	color.push_front("green");
	color.push_back("gold");
	print(color, "Print list :: ");

	/*cout << "\n List in reverse order :: ";
	for (auto it = color.rbegin(); it != color.rend(); it++)
	{
		cout << *it << "\t";
	}cout << endl;*/
	cout << "\n List in reverse order :: ";
	for (auto it = --color.end(); it != color.begin(); it--)
	{
		cout << *it << "\t";
	}cout << *color.begin() << endl;

	char letter = 'p';
	color.remove_if([letter](auto el) {return el.find(letter) != string::npos || el.find(toupper(letter)) != string::npos; /*-1*/; });
	print(color, "Print list :: ");
	/*system("pause");
	system("cls");*/

	cout << "\n\n ==================================================== \n";
	multiset<int> ms{ 10,5,-20,-10,22,33,100,-33,100,1,100,-200 };
	//multiset<int, greater<int>> ms{ 10,5,-20,-10,22,33,-33,100,1,100,-200 };
	print(ms, "Print multiset");
	ms.insert(77);
	for (auto it = ms.begin(); it != ms.end(); it++)
	{
		cout << *it << "\t";
	} cout << endl;
	for (auto it = ms.rbegin(); it != ms.rend(); it++)
	{
		cout << *it << "\t";
	} cout << endl;

	cout << "\n\n ==================================================== \n";
	cout << "Min :: " << *ms.begin() << endl;
	cout << "Max :: " << *ms.rbegin() << endl;
	cout << "\nCount of key 100 " << ms.count(100) << endl;
	print(ms, "Print multiset");
	int key = 10;
	auto it_ms = ms.find(key);
	if (it_ms != ms.end())
	{
		cout << "Key " << key << " was found << " << ms.count(key) << " times" << endl;
		//ms.erase(key);
		//ms.erase(it_ms,ms.end());
	}
	else {
		cout << "Key " << key << " not found" << endl;
	}
	print(ms, "Print multiset");
	set<int> s(ms.begin(), ms.end());
	print(s, "Print set     ");

	cout << "\n\n ==================================================== \n";
	set<int>s2{ 100,55,77,88,300,22,33 };
	print(s, "Print set     ");
	print(s2, "Print set     ");

	ostream_iterator<int> outIt(cout, "\t");
	cout << "\n-------------------- UNION -------------------------------\n";
	set_union(s.begin(), s.end(), s2.begin(), s2.end(), outIt);
	cout << "\n-------------------- COMMON(INTERSECTION) -------------------------------\n";
	set_intersection(s.begin(), s.end(), s2.begin(), s2.end(), outIt);
	cout << "\n-------------------- DIFFERENCE(s1-s2) -------------------------------\n";
	set_difference(s.begin(), s.end(), s2.begin(), s2.end(), outIt);
	cout << "\n-------------------- DIFFERENCE(s2-s1) -------------------------------\n";
	set_difference(s2.begin(), s2.end(), s.begin(), s.end(), outIt);

	/*system("pause");
	system("cls");*/
	{
		cout << "\n\n ==================================================== \n";
		map<id, name> people
		{
			pair<id,name>(555,"Anna"),
			make_pair(777,"Tom"),
			{222,"Olena"}
		};
		print(people);
		people.insert({ 333,"Ivan" });
		people.insert({ 333,"Den" });
		print(people);

		people[555] = "Olia";
		people[888] = "Matviy";

		print(people);

		id key = 1000;
		//cout << "Test get by key " << key << " ::::: " << people[key] << endl;
		try
		{
			cout << "Test get by key " << key << " ::::: " << people.at(key) << endl;
		}
		catch (const std::exception& ex)
		{
			cout << "\t\t Not find key " << key << endl;
			cout << "\t\t Error message :: " << ex.what() << endl;
		}
		print(people);
		key = 555;
		auto it = people.find(key);
		if (it != people.end())
		{
			cout << "Was found id " << key << " in index " << distance(people.begin(), it) << endl;
			people.erase(it);
		}
		else
		{
			cout << "Not found key " << key << endl;
		}
		print(people);

		key = 333;
		cout << "\n--------------------------LOWER_BOUND---------------------\n";
		it = people.lower_bound(key); // key >= 333
		if (it != people.end())
		{
			cout << "Found person qith id >= " << key << "\n Name " << it->second << "\t Id " << it->first << endl;
		}
		else {
			cout << "Not found person with id >= " << key << endl;

		}
		cout << "\n--------------------------UPPER_BOUND---------------------\n";
		it = people.upper_bound(key); // key > 333
		if (it != people.end())
		{
			cout << "Found person qith id > " << key << "\n Name " << it->second << "\t Id " << it->first << endl;
		}
		else {
			cout << "Not found person with id > " << key << endl;

		}
	}

	{
		system("pause");
		system("cls");
		cout << "\n\n ==================================================== \n";
		multimap<author, title> library
		{
			{ "J.K. Rowling","Harry Potter and the Philosopher's Stone" },
			{ "LJ Andrews","The Ever King" },
			{ "J.K. rowling","Harry Potter and the Chamber of Secrets" },
			{ "J.K. Rowling","Harry Potter and the Prisoner of Azkaban"},
		};
		print(library);
		library.insert({ "LJ Andrews" ,"Crown of Blood and Ruin" });
		print(library);

		//library["J.K. rowling"] = "new book"; // errro
		//print(library);
	}



}


//{"Iron Flame", "Rebecca Yarros", "Entangled: Red Tower Books", "Fantasy"},
//{ "The Ever King","LJ Andrews","Victorious","Fantasy" },
//{ "Harry Potter and the Philosopher's Stone","J.K. Rowling","Pottermore Publishing","Children's Fantasy" },
//{ "Harry Potter and the Chamber of Secrets","J.K. rowling","Pottermore Publishing","Children's Fantasy" },
//{ "Harry Potter and the Prisoner of Azkaban","J.K. Rowling","Pottermore Publishing","Children's Fantasy" },
//{ "Harry Potter and the Order of the Phoenix","J.K. Rowling","Pottermore Publishing","Children's Fantasy" },
//{ "Harry Potter and the Half-Blood Prince","J.K. Rowling","Pottermore Publishing","Children's Fantasy" },
//{ "Crown of Blood and Ruin","LJ Andrews","Victorious","Dark Fantasy Horror" },
//{ "Battlefield Reclaimer","David North","High Peak Publishing","Fiction" },
//{ "Swords of Empire","Robert Ryan","Trotting Fox Press","Fantasy" },