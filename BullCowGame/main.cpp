#include <iostream>
#include <string>
#include "FBullCowGame.h"

using ftext = std::string;
using int32 = int;


void PrintIntro();
/*std:: is the standard library (can circumvent by using the "using" key word, but this is bad codding practice if using more than one namspace.
	Never use the "using" keyword in a header file because any class that imports that header will use that namespace.
 */
ftext getGuess();
FBullCowGame Game;
void PlayGame();
bool AskToReplay();

int main(){
	
	
	do {
		PrintIntro();
		PlayGame();
	} while (AskToReplay());
	
	return 0; 
}


void PlayGame()
{
	
	Game.Reset();
	int32 MAX_GUESSES = Game.getMaxTries();

	for (int32 i = 0; i < MAX_GUESSES; i++) {

		ftext guess = getGuess();
		std::cout << "Your guess was " << guess << std::endl;  

	}
	//TODO give a game summary
}

bool AskToReplay()
{
	std::cout << "Would you like to play again?" << std::endl << "Y = yes, N = no" << std::endl;
	ftext choice = " ";
	getline(std::cin, choice);
	char first = choice[0];
	if (first == 'y' || first == 'Y')
	{
		return true;
	}
	else {
		if (first == 'n' || first == 'N')
		{
			return false;
		}
	}
}

std::string getGuess() //TODO needs to validate guess
{
	int32 tryNum = Game.getCurrenttry();
	std::cout << std::endl << "Try " << tryNum << ": Enter your guess" << std::endl;
	std::string guess = "";
	getline(std::cin, guess);
	return guess;
}

void PrintIntro() {
	constexpr int32 MAX_LENGTH = 5; 
	std::cout << "Welcome to Bulls and Cows!\nCan you guess the " << MAX_LENGTH << " letter isogram that I'm thinking of?";
	return;
}
