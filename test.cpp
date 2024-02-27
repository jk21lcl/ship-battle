#include <vector>
#include <iostream>
using namespace std;
int main()
{
    vector<int> a = {1,2,3,4,5};
    auto it = a.begin();
    while (it != a.end())
    {
        if (*it == 2)
            it = a.erase(it);
        else 
        {
            (*it)++;
            it++;
        }
    }
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << " ";
    return 0;
}