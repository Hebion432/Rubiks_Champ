//
// Created by Amit Kumar on 09/03/2025
//

#ifndef RUBIKS_CUBE_SOLVER_RUBIKSCUBE_H
#define RUBIKS_CUBE_SOLVER_RUBIKSCUBE_H

#include "bits/stdc++.h"
using namespace std;

/**
 * A base class for all Rubik's Cube Model.
 */

class RubiksCube {
public:
    enum class FACE {
        UP,
        LEFT,
        FRONT,
        RIGHT,
        BACK,
        DOWN
    };

    enum class COLOR {
        WHITE,
        GREEN,
        RED,
        BLUE,
        ORANGE,
        YELLOW
    };

    enum class MOVE {    // because the RB 20 move law is based on these 18 moves  ****
        L, LPRIME, L2,
        R, RPRIME, R2,
        U, UPRIME, U2,
        D, DPRIME, D2,
        F, FPRIME, F2,
        B, BPRIME, B2
    };

    /*
     * Returns the color of the cell at (row, col) in face.
     */
    virtual COLOR getColor(FACE face, unsigned row, unsigned col) const = 0;

    /*
     * Returns the first letter of the given COLOR
     */
    static char getColorLetter(COLOR color);

    /*
     * Returns true if the Rubik Cube is solved, otherwise returns false.
     */
    virtual bool isSolved() const = 0;

    /*
     * Returns the move in the string format.
     */
    static string getMove(MOVE ind);

    /*
     * Print the Rubik Cube in Planar format.
    */
    void print() const;
};


#endif //RUBIKS_CUBE_SOLVER_RUBIKSCUBE_H