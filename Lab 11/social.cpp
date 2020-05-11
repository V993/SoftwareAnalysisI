/* 
Author: Leonardo Matone
Instructor: Katherine Howitt
Assignment: Lab 11A

class Profile
*/

#include <iostream>
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
    string fullName = displayName + " (@" + username + ")";
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
    Profile p1("marco", "Marco");    
    cout << p1.getUsername() << endl; // marco
    cout << p1.getFullName() << endl; // Marco (@marco)

    p1.setDisplayName("Marco Rossi"); 
    cout << p1.getUsername() << endl; // marco
    cout << p1.getFullName() << endl; // Marco Rossi (@marco)
    
    Profile p2("tarma1", "Tarma Roving");    
    cout << p2.getUsername() << endl; // tarma1
    cout << p2.getFullName() << endl; // Tarma Roving (@tarma1)
}