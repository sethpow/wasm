#include <cstdlib>
#include <iostream>

#include <emscripten.h>

void guessingGame(void * _guess)
{
    const auto guess = static_cast<unsigned int*>(_guess);
    unsigned int userGuess = 0;
    std::cout << "Please enter a guess between 1-100.\n";
    
    std::cin >> userGuess;

    if(userGuess > 100 || userGuess < 1)
    {
        std::cerr << userGuess << " - is an invalid input\n";
        delete guess;
        emscripten_cancel_main_loop();
    }
    else if(userGuess > *guess)
    {
        std::cout << userGuess << " - is too high\n";
    }
    else if(userGuess < *guess)
    {
        std::cout << userGuess << " - is too low\n";
    }
    else
    {
        std::cout << userGuess << " - is... Correct!!\n";
        emscripten_cancel_main_loop();
    }
    
}

int main()
{
    srand(time(NULL));
    unsigned int* guess = new unsigned int(rand() % 100 +1);

    //  guessingGame represents 1 iteration of the loop, so JS doesnt hang indefinitely
    //  call guessingGame, pass in guess, 0 fps, false (whether you should simulate an inf loop or not)
    emscripten_set_main_loop_arg(guessingGame, guess, 0, false);
}