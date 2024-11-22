#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <limits>
#include <iomanip>
using namespace std;

class Player {
    public:
        int Health = 3;
};

Player player;

string PlayAgain;

int pAB = 0, pSB = 0, pMB = 0, pDB = 0, pMIXB;
int pAI = 0, pSI = 0, pMI = 0, pDI = 0, pMIXI;
int pAA = 0, pSA = 0, pMA = 0, pDA = 0, pMIXA;
int pAM = 0, pSM = 0, pMM = 0, pDM = 0, pMIXM;

int score = 0, gems = 10000;

const int INTERMEDIATE_THRESHOLD = 250;
const int ADVANCED_THRESHOLD = 800;
const int MASTER_THRESHOLD = 1650;

int mainmenu() {
    int y;
    cout << "Welcome To Math Quiz Main Menu" << endl;
    do {
        cout << "Please select an option from the menu by entering the corresponding number: " << endl;
        cout << "1. Play" << endl;
        cout << "2. Store" << endl;
        cout << "3. Highscore" << endl;
        cout << "4. Achievements" << endl;
        cout << "5. About" << endl;
        cout << "6. Help" << endl;
        cin >> y;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid choice. Please enter a valid number between 1 and 6." << endl;
        } else if (y < 1 || y > 6) {
            cout << "Invalid choice. Please enter a number between 1 and 6." << endl;
        }
    } while (y < 1 || y > 6 || cin.fail());
    cout <<endl;
    return y;
}

int gamemode() {
    int z;
    cout << "Let's play a game! Please select a game mode by entering the corresponding number: " << endl;
    do {
        cout << "1. Addition" << endl;
        cout << "2. Subtraction" << endl;
        cout << "3. Multiplication" << endl;
        cout << "4. Division" << endl;
        cout << "5. Mix" << endl;
        cin >> z;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid choice. Please enter a valid number." <<endl;
        }else if (z < 1 || z > 5) {
            cout <<"Invalid choice. Please enter a number between 1 and 5"<< endl;
        }
    } while (z < 1 || z > 5 || cin.fail());
    cout <<endl;
    return z;
}

int difficulty() {
    int w;
    cout << "Choose a difficulty level!" << endl;
    do {
        cout << "1. Beginner" << endl;
        cout << "2. Intermediate" << endl;
        cout << "3. Advanced" << endl;
        cout << "4. Master" << endl;
        cin >> w;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid choice. Please enter a valid number." <<endl;
        }else if (w < 1 || w > 4) {
            cout << "Invalid choice. Please enter a number between 1 and 4"<< endl;
        }
    } while (w < 1 || w > 4 || cin.fail());
    return w;
}

void Store(int& health, int& gems) {
    string r;
    int q;
    
    int HealthUpgradeCount = 0;
    
    do {
        int HealthUpgradeCost = 1000 + (HealthUpgradeCount * 1000);

        cout << "\n-- Store --" << endl;
        cout << "Gems: " << gems << " | Health: " << player.Health << endl;
        cout << "1. Buy Health (+1 Health) - Cost: " << HealthUpgradeCost << " gems" << endl;
        cout << "2. Leave Store" << endl;
        cout << "Enter your choice: ";
        cin >> q;
        
        // code dibawah prevent output kespam kalo input user salah
        if (cin.fail()) { //jika input invalid
            cin.clear(); //ngeclear input yg salah
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //hapus invalid input
            cout << "Invalid choice. Please enter a valid number (1 or 2)." << endl; //disuruh input ulang
            continue;
        }
        
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        if (q == 1) {
            if (gems >= HealthUpgradeCost) {
                do {
                    cout << "Are you sure you want to buy more health? (y/n): ";
                    cin >> r;
                    
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    
                    if (r == "y" || r == "Y") {
                        gems -= HealthUpgradeCost;
                        player.Health++;
                        HealthUpgradeCount++;
                        cout << "You've bought 1 health point! Your new health: " << health << endl;
                        break;
                    } else if (r == "n" || r == "N") {
                        cout << "Purchase cancelled." << endl;
                        break;
                    } else {
                        cout << "Invalid input. Please enter 'y' or 'n'." << endl;
                    }
                } while (r != "y" && r != "Y" && r != "n" && r != "N");
            } else {
                cout << "You don't have enough gems to buy more health!" << endl;
            }
        } else if (q == 2) {
            cout << "Leaving store..." << endl;
            break;
        } else {
            cout << "Invalid choice. Please enter a valid option." << endl;
        }
    } while (true);
}

void About() {
    cout << "Math Games is an interactive platform designed to help improve math skills through fun and engaging games. Whether you're a beginner or looking to sharpen your abilities, our games provide a variety of challenges that enhance problem-solving, boost mental agility, and make learning math enjoyable." << "\n";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "\nPress any key to return to the main menu..." << endl;
    cin.get();
}

void MultiplicationTable() {
    const int SIZE = 10;
    int table[SIZE][SIZE];

    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            table[i][j] = (i + 1) * (j + 1);
        }
    }

    cout << "\nMultiplication Table (1 to 10): "<< endl;

    cout <<"    ";
    for (int i = 0; i < SIZE; ++i) {
        cout << setw(4) << (i + 1);
    }
    cout << endl;

    for (int i = 0; i < SIZE; ++i) {
        cout << setw(4) << (i + 1);
        for (int j = 0; j < SIZE; ++j) {
            cout << setw(4) <<  table[i][j];
        }
        cout << endl;
    }
}

void Help() {
    cout << "\n-- Help Section --"<< endl;
    MultiplicationTable();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "\nPress any key to return to the main menu..." << endl;
    cin.get();
}

void AdditionBeginner(int& score, int&health, int& gems) {
    int AB1, AB2, ABP, ABC;
    int BGEMS = 1;
    int BPOINTS = 10;
    
    do {
        score = 0;
        while (player.Health > 0) {
            AB1 = rand() % 10 + 1;
            AB2 = rand() % 10 + 1;
            ABC = AB1 + AB2;
            
            cout << AB1 << " + " << AB2 << " = ";
            while (true) {
                cin >> ABP;
                if (cin.fail()) {
                    cout << "Invalid input. Please enter a valid integer answer." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << AB1 << " + " << AB2 << " = ";
                } else {
                    break;
                }
            }
            if (ABP == ABC) {
                score += BPOINTS;
                gems += BGEMS;
            } else {
                cout << "Incorrect. The correct answer is " << ABC << "." << endl;
                player.Health--;
                cout << "You lost 1 life. Your health remaining is: " << player.Health << endl;
                
                if (player.Health <= 0) {
                    cout << "Game over! You're out of lives." << endl;
                }
            }
        }
        cout << "Final Score: " << score << " | Total Gems: " << gems << endl;
        pAB += score;
        if (pAB >= INTERMEDIATE_THRESHOLD) {
            cout <<"You've unlocked Intermediate difficulty for Addition!"<< endl;
        }
        cout <<"play again?(y/n): "<< endl;
        cin >> PlayAgain;
        while (PlayAgain != "y" && PlayAgain != "Y" && PlayAgain != "n" && PlayAgain != "N") {
            cout << "Invalid input. Please enter 'y' to play again or 'n' to exit: ";
            cin >> PlayAgain;
            cout << endl;
        }
    }while (PlayAgain == "y" || PlayAgain == "Y");
    cout <<"Returning to Main Menu..."<< endl;
}

