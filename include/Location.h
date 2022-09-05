//
// Created by USER on 28/03/2022.
//

#pragma once
#include <iostream>

struct Location{
     int row;
     int col;

    // operator =
     Location& operator=(const Location& pos)= default;
    // operator +
     Location operator+(const Location&pos){
        row = row + pos.row;
        col = col + pos.col;
        return *this;
    }
    Location operator-(const Location&pos){
        row = row - pos.row;
        col = col - pos.col;
        return *this;
    }
};

// operator +=
inline Location &operator+=(Location& calculatedPos,const Location& pos){
    calculatedPos = calculatedPos + pos;
    return calculatedPos;
}
// operator ==
inline bool operator==(Location & first_pos,const Location & second_pos) {
    return (first_pos.row == second_pos.row && first_pos.col == second_pos.col);
}

// operator !=
inline bool operator!=(Location & first_pos,const Location & second_pos){
    return !(first_pos == second_pos);
}

inline std::ostream& operator<<(std::ostream& os, const Location& pos)
{
    os << "(" << pos.row << ", " << pos.col << ")";
    return os;
}
// operator >
inline bool operator >(Location &pos1,const Location &pos2){
    if(pos1.row > pos2.row)
        return true;
    if(pos1.row == pos2.row){
            return pos1.col > pos2.col;
    }
    return false;
}
// operator <
inline bool operator <(Location &pos1,const Location &pos2){
    return (!(pos1 > pos2) && pos1 !=pos2);
}