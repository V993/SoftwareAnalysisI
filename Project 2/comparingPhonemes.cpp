
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cctype>
using namespace std;

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
    
int main()
{
    string input; 
    cout << "Enter a word: ";
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
        cout << "Not found" << endl;
    }
    else
    {
        cout << "Pronounciation: " << pronounciation;  
        string identicals = identical(pronounciation, word);
        cout << "Identical: " << identicals << endl;
        string replaced = replacePhonemes(pronounciation);
        cout << "Replace phonemes: " << replaced << endl;
    } 
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
                    replaced += replacedPhoneme + " ";
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