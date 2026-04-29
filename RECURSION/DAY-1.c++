#include <iostream>
using namespace std;

void func(int count)
{
    if(count == 4) return;

    cout << count << endl;
     count++;
    func(count);
}

int main() 
{
    int count = 0;
    func(count);

    return 0;
}