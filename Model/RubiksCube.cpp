//
// Created by Amit Kumar 18/03/2025
//

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;
#include "RubiksCube.h"


// Given the color return it's first letter
char RubiksCube::getColorLetter(COLOR color)
{
    switch (color)
    {
        case COLOR::WHITE:
            return 'W';
        case COLOR::GREEN:
            return 'G';
        case COLOR::RED:
            return 'R';
        case COLOR::BLUE:
            return 'B';
        case COLOR::ORANGE:
            return 'O';
        case COLOR::YELLOW:
            return 'Y';
        default:
            return '?';
    }
}




// takes a MOVE enum value and returns its corresponding string representation

string RubiksCube::getMoveLetter(MOVE ind)
{
    switch (ind)
    {
        case MOVE::F: // Front face clockwise
            return "F";
        case MOVE::FPRIME: // Front face counterclockwise
            return "F'";
        case MOVE::F2: // Front face 180 degrees
            return "F2";
        case MOVE::U: // Up face clockwise
            return "U";
        case MOVE::UPRIME: // Up face counterclockwise
            return "U'";
        case MOVE::U2: // Up face 180 degrees
            return "U2";
        case MOVE::D: // Down face clockwise
            return "D";
        case MOVE::DPRIME: // Down face counterclockwise
            return "D'";
        case MOVE::D2: // Down face 180 degrees
            return "D2";
        case MOVE::R: // Right face clockwise
            return "R";
        case MOVE::RPRIME: // Right face counterclockwise
            return "R'";
        case MOVE::R2: // Right face 180 degrees
            return "R2";
        case MOVE::L: // Left face clockwise
            return "L";
        case MOVE::LPRIME: // Left face counterclockwise
            return "L'";
        case MOVE::L2: // Left face 180 degrees
            return "L2";
        case MOVE::B: // Back face clockwise
            return "B";
        case MOVE::BPRIME: // Back face counterclockwise
            return "B'";
        case MOVE::B2: // Back face 180 degrees
            return "B2";
        default:
            return "?";
    }
}

/*
 * Perform a move operation on using a Move index.
 */
RubiksCube &RubiksCube::move(MOVE ind) {
    switch (ind) {
        case MOVE::L:
            return this->l();
        case MOVE::LPRIME:
            return this->lPrime();
        case MOVE::L2:
            return this->l2();
        case MOVE::R:
            return this->r();
        case MOVE::RPRIME:
            return this->rPrime();
        case MOVE::R2:
            return this->r2();
        case MOVE::U:
            return this->u();
        case MOVE::UPRIME:
            return this->uPrime();
        case MOVE::U2:
            return this->u2();
        case MOVE::D:
            return this->d();
        case MOVE::DPRIME:
            return this->dPrime();
        case MOVE::D2:
            return this->d2();
        case MOVE::F:
            return this->f();
        case MOVE::FPRIME:
            return this->fPrime();
        case MOVE::F2:
            return this->f2();
        case MOVE::B:
            return this->b();
        case MOVE::BPRIME:
            return this->bPrime();
        case MOVE::B2:
            return this->b2();
    }
}


/*
 * here we will invert a move.
 */
RubiksCube &RubiksCube::invert(MOVE ind) {
    switch (ind) {
        case MOVE::L:
            return this->lPrime();
        case MOVE::LPRIME:
            return this->l();
        case MOVE::L2:
            return this->l2();
        case MOVE::R:
            return this->rPrime();
        case MOVE::RPRIME:
            return this->r();
        case MOVE::R2:
            return this->r2();
        case MOVE::U:
            return this->uPrime();
        case MOVE::UPRIME:
            return this->u();
        case MOVE::U2:
            return this->u2();
        case MOVE::D:
            return this->dPrime();
        case MOVE::DPRIME:
            return this->d();
        case MOVE::D2:
            return this->d2();
        case MOVE::F:
            return this->fPrime();
        case MOVE::FPRIME:
            return this->f();
        case MOVE::F2:
            return this->f2();
        case MOVE::B:
            return this->bPrime();
        case MOVE::BPRIME:
            return this->b();
        case MOVE::B2:
            return this->b2();
    }
}



// so what we are doing is we are simply printing here only, but we will define the getColor in derived classes to get the cube cell color of that cube
void RubiksCube::print() const {
    cout << "Rubik's Cube:\n\n";

    for (int row = 0; row <= 2; row++) {
        for (unsigned i = 0; i < 7; i++) cout << " ";
        for (int col = 0; col <= 2; col++) {
            cout << getColorLetter(getColor(FACE::UP, row, col)) << " ";
        }
        cout << "\n";
    }

    cout << "\n";

    for (int row = 0; row <= 2; row++) {

        for (int col = 0; col <= 2; col++) {
            cout << getColorLetter(getColor(FACE::LEFT, row, col)) << " ";
        }
        cout << " ";

        for (int col = 0; col <= 2; col++) {
            cout << getColorLetter(getColor(FACE::FRONT, row, col)) << " ";
        }
        cout << " ";

        for (int col = 0; col <= 2; col++) {
            cout << getColorLetter(getColor(FACE::RIGHT, row, col)) << " ";
        }
        cout << " ";

        for (int col = 0; col <= 2; col++) {
            cout << getColorLetter(getColor(FACE::BACK, row, col)) << " ";
        }
        cout << "\n";
    }

    cout << "\n";

    for (int row = 0; row <= 2; row++) {
        for (unsigned i = 0; i < 7; i++) cout << " ";
        for (int col = 0; col <= 2; col++) {
            cout << getColorLetter(getColor(FACE::DOWN, row, col)) << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

// randomly shuffle the cube
// static cast is used to convert from number to move or move to number
vector<RubiksCube::MOVE> RubiksCube::randomShuffleCube(unsigned int times) {
    vector<MOVE> moves_performed;
    srand(time(0)); // so that srand() -> doen't return the same value everytime
    for (unsigned int i = 0; i < times; i++) {
        unsigned int selectMove = (rand() % 18);
        moves_performed.push_back(static_cast<MOVE>(selectMove)); // save the move
        this->move(static_cast<MOVE>(selectMove)); // perform the move
    }
    return moves_performed;
}