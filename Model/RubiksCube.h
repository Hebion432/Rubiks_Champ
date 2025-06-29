//
// Created by Amit Kumar 18/03/2025
//

#ifndef RUBIKSCUBE_H
#define RUBIKSCUBE_H

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

/**
 * A base class for all Rubik's Cube Model.
 */


class RubiksCube
{
public:
    enum class FACE
    {
        UP,
        LEFT,
        FRONT,
        RIGHT,
        BACK,
        DOWN
    };
     enum class COLOR
    {
        WHITE,
        GREEN,
        RED,
        BLUE,
        ORANGE,
        YELLOW
    };
    enum class MOVE
    {
        U,
        U2,
        UPRIME,
        L,
        L2,
        LPRIME,
        F,
        F2,
        FPRIME,
        R,
        R2,
        RPRIME,
        B,
        B2,
        BPRIME,
        D,
        D2,
        DPRIME
    };
    //1.unsigned is used here because row and col must be positive
	// virtual will make the class abstract( object can be make if it has implementation ) but const == 0 will make it purely abstract ( no object can be made )
    //2.const is used here because the function should not by any circumstance modify the object it is called upon

    //these can be implemented in abstract class only because it is independent from models



    virtual COLOR getColor(FACE face, unsigned row, unsigned col) const = 0;

	/*
     * Returns the first letter of the given COLOR
     * Eg: For COLOR::GREEN, it returns 'G'
     */
    static char getColorLetter(COLOR color);


    //To see if the cube is solved or not
    virtual bool isSolved()const=0;


    // return the move in the string format ( f -> "f")
    static string getMoveLetter(MOVE ind);

    /*
     * Print the Rubik Cube in Planar format.
     *
     * The cube is laid out as follows.
     *
     * The sides:
     *    U
     *  L F R B
     *    D
     *
     * Color wise:
     *
     *          W W W
     *          W W W
     *          W W W
     *
     *  G G G   R R R   B B B   O O O
     *  G G G   R R R   B B B   O O O
     *  G G G   R R R   B B B   O O O
     *
     *          Y Y Y
     *          Y Y Y
     *          Y Y Y
     *
     * Row and Column Numberings:
     * rx -> row numbering
     * cx -> column numbering
     * bx -> both row and column numbering
     *
     *             b0 c1 c2
     *             r1  .  .
     *             r2  .  .
     *
     *  b0 c1 c2   b0 c1 c2   b0 c1 c2   b0 c1 c2
     *  r1  .  .   r1  .  .   r1  .  .   r1  .  .
     *  r2  .  .   r2  .  .   r2  .  .   r2  .  .
     *
     *             b0 c1 c2
     *             r1  .  .
     *             r2  .  .
     *
     */
    void print() const;


    //to implement moves
    RubiksCube &move(MOVE ind);

    //to invert the implemented moves
    RubiksCube &invert(MOVE ind);


    //to randomly shuffle the cube with time and give the moves performed
    vector<MOVE> randomShuffle(unsigned int times);


	/*
     * 18 fundamental moves
	 *  F2 == F'2 ( that's why those moves are not considered )
     *
     * F, F’, F2,
     * U, U’, U2,
     * L, L’, L2,
     * D, D’, D2,
     * R, R’, R2,
     * B, B’, B2
     */

    virtual RubiksCube &u() = 0;      // Up clockwise
    virtual RubiksCube &uPrime() = 0; // Up counterclockwise
    virtual RubiksCube &u2() = 0;     // Up 180 degrees

    virtual RubiksCube &d() = 0;      // Down clockwise
    virtual RubiksCube &dPrime() = 0; // Down counterclockwise
    virtual RubiksCube &d2() = 0;     // Down 180 degrees

    virtual RubiksCube &l() = 0;      // Left clockwise
    virtual RubiksCube &lPrime() = 0; // Left counterclockwise
    virtual RubiksCube &l2() = 0;     // Left 180 degrees

    virtual RubiksCube &r() = 0;      // Right clockwise
    virtual RubiksCube &rPrime() = 0; // Right counterclockwise
    virtual RubiksCube &r2() = 0;     // Right 180 degrees

    virtual RubiksCube &f() = 0;      // Front clockwise
    virtual RubiksCube &fPrime() = 0; // Front counterclockwise
    virtual RubiksCube &f2() = 0;     // Front 180 degrees

    virtual RubiksCube &b() = 0;      // Back clockwise
    virtual RubiksCube &bPrime() = 0; // Back counterclockwise
    virtual RubiksCube &b2() = 0;     // Back 180 degrees




    string getCornerColorString(uint8_t ind) const;

    uint8_t getCornerIndex(uint8_t ind) const;

    uint8_t getCornerOrientation(uint8_t ind) const;
};
#endif// RUBIKSCUBE_H