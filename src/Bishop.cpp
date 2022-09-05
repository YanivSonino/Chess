//
// Created by USER on 21/04/2022.
//

#include "Bishop.h"

bool Bishop::m_registerIt_player_1 = Factory<Piece>::registerObject('B', [](const Location& pos) -> std::unique_ptr<Piece>{
    return std::make_unique<Bishop>(t_1, pos);
});
bool Bishop::m_registerIt_player_2 = Factory<Piece>::registerObject('b', [](const Location& pos) -> std::unique_ptr<Piece>{
    return std::make_unique<Bishop>(t_2, pos);
});

Bishop::Bishop(const PLAYER & type, const Location &pos) : Piece(type, pos){}

bool Bishop::validateMovement(const Location &dest, std::vector<std::vector<std::unique_ptr<Piece>>> &pieces) {
    Location steps = getPosition() - dest;
    int factor_x = 1, factor_y = 1, range;

    if(steps.row != steps.col && steps.row * -1 != steps.col  )
        return false;
    if (steps.row > 0)
        factor_y = -1;
    if (steps.col > 0)
        factor_x = -1;
    range = steps.row > 0 ? steps.row : steps.row * -1;
    
    for(int k = 1; k < range;k++) {
        //checks if player step inside the steps the piece is attended to do.
            if (pieces[getPosition().row + (k*factor_y)][getPosition().col + (k*factor_x)])
                return false;
    }
    return true;
}

char Bishop::getPiece() const {
    return (getType() == t_1 ? 'R': 'r');
}

