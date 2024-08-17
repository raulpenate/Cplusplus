# C++ is cool bro
This repo was made just to learn `C++` pointers, and things that I was missing in CS journey.

## Honestly
You don't need to learn it if you're going to use it, but in case you're curious with this code you can understand it clearly if you already know any other High Level language:

```cpp
#include <iostream>
#include <cmath>

using namespace std;

enum Figure
{
    CIRCLE,
    SPHERE
};

// This is a function prototype
// this tells the compiler about the func name return type before it encounters the implementation
// before main() func is executed, like hosting in JS
double calculateArea(Figure figure, int *radius);

int main()
{
    int radius = 0;
    // If we print the values, we get:
    cout << "Radius value: " << radius << endl; // 0
    cout << "Radius memory reference: " << &radius << "\n" << endl; // 0x7ffd65f2e57c
    

    cout << "Write down the Circle radius: ";
    cin >> radius; // The user writes: 10

    // Here is where the magic happens, because instead of passing the value of radius (10) as any other High-level language
    // we instead pass the memory reference (0x7ffd65f2e57c) using an ampersand and the variable name: &radius
    double value = calculateArea(CIRCLE, &radius);
    cout << "The area of the circle is: " << value << "\n" << endl;

    cout << "Write down the Sphere radius: ";
    cin >> radius; // The user writes: 10
    
    // and again
    value = calculateArea(SPHERE, &radius);
    cout << "The surface area of the sphere is: " << value << endl;

    return 0;
}

// Here we ask for the pointer *radius
double calculateArea(Figure figure, int *radius)
{
    // Dereferencing: The *radius gives you the value (10) stored at the memory address radius, which is the actual integer value you input.
    // When you print radius without dereferencing it, you're printing the memory address (0x7ffd65f2e57c) where the variable is stored.
    cout << "Radius value: " << *radius << endl; //10
    cout << "Radius memory reference: " << radius << endl; //0x7ffd65f2e57c

    if (figure == CIRCLE)
    {
        // Here we use that pointer
        return M_PI * pow(*radius, 2);
    }
    
    if(figure == SPHERE){
        // And again
        return 4 * M_PI  * pow(*radius, 2);
    }

    return 0;
}
```

Here you can see the program in action:
![running](https://raw.githubusercontent.com/raulpenate/Cplusplus/main/info/example.png)

# How to Run C++ inside VSCode

## 1 - Monolithic projects

- Install __C++ Code Pack__ and __Code Runner__ extension:
![c++ extension](https://raw.githubusercontent.com/raulpenate/Cplusplus/main/info/extension-cpp.png)
![coderunner extension](https://raw.githubusercontent.com/raulpenate/Cplusplus/main/info/extension-cr.png)

- Press `ctrl + ,` Search __code runner terminal__ and Allow __Code Runner__ to run in the terminal, in case you need to use `cin` to insert data to your program.
![coderunner extension](https://raw.githubusercontent.com/raulpenate/Cplusplus/main/info/code-runner.png)

- Congratulation, now you can runt it just pressing `ctrl + enter` or the `Run Code` button, and __Code Runne__ will create the commands for you to compile the file and show it.
![Running](https://raw.githubusercontent.com/raulpenate/Cplusplus/main/info/running.png)

### Personal tweaks 
In case you want to an script that creates a `bin` folder and `bin` files inside that folder automatically, I made this personal tweak in my code runner inside VSCode to make that possible:
```bash
 "code-runner.executorMap": {
      ...
      "cpp": "cd $dir && ./$workspaceRoot/helper/make_bin_folder.sh && g++ $fileName -o bin/$fileNameWithoutExt && bin/$fileNameWithoutExt",
```
[Code Runner](https://marketplace.visualstudio.com/items?itemName=formulahendry.code-runner) have [customized parameters](https://marketplace.visualstudio.com/items?itemName=formulahendry.code-runner#:~:text=Supported%20customized%20parameters,Select%20Interpreter%20command), something that is similar to `.env` variables, so I just made a script to target the `$workspaceRoot` folder, to create the `bin` folder, for the `bin` files created when are compiled with GNU C++ compiler invocation command (`g++ $fileName -o bin/$fileNameWithoutExt`)

Script insde `helper/make_bin_folder.sh` to create `bin` folder in case this don't exist before creating the `bin` file:
```bash 
if ! [ -d bin ]; then
    echo "Creating \"bin\" folder"
    mkdir bin
else
    exit 0
fi
```
I must admin the `else` in unnecessary, but I like that `exit 0` guarantees that in case `bin` file exist it will finish the script as a succesful run and the pipeline keeps running.

## 2 - Modular projects
The make program is intended to automate the mundane aspects of transforming
source code into an executable. The advantages of make over scripts is that you can
specify the relationships between the elements of your program to make, and it knows
through these relationships and timestamps exactly what steps need to be redone to
produce the desired program each time. Using this information, make can also optimize the build process avoiding unnecessary steps.

```makefile
# using:
# make				# compile proyect
# make remove	#	remove all binaries and objects
# 
.PHONY = all clean ensamble remove

CC = g++
HEADERSDIR = ./Headers/include
SRCSDIR = ./Sources/src
MAINDIR = ./Sources

SRCS := $(wildcard ${SRCSDIR}/*.cpp)
OBJECTSRCS := ${SRCS:${SRCSDIR}/%.cpp=%.o}

all: ${OBJECTSRCS} main.o ensamble clean

ensamble: main.o
	@echo "Ensambling.."
	${CC} -o proyect.out *.o

%.o: ${SRCSDIR}/%.cpp
	@echo "Creating object..."
	${CC} -c -I ${HEADERSDIR} $<

main.o: ${MAINDIR}/main.cpp
	@echo "Compiling main.cpp.."
	${CC} -c -I ${HEADERSDIR} $<

clean:
	@echo "Cleaning compilation..."
	rm *.o

remove:
	rm -fv proyect.out
	rm -fv *.
```

And to build your project just build it `make` command and run the `bin` file with `./project.out` or the name you decided to use:
```
 make && ./proyect.out
 ```

 # Memes
 Oh yes, it happened and a lot..:

 ![memory](https://raw.githubusercontent.com/raulpenate/Cplusplus/main/info/segmentation-xd.png)

 ![meme](https://raw.githubusercontent.com/raulpenate/Cplusplus/main/info/meme.png)
