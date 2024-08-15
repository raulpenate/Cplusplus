# include <iostream>

using namespace std;

public void doSomething()
{
    int i = 10;
    doSomethingElse(i);  // passes i by references since doSomethingElse() receives it
                         // by reference, but the syntax makes it appear as if i is passed
                         // by value
}

public void doSomethingElse(int& i)  // receives i as a reference
{
    cout << i << endl;
}

public void doSomething()
{
    int i = 10;
    doSomethingElse(&i);
}

public void doSomethingElse(int* i)
{
    cout << *i << endl;
}