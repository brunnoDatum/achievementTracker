//
// Created by Brunno Tripovichy on 2019-01-16.
//

#ifndef GAME1011_TRIPOVICHYBRUNNO_LAB1_ACHIEVEMENT_H
#define GAME1011_TRIPOVICHYBRUNNO_LAB1_ACHIEVEMENT_H

#include <string>

using namespace std;

class Achievement {

private:

    string title;
    string description;
    double scoreValue;

public:

    Achievement();

    Achievement(const string &title, const string &description, double scoreValue);

    ~Achievement();

    const string &getTitle() const;

    void setTitle(const string &title);

    const string &getDescription() const;

    void setDescription(const string &description);

    double getScoreValue() const;

    void setScoreValue(double scoreValue);

};


#endif //GAME1011_TRIPOVICHYBRUNNO_LAB1_ACHIEVEMENT_H
