//
// Created by Brunno Tripovichy on 2019-01-16.
//

#ifndef GAME1011_TRIPOVICHYBRUNNO_LAB1_GAME_H
#define GAME1011_TRIPOVICHYBRUNNO_LAB1_GAME_H

#include <string>
#include <vector>
#include "Achievement.h"

using namespace std;

class Game {

private:

    string name;
    string publisher;
    string developer;
    vector<Achievement> achievements;

public:

    Game();

    Game(const string &name, const string &publisher, const string &developer, const vector<Achievement> &achievements);

    ~Game();

    const string &getName() const;

    void setName(const string &name);

    const string &getPublisher() const;

    void setPublisher(const string &publisher);

    const string &getDeveloper() const;

    void setDeveloper(const string &developer);

    vector<Achievement> &getAchievements();

    void setAchievements(const vector<Achievement> &achievements);

    void addAchievement(Achievement &achievement);

};


#endif //GAME1011_TRIPOVICHYBRUNNO_LAB1_GAME_H
