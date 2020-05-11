/* 
Author: Leonardo Matone
Instructor: Katherine Howitt
Assignment: Project 2

takes an input and outputs the pronounciation of the inputted word, any words with 
identical pronunciations, replaced phonemes, added phonemes, and removed phonemes.
*/

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cctype>
using namespace std;

    //function which takes input of a pronunciation and outputs words with all the same phonemes, but one subtracted.
    string subPhoneme(string pronounce);
    //function which takes input of a pronunciation and outputs words with the same phonemes and one added.
    string addPhoneme(string pronounce);
    //function which takes input of a prounciation and outputs a word with the same pronounciation.
    string identical(string pronounciation, string word);
    //function that takes an input of a word and outputs the phonetics of the word.
    string dictionary(string word);
    //function which takes string s, before, and after, and modifies before and after
    //as the first component of the string before the space, and after.
    void splitOnSpace(string s, string & before, string & after);
    //function which takes a word and replaces its phonemes to output a string with
    //complementary words.
    string replacePhonemes(string pronounce);
    //function which takes a string and number of spaces to output a string with all spaces split.
    string splitAllSpace(string & s);
    //takes an input of a string and outputs the number of spaces in the string. 
    int countSpaces(string s);
    bool isDigit(string user);
    
int main()
{
    string input; 
    char run;
    cout << endl;
    cout << "\t\tEnter a word" << setw(7) << ": ";
    cin >> input;
    string word = "";
    for (int i = 0; i < input.length(); i++)
    {
        char chr = toupper(input[i]);
        word += chr; 
    }
    string pronounciation = dictionary(word);
    if (pronounciation == "Not found.")
    {

        cout << "\t\tNot found" << endl;
    }
    else
    {
        cout << "\t\tPronounciation" << setw(4) << " :" << pronounciation;  
        cout << endl;

        string identicals = identical(pronounciation, word);
        cout << "\t\tIdentical" << setw(10) << " : " <<  identicals << endl;

        string added = addPhoneme(pronounciation);
        cout << "\t\tAdd phoneme" << setw(8) << " : " << added << endl;

        string subtracted = subPhoneme(pronounciation);
        cout << "\t\tRemove phoneme" << setw(5) << " : " << subtracted << endl;

        string replaced = replacePhonemes(pronounciation);
        cout << "\t\tReplace phoneme" << setw(4) << " : " << replaced << endl<< endl;

        cout << "\t\tNew word? y/n" << setw(6) << ": ";
        cin >> run;
        if (run == 'y')
        {
            main();
        }
        else 
        {
            cout << endl;
            cout << "\t\texiting." << endl;
        }
    } 
    cout << endl;
}

string subPhoneme(string pronounce)
{
    string trash, line, replaced, beforeSpace, afterSpace;
    bool val;

    ifstream fin("cmudict.0.7a");
    if (fin.fail())
    {
        cerr << "File cannot be found." << endl;
        exit(1);
    }
    for (int junk = 0; junk < 54; junk++)
    {
        getline(fin, trash);
        //cout << trash << endl;
    }   

    string empty, pronounciation; //empty contains that initital space, pronounciation will have the actual pronunciation.
    splitOnSpace(pronounce, empty, pronounciation); //getting rid of that initial space

    int numPhonemes = countSpaces(pronounciation) + 1; // counts the number of spaces in the pronounciation and adding 1, for the number of phonemes
    string * phonemes = new string[numPhonemes]; // dynamically allocates memory for the array of strings 'phonemes', with 'numPhonemes' size.
    //cout << "num" << numPhonemes << endl;
    
                // setting up array of phonemes for entered word:
    for (int i = 0; i < numPhonemes; i++)
    {
        string phoneme = splitAllSpace(pronounciation);
        phonemes[i] = phoneme;
        //cout << "phoneme:" << phonemes[i] << endl;
    }

    string subtracted = "";
    
    while(getline(fin, line))
    {
        //cout << "Line: " << line << endl;
        splitOnSpace(line, beforeSpace, afterSpace);
        string empty2, pronounciation2; 
        splitOnSpace(afterSpace, empty2, pronounciation2); 
        string testPronounce = pronounciation2;
        //cout << "Before:" << beforeSpace << "After:" << pronounciation2 << endl;
        if ((countSpaces(pronounciation2)) == numPhonemes - 2)  //in replacePhonemes, we used this minus one to test the number of phonemes.
                                                                //In this case, we want to to test for numPhonemes - 2, one subtraction for
                                                                //the spaces, and one subtraction for the phoneme.
        {
            string * phonemes2 = new string[(numPhonemes - 1)]; //we add 1 to the count of numPhonemes to get one more phoneme than our original array
            for (int i = 0; i < (numPhonemes - 1); i++)
            {
                string phoneme2 = splitAllSpace(pronounciation2);
                phonemes2[i] = phoneme2;
                //cout << "phoneme2, " << "index " << i << ":" << phonemes2[i] << endl;
            }
            int count = 0;
            string test = "";
            string test2 = ""; 

            for (int i = 0; i < numPhonemes - 1; i++)
            {
                string phoneme2 = phonemes2[i];
                    for (int j = i; j < i + 2; j++)
                    {
                        string phoneme1 = phonemes[j];
                        if (phoneme1 == phoneme2)
                        {
                            count++;
                            break;
                        }
                    }
            }

            if (count == numPhonemes - 1)
            {
                //cout << count << endl;
                // cout << testPronounce << " " << beforeSpace << endl;
                subtracted += beforeSpace + " ";
            }
        }
    }
    return subtracted;
}

