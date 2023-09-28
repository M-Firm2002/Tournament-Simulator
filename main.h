#include <iostream>
#include <string>

using namespace std;

typedef struct team {
    string name;
    int attack;
    int defence;
    int points;
} team;

struct greater_than_points {
    inline bool operator() (const team& team1, const team& team2) {
        return (team1.points > team2.points);
    }
};