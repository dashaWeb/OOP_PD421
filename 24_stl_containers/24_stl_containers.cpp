#include <iostream>
#include <array>
#include <vector>
#include <deque>
#include <string>
#include <algorithm>
using namespace std;


bool div_3(int number)
{
	return number % 3 == 0;
}

int inc(int number)
{
	return number + 1;
}

template <typename ContType>
void print(const ContType& cont, const string& prompt = "")
{
	cout << prompt << " :: ";
	for (const auto& el : cont)
	{
		cout << el << "\t";
	}
	cout << endl;
}

int main()
{
	const size_t SIZE = 5;
	array<int, SIZE> arr{ 10,38,-4,5,2 };

	for (size_t i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << "\t";
	}cout << endl;

	for (auto it = arr.begin(); it != arr.end(); it++)
	{
		cout << *it << "\t";
	}
	cout << endl;
	cout << "Reverse order \t :: ";
	for (auto it = arr.rbegin(); it != arr.rend(); it++)
	{
		cout << *it << "\t";
	}
	cout << endl;
	//arr[5] = 45;
	try
	{
		arr.at(5) = 55;
	}
	catch (const std::exception& ex)
	{
		cout << "Bad index :: " << ex.what() << endl;
	}

	array<int, SIZE>::iterator it = min_element(arr.begin(), arr.end());
	cout << "Min in array :: " << *it << endl;
	*it *= -1;
	print(arr, "Print Array");
	it = max_element(arr.begin(), arr.end());
	cout << "Max in array :: " << *it << endl;
	cout << "\n\n ===================================\n\n" << endl;

	vector<int> vec(arr.rbegin(), arr.rend()); // скопіювали реверсно у вектор всі елементи масиву arr
	print(vec, "Print vector (ar reverse copy of arr)");
	vec.push_back(333);
	print(vec, "Print vector after push ");
	vec.insert(vec.begin() + vec.size() / 2, 7777);
	print(vec, "Print vector after insert ");

	cout << "\n\n ===================================\n\n" << endl;
	deque<int> d(vec.begin(), vec.begin() + vec.size() / 2); // копіюємо першу половину вектора
	print(d, "Deque (copy 1-st hala of vector) ");
	d.resize(vec.size(), -1);
	print(d, "Deque (copy 1-st hala of vector) ");
	copy(vec.rbegin(), vec.rend() - vec.size() / 2, d.begin() + d.size() / 2);
	//copy_if()
	print(d, "Deque (copy 2-nd of vector) ");

	d.push_back(10);
	d.push_front(10);
	print(d, "Deque");
	int value = 10;
	deque<int>::iterator itF = find(d.begin(), d.end(), value);
	while (itF != d.end())
	{
		cout << "Found value :: " << *itF << " in index " << itF - begin(d) << endl;
		itF = find(itF + 1, d.end(), value);
	}

	cout << "\n Count of value :: " << value << " = " << count(begin(d), end(d), value) << endl;

	itF = find_if(begin(d), end(d), div_3);
	if (itF != end(d))
	{
		cout << "Found value :: " << *itF << " in index " << itF - begin(d) << endl;
	}
	else
	{
		cout << "Not found any divisable by 3" << endl;
	}
	cout << "\n\n ===================================\n\n" << endl;
	transform(begin(d), end(d), begin(d), inc);
	print(d, "Deque after transform");

	sort(d.begin(), d.end());
	print(d, "Deque after sort");

	//sort(d.begin(), d.end(),greater<int>()); // sorted deque by desc
	sort(d.rbegin(), d.rend()); // sorted deque by desc
	print(d, "Deque after sort");

	cout << "\n\n ================= Anonim function ==================\n\n" << endl;
	int test = 55;
	auto func = [&test](int a, int b)-> double {
		test = 22;
		double sum = (double)a / b + test;
		return sum;
	};
	cout << "func(2,3) ==> " << func(2, 3) << endl;
	cout << "TypeId :: " << typeid(func).name() << endl;
	//[capture-list](formal parameters)-> resultType {body};
	//[=] -  захопити всі локальні змінні у тому ж блоці що лямбда по значенню
	//[&] -  захопити всі локальні змінні у тому ж блоці що лямбда по ПОСИЛАННЮ
	//[nameVariable] - захоплення за значенням, [&nameVariable] - захоплення за ПОСИЛАННЯМ
	print(d, "Deque");
	int divisor = 5;
	itF = find_if(begin(d), end(d), [divisor](int el) {return el % divisor  == 0; });
	if (itF != end(d))
	{
		cout << "Found value :: " << *itF << " in index " << itF - begin(d) << endl;
	}
	else
	{
		cout << "Not found any divisable by 3" << endl;
	}

	int multiplier = 3;
	vector<int> vv(d.size());
	transform(begin(d), end(d), begin(vv), [multiplier](auto el) {return el * multiplier; });
	print(vv, "Vector");
	print(d, "Deque");

	deque<string> color{ "red","green","blue","yellow","orange","purple" };
	auto itColor = max_element(begin(color), end(color), [](auto s1, auto s2) {return s1.size() < s2.size(); });

	cout << "Result :: " << *itColor << endl;
	int size = (*itColor).size();
	cout << count_if(begin(color), end(color), [size](auto str) {return str.size() == size; }) << endl;
}

