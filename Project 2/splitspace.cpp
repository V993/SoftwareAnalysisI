#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

void splitOnSpace(string s, string & before, string & after);

int countSpaces(string s);

string splitAllSpace(string & s, int spaces);

int main()
{
    string line = "AAAA  BB CCC";
    string beforeSpace, afterSpace;
    splitOnSpace(line, beforeSpace, afterSpace);

    cout << "beforeSpace: " <<  beforeSpace << endl;
    cout << "afterSpace: " <<  afterSpace << endl << endl;

    int spaces = countSpaces(line);
    string phonemes[spaces];

    for (int i = 0; i <= spaces; i++)
    {
      string phoneme = splitAllSpace(line, spaces);
      cout << i << setw(3) << phoneme << endl;
      phonemes[i] = phoneme;
    }

    for (int i = 0; i <= spaces; i++)
    {
      cout << phonemes[i] << " ";
    }
    cout << endl;
}

void splitOnSpace(string s, string & before, string & after) 
{
  // reset strings
    before = ""; 
    after = "";
  // accumulate before space
    int i = 0;
    while (i < s.length() && not isspace(s[i])) { 
        before = before + s[i]; 
        i++; 
    }
  // skip the space
    i++;
    // accumulate after space
    while (i < s.length()) { 
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

string splitAllSpace(string & s, int spaces)
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