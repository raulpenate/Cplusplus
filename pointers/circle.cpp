#include <iostream>
#include <cmath>

using namespace std;

enum Figure
{
    CIRCLE,
    SPHERE
};
// This is a function prototype - declaration
// this tells the compiler about the func name return type before it encounters the implementation
// before main() func is executed, like hosting in JS
double calculateArea(Figure figure, int *radius);

int main()
{
    // This assignment
    int radius = 0;
    cout << "Radius value: " << radius << endl;
    cout << "Radius memory reference: " << &radius << "\n" << endl;
    
    cout << "Write down the Circle radius: ";
    cin >> radius;
    double value = calculateArea(CIRCLE, &radius);
    cout << "The area of the circle is: " << value << "\n" << endl;

    cout << "Write down the Sphere radius: ";
    cin >> radius;
    value = calculateArea(SPHERE, &radius);
    cout << "The surface area of the sphere is: " << value << endl;

    return 0;
}

double calculateArea(Figure figure, int *radius)
{
    // Dereferencing: The *radius gives you the value stored at the memory address radius, which is the actual integer value you input.
    // When you print radius without dereferencing it, you're printing the memory address where the variable is stored.
    cout << "Radius value: " << *radius << endl;
    cout << "Radius memory reference: " << radius << endl;

    if (figure == CIRCLE)
    {
        return M_PI * pow(*radius, 2);
    }
    
    if (figure == SPHERE)
    {
        return 4 * M_PI * pow(*radius, 2);
    }

    return 0;
}
