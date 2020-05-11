/* 
Author: Leonardo Matone
Instructor: Katherine Howitt
Assignment: Lab 11C

Network following
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
    bool follow(string user1, string user2);
    void printDot();
private:
    static const int MAX_USERS = 20;
    int numUsers;
    Profile profiles[MAX_USERS];
    int findID(string user);
    string findUser(int ID);
    bool following[MAX_USERS][MAX_USERS];
};

bool test(string user);

bool Network::follow(string user1, string user2)
{
    int followerID = findID(user1);
    int followedID = findID(user2);

    following[followerID][followedID] = true;
}

void Network::printDot()
{
    cout << "digraph {" << endl;
    for (int i = 0; i < numUsers; i++)
    {
        cout << "\t\"@" << (profiles[i]).getUsername() << '"' <<  endl;
    }
    cout << endl;
    for (int i = 0; i < numUsers; i++)
    {
        for (int j = 0; j < numUsers; j++)
        {
            if (following[i][j])
            {
                string follower = findUser(i);
                string followed = findUser(j);
                cout << "\t\"@" << follower << "\" -> " << "\"@" << followed << "\"" << endl;
            }
        }
    }
    cout << "}" << endl;
}

Network::Network()
{
    numUsers = 0;
    for (int i = 0; i < MAX_USERS; i++)
    {
        for (int j = 0; j < MAX_USERS; j++)
        {
            following[i][j] = false;
        }
    }
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

string Network::findUser(int ID)
{
    string user = profiles[ID].getUsername();
    return user;
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
    // add three users
    nw.addUser("mario", "Mario");
    nw.addUser("luigi", "Luigi");
    nw.addUser("yoshi", "Yoshi");

    // make them follow each other
    nw.follow("mario", "luigi");
    nw.follow("mario", "yoshi");
    nw.follow("luigi", "mario");
    nw.follow("luigi", "yoshi");
    nw.follow("yoshi", "mario");
    nw.follow("yoshi", "luigi");

    // add a user who does not follow others
    nw.addUser("wario", "Wario");
    
    // add clone users who follow @mario
    for(int i = 2; i < 6; i++) {
        string usrn = "mario" + to_string(i);
        string dspn = "Mario " + to_string(i);
        nw.addUser(usrn, dspn);
        nw.follow(usrn, "mario");
    }
    // additionally, make @mario2 follow @luigi
    nw.follow("mario2", "luigi");

    nw.printDot();
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