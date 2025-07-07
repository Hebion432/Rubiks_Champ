//
// Created by Amit on 04/05/25.
//


#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>      // if using math functions
#include <limits>     // for numeric_limits

#include "../Model/RubiksCube.h"

#ifndef RUBIKS_CUBE_SOLVER_DFSSOLVER_H
#define RUBIKS_CUBE_SOLVER_DFSSOLVER_H

// Typename T: RubiksCube Representation used (3d, 1d, Bitboard)
// Typename H: Corresponding Hash function

template<typename T, typename H>
class DFSSolver {
private:

    vector<RubiksCube::MOVE> moves;
    int max_search_depth;

    //    DFS code to find the solution (helper function)
    bool dfs(int dep) {
        if (rubiksCube.isSolved()) return true;
        if (dep > max_search_depth) return false;  //pruning

        for (int i = 0; i < 18; i++) { // check all 18 moves
            rubiksCube.move(RubiksCube::MOVE(i)); // typecase the i to MOVE enum and send to .move method
            moves.push_back(RubiksCube::MOVE(i));
            if (dfs(dep + 1)) return true;

            // backtrack
            moves.pop_back();
            rubiksCube.invert(RubiksCube::MOVE(i));
        }
        return false;
    }

public:
    T rubiksCube; // whatever type we will make wo yaha aa jaayega

    DFSSolver(T _rubiksCube, int _max_search_depth = 8) { //  we will get the jumbled rubiks cube, if no depth provided, then default value will be 8
        rubiksCube = _rubiksCube;
        max_search_depth = _max_search_depth;
    }

    // this solve methods return specific move in order to solve the cube
    vector<RubiksCube::MOVE> solve() {
        dfs(1);
        return moves;
    }

};


#endif //RUBIKS_CUBE_SOLVER_DFSSOLVER_H