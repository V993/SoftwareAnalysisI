/* 
Author: Leonardo Matone
Instructor: Katherine Howitt
Assignment: Lab 11B

class Profile
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
using namespace std;

class Profile{
public:
    //Profule constructor for a user
    Profile(string user, string display);
    //Default profile constructor (empty strings)
    Profile();
    //get the username
    string getUsername() const;
    //returns display name "displayname (@username)"
    string getFullName() const;
    //change displayname
    void setDisplayName(string newName);
private:
    string username;
    string displayName;
};

class Network{
public:
    Network();
    bool addUser(string user, string display);
private:
    static const int MAX_USERS = 20;
    int numUsers;
    Profile profiles[MAX_USERS];
    int findID(string user);
};

bool test(string user);

Network::Network()
{
    numUsers = 0;
}

bool Network::addUser(string user, string display)
{
    bool IDTest = false;
    int ID = findID(user);
    
    // cout << "ID: " << ID << endl;

    //if there is no ID, there isn't anyone with that username, and we continue.
    if (ID == -1) { IDTest = true; }
    //if there is an ID, that means the username is already added, and we do not advance.
    else{IDTest = false;}
    //now that we know the ID doesn't exist, we test to see if it is valid:
    bool alphanum = test(user);
    //if the username is not empty, not taken, our array of users isn't full, and the username is alphanumetric:
    if ((user != "") && (IDTest == true) && (numUsers < MAX_USERS) && (alphanum))
    {
        //adding one user with values from formal parameters:
        profiles[numUsers] = {user, display};
        numUsers++;
        return true;
        //we added!
    }
    else 
    {
        return false;
        //condition unmet. not added.
    }
}

int Network::findID(string user)
{
    for (int i = 0; i < MAX_USERS; i++)
    {
        string userCompare = profiles[i].getUsername();
        if (user == userCompare)
        {
            return i;
        }
    }
    return -1;
}   

    Profile::Profile(string user, string display)
    {
        username = user;
        displayName = display;
    }
    Profile::Profile()
    {
        username = "";
        displayName = "";
    }
    string Profile::getFullName() const
    {
        string fullName = displayName + " (@" + displayName + ")";
        return fullName;
    }
    string Profile::getUsername() const
    {
        return username;
    }
    void Profile::setDisplayName(string newName)
    {
        displayName = newName;
    }

int main()
{
  Network nw;
  cout << nw.addUser("mario", "Mario") << endl;     // true (1)
  cout << nw.addUser("luigi", "Luigi") << endl;     // true (1)

  cout << nw.addUser("mario", "Mario2") << endl;    // false (0)
  cout << nw.addUser("mario 2", "Mario2") << endl;  // false (0)
  cout << nw.addUser("mario-2", "Mario2") << endl;  // false (0)

  for(int i = 2; i < 20; i++)
      cout << nw.addUser("mario" + to_string(i), 
                 "Mario" + to_string(i)) << endl;   // true (1)

  cout << nw.addUser("yoshi", "Yoshi") << endl;     // false (0)
}

bool test(string user)
{
    for (int i = 0; i < user.size(); i++)
    {
        if (isalnum(user[i]))
        {
            continue;
        }
        else
        {
            return false;
        }
    }
    return true;
}