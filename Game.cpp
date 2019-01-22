//
// Created by Brunno Tripovichy on 2019-01-16.
//

#include "Game.h"

Game::Game() = default;

Game::Game(const string &name, const string &publisher, const string &developer, const vector<Achievement> &achievements) : name(name), publisher(publisher), developer(developer),
                                                                                                                            achievements(achievements) {}

Game::~Game() = default;

const string &Game::getName() const {
    return name;
}

void Game::setName(const string &name) {
    Game::name = name;
}

const string &Game::getPublisher() const {
    return publisher;
}

void Game::setPublisher(const string &publisher) {
    Game::publisher = publisher;
}

const string &Game::getDeveloper() const {
    return developer;
}

void Game::setDeveloper(const string &developer) {
    Game::developer = developer;
}

vector<Achievement> &Game::getAchievements() {
    return achievements;
}

void Game::setAchievements(const vector<Achievement> &achievements) {
    Game::achievements = achievements;
}

void Game::addAchievement(Achievement &achievement) {
    Game::achievements.push_back(achievement);
}
