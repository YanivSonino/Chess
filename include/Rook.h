#pragma once

#include "Piece.h"
#include "Factory.h"

/**
 * Rook Class
 */
class Rook : virtual public Piece{
public:
    Rook(const enum PLAYER &, const Location &);
    bool validateMovement(const Location&, std::vector<std::vector<std::unique_ptr<Piece>>>&) override;
    char getPiece()const override;
private:
    int max(int&,int&);
    static bool m_registerIt_player_1;
    static bool m_registerIt_player_2;
};
