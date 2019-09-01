//written by Jtaim
//date 8 Apr 2017
//Programming Principles and Practice Using C++ Second Edition, Bjarne Stroustrup

/*
Section 5 exercise 12
Bulls and Cows game.
Guess the 4 numbers range(0 to 9)
*/

#include "section5.h"

using vType = std::vector<int>;
bool get_guesses(vType& input, const char term);
int get_bulls(const vType& guesses, vType& setSequence);
int get_cows(const vType& guesses, vType& setSequence);
const vType::value_type foundMark = std::numeric_limits<vType::value_type>::max();

int main()
try{
	const char termination = '|';

	vType const setNumbers{2, 5, 8, 1};
	vType guesses{};
	guesses.reserve(setNumbers.size());

	std::cout << "Guess " << setNumbers.size() << " numbers in the range of 0 - 9 to guess what I have.\n";
	std::cout << "If guess a correct number and the correct location will get a Bull.\n";
	std::cout << "If guess a correct number but not the correct location then will get a Cow.\n";
	std::cout << "Example: My set is 2345 and your guess was 5248, so there are 2 Cows (5 and 2)  1 Bull (4).\n\n";
	std::cout << "Enter your guess.  To quit enter '" << termination << "'.\n";

	while(get_guesses(guesses, termination)){
		if(guesses == setNumbers){
			std::cout << "You have " << setNumbers.size() << " Bulls, Congratulations!\n";
			break;
		} else{
			auto temp = setNumbers;
			auto bulls = get_bulls(guesses, temp);
			auto cows = get_cows(guesses, temp);

			std::cout << "The result is " << cows << (cows == 1 ? " Cow" : " Cows");
			std::cout << " and " << bulls << (bulls == 1 ? " Bull" : " Bulls") << ". Try again.\n";
			guesses.clear();	// clear for new set of guesses
		}
	}

	std::cout << "Bye\n";
	keep_window_open();
	return 0;
}
catch(std::exception& e){
	std::cerr << "error: " << e.what() << '\n';
	keep_window_open();
	return 1;
}
catch(...){
	std::cerr << "Oops: unknown exception!\n";
	keep_window_open();
	return 2;
}

/* function to get user input for guesses or termination.
INPUT:  vType reference to place valid guesses in.
OUPUT:  bool true = got valid guesses
		bool false = got valid termination.
ERROR: invalid guess or termination.
*/
bool get_guesses(vType& input, const char term)
{
	for(vType::size_type itr = 0; itr < input.capacity(); ++itr){
		char guess{};
		std::cin >> guess;
		//check for valid number or escape entry
		if(guess == term){
			return false;
		}
		//convert number char to integer and place into a vector
		else if(isdigit(guess)){
			vType::value_type i = guess - '0'; // '9'(57) - '0'(48) provides 0 to 9
			input.push_back(i);
		} else{
			error("Bad entry data!");
		}
	}
	return !input.empty();
}

/* function to bulls.
INPUT: vType reference to user input guesses.
	   vType reference to number to guess.
OUPUT: int for number of bulls found
ERROR: no error.
modifies set sequence by setting matching elements to type max number
*/
int get_bulls(const vType& guesses, vType& setSequence)
{
	int bulls{};
	auto j{setSequence.begin()};
	for(auto i{guesses.cbegin()}; i < guesses.cend(); ++i, ++j){
		if(*i == *j){
			++bulls;
			*j = foundMark;
		}
	}
	return bulls;
}

/* function to cows.
INPUT: vType reference to user input guesses.
	   vType reference to number to guess.
OUPUT: int for number of cows found
ERROR: no error.
modifies set sequence by setting matching elements to type max number
*/
int get_cows(const vType& guesses, vType& setSequence)
{
	int cows{};
	for(auto j{setSequence.begin()}; j < setSequence.end(); ++j){
		for(auto i{guesses.cbegin()}; i < guesses.cend(); ++i){
			if(*i == *j){
				++cows;
				*j = foundMark;
				break;
			}
		}
	}
	return cows;
}