void SubstractionBeginner(int& score, int& health, int& gems) {
    int SB1, SB2, SBP, SBC;
    int BGEMS = 1;
    int BPOINTS = 10;
    
    do {
        score = 0;
        while (player.Health > 0) {
            do {
                SB1 = rand() % 10 + 1;
                SB2 = rand() % 10 + 1;
                SBC = SB1 - SB2;
            } while (SBC < 0);
            cout << SB1 << " - " << SB2 << " = ";
            while (true) {
                cin >> SBP;
                if (cin.fail()) {
                    cout << "Invalid input. Please enter a valid integer answer." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << SB1 << " - " << SB2 << " = ";
                } else {
                    break;
                }
            }
            if (SBP == SBC) {
                score += BPOINTS;
                gems += BGEMS;
            } else {
                cout << "Incorrect. The correct answer is " << SBC << "." << endl;
                player.Health--;
                cout << "You lost 1 life. Your health remaining is: " << player.Health << endl;
                
                if (player.Health <= 0) {
                    cout << "Game over! You're out of lives." << endl;
                }
            }
        }
        cout << "Final Score: " << score << " | Total Gems: " << gems << endl;
        pSB += score;
        if (pSB >= INTERMEDIATE_THRESHOLD) {
            cout <<"You've unlocked Intermediate difficulty for Substraction!"<< endl;
        }
        cout <<"Play again?(y/n): "<< endl;
        cin >> PlayAgain;
        while (PlayAgain != "y" && PlayAgain != "Y" && PlayAgain != "n" && PlayAgain != "N") {
            cout << "Invalid input. Please enter 'y' to play again or 'n' to exit: ";
            cin >> PlayAgain;
            cout << endl;
        }
    } while (PlayAgain == "y" || PlayAgain == "Y");
    cout <<"Returning to Main Menu..."<< endl;
}

void MultiplicationBeginner(int& score, int& health, int& gems) {
    int MB1, MB2, MBP, MBC;
    int BGEMS = 1;
    int BPOINTS = 10;
    
    do {
        score = 0;
        while (player.Health > 0) {
            MB1 = rand() % 10 + 1;
            MB2 = rand() % 10 + 1;
            MBC = MB1 * MB2;
                
            cout << MB1 <<" X "<< MB2 <<" = ";
            while (true) {
                cin >> MBP;
                if (cin.fail()) {
                    cout << "Invalid input. Please enter a valid integer answer." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << MB1 << " X " << MB2 << " = ";
                } else {
                    break;
                }
            }
            if (MBP == MBC) {
                score += BPOINTS;
                gems += BGEMS;
            } else {
                cout <<"Incorrect. The correct answer is "<< MBC << "."<< endl;
                player.Health--;
                cout <<"You lost 1 life. Your health remaining is: " << player.Health << endl;
                
                if (player.Health <= 0) {
                    cout <<"Game over! You're out of lives." <<endl;
                }
            }
        }
        cout << "Final Score: " << score << " | Total Gems: " << gems << endl;
        pMB += score;
        if (pMB >= INTERMEDIATE_THRESHOLD) {
            cout <<"You've unlocked Intermediate difficulty for Multiplication!"<< endl;
        }
        cout <<"Play again?(y/n): "<< endl;
        cin >> PlayAgain;
        while (PlayAgain != "y" && PlayAgain != "Y" && PlayAgain != "n" && PlayAgain != "N") {
            cout << "Invalid input. Please enter 'y' to play again or 'n' to exit: ";
            cin >> PlayAgain;
            cout << endl;
        }
    } while (PlayAgain == "y" || PlayAgain == "Y");
    cout <<"Returning to Main Menu..."<< endl;
}

void DivisionBeginner(int& score, int&health, int& gems) {
    int DB1, DB2, DBP, DBC;
    int BGEMS = 1 ;
    int BPOINTS = 10;
    
    do {
        score = 0;
        while (player.Health > 0) {
            do {
                DB1 = rand() % 10 + 1;
                DB2 = rand() % 10 + 1;
            } while (DB1 % DB2 !=0);
            DBC = DB1/DB2;
            
            cout << DB1 <<" / "<< DB2 <<" = ";
            while (true) {
                cin >> DBP;
                if (cin.fail()) {
                    cout << "Invalid input. Please enter a valid integer answer." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << DB1 << " / " << DB2 << " = ";
                } else {
                    break;
                }
            }
            if (DBP == DBC) {
                score += BPOINTS;
                gems += BGEMS;
            } else {
                cout <<"Incorrect. The correct answer is "<< DBC <<"."<< endl;
                player.Health--;
                cout <<"You lost 1 life. Your health remaining is: "<< player.Health << endl;
                
                if (player.Health <= 0) {
                    cout <<"Game over! You're out of lives." << endl;
                }
            }
        }
        cout << "Final Score: " << score << " | Total Gems: " << gems << endl;
        pDB += score;
        if (pDB >= INTERMEDIATE_THRESHOLD) {
            cout <<"You've unlocked Intermediate difficulty for Division!"<< endl;
        }
        cout <<"Play again?(y/n): "<< endl;
        cin >> PlayAgain;
        while (PlayAgain != "y" && PlayAgain != "Y" && PlayAgain != "n" && PlayAgain != "N") {
            cout << "Invalid input. Please enter 'y' to play again or 'n' to exit: ";
            cin >> PlayAgain;
            cout << endl;
        }
    } while (PlayAgain == "y" || PlayAgain == "Y");
    cout <<"Returning to Main Menu..."<< endl;
}