string addPhoneme(string pronounce)
{
    string trash, line, replaced, beforeSpace, afterSpace;
    bool val;

    ifstream fin("cmudict.0.7a");
    if (fin.fail())
    {
        cerr << "File cannot be found." << endl;
        exit(1);
    }
    for (int junk = 0; junk < 54; junk++)
    {
        getline(fin, trash);
        //cout << trash << endl;
    }   

    string empty, pronounciation; //empty contains that initital space, pronounciation will have the actual pronunciation.
    splitOnSpace(pronounce, empty, pronounciation); //getting rid of that initial space

    int numPhonemes = countSpaces(pronounciation) + 1; // counts the number of spaces in the pronounciation and adding 1, for the number of phonemes
    string * phonemes = new string[numPhonemes]; // dynamically allocates memory for the array of strings 'phonemes', with 'numPhonemes' size.
    //cout << "num" << numPhonemes << endl;
    
                // setting up array of phonemes for entered word:
    for (int i = 0; i < numPhonemes; i++)
    {
        string phoneme = splitAllSpace(pronounciation);
        phonemes[i] = phoneme;
        //cout << "phoneme:" << phonemes[i] << endl;
    }

    string added = "";
    
    while(getline(fin, line))
    {
        //cout << "Line: " << line << endl;
        splitOnSpace(line, beforeSpace, afterSpace);
        string empty2, pronounciation2; 
        splitOnSpace(afterSpace, empty2, pronounciation2); 
        string testPronounce = pronounciation2;
        //cout << "Before:" << beforeSpace << "After:" << pronounciation2 << endl;
        if ((countSpaces(pronounciation2)) == numPhonemes) //in replacePhonemes, we used this minus one to test the number of phonemes.
                                                           //The negative 1 isn't necessary here, ebcause instead we're testing to see 
                                                           //if the compared array has one MORE space, an added phoneme.
        {
            string * phonemes2 = new string[(numPhonemes + 1)]; //we add 1 to the count of numPhonemes to get one more phoneme than our original array
            for (int i = 0; i < (numPhonemes + 1); i++)
            {
                string phoneme2 = splitAllSpace(pronounciation2);
                phonemes2[i] = phoneme2;
                //cout << "phoneme2, " << "index " << i << ":" << phonemes2[i] << endl;
            }
            int count = 0;
            string test = "";
            string test2 = ""; 

            for (int i = 0; i < numPhonemes; i++)
            {
                string phoneme1 = phonemes[i];
                    for (int j = i; j < i + 2; j++)
                    {
                        string phoneme2 = phonemes2[j];
                        if (phoneme1 == phoneme2)
                        {
                            count++;
                            break;
                        }
                    }
            }
            bool testing = isDigit(beforeSpace);
            if ((count == numPhonemes) && (testing))
            {
                //cout << count << endl;
                added += beforeSpace + " "; //" pronunciation: " + testPronounce;
            }
        }
    }
    return added;
}

