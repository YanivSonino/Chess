#pragma once

#include "Piece.h"
#include "Factory.h"

/**
 * Pawn Class
 */
class Pawn : public Piece{
public:
    Pawn(const enum PLAYER &, const Location &);
    bool validateMovement(const Location&, std::vector<std::vector<std::unique_ptr<Piece>>>&) override;
    char getPiece()const override;
private:
    static bool m_registerIt_player_1;
    static bool m_registerIt_player_2;
};

