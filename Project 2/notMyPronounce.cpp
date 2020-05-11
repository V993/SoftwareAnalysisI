/*Author: Arterio ROdrigues
 *Course: CSCI-136
 *Instructor: Melissah
 *Assignment: 10A
 *Pronuce add phoneme
 */
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <string>
using namespace std;


void Identical(string Word, string afterID);
void AddPhoneme(string Word ,string afterID);
void RemovePhoneme(string Word, string afterID);
void ReplacePhoneme(string Word , string afterID);
void splitOnSpace(string s, string & before, string & after);

bool ReplacePhonemeCheck(string word1, string word2);
bool AddPhonemeCheck(string word1, string word2);
bool RemovePhonemeCheck(string word1, string word2);

string Pronunciation(string word , string& afterID);

int main() {

	string W ;
	string afterID;
	
   	cout << "> "; cin >> W; 
   	cout << endl;
   	
    cout << "Pronunciation   :" << Pronunciation(W ,afterID);
    cout << endl << endl;
    
    cout << "Identical       : " ; Identical(W , afterID);
    cout << endl;
   	
   	cout << "Add phoneme     : " ; AddPhoneme(W , afterID);
   	cout << endl;
   	
   	cout << "Remove phoneme  : " ; RemovePhoneme(W, afterID);
   	cout << endl;
   	
    cout << "Replace phoneme : " ; ReplacePhoneme(W , afterID);
}
//use to find Remove Phoneme
void RemovePhoneme(string Word, string afterID)
{
	string s;
	string afterSpace;
	string beforeSpace;
	
	
	int check = 0;
	
	ifstream fin("cmudict.0.7a");
	
	for(int i = 0; i < Word.length(); i++)
       Word[i] = toupper(Word[i]);
	     
	while(getline(fin, s))
	{
		//Split for afterspace
		splitOnSpace(s, beforeSpace, afterSpace);
		
		//Check if afterspace is a remove phoneme
		if(RemovePhonemeCheck(afterID , afterSpace))
		{
			cout << beforeSpace << " ";
		}
	}
	fin.close();
}


//Checks Remove Phoneme
bool RemovePhonemeCheck(string word1, string word2)
{
	string before;
 	string after;
 	string before1;
 	string after1;
 	
 	string w = word1;
 	string s = word2;
 	
 	int check = 0;
 	int i = 0;
 	
	//Split w and s into phoneme 
 	while(i < word1.length())
 	{
 		splitOnSpace( w,  before, after);
 		splitOnSpace( s,  before1, after1);
 		
		//If before split dont equal set s back one form w
  		if(before != before1)
  		{
  			check++;
  			s = s;
  		}
  		else
  			s = after1;
 		
 		w = after;
 		i++;
 			
 	}
	
	//if only one phoneme removed send true
	if(check == 1)
 			return true;
 		else
 			return false;
}
//use to find add Phoneme
void AddPhoneme(string Word ,string afterID)
{
	string s;
	string afterSpace;
	string beforeSpace;
	
	bool flag = false;
	
	int check = 0;
	
	ifstream fin("cmudict.0.7a");
	
	for(int i = 0; i < Word.length(); i++)
       Word[i] = toupper(Word[i]);
	     
	while(getline(fin, s))
	{
		splitOnSpace(s, beforeSpace, afterSpace);
		
		//Send afterSpace to check if it is a Addphoneme
		if(AddPhonemeCheck(afterID , afterSpace))
		{
			for(int i = 0; i < beforeSpace.length(); i++)
			{
				//If true is returned chack if the afterSpace had a ' is so flag = true
				if(isalpha(beforeSpace[i]) || beforeSpace[i] == char(39))
					flag = true;
				else 
				{
					flag = false;
					break;
				}
			}
			//print the AddPhoneme
			if(flag)
				cout << beforeSpace << " ";
		}
	}
	fin.close();
}