void MixBeginner(int& score, int& health, int& gems) {
    int s, MIXBP, MIXBC;
    int BGEMS = 1;
    int BPOINTS = 10;
    
    do {
        score = 0;
        while (player.Health > 0) {
            do {
                s = rand() % 4 + 1;
                if (s == 1) {
                    int AB1, AB2;
                    AB1 = rand() % 10 + 1;
                    AB2 = rand() % 10 + 1;
                    MIXBC = AB1 + AB2;
                    
                    cout << AB1 << " + " << AB2 << " = ";
                    while (true) {
                        cin >> MIXBP;
                        if (cin.fail()) {
                            cout << "Invalid input. Please enter a valid integer answer." << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << AB1 << " + " << AB2 << " = ";
                        } else {
                            break;
                        }
                    }
                    if (MIXBP == MIXBC) {
                        score += BPOINTS;
                        gems += BGEMS;
                    } else {
                        cout << "Incorrect. The correct answer is " << MIXBC << "." << endl;
                        player.Health--;
                        cout << "You lost 1 life. Your health remaining is: " << player.Health << endl;
                    }
                } else if (s == 2) {
                    int SB1, SB2;
                    do {
                        SB1 = rand() % 10 + 1;
                        SB2 = rand() % 10 + 1;
                        MIXBC = SB1 - SB2;
                    } while (MIXBC < 0);
                    cout << SB1 << " - " << SB2 << " = ";
                    while (true) {
                        cin >> MIXBP;
                        if (cin.fail()) {
                            cout << "Invalid input. Please enter a valid integer answer." << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << SB1 << " + " << SB2 << " = ";
                        } else {
                            break;
                        }
                    }
                    if (MIXBP == MIXBC) {
                        score += BPOINTS;
                        gems += BGEMS;
                    } else {
                        cout << "Incorrect. The correct answer is " << MIXBC << "." << endl;
                        player.Health--;
                        cout << "You lost 1 life. Your health remaining is: " << player.Health << endl;
                    }
                } else if (s == 3){
                    int MB1, MB2;
                    MB1 = rand() % 10 + 1;
                    MB2 = rand() % 10 + 1;
                    MIXBC = MB1 * MB2;
                    
                    cout << MB1 << " X " << MB2 << " = ";
                    while (true) {
                        cin >> MIXBP;
                        if (cin.fail()) {
                            cout << "Invalid input. Please enter a valid integer answer." << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << MB1 << " + " << MB2 << " = ";
                        } else {
                            break;
                        }
                    }
                    if (MIXBP == MIXBC) {
                        score += BPOINTS;
                        gems += BGEMS;
                    } else {
                        cout << "Incorrect. The correct answer is " << MIXBC << "." << endl;
                        player.Health--;
                        cout << "You lost 1 life. Your health remaining is: " << player.Health << endl;
                    }
                } else if (s == 4){
                    int DB1, DB2;
                    do {
                        DB1 = rand() % 10 + 1;
                        DB2 = rand() % 10 + 1;
                    } while (DB1 % DB2 !=0);
                    MIXBC = DB1/DB2;
                    
                    cout << DB1 << " / " << DB2 << " = ";
                    while (true) {
                        cin >> MIXBP;
                        if (cin.fail()) {
                            cout << "Invalid input. Please enter a valid integer answer." << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << DB1 << " + " << DB2 << " = ";
                        } else {
                            break;
                        }
                    }
                    if (MIXBP == MIXBC) {
                        score += BPOINTS;
                        gems += BGEMS;
                    } else {
                        cout << "Incorrect. The correct answer is " << MIXBC << "." << endl;
                        player.Health--;
                        cout << "You lost 1 life. Your health remaining is: " << player.Health << endl;
                    }
                }
                if (player.Health <= 0) {
                    cout <<"Game over! You're out of lives." <<endl;
                }
            } while (player.Health > 0);
            cout <<"Final Score: " << score << " | Total Gems: " << gems << endl;
            pMIXB += score;
            if (pMIXB >= INTERMEDIATE_THRESHOLD) {
                cout <<"You've unlocked Intermediate difficulty for Mix!"<< endl;
            }
            cout <<"Play again?(y/n): "<< endl;
            cin >> PlayAgain;
            while (PlayAgain != "y" && PlayAgain != "Y" && PlayAgain != "n" && PlayAgain != "N") {
                cout << "Invalid input. Please enter 'y' to play again or 'n' to exit: ";
                cin >> PlayAgain;
                cout << endl;
            }
        }
    } while (PlayAgain == "y" || PlayAgain == "Y");
    cout <<"Returning to Main Menu..."<< endl;
}

void AdditionIntermediate(int& score, int& health, int& gems) {
    int AI1, AI2, AIP, AIC;
    int IGEMS = 3;
    int IPOINTS = 20;
    
    do {
        score = 0;
        while (player.Health > 0) {
            AI1 = rand() % 10 + 11;
            AI2 = rand() % 10 + 11;
            AIC = AI1 + AI2;
            
            cout << AI1 << " + " << AI2 << " = ";
            while (true) {
                cin >> AIP;
                if (cin.fail()) {
                    cout << "Invalid input. Please enter a valid integer answer." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << AI1 << " + " << AI2 << " = ";
                } else {
                    break;
                }
            }
            if (AIP == AIC) {
                score += IPOINTS;
                gems += IGEMS;
            } else {
                cout << "Incorrect. The correct answer is " << AIC << "." << endl;
                player.Health--;
                cout << "You lost 1 life. Your health remaining is: " << player.Health << endl;
                
                if (player.Health <= 0) {
                    cout << "Game over! You're out of lives." << endl;
                }
            }
        }
        cout << "Final Score: " << score << " | Total Gems: " << gems << endl;
        pAI += score;
        if (pAI >= ADVANCED_THRESHOLD) {
            cout <<"You've unlocked Advanced difficulty for Addition!"<< endl;
        }
        cout <<"Play again?(y/n): "<< endl;
        cin >> PlayAgain;
        while (PlayAgain != "y" && PlayAgain != "Y" && PlayAgain != "n" && PlayAgain != "N") {
            cout << "Invalid input. Please enter 'y' to play again or 'n' to exit: ";
            cin >> PlayAgain;
            cout << endl;
        }
    } while (PlayAgain == "y" || PlayAgain == "Y");
       cout <<"Returning to Main Menu..."<< endl;
}

void SubstractionIntermediate(int& score, int& health, int& gems) {
    int SI1, SI2, SIP, SIC;
    int IGEMS = 3;
    int IPOINTS = 20;

    do {
        score = 0;
        while (player.Health > 0) {
            do {
                SI1 = rand() % 10 + 11;
                SI2 = rand() % 10 + 11;
                SIC = SI1 - SI2;
            } while (SIC < 0);

            cout << SI1 << " - " << SI2 << " = ";
            while (true) {
                cin >> SIP;
                if (cin.fail()) {
                    cout << "Invalid input. Please enter a valid integer answer." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << SI1 << " - " << SI2 << " = ";
                } else {
                    break;
                }
            }
            if (SIP == SIC) {
                score += IPOINTS;
                gems += IGEMS;
            } else {
                cout << "Incorrect. The correct answer is " << SIC << "." << endl;
                player.Health--;
                cout << "You lost 1 life. Your health remaining is: " << player.Health << endl;

                if (player.Health <= 0) {
                    cout << "Game over! You're out of lives." << endl;
                }
            }
        }
        cout << "Final Score: " << score << " | Total Gems: " << gems << endl;
        pSI += score;
        if (pSI >= ADVANCED_THRESHOLD) {
            cout <<"You've unlocked Advanced difficulty for Substraction!"<< endl;
        }
        cout <<"Play again?(y/n): "<< endl;
        cin >> PlayAgain;
        while (PlayAgain != "y" && PlayAgain != "Y" && PlayAgain != "n" && PlayAgain != "N") {
            cout << "Invalid input. Please enter 'y' to play again or 'n' to exit: ";
            cin >> PlayAgain;
            cout << endl;
        }
    } while (PlayAgain == "y" || PlayAgain == "Y");
    cout <<"Returning to Main Menu..."<< endl;
}

