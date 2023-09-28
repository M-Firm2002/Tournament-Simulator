#include <iostream>
#include <string>

using namespace std;

typedef struct team {
    string name;
    int attack;
    int defence;
    int points;
} team;

typedef struct group {
    string teamOne;
    string teamTwo;
    string teamThree;
    string teamFour;
} group;