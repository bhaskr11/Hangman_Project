#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
using namespace std;

const int MAX_TRIES=4;

/* Take a one character guess and fill in the unfinished guessword. 
Returns the number of characters matched. 
	Returns zero if the character is already in the word */
	
int drawline(){
	cout<<"-----------------------";
	return 0;
}

int guessLetter (char guess, string unknownword, string &guessword)
{
	int i;
	int match=0;
	for (i = 0; i< unknownword.length(); i++)
	{
		// return nothing if already guessed
		if (guess == guessword[i])
			return 0;
		// if guessed character is correct put the guessed character in the word
		if (guess == unknownword[i])
		{
			guessword[i] = guess;
			match++;
		}
	}
	return match;
}

int main ()
{
	string name;
	char letter,exit;
	int num_of_wrong_guesses=0;
	string word;
	string words[] =
	{
		"azerbaijan",
		"nepal",
		"pakistan",
		"singapore",
		"philippines",
		"australia",
		"bhutan",
		"ethiopia",
		"eritrea",
		"indonesia"
	};

	//randomly pick the word from the array of strings
	srand(time(NULL));				//random picks everytime program is run
	int i=rand()% 10;
	word=words[i];
    
	// Hide the unknown word with *'s
	string unknown(word.length(),'*');

	// welcome
	cout << "\n\nWelcome to guess a country Name";
	cout << "\n\nEach letter is represented by a star.";
	cout << "\n\nTYPE ONLY ONE LETTER AT A TIME!";
	cout << "\n\nYou have " << MAX_TRIES << " tries to try and guess the word. :)\n";
	drawline();
	
	//Loop until the user runs out of guesses
	while (num_of_wrong_guesses < MAX_TRIES)
	{
		cout << "\n" << unknown;
		cout << "\n\nGuess a letter: ";
		cin >> letter;
		letter = tolower(letter);
		
		/*Fill unknowword with guessed letter if the guess is correct,
		 otherwise increment the number of wrong guesses. */
		 
		if (guessLetter(letter, word, unknown)==0)
		{
			cout << endl << "Sorry! Try Again!" << endl;
			num_of_wrong_guesses++;
		}
		else
		{
			cout << endl << "You found a letter!" << endl;
		}
		
		cout << "You have " << MAX_TRIES - num_of_wrong_guesses; //tell the user their remaining chances
		cout << " guesses left." << endl;
		drawline();
		
		
		/* Check if user guessed the word. */
		if (word==unknown)
		{
			cout << "\n\ncorrect word = " << word << endl;
			cout << "Congrats! You guessed it!";
			break;
		}
			
	}
	if(num_of_wrong_guesses == MAX_TRIES)
	{
		cout << "\nSorry, you're out of lives! :(" << endl;
		cout << "The word was : " << word << endl;
	}	

	cin.ignore();
	cin.get();
	return 0;
}
