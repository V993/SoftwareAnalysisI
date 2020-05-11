    /* 
    Author: Leonardo Matone
    Instructor: Katherine Howitt
    Assignment: Project 2

    takes an input and outputs the pronounciation of the inputted word, words with identical pronunciations,
    and words with replaced phonemes, subtracted, and added phonemes.
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
    string replacePhonemes(string phoneme[], int spaces, string pr);
    //function which takes a string and number of spaces to output a string with all spaces split.
    string splitAllSpace(string & s);
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
        cout << "Pronounciation: " << pronounciation << endl;   
        string identicals = identical(word);
        cout << "Identical: " << identicals << endl;
        int spaces = countSpaces(pronounciation);
        // cout << spaces << endl;
        string phoneme[spaces];
        string replaced = replacePhonemes(phoneme, spaces, pronounciation);
        cout << "Replace phonemes: " << replaced << endl;
    } 
}

string replacePhonemes(string phoneme[], int spaces, string pr)
{
    int spaces2;
    string replaced;
    string beforeSpace, afterSpace, line, trash, phonemes, phonemes2, pro;
    string pronounce = "";
    string p = "";
    
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

        //removing the initial space in the pronunciation
        for (int o = 1; o <= pr.length(); o++)
        {
            pronounce += pr[o];
        }

        //phoneme array for the item phoneme[]
        for (int i = 0; i < spaces; i++)
        {
            phonemes = splitAllSpace(pronounce);
            phoneme[i] = phonemes;
            //cout << i << " " << phoneme[i] << endl; 
        }
    
    while (getline(fin, line))
    {
        splitOnSpace(line, beforeSpace, afterSpace);
        pro = dictionary(beforeSpace);
        string word = beforeSpace;
        //cout << pro << endl;
        //cout << beforeSpace << endl;
        spaces2 = countSpaces(afterSpace);
        string phoneme2[spaces];
        //cout << spaces << " " << spaces2;
        if (spaces2 == spaces)
        {
            //cout << endl << "a " << "p " << "p2" << endl;
            //removing the initial space in the pronunciation
            for (int n = 1; n < afterSpace.length(); n++)
            {
                p += pro[n];
            }
            //cout << p << endl;
            int count = 0;
            //comparison array for the item phoneme2[]
            for (int k = 0; k < spaces; k++)
            {
                phonemes2 = splitAllSpace(p);
                phoneme2[k] = phonemes2;
                //cout << k << " " << phoneme2[k] << setw(5) << phoneme[k] << endl;
                if (phoneme[k] == phoneme2[k])
                {
                    count++;
                }
                // cout << count << endl; 
                if (count >= spaces) //if the count is greater than or equal to spaces,
                                // which is the number of phonemes - 1.
                {
                    replaced += word + " ";
                    cout << replaced << endl;
                }
            }
        }
    }
    return replaced;
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