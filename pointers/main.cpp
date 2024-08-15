# include <iostream>

using namespace std;

int main()
{
    int Address = 3509;

    int* PointerToDir;

    PointerToDir = &Address;
    *PointerToDir = 3;

    cout << Address << endl;
    

    return 0;
}

