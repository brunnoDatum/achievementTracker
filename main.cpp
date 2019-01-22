#include <iostream>
#include <vector>
#include "Platform.h"
#include "Game.h"
#include "Achievement.h"

using namespace std;

vector<Platform> platforms;

int main() {

    int firstMenuChoice = 0, secondMenuChoice = 0, thirdMenuChoice = 0, fourthMenuChoice = 0, fithMenuChoice = 0, sixthMenuChoice = 0;

    while (firstMenuChoice != 3) {
        cout << endl;
        cout << "Welcome to my achievement tracker app! Select an option below:" << endl;
        cout << "1 -> Create a platform" << endl;
        cout << "2 -> Check your platforms" << endl;
        cout << "3 -> Exit application" << endl;
        cout << "Enter your choice: ";
        cin >> firstMenuChoice;

        while (cin.fail() || (firstMenuChoice < 1 || firstMenuChoice > 3)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "You have entered wrong input! Try again: ";
            cin >> firstMenuChoice;
        }

        cin.ignore(); // ignore the newline here, after the call to cin >>.
        cout << endl;

        if (firstMenuChoice == 1) {

            string platformName, manufacturerName;

            cout << "To create a platform first type the name: ";
            getline(cin, platformName);

            while (platformName.length() < 3) {
                cout << endl;
                cout << "You must enter at least 3 characters! Enter again: ";
                getline(cin, platformName);
            }

            cout << "Second, type the manufacturer: ";
            getline(cin, manufacturerName);

            while (manufacturerName.length() < 3) {
                cout << endl;
                cout << "You must enter at least 3 characters! Enter again: ";
                getline(cin, manufacturerName);
            }

            cout << endl;

            Platform newPlatform(platformName, manufacturerName, {});
            platforms.push_back(newPlatform);

            cout << "Platform created successfully!";
            cout << endl;

        } else if (firstMenuChoice == 2) {

            if (!platforms.empty()) {

                bool keepPlatformMenuOn = true;

                //platform loop

                while (keepPlatformMenuOn) {
                    cout << endl;

                    cout << "This are your current platforms. Select an option below:" << endl;

                    for (auto &plat : platforms) { // access by reference to avoid copying
                        cout << (&plat - &platforms[0] + 1) << " -> " << plat.getName() << " - " << plat.getManufacturer() << " - Nr. Games:  " << plat.getGames().size() << endl;
                    }

                    cout << "0 -> Go back" << endl;
                    cout << "Enter your choice: ";
                    cin >> secondMenuChoice;

                    while (cin.fail() || (secondMenuChoice < 0 || secondMenuChoice > platforms.size())) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "You have entered wrong input! Try again: ";
                        cin >> secondMenuChoice;
                    }

                    if (secondMenuChoice == 0) {
                        firstMenuChoice = 0;
                        keepPlatformMenuOn = false;
                    } else {

                        bool keepGameMenuOn = true;

                        while (keepGameMenuOn) {
                            cout << endl;

                            cout << "You selected -> " << platforms.at(static_cast<unsigned long>(secondMenuChoice - 1)).getName() << endl;

                            cout << "1 -> Create a game" << endl;
                            cout << "2 -> List current games" << endl;
                            cout << "0 -> Go back" << endl;
                            cout << "Enter your choice: ";
                            cin >> thirdMenuChoice;

                            while (cin.fail() || (thirdMenuChoice < 0 || thirdMenuChoice > 2)) {
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                cout << "You have entered wrong input! Try again: ";
                                cin >> thirdMenuChoice;
                            }

                            cin.ignore(); // ignore the newline here, after the call to cin >>.

                            if (thirdMenuChoice == 0) {
                                secondMenuChoice = 0;
                                keepGameMenuOn = false;
                            } else if (thirdMenuChoice == 1) {

                                cout << endl;

                                string gameName, publisherName, developerName;

                                cout << "To create a game first type the name: ";
                                getline(cin, gameName);

                                while (gameName.length() < 3) {
                                    cout << endl;
                                    cout << "You must enter at least 3 characters! Enter again: ";
                                    getline(cin, gameName);
                                }

                                cout << "Second, type the publisher: ";
                                getline(cin, publisherName);

                                while (publisherName.length() < 3) {
                                    cout << endl;
                                    cout << "You must enter at least 3 characters! Enter again: ";
                                    getline(cin, publisherName);
                                }

                                cout << "Finally, type the developer: ";
                                getline(cin, developerName);

                                while (developerName.length() < 3) {
                                    cout << endl;
                                    cout << "You must enter at least 3 characters! Enter again: ";
                                    getline(cin, developerName);
                                }

                                cout << endl;

                                Game newGame(gameName, publisherName, developerName, {});
                                platforms.at(static_cast<unsigned long>(secondMenuChoice - 1)).addGame(newGame);

                                cout << "Game created successfully!";
                                cout << endl;

                            } else if (thirdMenuChoice == 2) {

                                cout << endl;

                                if (platforms.at(static_cast<unsigned long>(secondMenuChoice - 1)).getGames().empty()) {
                                    cout << "NO GAMES! " << endl;
                                } else {
                                    for (auto &game : platforms.at(static_cast<unsigned long>(secondMenuChoice - 1)).getGames()) { // access by reference to avoid copying
                                        cout << (&game - &platforms.at(static_cast<unsigned long>(secondMenuChoice - 1)).getGames()[0] + 1) << " -> " << game.getName() << " - " << game.getPublisher() << " - " << game.getDeveloper() << " - Nr. Achievements:  " << game.getAchievements().size() << endl;
                                    }
                                }

                                cout << "0 -> Go back" << endl;
                                cout << "Enter your choice: ";
                                cin >> fourthMenuChoice;

                                while (cin.fail() || (fourthMenuChoice < 0 || fourthMenuChoice > platforms.at(static_cast<unsigned long>(secondMenuChoice - 1)).getGames().size())) {
                                    cin.clear();
                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                    cout << "You have entered wrong input! Try again: ";
                                    cin >> fourthMenuChoice;
                                }

                                if (fourthMenuChoice == 0) {
                                    thirdMenuChoice = 0;
                                    keepPlatformMenuOn = false;
                                } else {

                                    bool keepAchievementMenuOn = true;

                                    while (keepAchievementMenuOn) {
                                        cout << endl;

                                        cout << "You selected -> " << platforms.at(static_cast<unsigned long>(secondMenuChoice - 1)).getGames().at(static_cast<unsigned long>(fourthMenuChoice - 1)).getName() << endl;

                                        cout << "1 -> Create a achievement" << endl;
                                        cout << "2 -> List current achievements" << endl;
                                        cout << "0 -> Go back" << endl;
                                        cout << "Enter your choice: ";
                                        cin >> fithMenuChoice;

                                        while (cin.fail() || (fithMenuChoice < 0 || fithMenuChoice > 2)) {
                                            cin.clear();
                                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                            cout << "You have entered wrong input! Try again: ";
                                            cin >> fithMenuChoice;
                                        }

                                        cin.ignore(); // ignore the newline here, after the call to cin >>.

                                        if (fithMenuChoice == 0) {
                                            fourthMenuChoice = 0;
                                            keepAchievementMenuOn = false;
                                        } else if (fithMenuChoice == 1) {

                                            cout << endl;

                                            string achTitle, achDescription;
                                            double achScore;

                                            cout << "To create a achievement first type the title: ";
                                            getline(cin, achTitle);

                                            while (achTitle.length() < 3) {
                                                cout << endl;
                                                cout << "You must enter at least 3 characters! Enter again: ";
                                                getline(cin, achTitle);
                                            }

                                            cout << "Second, type the description: ";
                                            getline(cin, achDescription);

                                            while (achDescription.length() < 3) {
                                                cout << endl;
                                                cout << "You must enter at least 3 characters! Enter again: ";
                                                getline(cin, achDescription);
                                            }

                                            cout << "Finally, type the score: ";
                                            cin >> achScore;

                                            while (cin.fail()) {
                                                cin.clear();
                                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                                cout << "You have entered wrong input! Try again: ";
                                                cin >> achScore;
                                            }

                                            cout << endl;

                                            Achievement newAchievement(achTitle, achDescription, achScore);
                                            platforms.at(static_cast<unsigned long>(secondMenuChoice - 1)).getGames().at(static_cast<unsigned long>(fourthMenuChoice - 1)).addAchievement(newAchievement);

                                            cout << "Achievement created successfully!";
                                            cout << endl;

                                        } else if (fithMenuChoice == 2) {

                                            cout << endl;

                                            if (platforms.at(static_cast<unsigned long>(secondMenuChoice - 1)).getGames().at(static_cast<unsigned long>(fourthMenuChoice - 1)).getAchievements().empty()) {
                                                cout << "NO ACHIEVEMENTS! " << endl;
                                            } else {
                                                for (auto &game : platforms.at(static_cast<unsigned long>(secondMenuChoice - 1)).getGames().at(static_cast<unsigned long>(fourthMenuChoice - 1)).getAchievements()) { // access by reference to avoid copying
                                                    cout << (&game - &platforms.at(static_cast<unsigned long>(secondMenuChoice - 1)).getGames().at(static_cast<unsigned long>(fourthMenuChoice - 1)).getAchievements()[0] + 1) << " -> " << game.getTitle() << " - " << game.getDescription() << " - Points: " << game.getScoreValue() << endl;
                                                }
                                            }

                                            cout << "0 -> Go back" << endl;
                                            cout << "Enter your choice: ";
                                            cin >> sixthMenuChoice;

                                            while (cin.fail() || sixthMenuChoice != 0) {
                                                cin.clear();
                                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                                cout << "You have entered wrong input! Try again: ";
                                                cin >> sixthMenuChoice;
                                            }

                                            cin.ignore(); // ignore the newline here, after the call to cin >>.

                                            if (sixthMenuChoice == 0) fithMenuChoice = 0;

                                        }

                                        cout << endl;
                                    }
                                }

                            }

                            cout << endl;
                        }
                    }

                    cout << endl;
                }
            } else {
                cout << "You have to create at least one platform!";
                cout << endl;
            }

        }

    }

    cout << "Exiting application!" << endl;
    return 0;
}