void MultiplicationIntermediate(int& score, int& health, int& gems) {
    int MI1, MI2, MIP, MIC;
    int IGEMS = 3;
    int IPOINTS = 20;

    do {
        score = 0;
        while (player.Health > 0) {
            MI1 = rand() % 10 + 11;
            MI2 = rand() % 10 + 11;
            MIC = MI1 * MI2;

            cout << MI1 << " X " << MI2 << " = ";
            while (true) {
                cin >> MIP;
                if (cin.fail()) {
                    cout << "Invalid input. Please enter a valid integer answer." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << MI1 << " X " << MI2 << " = ";
                } else {
                    break;
                }
            }
            if (MIP == MIC) {
                score += IPOINTS;
                gems += IGEMS;
            } else {
                cout << "Incorrect. The correct answer is " << MIC << "." << endl;
                player.Health--;
                cout << "You lost 1 Life. Your health remaining is: " << player.Health << endl;

                if (player.Health <= 0) {
                    cout << "Game over! You're out of lives." << endl;
                }
            }
        }
        cout << "Final Score: " << score << " | Total Gems: " << gems << endl;
        pMI += score;
        if (pMI >= ADVANCED_THRESHOLD) {
            cout <<"You've unlocked Advanced difficulty for Multiplication!"<< endl;
        }
        cout <<"Play again?(y/n): "<< endl;
        cin >> PlayAgain;
        while (PlayAgain != "y" && PlayAgain != "Y" && PlayAgain != "n" && PlayAgain != "N") {
            cout << "Invalid input. Please enter 'y' to play again or 'n' to exit: ";
            cin >> PlayAgain;
            cout << endl;
        }
    } while (PlayAgain == "y" || PlayAgain == "Y");
    cout <<"Returning to Main Menu..."<< endl;
}

void DivisionIntermediate(int& score, int& health, int& gems){
    int DI1, DI2, DIP, DIC;
    int IGEMS = 3;
    int IPOINTS = 20;
    
    do {
        score = 0;
        while (health > 0){
            do{
                DI1 = rand() % 10 + 11; //range 11 - 20
                DI2 = rand() % 20 + 1; //range 1-20
            } while (DI1 % DI2 != 0);
            DIC = DI1 / DI2;
            
            cout << DI1 <<" / "<< DI2 <<" = ";
            while (true) {
                cin >> DIP;
                if (cin.fail()) {
                    cout << "Invalid input. Please enter a valid integer answer." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << DI1 << " / " << DI2 << " = ";
                } else {
                    break;
                }
            }
            if (DIP == DIC) {
                score += IPOINTS;
                gems += IGEMS;
            } else {
                cout <<"Incorrect. The correct answer is "<< DIC <<"."<< endl;
                player.Health--;
                cout <<"You lost 1 life. Your health remaining is: "<< player.Health << endl;
                
                if (player.Health <= 0) {
                    cout <<"Game over! You're out of lives." << endl;
                }
            }
        }
        cout <<"Final Score: " << score << " | Total Gems: " << gems << endl;
        pDI += score;
        if (pDI >= ADVANCED_THRESHOLD) {
            cout <<"You've unlocked Advanced difficulty for Addition!"<< endl;
        }
        cout <<"Play again?(y/n): "<< endl;
        cin >> PlayAgain;
        while (PlayAgain != "y" && PlayAgain != "Y" && PlayAgain != "n" && PlayAgain != "N") {
            cout << "Invalid input. Please enter 'y' to play again or 'n' to exit: ";
            cin >> PlayAgain;
            cout << endl;
        }
    } while (PlayAgain == "y" || PlayAgain == "Y");
    cout <<"Returning to Main Menu..."<< endl;
}

void MixIntermediate(int& score, int& health, int& gems) {
    int s, MIXIP, MIXIC;
    int BGEMS = 3;
    int BPOINTS = 20;
    
    do {
        score = 0;
        while (player.Health > 0) {
            do {
                s = rand() % 4 + 1;
                if (s == 1) {
                    int AI1, AI2;
                    AI1 = rand() % 10 + 11;
                    AI2 = rand() % 10 + 11;
                    MIXIC = AI1 + AI2;
                    
                    cout << AI1 << " + " << AI2 << " = ";
                    while (true) {
                        cin >> MIXIP;
                        if (cin.fail()) {
                            cout << "Invalid input. Please enter a valid integer answer." << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << AI1 << " + " << AI2 << " = ";
                        } else {
                            break;
                        }
                    }
                    if (MIXIP == MIXIC) {
                        score += BPOINTS;
                        gems += BGEMS;
                    } else {
                        cout << "Incorrect. The correct answer is " << MIXIC << "." << endl;
                        player.Health--;
                        cout << "You lost 1 life. Your health remaining is: " << player.Health << endl;
                    }
                } else if (s == 2) {
                    int SI1, SI2;
                    do {
                        SI1 = rand() % 10 + 11;
                        SI2 = rand() % 10 + 11;
                        MIXIC = SI1 - SI2;
                    } while (MIXIC < 0);
                    cout << SI1 << " - " << SI2 << " = ";
                    while (true) {
                        cin >> MIXIP;
                        if (cin.fail()) {
                            cout << "Invalid input. Please enter a valid integer answer." << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << SI1 << " - " << SI2 << " = ";
                        } else {
                            break;
                        }
                    }
                    if (MIXIP == MIXIC) {
                        score += BPOINTS;
                        gems += BGEMS;
                    } else {
                        cout << "Incorrect. The correct answer is " << MIXIC << "." << endl;
                        player.Health--;
                        cout << "You lost 1 life. Your health remaining is: " << player.Health << endl;
                    }
                } else if (s == 3){
                    int MI1, MI2;
                    MI1 = rand() % 10 + 11;
                    MI2 = rand() % 10 + 11;
                    MIXIC = MI1 * MI2;
                    
                    cout << MI1 << " X " << MI2 << " = ";
                    while (true) {
                        cin >> MIXIP;
                        if (cin.fail()) {
                            cout << "Invalid input. Please enter a valid integer answer." << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << MI1 << " X " << MI2 << " = ";
                        } else {
                            break;
                        }
                    }
                    if (MIXIP == MIXIC) {
                        score += BPOINTS;
                        gems += BGEMS;
                    } else {
                        cout << "Incorrect. The correct answer is " << MIXIC << "." << endl;
                        player.Health--;
                        cout << "You lost 1 life. Your health remaining is: " << player.Health << endl;
                    }
                } else if (s == 4){
                    int DI1, DI2;
                    do {
                        DI1 = rand() % 10 + 11;
                        DI2 = rand() % 20 + 1;
                    } while (DI1 % DI2 !=0);
                    MIXIC = DI1/DI2;
                    
                    cout << DI1 << " / " << DI2 << " = ";
                    while (true) {
                        cin >> MIXIP;
                        if (cin.fail()) {
                            cout << "Invalid input. Please enter a valid integer answer." << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << DI1 << " / " << DI2 << " = ";
                        } else {
                            break;
                        }
                    }
                    if (MIXIP == MIXIC) {
                        score += BPOINTS;
                        gems += BGEMS;
                    } else {
                        cout << "Incorrect. The correct answer is " << MIXIC << "." << endl;
                        player.Health--;
                        cout << "You lost 1 life. Your health remaining is: " << player.Health << endl;
                    }
                }
                if (player.Health <= 0) {
                    cout <<"Game over! You're out of lives." <<endl;
                }
            } while (player.Health > 0);
            cout <<"Final Score: " << score << " | Total Gems: " << gems << endl;
            pMIXI += score;
            if (pMIXI >= ADVANCED_THRESHOLD) {
                cout <<"You've unlocked Advanced difficulty for Mix!"<< endl;
            }
            cout <<"Play again?(y/n): "<< endl;
            cin >> PlayAgain;
            while (PlayAgain != "y" && PlayAgain != "Y" && PlayAgain != "n" && PlayAgain != "N") {
                cout << "Invalid input. Please enter 'y' to play again or 'n' to exit: ";
                cin >> PlayAgain;
                cout << endl;
            }
        }
    } while (PlayAgain == "y" || PlayAgain == "Y");
    cout <<"Returning to Main Menu..."<< endl;
}

