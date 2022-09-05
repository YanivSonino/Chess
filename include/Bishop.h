//
// Created by USER on 21/04/2022.
//
#pragma once
#include "Piece.h"
#include "Factory.h"

/**
 * Bishop Class
 */
class Bishop :virtual public Piece{
public:
    Bishop(const enum PLAYER&, const Location &);
    bool validateMovement(const Location&, std::vector<std::vector<std::unique_ptr<Piece>>>&) override;
    char getPiece()const override;

private:
    static bool m_registerIt_player_1;
    static bool m_registerIt_player_2;
};


