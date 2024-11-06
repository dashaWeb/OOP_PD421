#include <iostream>
#include <tuple>
#include <initializer_list>
using namespace std;

int** createMatrix(const size_t& row, const size_t& col)
{
    int** arr = new int* [row];
    for (size_t i = 0; i < row; i++)
    {
        arr[i] = new int[col];
    }
    return arr;
}

void fillMatrix(int** arr, const size_t& row, const size_t& col, int min = 1, int max = 20)
{
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            arr[i][j] = min + rand() % (max - min + 1);
            cout << arr[i][j] << "\t";
        }cout << endl;
    }
}

pair<int, int> minMaxValue(int** arr, const size_t& row, const size_t& col)
{
    int max = arr[0][0];
    int min = arr[0][0];
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            if (max < arr[i][j])
                max = arr[i][j];
            if (min > arr[i][j])
                min = arr[i][j];
        }
    }
    return { min,max };
}

using Product = tuple<string, double, size_t>;
int main()
{
    
    pair<int, string> p{ 100,"Test" };
    pair<int, string> p2{ 200,"Test2" };
    cout << "first pair  :: " << endl;
    cout << "pair first  :: " << p.first << endl;
    cout << "pair second :: " << p.second << endl;

    cout << "second pair :: " << endl;
    cout << "pair first  :: " << p2.first << endl;
    cout << "pair second :: " << p2.second << endl;

    p.swap(p2);
    cout << endl;
    cout << "first pair  :: " << endl;
    cout << "pair first  :: " << p.first << endl;
    cout << "pair second :: " << p.second << endl;

    cout << "second pair :: " << endl;
    cout << "pair first  :: " << p2.first << endl;
    cout << "pair second :: " << p2.second << endl;

    int row = 2, col = 3;
    int** matrix = createMatrix(row,col);
    fillMatrix(matrix, row, col);
    //pair<int,int>
    auto minmax = minMaxValue(matrix, row, col);
    cout << "Min :: " << minmax.first << endl;
    cout << "Max :: " << minmax.second << endl;

    minmax.first = 333;
    cout << "Min :: " << minmax.first << endl;

    //tuple<string, double, size_t> product{"Bread",17.5, 100};
    Product product{"Bread",17.5, 100};
    cout << get<0>(product) << "\t" << get<1>(product) << "\t" << get<2>(product) << endl;

    cout << "\n\n ================= initializer_list =====================" << endl;
    initializer_list<int> list{ 10,23,-33,44,77 };
    cout << "Size  :: " << list.size() << endl;
    cout << "First :: " << *list.begin() << endl;
    cout << "Last  :: " << *(list.end() - 1) << endl;

    cout << "\n\n ================= All list(for with []) =====================" << endl;
    for (size_t i = 0; i < list.size(); i++)
    {
        cout << list.begin()[i] << "\t";
    }cout << endl;

    cout << "\n\n ================= All list(for with pointers) =====================" << endl;
    for (auto ptr = list.begin(); ptr != list.end(); ptr++)
    {
        cout << *ptr << "\t";
    }cout << endl;

    cout << "\n\n ================= All list(range for) =====================" << endl;
    for (auto& item : list)
    {
        cout << item << "\t";
    }cout << endl;

    int arr[]{ 1,2,3,4,5,6,7,8 };
    for (auto& i : arr)
    {
        cout << i << "\t";
    }cout << endl;
}
