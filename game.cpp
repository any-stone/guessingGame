#include <iostream>
#include <string>
#include <cstdlib>
#include "game.h"

bool playGame(int guesses) {
    std::cout << "Playing game..." << std::endl;
    int correct;
    srand(time(NULL));
    if (guesses == 1) {
        correct = rand() % 200;
    } else {
        correct = rand() % 20;
    }

    //std::cout << "Correct # is: " << correct << std::endl;
    std::cout << "You get " << guesses << " guesses" << std::endl;

    for (int guessesLeft = guesses; guessesLeft > 0; guessesLeft--) {
        std::cout << "Guess a number..." << std::endl;
        int guess;
        std::cin >> guess;
        if (guess == correct) {
            return true;
        } else if (guess < correct) {
            std::cout << "Too low mate! " << guess << std::endl;
        } else {
            std::cout << "Too high mate! " << guess << std::endl;
        }
        std::cout << "You've have " << guessesLeft-1 << " guesses left." << std::endl;
    }
    return false;
}