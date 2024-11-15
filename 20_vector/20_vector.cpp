#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void printVector(const vector<T>& v)
{
	for (auto& i : v)
	{
		cout << i << "\t";
	}cout << endl;
}
int main()
{
    vector<int> v{ 1,5,4,7,8,5,4,2 };
    vector<double> v2{ 1.0,2.0,3.0,4.0,5.5 };
	cout << "Vector int    :: "; printVector(v);
	cout << "Vector double :: "; printVector(v2);

	cout << "Size     :: " << v.size() << endl;
	cout << "capacity :: " << v.capacity() << endl;
	cout << "max_size :: " << v.max_size() << endl;

	cout << "\n\n";
	for (size_t i = 0; i < 7; i++)
	{
		v.push_back(rand() % 100); 
		/*cout << "Size     :: " << v.size() << endl;
		cout << "capacity :: " << v.capacity() << endl;*/
	}

	cout << "Vector int    :: ";
	for (size_t i = 0; i < v.size(); i++)
	{
		cout << v[i] << "\t";
	}cout << endl;

	v.pop_back();
	cout << "Vector int    :: "; printVector(v);

	v.insert(v.begin(), 555);
	cout << "Vector int    :: "; printVector(v);
	v.insert(v.begin() + (v.size() / 2), 999);
	cout << "Vector int    :: "; printVector(v);
	v.insert(v.end(), {1,2,3});
	cout << "Vector int    :: "; printVector(v);

	v.erase(v.begin() + 2);
	cout << "Vector int    :: "; printVector(v);
	v.erase(v.begin(), v.begin() + 2);
	cout << "Vector int    :: "; printVector(v);
}

