cmake_minimum_required(VERSION 3.31)
project(RubiksChamp_V1)

set(CMAKE_CXX_STANDARD 20)

add_executable(RubiksChamp_V1
        main.cpp
        Model/RubiksCube.cpp
        Model/RubiksCube3d.cpp
        Model/RubiksCube1d.cpp
        Solver/BFSSolver.h
        Solver/DFSSolver.h
        Solver/IDDFSSolver.h
        Model/PatternDatabase/PatternDatabase.h
        Solver/IDAstarSolver.h
        PatternDatabases/NibbleArray.h
        PatternDatabases/NibbleArray.cpp
        PatternDatabases/PatternDatabase.cpp
        PatternDatabases/PatternDatabase.h
        PatternDatabases/PermutationIndexer.h
        PatternDatabases/math.cpp
        PatternDatabases/math.h
        PatternDatabases/CornerPatternDatabase.cpp
        PatternDatabases/CornerPatternDatabase.h
        PatternDatabases/CornerDBMaker.cpp
        PatternDatabases/CornerDBMaker.h
        Model/RubiksCubeBitboard.cpp
        PatternDatabases/CornerDBMaker.cpp
        PatternDatabases/CornerDBMaker.h)
