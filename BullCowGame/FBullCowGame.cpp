#include "FBullCowGame.h"



FBullCowGame::FBullCowGame()
{
	Reset();
}

void FBullCowGame::Reset(){
	myCurrentTry = 1;
	myHiddenWord = "penis"; // must be an isogram or the game will break
	bIsWon = false;
	return;
}


int FBullCowGame::getCurrentTry() const{
	return myCurrentTry;
}

int32 FBullCowGame::getHiddenWordLength() const
{
	return myHiddenWord.length();
}

//to use the enum list you must use EWordStatus::
EGuessValidity FBullCowGame::confirmWord(FString guess) const{
	 
	

	if (isIsogram(guess))//if the guess isn't an isogram 
	{
		return  EGuessValidity::NOT_ISOGRAM;
	}
	else if (!(isLowerCase(guess))) //if the guess isn't all lowercase
	{
		return EGuessValidity::NOT_LOWERCASE;
	}
	else if (guess.length() != getHiddenWordLength())  //if the guess is the wrong length
	{
		return EGuessValidity::WRONG_LENGTH;
	}
	else
	{
		return EGuessValidity::OK;
	}
}

int FBullCowGame::getMaxTries() const {

	TMap <int32, int32> wordLenghtToMaxTries{ {3,5},{4,6},{5,9}, {6,12} };

	return wordLenghtToMaxTries[myHiddenWord.length()];
}



bool FBullCowGame::IsGameWon() const {
	
	return bIsWon;
}


bool FBullCowGame::isIsogram(FString guess) const
{
	if (guess.length() <= 1) { return false; }
	
	TMap <char, bool> letterSeen;//set up map
	for (auto letter : guess)//loop through each letter of the guess
	{
		letter = tolower(letter);
		if (letterSeen[letter]) { return true; } // check to see if the letter has been used yet
		else {
			letterSeen[letter] = true;
		}

	}
	return false;
}

bool FBullCowGame::isLowerCase(FString guess) const
{
	if (guess.length() <= 1) { return true; }
	for (auto letter : guess)
	{
		if (!islower(letter)) // if the letter is NOT a lower case FALSE
		{
			
			return false;
		}
	}
	return true;
}

FBullCowCount FBullCowGame::awardAnimals(FString guess)
{
	
	myCurrentTry++;
	//setup a return value
	FBullCowCount count;
	int maxlength = myHiddenWord.length();
	//loop through all letters in the guess
	for (int32 gx = 0; gx < maxlength; gx++) {
		// compare place against hidden word and increment any bulls
		
		
		for (int32 hx = 0; hx < maxlength; hx++) {
			//check if any letter used in the guessed word matches a letter in the hidden word
			if (guess[gx] == myHiddenWord[hx]){
				if (gx == hx){
					count.bulls++;
				}
				else {
					count.cows++;
				}
			}
			
		}
		if (count.bulls == myHiddenWord.length())
		{
			bIsWon = true;

		}
		else
		{
			bIsWon = false;
		}
		
	}


	return count;
}
