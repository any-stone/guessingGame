#include <iostream>
#include <string>
#include <cstdlib>

bool playGame(int guesses) {
    std::cout << "Playing game..." << std::endl;
    int correct;
    srand(time(NULL));
    if (guesses == 1) {
        correct = rand() % 200;
    } else {
        correct = rand() % 20;
    }

    std::cout << "Correct # is: " << correct << std::endl;
    int guessCount = 0;
        std::cout << "You get " << guesses << " guesses" << std::endl;
    while(guessCount < guesses) {
        std::cout << "Guess a number..." << std::endl;

        int guess;
        std::cin >> guess;
        if (guess == correct) {
            return true;
        } else if (guess < correct) {
            std::cout << "Too low mate!" << guess << std::endl;
        } else {
            std::cout << "Too high mate!" << guess << std::endl;
        }
        guessCount++;
        std::cout << "You've guessed " << guessCount << " times." << std::endl;
    }
    return false;
}

int main() {

    std::cout << "Hey! Do you want to play a game? (y/n) " << std::endl;

    std::string response;
    std::getline(std::cin, response);
    std::cout << "You entered: " << response << std::endl;

    // Safety check: is there anything in the string?
    if (!response.empty()) {
        char firstChar = tolower(response[0]); // Get first char and lowercase it

        if (firstChar == 'y') {
            std::cout << "Let's play a game then..."  << std::endl;

            std::cout << "Have you beat the game?\n1: yes\n0: no" << std::endl;
            bool beatGame;
            std::cin >> beatGame;

            bool won;
            if(beatGame) {
                std::cout << "Since you beat the game, you can play impossible mode." << std::endl;
                won = playGame(1);
            } else {
                std::cout << "What difficulty?\n0: easy\n1: medium\n2: hard " << std::endl;
                int difficulty;
                std::cin >> difficulty;

                switch(difficulty) {
                    case 0:
                        won = playGame(10);
                        break;
                    case 1:
                        won = playGame(5);
                        break;
                    case 2:
                        won = playGame(3);
                        break;
                    default:
                        std::cout << "Bro what?.." << std::endl;
                        break;
                }
            }
            if (won) {
                std::cout << "Congrats, you won!" << std::endl;
            } else {
                std::cout << "No winning this time. Try again later..." << std::endl;
            }
        } else if (firstChar == 'n') {
            std::cout << "Ok, maybe next time. Goodbye!" << std::endl;
        } else {
            std::cout << "Hmmmm... I don't understand" << std::endl;
        }
    } else {
        std::cout << "You didn’t type anything!" << std::endl;
    }

    return 0;
}

