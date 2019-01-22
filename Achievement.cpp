//
// Created by Brunno Tripovichy on 2019-01-16.
//

#include "Achievement.h"

Achievement::Achievement() = default;

Achievement::Achievement(const string &title, const string &description, double scoreValue) : title(title), description(description), scoreValue(scoreValue) {}

Achievement::~Achievement() = default;

const string &Achievement::getTitle() const {
    return title;
}

void Achievement::setTitle(const string &title) {
    Achievement::title = title;
}

const string &Achievement::getDescription() const {
    return description;
}

void Achievement::setDescription(const string &description) {
    Achievement::description = description;
}

double Achievement::getScoreValue() const {
    return scoreValue;
}

void Achievement::setScoreValue(double scoreValue) {
    Achievement::scoreValue = scoreValue;
}
