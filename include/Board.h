#pragma once
#include "Piece.h"
#include "Factory.h"

class Board{
public:
    Board(const std::string &);
    int getResponse(const std::string &);


private:
    Location m_king_1_pos;
    Location m_king_2_pos;
    enum PLAYER m_turn;
    bool iGotChecked(const Location&);
    bool iDidCheck(const Location&);
    void changeTurn();
    void createInitialPieces(const std::string &);
    std::vector<std::vector<std::unique_ptr<Piece>>> m_pieces;
};

