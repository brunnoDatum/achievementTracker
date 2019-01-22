//
// Created by Brunno Tripovichy on 2019-01-16.
//

#include "Platform.h"

using namespace std;

Platform::Platform() = default;

Platform::Platform(const string &name, const string &manufacturer, const vector<Game> &games) : name(name), manufacturer(manufacturer), games(games) {}

Platform::~Platform() = default;

const string &Platform::getName() const {
    return name;
}

void Platform::setName(const string &name) {
    Platform::name = name;
}

const string &Platform::getManufacturer() const {
    return manufacturer;
}

void Platform::setManufacturer(const string &manufacturer) {
    Platform::manufacturer = manufacturer;
}

vector<Game> &Platform::getGames() {
    return games;
}

void Platform::setGames(const vector<Game> &games) {
    Platform::games = games;
}

void Platform::addGame(Game &game) {
    Platform::games.push_back(game);
}
