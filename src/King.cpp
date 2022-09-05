//
// Created by USER on 21/04/2022.
//

#include "King.h"
bool King::m_registerIt_player_1 = Factory<Piece>::registerObject('K', [](const Location& pos) -> std::unique_ptr<Piece>{
    return std::make_unique<King>(t_1, pos);
});
bool King::m_registerIt_player_2 = Factory<Piece>::registerObject('k', [](const Location& pos) -> std::unique_ptr<Piece>{
    return std::make_unique<King>(t_2, pos);
});

/**
 * Constructor
 * @param type : Player one or Player two
 * @param pos : Piece positon
 */
King::King(const enum PLAYER&type, const Location &pos) : Piece(type, pos) {}

bool King::validateMovement(const Location & dest, std::vector<std::vector<std::unique_ptr<Piece>>>& pieces) {
    Location steps = getPosition() - dest;
    int factor = 1;
    if((steps.row > 1 || steps.col > 1) || (steps.row < -1 || steps.col < -1))
        return false;

    return true;
}

char King::getPiece() const {
    return (getType()== t_1 ? 'K': 'k');
}