//Checks add phoneme
bool AddPhonemeCheck(string word1, string word2)
{
	string before;
 	string after;
 	string before1;
 	string after1;
 	
 	string w = word1;
 	string s = word2;
 	
 	int check = 0;
 	int i = 0;
 	
	//keep spilting the after space to see if any phoneme dont match
 	while(i < word1.length())
 	{
 		splitOnSpace( w,  before, after);
 		splitOnSpace( s,  before1, after1);
 		
		//Add one if they dont match
		//Sent word back one 
  		if(before != before1)
  		{
  			check++;
  			w = w;
  		}
  		else
  			w = after;
 		
 		s = after1;
 		i++;
 			
 	}
	//if only one phoneme was add send true
	if(check == 1)
 			return true;
 		else
 			return false;
}
//use to find Replace Phoneme
void ReplacePhoneme(string Word , string afterID)
{
	
	string s;
	string afterSpace;
	string beforeSpace;
	
	bool flag = false;
	
	int check = 0;
	
	ifstream fin("cmudict.0.7a");
	
	for(int i = 0; i < Word.length(); i++)
       Word[i] = toupper(Word[i]);
	     
	while(getline(fin, s))
	{
		splitOnSpace(s, beforeSpace, afterSpace);
		
		//Send to check if afterspace is a Replace Phoneme
		if(ReplacePhonemeCheck(afterID , afterSpace))
		{
			for(int i = 0; i < beforeSpace.length(); i++)
			{
				//If true is returned chack if the afterSpace had a ' is so flag = true
				if(isalpha(beforeSpace[i]) || beforeSpace[i] == char(39))
					flag = true;
				else 
				{
					flag = false;
					break;
				}
			}
			//print the replacePhoneme
			if(flag)
				cout << beforeSpace << " ";
		}
	}
	fin.close();
}

bool ReplacePhonemeCheck(string word1, string word2)
{
 	string before;
 	string after;
 	string before1;
 	string after1;
 	
 	string w = word1;
 	string s = word2;
 	
 	int check = 0;
 	int i = 0;
 	
 	while(i < word1.length())
 	{
 		splitOnSpace( w,  before, after);
 		splitOnSpace( s,  before1, after1);
 		if(before != before1)
 			check++;
 		i++;
 		w = after;
 		s = after1;
 			
 	}
 	if(check == 1 && i <= word2.length())
 		return true;
 	else
 		return false;
 	
}


//use to find Identical
void Identical(string Word, string afterID)
{
	string s;
	string beforeSpace;
	string afterSpace;
	
	ifstream fin("cmudict.0.7a");
	
	for(int i = 0; i < Word.length(); i++)
       Word[i] = toupper(Word[i]);
	     
	while(getline(fin, s))
	{
		splitOnSpace(s, beforeSpace, afterSpace);
		{
			//If the pronunciation of the word equal another word 
			//return the word 
			if(afterID == afterSpace && beforeSpace != Word)
			{	
				cout << beforeSpace << " ";
			}		 
		}
	}
	fin.close();
}
//use to find Pronunciation
string Pronunciation(string Word, string& afterID)
{
	string s;
	string beforeSpace;
	string afterSpace;
	
	//Open up file to be read
	ifstream fin("cmudict.0.7a");
	
	//Converts all letters to upper case
	for(int i = 0; i < Word.length(); i++)
       Word[i] = toupper(Word[i]);
       
	//Read each line at a time and save as 's'
	while(getline(fin, s))
	{
		//Split on space
		splitOnSpace(s, beforeSpace, afterSpace);
		{
			//Check if before equal entered word 
			//if so output pronunciation
			if(beforeSpace == Word)
			{
				fin.close();
				afterID = afterSpace;
				return afterSpace;
			}		
		}
	}
	return "Not found";
}


//Split a sentence at first space
void splitOnSpace(string s, string & before, string & after) {
  
    before = ""; 
    after = "";
	
	//Run thourgh each letter until a space
    int i = 0;
    while (i < s.size() && i != isspace(s[i])) { 
        before = before + s[i]; 
        i++; 
    }
  
    i++;
    
    while (i < s.size()) { 
        after = after + s[i]; 
        i++; 
    }
}