string replacePhonemes(string pronounce)
{   
    string trash, line, replaced, beforeSpace, afterSpace;
    bool val;

    ifstream fin("cmudict.0.7a");
    if (fin.fail())
    {
        cerr << "File cannot be found." << endl;
        exit(1);
    }
    for (int junk = 0; junk < 54; junk++)
    {
        getline(fin, trash);
        //cout << trash << endl;
    }   

    string empty, pronounciation;
    splitOnSpace(pronounce, empty, pronounciation);

    int numPhonemes = countSpaces(pronounciation) + 1; // counts the number of spaces in the pronounciation and adding 1, for the number of phonemes
    string * phonemes = new string[numPhonemes]; // dynamically allocates memory for the array of strings 'phonemes', with 'numPhonemes' size.
    //cout << "num" << numPhonemes << endl;
    
    // setting up array of phonemes for entered word

    for (int i = 0; i < numPhonemes; i++)
    {
        string phoneme = splitAllSpace(pronounciation);
        phonemes[i] = phoneme;
        //cout << "phoneme:" << phonemes[i] << endl;
    }

    while(getline(fin, line))
    {
        // cout << "Line: " << line << endl;
        splitOnSpace(line, beforeSpace, afterSpace);

        string empty2, pronounciation2; 
        splitOnSpace(afterSpace, empty2, pronounciation2);

        string replacedPhoneme = "";
        if (countSpaces(pronounciation2) == (numPhonemes - 1))
        {
            //cout << "Sphaghetti 1" << endl;
            //cout << "Before:" << beforeSpace << " " << "After:" << pronounciation2 << endl;

            string * phonemes2 = new string[numPhonemes];
            for (int i = 0; i < numPhonemes; i++)
            {
                string phoneme2 = splitAllSpace(pronounciation2);
                phonemes2[i] = phoneme2; 
                //cout << "phoneme2, " << "index "<< i << ":" << phonemes2[i] << " " << endl;           
            }
            //cout << endl;
            int i = 0;
            int count = 0;
            while (i < numPhonemes)
            {
                //cout << "Sphaghetti 2" << endl;
                string phoneme1 = phonemes[i];
                string phoneme2 = phonemes2[i];
                if (phoneme1 != phoneme2)
                {
                    // cout << "phoneme1:" << phoneme1 << " ";
                    // cout << "phoneme2:" << phoneme2 << endl;
                    count++;
                }
                if (count < 2 && count >= 1 && i == numPhonemes - 1)
                {
                    replacedPhoneme = beforeSpace;
                    // cout << replacedPhoneme << endl;
                    bool testNum = isDigit(replacedPhoneme);
                    if (testNum)
                    {
                        replaced += replacedPhoneme + " ";
                    }
                }
                i++;
            }
            delete[] phonemes2;
        }
    }
    delete[] phonemes;
    fin.close();
    return replaced;
}

string splitAllSpace(string & s)
{
  int len = s.length();
  string after = "";
  string before = "";
  int j = 0;
  while (j < len && !isspace(s[j]))
  {
    before += s[j];
    j++;
  }
  j++;
  while (j < len)
  {
    after += s[j];
    j++;
  }
  s = after;
  return before;
}

string identical(string pronounce, string word)
{
    string line, trash;
    string beforeSpace, afterSpace;
    int junk;
    string test;

    string identical = "";
    ifstream fin("cmudict.0.7a");
    if (fin.fail())
    {
        cerr << "File cannot be found." << endl;
        exit(1);
    }
    for (int junk = 0; junk < 54; junk++)
    {
        getline(fin, trash);
    }
    cout << endl;



    while(getline(fin, line))
    {
        //cout << x << " " << y << endl;
        //getline(fin, line);
        splitOnSpace(line, beforeSpace, afterSpace);
        if (beforeSpace != word)
        {
            if (afterSpace == pronounce)
            {
                //cout << beforeSpace << endl;
                //cout << afterSpace << endl;
                identical += beforeSpace + " ";
            }            
        }
    }
    fin.close();
    return identical;
}

string dictionary(string word)
{
    string line, trash, pronounce, dictionaryWord;
    string beforeSpace, afterSpace;
    string file;
    int junk;
    bool test = true;

    ifstream fin("cmudict.0.7a");
    if (fin.fail())
    {
        cerr << "File cannot be found." << endl;
        exit(1);
    }
    for (int junk = 0; junk < 54; junk++)
    {
        getline(fin, trash);
        //cout << trash << endl;
    }
    cout << endl;

    for (int i = 0; i < 133342; i++)
    {
        getline(fin, line);
        //cout << line << " " << i << endl;
        splitOnSpace(line, beforeSpace, afterSpace);
        //cout << beforeSpace << setw(12) << afterSpace << endl;
        if (beforeSpace == word)
        {
            pronounce = afterSpace;
            //cout << i << endl;
            //cout << "success" << endl;
            //test = false;
            break;
        }
        else
        {
            pronounce = "Not found.";
        }
    }
    
    fin.close();
    //cout << line << endl;
    return pronounce;
}

void splitOnSpace(string s, string & before, string & after)
{
    before = "";
    after = "";

    int i = 0;
    while (i < s.size() && !isspace(s[i]))
    {
        before += s[i];
        i++;
    }
    i++; //next character after the first word
    while (i < s.size())
    {
        after += + s[i];
        i++;
    }
}

int countSpaces(string s)
{
  int count = 0;
  for (int i = 0; i < s.size(); i++)
  {
    char chr = s[i];
    if (chr == ' ')
    {
      count++;
    }
  }
  return count;
}

bool isDigit(string user)
{
    for (int i = 0; i < user.size(); i++)
    {
        if (isdigit(user[i]))
        {
            return false;
        }
        else
        {
            continue;
        }
    }
    return true;
}