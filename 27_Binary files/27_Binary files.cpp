#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

const size_t SIZE = 50;
struct Train
{
	size_t number;
	char destination[SIZE];
	char from[SIZE];
	void print() const
	{
		cout << "\t Number of train :: " << number << endl;
		cout << "\t Place from      :: " << from << endl;
		cout << "\t Destination     :: " << destination << endl;
	}
};

int main()
{
	string fname = "train.dat";
	fstream file(fname, ios_base::out | ios_base::in | ios_base::binary);
	Train train{ 90,"Prague","Lviv" };
	if (!file.is_open())
	{
		cout << "Errro open file " << endl;
		return 0;
	}
	file.write((char*)&train, sizeof(train));

	Train trainArr[2]{ {122,"Warsaw","Lviv"},{5,"Sopot","Lviv"} };
	file.write(reinterpret_cast<const char*>(trainArr), sizeof(trainArr));

	vector<Train> trainVec{ {7,"Budapest","Kyiv"},{188,"Odesa","Lviv"} };
	file.write(reinterpret_cast<const char*>(trainVec.data()), trainVec.size() * sizeof(Train));


	file.seekg(0);
	Train tmp;
	cout << "\n\tRead from file \n";
	while (file.read(reinterpret_cast<char*>(&tmp), sizeof(Train)))
	{
		cout << "\n";
		tmp.print();
	}

	// recocer vector
	file.clear();
	file.seekg(0);
	vector<Train> result;

	while (file.read(reinterpret_cast<char*>(&tmp), sizeof(Train)))
	{
		result.push_back(tmp);
	}
	for (auto& i : result)
	{
		cout << "\n -------------- \n";
		i.print();
	}

	auto it = find_if(result.begin(), result.end(), [](Train tmp) {return strcmp(tmp.from, "Lviv") == 0; });
	cout << "Result find :: \n";
	while (it != result.end())
	{
		it->print();
		it = find_if(it + 1, result.end(), [](Train tmp) {return strcmp(tmp.from, "Lviv") == 0; });
		cout << endl;
	}
	cout << "\n\n ==============================\n\n";
	result.clear();
	file.clear();
	file.seekg(0, ios_base::end); //
	size_t lengthFile = file.tellg(); 
	size_t count = lengthFile / sizeof(Train);
	result.resize(count);

	file.clear();
	file.seekg(0);
	file.read(reinterpret_cast<char*>(result.data()), sizeof(Train) * count);
	cout << "\n ----- Recover vector<Train> from file ::: other way" << endl;
	for (auto& i : result)
	{
		i.print();
		cout << "\n -------------- \n";
	}

	int index = 3;
	file.clear();
	file.seekg((index) * sizeof(Train));
	file.read(reinterpret_cast<char*>(&tmp), sizeof(Train));
	cout << "Result Train with index 3" << endl;
	tmp.print();
}