void AdditionAdvance(int& score, int& health, int& gems) {
    int AA1, AA2, AAP, AAC;
    int AGEMS = 5;
    int APOINTS = 30;
    
    do {
        score = 0;
        while (player.Health > 0) {
            AA1 = rand() % 30 + 21;
            AA2 = rand() % 30 + 21;
            AAC = AA1 + AA2;
            
            cout << AA1 << " + " << AA2 << " = ";
            while (true) {
                cin >> AAP;
                if (cin.fail()) {
                    cout << "Invalid input. Please enter a valid integer answer." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << AA1 << " + " << AA2 << " = ";
                } else {
                    break;
                }
            }
            if (AAP == AAC) {
                score += APOINTS;
                gems += AGEMS;
            } else {
                cout << "Incorrect. The correct answer is " << AAC << "." << endl;
                player.Health--;
                cout << "You lost 1 life. Your health remaining is: " << player.Health << endl;
                
                if (player.Health <= 0) {
                    cout << "Game over! You're out of lives." << endl;
                }
            }
        }
        cout << "Final Score: " << score << " | Total Gems: " << gems << endl;
        pAA += score;
        if (pAA >= MASTER_THRESHOLD) {
            cout <<"You've unlocked Advanced difficulty for Substraction!"<< endl;
        }
        cout <<"Play again?(y/n): "<< endl;
        cin >> PlayAgain;
        while (PlayAgain != "y" && PlayAgain != "Y" && PlayAgain != "n" && PlayAgain != "N") {
            cout << "Invalid input. Please enter 'y' to play again or 'n' to exit: ";
            cin >> PlayAgain;
            cout << endl;
        }
    } while (PlayAgain == "y" || PlayAgain == "Y");
    cout <<"Returning to Main Menu..."<< endl;
}

void SubstractionAdvanced(int& score, int& health, int& gems) {
    int SA1, SA2, SAP, SAC;
    int AGEMS = 5;
    int APOINTS = 30;

    do {
        score = 0;
        while (player.Health > 0) {
            do {
                SA1 = rand() % 30 + 21;
                SA2 = rand() % 30 + 21;
                SAC = SA1 - SA2;
            } while (SAC < 0);

            cout << SA1 << " - " << SA2 << " = ";
            while (true) {
                cin >> SAP;
                if (cin.fail()) {
                    cout << "Invalid input. Please enter a valid integer answer." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << SA1 << " / " << SA2 << " = ";
                } else {
                    break;
                }
            }
            if (SAP == SAC) {
                score += APOINTS;
                gems += AGEMS;
            } else {
                cout << "Incorrect. The correct answer is " << SAC << "." << endl;
                player.Health--;
                cout << "You lost 1 life. Your health remaining is: " << player.Health << endl;

                if (player.Health <= 0) {
                    cout << "Game over! You're out of lives." << endl;
                }
            }
        }
        cout << "Final Score: " << score << " | Total Gems: " << gems << endl;
        pSA += score;
        if (pSA >= MASTER_THRESHOLD) {
            cout <<"You've unlocked Advanced difficulty for Substraction!"<< endl;
        }
        cout <<"Play again?(y/n): "<< endl;
        cin >> PlayAgain;
        while (PlayAgain != "y" && PlayAgain != "Y" && PlayAgain != "n" && PlayAgain != "N") {
            cout << "Invalid input. Please enter 'y' to play again or 'n' to exit: ";
            cin >> PlayAgain;
            cout << endl;
        }
    } while (PlayAgain == "y" || PlayAgain == "Y");
    cout <<"Returning to Main Menu..."<< endl;
}

void MultiplicationAdvance(int& score, int& health, int& gems) {
    int MA1, MA2, MAP, MAC;
    int AGEMS = 5;
    int APOINTS = 30;

    do {
        score = 0;
        while (player.Health > 0) {
            MA1 = rand() % 30 + 21;
            MA2 = rand() % 30 + 21;
            MAC = MA1 * MA2;

            cout << MA1 << " X " << MA2 << " = ";
            while (true) {
                cin >> MAP;
                if (cin.fail()) {
                    cout << "Invalid input. Please enter a valid integer answer." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << MA1 << " X " << MA2 << " = ";
                } else {
                    break;
                }
            }
            if (MAP == MAC) {
                score += APOINTS;
                gems += AGEMS;
            } else {
                cout << "Incorrect. The correct answer is " << MAC << "." << endl;
                player.Health--;
                cout << "You lost 1 Life. Your health remaining is: " << player.Health << endl;

                if (player.Health <= 0) {
                    cout << "Game over! You're out of lives." << endl;
                }
            }
        }
        cout << "Final Score: " << score << " | Total Gems: " << gems << endl;
        pMA += score;
        if (pMA >= MASTER_THRESHOLD) {
            cout <<"You've unlocked Advanced difficulty for Substraction!"<< endl;
        }
        cout <<"Play again?(y/n): "<< endl;
        cin >> PlayAgain;
        while (PlayAgain != "y" && PlayAgain != "Y" && PlayAgain != "n" && PlayAgain != "N") {
            cout << "Invalid input. Please enter 'y' to play again or 'n' to exit: ";
            cin >> PlayAgain;
            cout << endl;
        }
    } while (PlayAgain == "y" || PlayAgain == "Y");
    cout <<"Returning to Main Menu..."<< endl;
}

