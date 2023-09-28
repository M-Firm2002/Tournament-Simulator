#include "main.h"
#include <vector>
#include <algorithm>

using namespace std;

void addTeam(team *A) {
    string x;
    int y;

    cout << "\nTeam name: ";
    cin >> x;
    A -> name = x;

    cout << "Attack level: ";
    cin >> y;
    A -> attack = y;

    cout << "Defence level: ";
    cin >> y;
    A -> defence = y;

    A -> points = 0;
}

void Fixture(team& teamA, team& teamB) {
    int teamAgoals = 0, teamBgoals = 0;
    cout << "\nNext Fixture: \n" << teamA.name << " vs " << teamB.name << endl;
    cin.ignore();

    if (teamA.attack - teamB.defence > 0) {
        teamAgoals = teamA.attack - teamB.defence;
    }
    if (teamB.attack - teamA.defence > 0) {
        teamBgoals = teamB.attack - teamA.defence;
    }

    if (teamAgoals > teamBgoals) {
        teamA.points = teamA.points + 3;
        cout << teamA.name << " wins! " << teamAgoals << "-" << teamBgoals << endl;
    }
    else if (teamBgoals > teamAgoals) {
        teamB.points = teamB.points + 3;
        cout << teamB.name << " wins! " << teamAgoals << "-" << teamBgoals << endl;
    }
    else if (teamAgoals == teamBgoals) {
        teamA.points = teamA.points + 1;
        teamB.points = teamB.points + 1;
        cout << "Draw! " << teamAgoals << "-" << teamBgoals << endl;
    }
}

int main(int argc, char * const argv[]) {
    int numOfTeams;
    vector<team> pool1, pool2;

    cout << "Welcome to Tournament Simulator" << endl;
    cout << "\nSelect the number of teams";
    cout << "\n 8 (2 groups)";
    cout << "\n 16 (4 groups)";
    cout << "\n 32 (8 groups)" << endl;
    cin >> numOfTeams;

    if (numOfTeams == 8 || numOfTeams == 16 || numOfTeams == 32) {
        const int GroupSize = 4, numOfGroups = numOfTeams / GroupSize;
        vector<vector<team>> groups;

        for (int i = 0; i < numOfGroups; i++) {
            vector<team> group;

            for (int j = 0; j < GroupSize; j++) {
                team X = {};
                addTeam(&X);

                group.push_back(X);
            }
            groups.push_back(group);
        }

        for (auto group = groups.begin(); group != groups.end(); group++) {
            for (auto teamA = group->begin(); teamA != group->end(); teamA++) {
                for (auto teamB = teamA + 1; teamB != group->end(); teamB++) {
                    Fixture(*teamA, *teamB);
                    cin.ignore();
                }
            }

            team teamA;
            team teamB;

            sort(group->begin(), group->end(), greater_than_points());
            teamA = group->at(0);
            teamB = group->at(1);

            pool1.push_back(teamA);
            pool2.push_back(teamB);
        }
    }

    else {
        cout << "Incorrect value given.";
    }
}