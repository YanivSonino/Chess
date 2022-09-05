//
// Created by USER on 21/04/2022.
//
#pragma once
#include "Rook.h"
#include "Bishop.h"

/**
 * Queen Class
 */
class Queen : public Rook, public Bishop {
public:
    Queen(const enum PLAYER &, const Location &);
    bool validateMovement(const Location&, std::vector<std::vector<std::unique_ptr<Piece>>>&) override;
    char getPiece()const override;
private:
    static bool m_registerIt_player_1;
    static bool m_registerIt_player_2;
};