void DivisionAdvanced(int& score, int& health, int& gems){
    int DA1, DA2, DAP, DAC;
    int AGEMS = 5;
    int APOINTS = 30;
    
    do {
        score = 0;
        while (health > 0){
            do{
                DA1 = rand() % 30 + 21; //range 21 - 50
                DA2 = rand() % 50 + 1; //range 1 - 50
            } while (DA1 % DA2 != 0);
            DAC = DA1 / DA2;
            
            cout << DA1 <<" / "<< DA2 <<" = ";
            while (true) {
                cin >> DAP;
                if (cin.fail()) {
                    cout << "Invalid input. Please enter a valid integer answer." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << DA1 << " X " << DA2 << " = ";
                } else {
                    break;
                }
            }
            if (DAP == DAC) {
                score += APOINTS;
                gems += AGEMS;
            } else {
                cout <<"Incorrect. The correct answer is "<< DAC <<"."<< endl;
                player.Health--;
                cout <<"You lost 1 life. Your health remaining is: "<< player.Health << endl;
                
                if (player.Health <= 0) {
                    cout <<"Game over! You're out of lives." << endl;
                }
            }
        }
        cout <<"Final Score: " << score << " | Total Gems: " << gems << endl;
        pDA += score;
        if (pDA >= MASTER_THRESHOLD) {
            cout <<"You've unlocked Advanced difficulty for Substraction!"<< endl;
        }
        cout <<"Play again?(y/n): "<< endl;
        cin >> PlayAgain;
        while (PlayAgain != "y" && PlayAgain != "Y" && PlayAgain != "n" && PlayAgain != "N") {
            cout << "Invalid input. Please enter 'y' to play again or 'n' to exit: ";
            cin >> PlayAgain;
            cout << endl;
        }
    } while (PlayAgain == "y" || PlayAgain == "Y");
    cout <<"Returning to Main Menu..."<< endl;
}

void MixAdvanced(int& score, int& health, int& gems) {
    int s, MIXAP, MIXAC;
    int BGEMS = 5;
    int BPOINTS = 30;
    
    do {
        score = 0;
        while (player.Health > 0) {
            do {
                s = rand() % 4 + 1;
                if (s == 1) {
                    int AA1, AA2;
                    AA1 = rand() % 10 + 11;
                    AA2 = rand() % 10 + 11;
                    MIXAC = AA1 + AA2;
                    
                    cout << AA1 << " + " << AA2 << " = ";
                    while (true) {
                        cin >> MIXAP;
                        if (cin.fail()) {
                            cout << "Invalid input. Please enter a valid integer answer." << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << AA1 << " + " << AA2 << " = ";
                        } else {
                            break;
                        }
                    }
                    if (MIXAP == MIXAC) {
                        score += BPOINTS;
                        gems += BGEMS;
                    } else {
                        cout << "Incorrect. The correct answer is " << MIXAC << "." << endl;
                        player.Health--;
                        cout << "You lost 1 life. Your health remaining is: " << player.Health << endl;
                    }
                } else if (s == 2) {
                    int SA1, SA2;
                    do {
                        SA1 = rand() % 10 + 11;
                        SA2 = rand() % 10 + 11;
                        MIXAC = SA1 - SA2;
                    } while (MIXAC < 0);
                    cout << SA1 << " - " << SA2 << " = ";
                    while (true) {
                        cin >> MIXAP;
                        if (cin.fail()) {
                            cout << "Invalid input. Please enter a valid integer answer." << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << SA1 << " - " << SA2 << " = ";
                        } else {
                            break;
                        }
                    }
                    if (MIXAP == MIXAC) {
                        score += BPOINTS;
                        gems += BGEMS;
                    } else {
                        cout << "Incorrect. The correct answer is " << MIXAC << "." << endl;
                        player.Health--;
                        cout << "You lost 1 life. Your health remaining is: " << player.Health << endl;
                    }
                } else if (s == 3){
                    int MA1, MA2;
                    MA1 = rand() % 10 + 11;
                    MA2 = rand() % 10 + 11;
                    MIXAC = MA1 * MA2;
                    
                    cout << MA1 << " X " << MA2 << " = ";
                    while (true) {
                        cin >> MIXAP;
                        if (cin.fail()) {
                            cout << "Invalid input. Please enter a valid integer answer." << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << MA1 << " X " << MA2 << " = ";
                        } else {
                            break;
                        }
                    }
                    if (MIXAP == MIXAC) {
                        score += BPOINTS;
                        gems += BGEMS;
                    } else {
                        cout << "Incorrect. The correct answer is " << MIXAC << "." << endl;
                        player.Health--;
                        cout << "You lost 1 life. Your health remaining is: " << player.Health << endl;
                    }
                } else if (s == 4){
                    int DA1, DA2;
                    do {
                        DA1 = rand() % 10 + 11;
                        DA2 = rand() % 20 + 1;
                    } while (DA1 % DA2 !=0);
                    MIXAC = DA1/DA2;
                    
                    cout << DA1 << " / " << DA2 << " = ";
                    while (true) {
                        cin >> MIXAP;
                        if (cin.fail()) {
                            cout << "Invalid input. Please enter a valid integer answer." << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << DA1 << " / " << DA2 << " = ";
                        } else {
                            break;
                        }
                    }
                    if (MIXAP == MIXAC) {
                        score += BPOINTS;
                        gems += BGEMS;
                    } else {
                        cout << "Incorrect. The correct answer is " << MIXAC << "." << endl;
                        player.Health--;
                        cout << "You lost 1 life. Your health remaining is: " << player.Health << endl;
                    }
                }
                if (player.Health <= 0) {
                    cout <<"Game over! You're out of lives." <<endl;
                }
            } while (player.Health > 0);
            cout <<"Final Score: " << score << " | Total Gems: " << gems << endl;
            pMIXA += score;
            if (pMIXA >= MASTER_THRESHOLD) {
                cout <<"You've unlocked Master difficulty for Mix!"<< endl;
            }
            cout <<"Play again?(y/n): "<< endl;
            cin >> PlayAgain;
            while (PlayAgain != "y" && PlayAgain != "Y" && PlayAgain != "n" && PlayAgain != "N") {
                cout << "Invalid input. Please enter 'y' to play again or 'n' to exit: ";
                cin >> PlayAgain;
                cout << endl;
            }
        }
    } while (PlayAgain == "y" || PlayAgain == "Y");
    cout <<"Returning to Main Menu..."<< endl;
}

