/* 
Author: Leonardo Matone
Instructor: Katherine Howitt
Assignment: Lab 11D

Network posting
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
using namespace std;

class Profile{ //Information for specific profiles
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

struct Post { //A single post structure
    string username;
    string message;
};

class Network{ //An integration of different profiles into an array of profiles
public:
    Network();
    bool addUser(string user, string display);
    bool follow(string user1, string user2);
    void printDot();
    bool writePost(string user, string message);
    bool printTimeline(string user);
private:
    static const int MAX_USERS = 20;
    int numUsers;
    Profile profiles[MAX_USERS];
    int findID(string user);
    string findUser(int ID);
    bool following[MAX_USERS][MAX_USERS];
    static const int MAX_POSTS = 100;
    int numPosts;
    Post posts[MAX_POSTS];
};

bool test(string user); //tests to see if username is valid

bool Network::writePost(string user, string message) //adds post to network given username and post message
{
    Post newPost = {user, message};
    if ((findID(user) != -1) && (numPosts != MAX_POSTS))
    {
        posts[numPosts] = newPost;
        numPosts++;
        return true;
    }
    else
    {
        return false;
    }
}

bool Network::printTimeline(string user) //prints the entirety of a user's timeline based on who they follow
{
    int ID = findID(user);
    for (int i = numPosts - 1; i >= 0; i--)
    {
        Post post = posts[i];
        string userN = post.username;
        int testID = findID(userN);
        bool follow = following[ID][testID];
        if (follow || ID == testID)
        {
            cout << profiles[testID].getFullName() << ": " << post.message << endl;
        }
    }
}

bool Network::follow(string user1, string user2) //adds user2 to the array of users user1 follows
{
    int followerID = findID(user1);
    int followedID = findID(user2);

    following[followerID][followedID] = true;
}

void Network::printDot() //prints a diagram of the network
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

Network::Network() //default constuctor for the network class. Zero posts, zero following, zero users
{
    numUsers = 0;
    for (int i = 0; i < MAX_USERS; i++)
    {
        for (int j = 0; j < MAX_USERS; j++)
        {
            following[i][j] = false;
        }
    }
    numPosts = 0;
}

bool Network::addUser(string user, string display) //adds a user to the network
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

int Network::findID(string user) //finds the userID for a specific username (the array reference)
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

string Network::findUser(int ID) //finds a username given a userID
{
    string user = profiles[ID].getUsername();
    return user;
}

Profile::Profile(string user, string display) //creates a profile
{
    username = user;
    displayName = display;
}
Profile::Profile() //default display constructor. Empty username and displayname strings
{
    username = "";
    displayName = "";
}
string Profile::getFullName() const //returns the username and display name, formatted
{
    string fullName = displayName + " (@" + username + ")";
    return fullName;
}
string Profile::getUsername() const //returns the username
{
    return username;
}
void Profile::setDisplayName(string newName) //changes the displayname for a profile
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

    nw.follow("mario", "luigi");
    nw.follow("luigi", "mario");
    nw.follow("luigi", "yoshi");
    nw.follow("yoshi", "mario");

    // write some posts
    nw.writePost("mario", "It's a-me, Mario!");
    nw.writePost("luigi", "Hey hey!");
    nw.writePost("mario", "Hi Luigi!");
    nw.writePost("yoshi", "Test 1");
    nw.writePost("yoshi", "Test 2");
    nw.writePost("luigi", "I just hope this crazy plan of yours works!");
    nw.writePost("mario", "My crazy plans always work!");
    nw.writePost("yoshi", "Test 3");
    nw.writePost("yoshi", "Test 4");
    nw.writePost("yoshi", "Test 5");

    cout << endl;
    cout << "======= Mario's timeline =======" << endl;
    nw.printTimeline("mario");
    cout << endl;

    cout << "======= Yoshi's timeline =======" << endl;
    nw.printTimeline("yoshi");
    cout << endl;
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