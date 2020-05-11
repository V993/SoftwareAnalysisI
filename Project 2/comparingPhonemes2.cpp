/* 
Author: Leonardo Matone
Instructor: Katherine Howitt
Assignment: Project 2

takes an input and outputs the pronounciation of the inputted word.
*/

    #include <iostream>
    #include <string>
    #include <fstream>
    #include <iomanip>
    #include <cctype>
using namespace std;

    string identical(string pronounciation);
    //function that takes an input of a word and outputs the phonetics of the word
    string dictionary(string word);
    //function which takes string s, before, and after, and modifies before and after
    //as the first component of the string before the space, and after.
    void splitOnSpace(string s, string & before, string & after);
    //function which takes a word and replaces its phonemes to output a string with
    //complementary words
    string replacePhonemes(int spaces, string pr, string word);
    //function which takes a string and number of spaces to output a string with all spaces split.
    string splitAllSpace(string & s);
    int countSpaces(string s);
    
int main()
{
    string input; 
    cout << "Enter a word: ";
    cin >> input;
    string word = "";
    // convert into uppercase
    for (int i = 0; i < input.length(); i++)
    {
        char chr = toupper(input[i]);
        word += chr; 
    }
    // 
    string pronounciation = dictionary(word);
    if (pronounciation == "Not found.")
    {
        cout << "Not found" << endl;
    }
    else
    {
        cout << "Pronounciation: " << pronounciation << endl << endl;   

        string identicals = identical(word);
        cout << "Identical: " << identicals << endl;

        int spaces = countSpaces(pronounciation);
        string replaced = replacePhonemes(spaces, pronounciation, word);
        cout << "Replace phonemes: " << replaced << endl;
    }   
}

string replacePhonemes(int spaces, string pr, string word)
{
    int spaces2, same;
    string replaced, identicalWord, newWord;
    string beforeSpace, afterSpace, line, trash, phonemes, phonemes2, pro;
    string pronounce = "";
    string p = "";
    string pre = "";
    
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

    int testVal = 0;
    same = spaces2 - 1;
    while (getline(fin, line) && testVal < 6)
    {
        splitOnSpace(line, beforeSpace, afterSpace);
        pro = dictionary(beforeSpace);

        if (beforeSpace != word)
        {
            newWord = beforeSpace;
            //cout << pro << endl;
            //cout << beforeSpace << endl;
            spaces2 = countSpaces(afterSpace);
            //cout << spaces << " " << spaces2;
            if (spaces2 == spaces)
            {
                //removing the initial space in the pronunciation for the test word
                for (int n = 1; n <= afterSpace.length(); n++)
                {
                    p += pro[n];
                }
                //removing the initial space in the inputted word
                for (int o = 1; o <= pr.length(); o++)
                {
                    pronounce += pr[o];
                }
                //the phoneme being tested for the original word
                
                int count = 0;
               
                for (int i = 0; i < spaces; i++)
                {
                    //the phoneme being tested for the test word
                    phonemes2 = splitAllSpace(p);
                    phonemes = splitAllSpace(pronounce);
                    //testing if the two phonemes are the same
                    if ((phonemes != phonemes2) && (count < 2))
                    {
                        count++; //if the phonemes are the same, add 1 to our 'count' int
                        //count is the integer which represents the number of phoneme differences
                        //between the two words. If the pronunciation has one phoneme replaced, it
                        //will have one phoneme difference, 
                    }
                }
                
                if ((count < 2 && count >= 1))
                    //if the count is greater than or equal to 
                    //1, which is the number of differences
                    //phonemes - 1, and is not equal to the 
                    //previous word:                          
                {
                    replaced += newWord + " ";  //add the new word, should it meet the conditions above,
                                                //to the string we will return.
                    //pre = newWord;              //for tests to ensure that the same word is not used twice.
                    testVal++;                  //for testing.
                    cout << replaced << endl;  
                }
            } 
        }
    }
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

string identical(string word)
{
    string line, trash;
    string beforeSpace, afterSpace;
    int junk;
    string test;

    string identical = "";
    ifstream fin("cmudict.0.7a.txt");
    if (fin.fail())
    {
        cerr << "File cannot be found." << endl;
        exit(1);
    }
    for (int junk = 0; junk < 54; junk++)
    {
        getline(fin, trash);
    }
    //cout << endl;

    string pronounce = dictionary(word);

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
    //cout << endl;

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
        before = before + s[i];
        i++;
    }
    i++; //next character after the first word
    while (i < s.size())
    {
        after = after + s[i];
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