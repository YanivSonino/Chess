    //
// Created by USER on 19/04/2022.
//

#include "Piece.h"

Piece::Piece(const enum PLAYER&type, const Location &pos): m_type(type),m_pos(pos){}

Location Piece::getPosition() const {
    return m_pos;
}

void Piece::setPosition(const Location & pos) {
    m_pos = pos;
}


