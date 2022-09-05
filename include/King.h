//
// Created by USER on 21/04/2022.
//

#include "Piece.h"
#include "Factory.h"
/**
 * King Class
 */
class King : public Piece{
public:
    King(const enum PLAYER&, const Location &);
    char getPiece()const override;
    bool validateMovement(const Location&, std::vector<std::vector<std::unique_ptr<Piece>>>&) override;

private:
    static bool m_registerIt_player_1;
    static bool m_registerIt_player_2;

};


