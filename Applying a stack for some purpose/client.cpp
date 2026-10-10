//Elizabeth Fanton 9/28/26
//There is a problem with this program, it's not checking the balance properly...need to fix.
#include <iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include <stack>

using namespace std;

//prototype
bool checkingString(string checkWordz);
bool currentCharMatches(char open, char close);

int main()
{
	//Read the contents of a "hello world" program (using ifstream - not just your eyeballs)
	// and store the text in a string variable
	ifstream inDataProgram;
	string wordz = "";

	inDataProgram.open("C:\\Users\\Elizabeth\\Documents\\TJC FALL 2026 COSC-III\\client.cpp");

	if (inDataProgram.fail())
	{
		cout << "file failed to open.";
		return -1;
	}

	//storing file to string
	//output string
	/*while (!inDataProgram.eof())
	{
		getline(inDataProgram, wordz);
		cout << wordz << endl;
	}*/
	//Loop through an input string:
	int numOfRuns = 0;
	while (!inDataProgram.eof())
	{
		getline(inDataProgram, wordz);
		//cout << wordz << endl;//reading/output works
		//call functions
		cout << endl << checkingString(wordz);
		//currentCharMatches(wordz.begin(), wordz.end());
		numOfRuns++;
	}
	cout << endl << "numOfRuns: " << numOfRuns << endl;
	return 0;
}
//functions
bool checkingString(string checkWordz)
{
	stack<char> openParenthesesAndBracket;
	for (auto& theCharacter : checkWordz)
	{
		if (theCharacter == '(' || theCharacter == '{')
		{
			openParenthesesAndBracket.push(theCharacter);
		}
		else if (theCharacter == ')' || theCharacter == '}')
		{
			if (openParenthesesAndBracket.empty())
			{
				cout << "False: Close symbol MUST be preceded by an open symbol." << endl;
				return false;
			}

			if (currentCharMatches(openParenthesesAndBracket.top(), theCharacter))//calls currentCharMatches function here.
			{
				openParenthesesAndBracket.pop();
			}
			else
			{
				cout << "currentCharMatches returned false, so string is unbalanced." << endl;
				return false;
			}
			// add else (neither an open symbol nor a close symbol)
			//else
			//{

			//}
		}
	}

	if (!openParenthesesAndBracket.empty())
	{
		return false;
	}
	else
	{
		return true;
	}

};//end of checkingString
	bool currentCharMatches(char open, char close)
	{
		if (open == '(' && close == ')')
		{
			cout << endl << "True: Open character is: '(' and the close character is: ')'." << endl;
			return true;
		}
		else if (open == '{' && close == '}')
		{
			cout << "True: Open character is: '{' and the close character is: '}'." << endl;
			return true;	
		}
		else
		{
			cout << "False: String is unbalanced." << endl; 
			return false;			
		}
	};


