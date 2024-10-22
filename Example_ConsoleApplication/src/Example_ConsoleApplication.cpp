// Example_ConsoleApplication.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*
#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
}
*/
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

#include "..\..\CrossView\src\CrossView.h"

#include <iostream>

struct EntryPointInitializer {
    EntryPointInitializer(int width, int height, const wchar_t* title) {
        almond::EntryPoint entryPoint(width, height, title);
        // Call any other initialization or setup here if needed
    }
};

// Example usage to trigger initialization
EntryPointInitializer init(800, 600, L"Game Title");



//int main(){} //thanks VS Code for defeating the purpose
/*
struct runit {
    runit()
    {
        std::cout << "runned!\n";

almond::EntryPoint ep(800, 600, L"VS Code/MSBuild Compiled!!!!");

        ep.show();

        //  while (true)
        // {
            std::cout << "cruising!\n";
            //   ep.pollEvents();
        // }

    }

} init;

*/