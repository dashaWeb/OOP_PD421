#include <iostream>
#include <stack>
#include "MyStack.h"
using namespace std;


int main()
{
	/*MyStack<int> st(2, 2);
	cout << "Size :: " << st.size() << endl;
	int value;
	for (size_t i = 0; i < 5; i++)
	{
		cout << "Value push :: " << (value = rand() % 100) << endl;
		st.push(value);
	}
	cout << "Size :: " << st.size() << endl;
	cout << "Top  :: " << st.top_() << endl;
	st.pop();
	cout << "Top now  :: " << st.top_() << endl;*/

	stack<string> st;
	st.push("one");
	st.push("two");
	st.push("three");
	cout << "Size :: " << st.size() << endl;
	if (!st.empty())
		cout << "Top :: " << st.top() << endl;
	st.pop();
	cout << "Top :: " << st.top() << endl;
	cout << "Size :: " << st.size() << endl;
}

