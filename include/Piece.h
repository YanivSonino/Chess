#pragma once

#include <vector>
#include <memory>
#include "macros.h"
/**
 * Piece abstract Class
 */
class Piece {
public:
    Piece(const enum PLAYER&,const Location&);
    virtual ~Piece() = default;
    virtual bool validateMovement(const Location&, std::vector<std::vector<std::unique_ptr<Piece>>>&) = 0;
    Location getPosition() const;
    virtual char getPiece()const=0;
    enum PLAYER getType()const{return m_type;};
    void setPosition(const Location&);


private:
    Location m_pos;
    enum PLAYER m_type;
};



