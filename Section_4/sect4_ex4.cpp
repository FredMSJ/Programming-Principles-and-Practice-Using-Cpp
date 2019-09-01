//written by Jtaim
//date 31 Mar 2017
//Programming: Principles and Practice Using C++ Second Edition

/*
Section 4 exercise 4.
A program to play a numbers guessing game.
The user thinks of a number between 1 and 100 and your program asks questions to figure out what the number is
(e.g., "Is the number you are thinking of less than 50?").
Your program should be able to identify the number after asking no more than seven questions.
Hint: Use the < and <= operators and the if-else construct.
*/

#include "section4.h"

int main()
{
	int constexpr maxRange{100};       // maximum number can select
	int constexpr minRange{1};         // minimum number can guess
	int constexpr maxGuessAttempts{7}; // maximum number of times to ask before identifying the number

	int high{maxRange}; 				// keeps track of a new high
	int low{minRange};					// keeps track of a new low
	int guess{(high - low) / 2 + low};	// keeps track of the next guess
	int guessAttempts{};				// keeps count of guess count

	std::cout << "Pick a number between " << low << " and " << high << " and let me try to guess it by asking some questions.\n";

	bool isFound{false};
	while(!isFound && guessAttempts < maxGuessAttempts){
		std::cout << "Is your number <= " << guess << " (y or n)? ";
		char yesOrNo{};
		std::cin >> yesOrNo;
		yesOrNo = static_cast<char>(std::tolower(yesOrNo));
		if(yesOrNo == 'y' || yesOrNo == 'n'){
			guessAttempts++;
			if(yesOrNo == 'y'){
				high = guess;
			} else{
				low = guess + 1;
			}
			if(high == low){
				isFound = true;
			} else{
				guess = (high - low) / 2 + low;
			}
		} else{
			std::cout << "You did not pick a valid (y or n) answer.  Select again.\n";
		}
	}

	if(isFound){
		std::cout << "Found the answer " << high << " in " << guessAttempts << " guesses.\n";
	} else{
		simple_error("Exceeded max number of guesses\n");
	}

	keep_window_open();
	return 0;
}