void AdditionMaster(int& score, int& health, int& gems) {
    int AM1, AM2, AMP, AMC;
    int MGEMS = 10;
    int MPOINTS = 50;
    
    do {
        score = 0;
        while (player.Health > 0) {
            AM1 = rand() % 50 + 51;
            AM2 = rand() % 50 + 51;
            AMC = AM1 + AM2;
            
            cout << AM1 << " + " << AM2 << " = ";
            while (true) {
                cin >> AMP;
                if (cin.fail()) {
                    cout << "Invalid input. Please enter a valid integer answer." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << AM1 << " X " << AM2 << " = ";
                } else {
                    break;
                }
            }
            if (AMP == AMC) {
                score += MPOINTS;
                gems += MGEMS;
            } else {
                cout << "Incorrect. The correct answer is " << AMC << "." << endl;
                player.Health--;
                cout << "You lost 1 life. Your health remaining is: " << player.Health << endl;
                
                if (player.Health <= 0) {
                    cout << "Game over! You're out of lives." << endl;
                }
            }
        }
        cout << "Final Score: " << score << " | Total Gems: " << gems << endl;
        cout <<"Play again?(y/n): "<< endl;
        cin >> PlayAgain;
        while (PlayAgain != "y" && PlayAgain != "Y" && PlayAgain != "n" && PlayAgain != "N") {
            cout << "Invalid input. Please enter 'y' to play again or 'n' to exit: ";
            cin >> PlayAgain;
            cout << endl;
        }
    } while (PlayAgain == "y" || PlayAgain == "Y");
    cout <<"Returning to Main Menu..."<< endl;
}

void SubstractionMaster(int& score, int& health, int& gems) {
    int SM1, SM2, SMP, SMC;
    int MGEMS = 10;
    int MPOINTS = 50;

    do {
        score = 0;
        while (player.Health > 0) {
            do {
                SM1 = rand() % 50 + 51;
                SM2 = rand() % 50 + 51;
                SMC = SM1 - SM2;
            } while (SMC < 0);

            cout << SM1 << " - " << SM2 << " = ";
            while (true) {
                cin >> SMP;
                if (cin.fail()) {
                    cout << "Invalid input. Please enter a valid integer answer." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << SM1 << " X " << SM2 << " = ";
                } else {
                    break;
                }
            }
            if (SMP == SMC) {
                score += MPOINTS;
                gems += MGEMS;
            } else {
                cout << "Incorrect. The correct answer is " << SMC << "." << endl;
                player.Health--;
                cout << "You lost 1 life. Your health remaining is: " << player.Health << endl;

                if (player.Health <= 0) {
                    cout << "Game over! You're out of lives." << endl;
                }
            }
        }
        cout << "Final Score: " << score << " | Total Gems: " << gems << endl;
        cout <<"Play again?(y/n): "<< endl;
        cin >> PlayAgain;
        while (PlayAgain != "y" && PlayAgain != "Y" && PlayAgain != "n" && PlayAgain != "N") {
            cout << "Invalid input. Please enter 'y' to play again or 'n' to exit: ";
            cin >> PlayAgain;
            cout << endl;
        }
    } while (PlayAgain == "y" || PlayAgain == "Y");
    cout <<"Returning to Main Menu..."<< endl;
}

void MultiplicationMaster(int& score, int& health, int& gems) {
    int MM1, MM2, MMP, MMC;
    int MGEMS = 10;
    int MPOINTS = 50;

    do {
        score = 0;
        while (player.Health > 0) {
            MM1 = rand() % 50 + 51;
            MM2 = rand() % 50 + 51;
            MMC = MM1 * MM2;

            cout << MM1 << " X " << MM2 << " = ";
            while (true) {
                cin >> MMP;
                if (cin.fail()) {
                    cout << "Invalid input. Please enter a valid integer answer." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << MM1 << " X " << MM2 << " = ";
                } else {
                    break;
                }
            }
            if (MMP == MMC) {
                score += MPOINTS;
                gems += MGEMS;
            } else {
                cout << "Incorrect. The correct answer is " << MMC << "." << endl;
                player.Health--;
                cout << "You lost 1 Life. Your health remaining is: " << player.Health << endl;

                if (player.Health <= 0) {
                    cout << "Game over! You're out of lives." << endl;
                }
            }
        }
        cout << "Final Score: " << score << " | Total Gems: " << gems << endl;
        cout <<"Play again?(y/n): "<< endl;
        cin >> PlayAgain;
        while (PlayAgain != "y" && PlayAgain != "Y" && PlayAgain != "n" && PlayAgain != "N") {
            cout << "Invalid input. Please enter 'y' to play again or 'n' to exit: ";
            cin >> PlayAgain;
            cout << endl;
        }
    } while (PlayAgain == "y" || PlayAgain == "Y");
    cout <<"Returning to Main Menu..."<< endl;
}

void DivisionMaster(int& score, int& health, int& gems){
    int DM1, DM2, DMP, DMC;
    int MGEMS = 10;
    int MPOINTS = 50;
    
    do {
        score = 0;
        while (health > 0){
            do{
                DM1 = rand() % 50 + 51; // range 51 - 100
                DM2 = rand() % 100 + 1; //range 1 - 100
            } while (DM1 % DM2 != 0);
            DMC = DM1 / DM2;
            
            cout << DM1 <<" / "<< DM2 <<" = ";
            while (true) {
                cin >> DMP;
                if (cin.fail()) {
                    cout << "Invalid input. Please enter a valid integer answer." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << DM1 << " X " << DM2 << " = ";
                } else {
                    break;
                }
            }
            if (DMP == DMC) {
                score += MPOINTS;
                gems += MGEMS;
            } else {
                cout <<"Incorrect. The correct answer is "<< DMC <<"."<< endl;
                player.Health--;
                cout <<"You lost 1 life. Your health remaining is: "<< player.Health << endl;
                
                if (player.Health <= 0) {
                    cout <<"Game over! You're out of lives." << endl;
                }
            }
        }
        cout <<"Final Score: " << score << " | Total Gems: " << gems << endl;
        cout <<"Play again?(y/n): "<< endl;
        cin >> PlayAgain;
        while (PlayAgain != "y" && PlayAgain != "Y" && PlayAgain != "n" && PlayAgain != "N") {
            cout << "Invalid input. Please enter 'y' to play again or 'n' to exit: ";
            cin >> PlayAgain;
            cout << endl;
        }
    } while (PlayAgain == "y" || PlayAgain == "Y");
    cout <<"Returning to Main Menu..."<< endl;
}

