//
// Created by Brunno Tripovichy on 2019-01-16.
//

#ifndef GAME1011_TRIPOVICHYBRUNNO_LAB1_PLATFORM_H
#define GAME1011_TRIPOVICHYBRUNNO_LAB1_PLATFORM_H

#include <string>
#include "Game.h"

using namespace std;

class Platform {

private:

    string name;
    string manufacturer;
    vector<Game> games;

public:

    Platform();

    Platform(const string &name, const string &manufacturer, const vector<Game> &games);

    ~Platform();

    const string &getName() const;

    void setName(const string &name);

    const string &getManufacturer() const;

    void setManufacturer(const string &manufacturer);

    vector<Game> &getGames();

    void setGames(const vector<Game> &games);

    void addGame(Game &game);

};


#endif //GAME1011_TRIPOVICHYBRUNNO_LAB1_PLATFORM_H
