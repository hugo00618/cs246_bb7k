#include "Block.h"
#include "Player.h"

Block::Block(string name, int number): name(name), number(number) {
    
}

void Block::repeat(string s, int times) {
    for (int i = 0; i < times; i++) {
        cout << s;
    }
}

void Block::bar7() {
    cout << "|";
    repeat("_", 7);
}

void Block::bar14() {
    cout << "|";
    repeat(" ", 14);
}

void Block::bar71() {
    cout << "|";
    repeat(" ", 71);
}

void Block::bar7bar14() {
    bar7();
    bar14();
}

void Block::bar7bar71() {
    bar7();
    bar71();
}

void Block::print(int lineNum, int leftMargin, int topMargin) {
    if (number >= 10 && number <= 20) {
        cout << setw(leftMargin+1) << "";
    }
    
    switch (lineNum) {
        case 1:
            if (number == 17) {
                bar7bar71();
            } else if (number == 20) {
                repeat("_", 9);
            } else if (number == 0 || number == 10 || number == 33 || number == 35 || number == 36 || number == 38) {
                bar7();
            } else {
                repeat("_", 8);
            }
            
            break;
        case 2:
            cout << "|";
            switch (number) {
                case 0:
                    cout << setw(7) << left << "COLLECT";
                    break;
                case 7:
                    cout << setw(7) << left << "NEEDLES";
                    break;
                case 10:
                    cout << setw(7) << left << "DC Tims";
                    break;
                case 20:
                    cout << setw(7) << left << "Goose";
                    break;
                case 22:
                    cout << setw(7) << left << "NEEDLES";
                    break;
                case 30:
                    cout << setw(7) << left << "GO TO";
                    break;
                case 36:
                    cout << setw(7) << left << "NEEDLES";
                    break;
                case 38:
                    cout << setw(7) << left << "COOP";
                    break;
                default:
                    cout << setw(7) << left << name;
                    if (number == 17) {
                        bar71();
                    }
                    break;
            }
            break;
        case 3:
            cout << "|";
            switch (number) {
                case 20:
                    cout << setw(7) << left << "Nesting";
                    break;
                case 22:
                    cout << setw(7) << left << "HALL";
                    break;
                case 30:
                    cout << setw(7) << left << "TIMS";
                    break;
                case 36:
                    cout << setw(7) << left << "HALL";
                    break;
                case 38:
                    cout << setw(7) << left << "FEE";
                    break;
                case 10:
                    cout << setw(7) << left << "Line";
                    break;
                case 7:
                    cout << setw(7) << left << "HALL";
                    break;
                case 0:
                    cout << setw(7) << left << "OSAP";
                    break;
                default:
                    cout << setw(7) << "";
                    if (number == 17) {
                        bar71();
                    }
                    break;
            }
            break;
        case 4:
            cout << setw(8) << left << "|";
            if (number == 17) {
                bar71();
            }
            break;
        case 5:
            string s = "";
            for (vector<Player*>::iterator it = landers.begin(); it != landers.end(); it++) {
                s.append(string(1, (*it)->getPiece()));
            }
            cout << "|" << setw(7) << left << s;
            if (number == 17) {
                bar71();
            }
            break;
    }
    
    if ((number == 30 && lineNum != 1) || (number > 30 && number <= 39) || number == 0) {
        cout << "|";
    }
}

void Block::addLander(Player *p) {
    landers.push_back(p);
}

void Block::removeLander(Player *p) {
    for (vector<Player*>::iterator it = landers.begin(); it != landers.end(); it++) {
        if ((*it)->getPiece() == p->getPiece()) {
            landers.erase(it);
            break;
        }
    }
}