void MixMaster(int& score, int& health, int& gems) {
    int s, MIXMP, MIXMC;
    int BGEMS = 10;
    int BPOINTS = 50;
    
    do {
        score = 0;
        while (player.Health > 0) {
            do {
                s = rand() % 4 + 1;
                if (s == 1) {
                    int AM1, AM2;
                    AM1 = rand() % 10 + 11;
                    AM2 = rand() % 10 + 11;
                    MIXMC = AM1 + AM2;
                    
                    cout << AM1 << " + " << AM2 << " = ";
                    while (true) {
                        cin >> MIXMP;
                        if (cin.fail()) {
                            cout << "Invalid input. Please enter a valid integer answer." << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << AM1 << " + " << AM2 << " = ";
                        } else {
                            break;
                        }
                    }
                    if (MIXMP == MIXMC) {
                        score += BPOINTS;
                        gems += BGEMS;
                    } else {
                        cout << "Incorrect. The correct answer is " << MIXMC << "." << endl;
                        player.Health--;
                        cout << "You lost 1 life. Your health remaining is: " << health << endl;
                    }
                } else if (s == 2) {
                    int SM1, SM2;
                    do {
                        SM1 = rand() % 10 + 11;
                        SM2 = rand() % 10 + 11;
                        MIXMC = SM1 - SM2;
                    } while (MIXMC < 0);
                    cout << SM1 << " - " << SM2 << " = ";
                    while (true) {
                        cin >> MIXMP;
                        if (cin.fail()) {
                            cout << "Invalid input. Please enter a valid integer answer." << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << SM1 << " - " << SM2 << " = ";
                        } else {
                            break;
                        }
                    }
                    if (MIXMP == MIXMC) {
                        score += BPOINTS;
                        gems += BGEMS;
                    } else {
                        cout << "Incorrect. The correct answer is " << MIXMC << "." << endl;
                        player.Health--;
                        cout << "You lost 1 life. Your health remaining is: " << health << endl;
                    }
                } else if (s == 3){
                    int MM1, MM2;
                    MM1 = rand() % 10 + 11;
                    MM2 = rand() % 10 + 11;
                    MIXMC = MM1 * MM2;
                    
                    cout << MM1 << " X " << MM2 << " = ";
                    while (true) {
                        cin >> MIXMP;
                        if (cin.fail()) {
                            cout << "Invalid input. Please enter a valid integer answer." << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << MM1 << " X " << MM2 << " = ";
                        } else {
                            break;
                        }
                    }
                    if (MIXMP == MIXMC) {
                        score += BPOINTS;
                        gems += BGEMS;
                    } else {
                        cout << "Incorrect. The correct answer is " << MIXMC << "." << endl;
                        player.Health--;
                        cout << "You lost 1 life. Your health remaining is: " << health << endl;
                    }
                } else if (s == 4){
                    int DM1, DM2;
                    do {
                        DM1 = rand() % 10 + 11;
                        DM2 = rand() % 20 + 1;
                    } while (DM1 % DM2 !=0);
                    MIXMC = DM1/DM2;
                    
                    cout << DM1 << " / " << DM2 << " = ";
                    while (true) {
                        cin >> MIXMP;
                        if (cin.fail()) {
                            cout << "Invalid input. Please enter a valid integer answer." << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << DM1 << " / " << DM2 << " = ";
                        } else {
                            break;
                        }
                    }
                    if (MIXMP == MIXMC) {
                        score += BPOINTS;
                        gems += BGEMS;
                    } else {
                        cout << "Incorrect. The correct answer is " << MIXMC << "." << endl;
                        player.Health--;
                        cout << "You lost 1 life. Your health remaining is: " << player.Health << endl;
                    }
                }
                if (player.Health <= 0) {
                    cout <<"Game over! You're out of lives." <<endl;
                }
            } while (player.Health > 0);
            cout <<"Final Score: " << score << " | Total Gems: " << gems << endl;
            cout <<"Play again?(y/n): "<< endl;
            cin >> PlayAgain;
            while (PlayAgain != "y" && PlayAgain != "Y" && PlayAgain != "n" && PlayAgain != "N") {
                cout << "Invalid input. Please enter 'y' to play again or 'n' to exit: ";
                cin >> PlayAgain;
                cout << endl;
            }
        }
    } while (PlayAgain == "y" || PlayAgain == "Y");
    cout <<"Returning to Main Menu..."<< endl;
}

int main() {
    string x;
    int a, b, c;
    int health = 3;
    srand(time(0));
    cout << "\n-- Math Quiz --" << endl;
    
    cout << "Press any key to continue" << endl;
    cin.get();
        
    do {
    a = mainmenu();
        switch (a) {
            case 1:
                b = gamemode();
                c = difficulty();
                if (b == 1) {
                    if (c == 1) {
                        AdditionBeginner(score, player.Health, gems);
                    }
                    else if (c == 2) {
                        AdditionIntermediate(score, player.Health, gems);
                    }
                    else if (c == 3) {
                        AdditionAdvance(score, player.Health, gems);
                    }
                    else if (c == 4) {
                        AdditionMaster(score, player.Health ,gems);
                    }
                } else if (b == 2) {
                    if (c == 1) {
                        SubstractionBeginner(score, player.Health, gems);
                    }
                    else if (c == 2) {
                        SubstractionIntermediate(score, player.Health, gems);
                    }
                    else if (c == 3) {
                        SubstractionAdvanced(score, player.Health, gems);
                    }
                    else if (c == 4) {
                        SubstractionMaster(score, player.Health, gems);
                    }
                    
                } else if (b == 3) {
                    if (c == 1) {
                        MultiplicationBeginner(score, player.Health, gems);
                    }
                    else if (c == 2) {
                        MultiplicationIntermediate(score, player.Health, gems);
                    }
                    else if (c == 3) {
                        MultiplicationAdvance(score, player.Health, gems);
                    }
                    else if (c == 4) {
                        MultiplicationMaster(score, player.Health, gems);
                    }
                } else if (b == 4) {
                    if (c == 1) {
                        DivisionBeginner(score, player.Health, gems);
                    }
                    else if (c == 2) {
                        DivisionIntermediate(score, player.Health, gems);
                    }
                    else if (c == 3) {
                        DivisionAdvanced(score, player.Health, gems);
                    }
                    else if (c == 4) {
                        DivisionMaster(score, player.Health, gems);
                    }
                } else if (b == 5) {
                    if (c == 1) {
                        MixBeginner(score, player.Health, gems);
                    }
                    else if (c == 2) {
                        MixIntermediate(score, player.Health, gems);
                    }
                    else if (c == 3) {
                        MixAdvanced(score, player.Health, gems);
                    }
                    else if (c == 4) {
                        MixMaster(score, player.Health, gems);
                    }
                }
                break;
            case 2:
                Store(player.Health, gems);
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                About();
                break;
            case 6:
                Help();
                break;
        }

} while (a != 7);

    return 0;
}

