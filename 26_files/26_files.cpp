#include <iostream>
#include <fstream>
#include <string>

using namespace std;
void printStaticCin()
{
    cout << "Good :: " << cin.good() << endl;
    cout << "EOF :: " << cin.eof() << endl;
    cout << "Fail :: " << cin.fail() << endl;
    cout << "Bad :: " << cin.bad() << endl;
}

void writeToFileArray(const int* arr, const size_t& size, const string& pathFile);
void showFile(const string& pathFile);
int* readArrayFromFile(size_t& size, const string& pathFile);

int main()
{
    //printStaticCin();
    //int value;
    //cout << "Enter int number : \n";
    //while (cin >> value) // cin.good(); true
    //{
    //    cout << "\t\t Value :: " << value << endl;
    //}
    //printStaticCin();

    //cin.clear(); 
    ////cin.ignore(2000, '\n');
    //cout << "Test avail :: " << cin.rdbuf()->in_avail() << endl;
    //cout << "\n Input again :: ";
    //cin >> value;
    //cout << "Value " << value << endl;

    const size_t SIZE = 5;
    int arr[SIZE]{ 10,12,100,-34,77 };
    string fname = "number.txt";
    /*writeToFileArray(arr, SIZE, fname);*/
    showFile(fname);

    size_t size;
    int* arr_;
    arr_ = readArrayFromFile(size, fname);
    for (size_t i = 0; i < size; i++)
    {
        cout << arr_[i] << "\t";
    }cout << endl;
}

void writeToFileArray(const int* arr, const size_t& size, const string& pathFile)
{
    ofstream file;
    file.open(pathFile/*,ios_base::out | ios_base::app | ios_base::trunc */); // out - для запису; app - для додавання, trunc - очистити вміст файлу
    if (!file.is_open())
    {
        cout << "Error opening file " << pathFile << " for write" << endl;
        return;
    }
    for (size_t i = 0; i < size; i++)
    {
        file << arr[i] << "\n";
    }
    cout << "Array was successfully written" << endl;
}

void showFile(const string& pathFile)
{
    fstream file(pathFile, ios_base::in); //ios_base::in - для читання
    if (!file.good())
    {
        cout << "Error opening file :: " << pathFile << " for read" << endl;
        return;
    }
    // 1 way
    cout << "--------- Content by rdbuf() ----------------" << endl;
    cout << file.rdbuf() << endl;

    // 2 way : read line by line
    cout << "--------- Content by getline(file, ...) ----------------" << endl;
    string line;
    int i = 0;
    file.seekg(0);
    while (getline(file,line))
    {
        cout << ++i << ": \t " << line << endl;
    }

    // 3 way 
    file.clear();
    cout << file.tellg() << endl;
    cout << "--------- Content by char ----------------" << endl;
    char ch;
    file.seekg(0);
    while (file.get(ch)) // читаємо з файлу по 1 символу доки це можливо 
    {
        cout << ch;
    }
    // 4 way 
    cout << "--------- Content by char again ----------------" << endl;
    ch;
    file.clear();
    file.seekg(0);
    while ((ch = file.get()) != EOF) // читаємо з файлу по 1 символу доки це можливо  (доки не зустрінемо ознаку кінця файлу)
    {
        cout << ch;
    }
}

int* readArrayFromFile(size_t& size, const string& pathFile)
{

    size = 0;
    fstream file(pathFile, ios_base::in);
    if (!file.is_open())
    {
        cout << "Error opening file :: " << pathFile << " for read" << endl;
        return nullptr;
    }

    int value;
    while (file >> value)
    {
        ++size; // лічимо числа у фвйлі
    }
    file.clear();
    file.seekg(0, ios_base::beg);
    int* arr = new int[size];
    int i = 0;
    while (file >> value)
    {
        arr[i] = value;
        i++;
    }
    return arr;
}
