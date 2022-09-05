#include "Board.h"

Board::Board(const std::string &board): m_turn(t_1){
    createInitialPieces(board);
}

void Board::createInitialPieces(const std::string &board) {
    std::vector<std::unique_ptr<Piece>> temp_pieces;
    int string_index = 0;
    for(int i = 0; i < BORDERS.row; i++){
        for(int j = 0; j < BORDERS.col; j++){
            if(board[string_index]!='#')
                temp_pieces.emplace_back(Factory<Piece>::create(board[string_index],Location({i,j})));
            else
                temp_pieces.emplace_back(nullptr);
            if(board[string_index]=='K')
                m_king_1_pos = {i,j};
            if (board[string_index]=='k')
                m_king_2_pos = {i,j};
            string_index++;
        }
        m_pieces.emplace_back(std::move(temp_pieces));
    }
}

int Board::getResponse(const std::string &res) {

    Location src = {res[0] - 'a',res[1] - '0'-1};
    Location dest = {res[2] - 'a',res[3] - '0'-1};
    if(!m_pieces[src.row][src.col])
        return 11;
    else if(m_pieces[src.row][src.col]->getType() != m_turn)
        return 12;
    else if(m_pieces[dest.row][dest.col] && m_pieces[dest.row][dest.col]->getType() == m_turn)
        return 13;
    else if (!m_pieces[src.row][src.col]->validateMovement(dest,m_pieces))
        return 21;

    if (m_pieces[src.row][src.col]->getPiece() == King)
        m_king_1_pos = { dest.row,dest.col };
    if (m_pieces[src.row][src.col]->getPiece() == king)
        m_king_2_pos = { dest.row,dest.col };
    m_pieces[dest.row][dest.col] = std::move(m_pieces[src.row][src.col]);
    m_pieces[dest.row][dest.col]->setPosition({dest.row,dest.col});


    //if i got checked after my move.
    if(m_turn == t_1) {
        
        if (iGotChecked(m_king_1_pos)) {
            m_pieces[src.row][src.col] = std::move(m_pieces[dest.row][dest.col]);
            m_pieces[src.row][src.col]->setPosition({src.row,src.col});
            if(m_pieces[src.row][src.col]->getPiece() == 'K')
                m_king_1_pos = {src.row,src.col};
            return 31;
        }
        if(iDidCheck(m_king_2_pos)) {
            changeTurn();
            return 41;
        }
    }else {
        
        if (iGotChecked(m_king_2_pos)) {
            m_pieces[src.row][src.col] = std::move(m_pieces[dest.row][dest.col]);
            m_pieces[src.row][src.col]->setPosition({src.row,src.col});
            if(m_pieces[src.row][src.col]->getPiece() == king)
                m_king_2_pos = {src.row,src.col};
            return 31;
        }
        if(iDidCheck(m_king_1_pos)) {
            changeTurn();
            return 41;
        }
    }

    changeTurn();
    return 42;
}

bool Board::iGotChecked(const Location &king_location) const {
    for (int i = 0; i < BORDERS.row; i++) {
        for (int j = 0; j < BORDERS.col; j++) {
            if (m_pieces[i][j] && m_pieces[i][j]->getType() != m_turn) {
                if (m_pieces[i][j]->validateMovement(king_location, m_pieces)) {
                    return true;
                }
            }
        }
    }
    return false;
}

bool Board::iDidCheck(const Location& king_location) const {
    for (int i = 0; i < BORDERS.row; i++) {
        for (int j = 0; j < BORDERS.col; j++) {
            if (m_pieces[i][j] && m_pieces[i][j]->getType() == m_turn) {
                if (m_pieces[i][j]->validateMovement(king_location, m_pieces)) {
                    return true;
                }
            }
        }
    }
    return false;
}

void Board::changeTurn() {
    switch (m_turn) {
        case t_1:
            m_turn = t_2;
            return;
        case t_2:
            m_turn = t_1;
            return;
    }
}



