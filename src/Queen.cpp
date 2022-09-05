//
// Created by USER on 21/04/2022.
//

#include "Queen.h"
bool Queen::m_registerIt_player_1 = Factory<Piece>::registerObject('Q', [](const Location& pos) -> std::unique_ptr<Piece>{
    return std::make_unique<Queen>(t_1, pos);
});
bool Queen::m_registerIt_player_2 = Factory<Piece>::registerObject('q', [](const Location& pos) -> std::unique_ptr<Piece>{
    return std::make_unique<Queen>(t_2, pos);
});

Queen::Queen(const PLAYER & type, const Location &pos) : Piece(type,pos),Rook(type,pos),Bishop(type,pos){}

bool Queen::validateMovement(const Location &dest, std::vector<std::vector<std::unique_ptr<Piece>>> &pieces) {
    return Bishop::validateMovement(dest,pieces) || Rook::validateMovement(dest,pieces);
}

char Queen::getPiece() const {
    return (getType() == t_1 ? 'Q': 'q');
}

