
// Created by Amit Kumar 09/03/2025
//

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>      // if using math functions
#include <limits>     // for numeric_limits


#include "Model/RubiksCube3d.cpp"
#include "Solver/IDDFSSolver.h"
#include "Solver/BFSSolver.h"
#include "Solver/DFSSolver.h"
#include "Solver/BFSSolver.h"
#include "Solver/IDDFSSolver.h"
#include "Solver/IDAstarSolver.h"
#include "PatternDatabases/CornerPatternDatabase.h"
#include "PatternDatabases/CornerDBMaker.h"
using namespace std;

int main() {

//    RubiksCube3d object3DArray;
//    RubiksCube1d object1dArray;
//    RubiksCube3d objectBitboard;
//
//    object3DArray.print();
//
//    if (object3DArray.isSolved()) cout << "SOLVED\n\n";
//    else cout << "NOT SOLVED\n\n";
//
//    if (object1dArray.isSolved()) cout << "SOLVED\n\n";
//    else cout << "NOT SOLVED\n\n";
//
//    if (objectBitboard.isSolved()) cout << "SOLVED\n\n";
//    else cout << "NOT SOLVED\n\n";
//
//    objectBitboard.u();
//    object3DArray.u();
//    object1dArray.u();
//    objectBitboard.print();
//    object3DArray.print();
//    object1dArray.print();
//
//    objectBitboard.l();
//    object3DArray.l();
//    object1dArray.l();
//    objectBitboard.print();
//    object3DArray.print();
//    object1dArray.print();
//
//    objectBitboard.f();
//    object3DArray.f();
//    object1dArray.f();
//    objectBitboard.print();
//    object3DArray.print();
//    object1dArray.print();
//
//    objectBitboard.r();
//    object3DArray.r();
//    object1dArray.r();
//    objectBitboard.print();
//    object3DArray.print();
//    object1dArray.print();
//
//    objectBitboard.b();
//    object3DArray.b();
//    object1dArray.b();
//    objectBitboard.print();
//    object3DArray.print();
//    object1dArray.print();
//
//    objectBitboard.d();
//    object3DArray.d();
//    object1dArray.d();
//    objectBitboard.print();
//    object3DArray.print();
//    object1dArray.print();
//
//    if (object3DArray.isSolved()) cout << "SOLVED\n\n";
//    else cout << "NOT SOLVED\n\n";
//
//    if (object1dArray.isSolved()) cout << "SOLVED\n\n";
//    else cout << "NOT SOLVED\n\n";
//
//    if (objectBitboard.isSolved()) cout << "SOLVED\n\n";
//    else cout << "NOT SOLVED\n\n";
//
//    objectBitboard.dPrime();
//    object3DArray.dPrime();
//    object1dArray.dPrime();
//    objectBitboard.print();
//    object3DArray.print();
//    object1dArray.print();
//
//    objectBitboard.bPrime();
//    object3DArray.bPrime();
//    object1dArray.bPrime();
//    objectBitboard.print();
//    object3DArray.print();
//    object1dArray.print();
//
//    objectBitboard.rPrime();
//    object3DArray.rPrime();
//    object1dArray.rPrime();
//    objectBitboard.print();
//    object3DArray.print();
//    object1dArray.print();
//
//    objectBitboard.fPrime();
//    object3DArray.fPrime();
//    object1dArray.fPrime();
//    objectBitboard.print();
//    object3DArray.print();
//    object1dArray.print();
//
//    objectBitboard.lPrime();
//    object3DArray.lPrime();
//    object1dArray.lPrime();
//    objectBitboard.print();
//    object3DArray.print();
//    object1dArray.print();
//
//    objectBitboard.uPrime();
//    object3DArray.uPrime();
//    object1dArray.uPrime();
//    objectBitboard.print();
//    object3DArray.print();
//    object1dArray.print();
//
//    if (object3DArray.isSolved()) cout << "SOLVED\n\n";
//    else cout << "NOT SOLVED\n\n";
//
//    if (object1dArray.isSolved()) cout << "SOLVED\n\n";
//    else cout << "NOT SOLVED\n\n";
//
//    if (objectBitboard.isSolved()) cout << "SOLVED\n\n";
//    else cout << "NOT SOLVED\n\n";

    // Create two Cubes ------------------------------------------------------------------------------------------

//    RubiksCube3d cube1;
//    RubiksCube3d cube2;

//    RubiksCube1d cube1;
//    RubiksCube1d cube2;

//    RubiksCube3d cube1;
//    RubiksCube3d cube2;


//  Equality and assignment of cubes --------------------------------------------------------------------------

//    if(cube1 == cube2) cout << "Is equal\n";
//    else cout << "Not Equal\n";
//
//    cube1.randomShuffle(1);
//
//    if(cube1 == cube2) cout << "Is equal\n";
//    else cout << "Not Equal\n";
//
//    cube2 = cube1;
//
//    if(cube1 == cube2) cout << "Is equal\n";
//    else cout << "Not Equal\n";


//  Unordered_map of Cubes  ------------------------------------------------------------------------------------


//    unordered_map<RubiksCube3d, bool, Hash3d> mp1;

//    unordered_map<RubiksCube1d, bool, Hash1d> mp1;

//    unordered_map<RubiksCube3d, bool, HashBitboard> mp1;
//
//    mp1[cube1] = true;
//    cube2.randomShuffle(8);
//    if (mp1[cube1]) cout << "Cube1 is present\n";
//    else cout << "Cube1 is not present\n";
//
//    if (mp1[cube2]) cout << "Cube2 is present\n";
//    else cout << "Cube2 is not present\n";
//

    // DFS Solver Testing __________________________________________________________________________________________
    // RubiksCube3d cube;
    // cube.print();
    //
    // vector<RubiksCube::MOVE> shuffle_moves = cube.randomShuffle(6);
    // for (auto move: shuffle_moves) cout << cube.getMoveLetter(move) << " ";
    // cout << "\n";
    // cube.print();
    //
    // DFSSolver<RubiksCube3d, Hash3d> dfsSolver(cube, 8);
    // vector<RubiksCube::MOVE> solve_moves = dfsSolver.solve();
    //
    // for (auto move: solve_moves) cout << cube.getMoveLetter(move) << " ";
    // cout << "\n";
    // dfsSolver.rubiksCube.print();



    //BFS Solver -----------------------------------------------------------------------------------------------------
    // RubiksCube3d cube;
    // cube.print();
    //
    // vector<RubiksCube::MOVE> shuffle_moves = cube.randomShuffle(3);
    // for(auto move: shuffle_moves) cout << cube.getMoveLetter(move) << " ";
    // cout << "\n";
    // cube.print();
    //
    // BFSSolver<RubiksCube3d, Hash3d> bfsSolver(cube);
    // vector<RubiksCube::MOVE> solve_moves = bfsSolver.solve();
    //
    // for(auto move: solve_moves) cout << cube.getMoveLetter(move) << " ";
    // cout << "\n";
    // bfsSolver.rubiksCube.print();

    // IDDFS Solver ----------------------------------------------------------------------------------------------------
    // RubiksCube3d cube;
    // cube.print();
    //
    // vector<RubiksCube::MOVE> shuffle_moves = cube.randomShuffle(7);
    // for (auto move: shuffle_moves) cout << cube.getMoveLetter(move) << " ";
    // cout << "\n";
    // cube.print();
    //
    // IDDFSSolver<RubiksCube3d, Hash3d> iddfsSolver(cube, 8);
    // vector<RubiksCube::MOVE> solve_moves = iddfsSolver.solve();
    //
    // for (auto move: solve_moves) cout << cube.getMoveLetter(move) << " ";
    // cout << "\n";
    // iddfsSolver.rubiksCube.print();



    // IDA* SOLVER ---------------------------------------------------------------------------------------------------
    RubiksCube3d cube;
    cube.print();

    vector<RubiksCube::MOVE> shuffle_moves = cube.randomShuffle(5);
    for (auto move: shuffle_moves) cout << cube.getMove(move) << " ";
    cout << "\n";
    cube.print();

    IDAstarSolver<RubiksCube3d, Hash3d> idAstarSolver(cube);
    vector<RubiksCube::MOVE> solve_moves = idAstarSolver.solve();
    for (auto move: solve_moves) cout << cube.getMove(move) << " ";
    cout << "\n";
    idAstarSolver.rubiksCube.print();

    // CornerPatternDatabase Testing ---------------------------------------------------------------------------------

    //    CornerPatternDatabase cornerDB;
    //    RubiksCube3d cube;
    //    cube.print();
    //
    //    cout << (int)cornerDB.getNumMoves(cube) << "\n";
    //
    //    cornerDB.setNumMoves(cube, 5);
    //
    //    cout << (int)cornerDB.getNumMoves(cube) << "\n";
    //
    //    cube.randomShuffle(1);
    //    cube.print();
    //    cout << (int)cornerDB.getNumMoves(cube) << "\n";
    //
    //    cornerDB.setNumMoves(cube, 6);
    //
    //    cout << (int)cornerDB.getNumMoves(cube) << "\n";


    return 0;
}