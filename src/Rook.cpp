//
// Created by USER on 19/04/2022.
//

#include "Rook.h"

bool Rook::m_registerIt_player_1 = Factory<Piece>::registerObject('R', [](const Location& pos) -> std::unique_ptr<Piece>{
    return std::make_unique<Rook>(t_1, pos);
});
bool Rook::m_registerIt_player_2 = Factory<Piece>::registerObject('r', [](const Location& pos) -> std::unique_ptr<Piece>{
    return std::make_unique<Rook>(t_2, pos);
});

/**
 * Constructor
 * @param type : Player one or Player two
 * @param pos : Piece positon
 */
Rook::Rook(const enum PLAYER&type, const Location &pos) : Piece(type, pos) {

}

bool Rook::validateMovement(const Location & dest, std::vector<std::vector<std::unique_ptr<Piece>>>& pieces) {
    Location steps = getPosition() - dest;
    bool check_row = false;
    int factor = 1;
    if(steps.row != 0 && steps.col!= 0)
        return false;
    if (steps.col == 0) {
        if (steps.row > 0)
            factor = -1;
        check_row = true;
    }
    if (steps.col > 0)
        factor = -1;
    
    for(int k = 1; k < max(steps.row,steps.col);k++) {
        //checks if player step inside the steps the piece is attended to do.

        if (check_row) {
            if (pieces[getPosition().row + (k*factor)][getPosition().col])
                return false;
        } else {
            if (pieces[getPosition().row][getPosition().col + (k * factor)])
                return false;
        }
    }
    return true;
}

int Rook::max(int &num1, int &num2) {
    if(num1 < 0)
        num1 *=-1;
    if(num2 < 0)
        num2*=-1;
    if(num1>num2)
        return num1;
    return num2;
}

char Rook::getPiece() const {
    return (getType() == t_1 ? 'R': 'r');
}
