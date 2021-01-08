#include <iostream>

int main()
{
    std::string user_input{""};

    std::cout << "Hey! How are you doing?\n";
    std::cin >> user_input;

    std::cout << "You're doing " << user_input << "?\n";
    std::cout << "Using WebAssembly to compile C++ code to run on the web!\n";

    return 0;
}