//
// Created by USER on 21/04/2022.
//

#include "Pawn.h"

bool Pawn::m_registerIt_player_1 = Factory<Piece>::registerObject('P', [](const Location& pos) -> std::unique_ptr<Piece>{
    return std::make_unique<Pawn>(t_1, pos);
});
bool Pawn::m_registerIt_player_2 = Factory<Piece>::registerObject('p', [](const Location& pos) -> std::unique_ptr<Piece>{
    return std::make_unique<Pawn>(t_2, pos);
});

Pawn::Pawn(const PLAYER &type, const Location &pos) : Piece(type, pos){}

bool Pawn::validateMovement(const Location &dest, std::vector<std::vector<std::unique_ptr<Piece>>> &pieces) {
    Location steps = getPosition() - dest;
    int factor = 1,start_row=6;
    if(getType() == t_1) {
        factor *= -1;
        start_row=1;
    }
    if(getPosition().row == start_row && steps == Location{2 * factor,0})
        return true;
    if (steps.row != factor*1)
        return false;
    if (steps.col == -1 || steps.col == 1) {
        if (!pieces[getPosition().row - (steps.row * factor)][getPosition().col - steps.col])
            return false;
    }
    if(pieces[getPosition().row - (steps.row * factor)][getPosition().col])
        return false;

    return true;
}

char Pawn::getPiece() const {
    return (getType() == t_1 ? 'P': 'p');
}
