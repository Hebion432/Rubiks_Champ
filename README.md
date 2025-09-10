# Rubik's Cube Solver Project

This project implements a Rubik's Cube solver using **Korf's Algorithm**, an optimal solution method for solving the cube in the minimum number of moves. The solver is designed to explore and demonstrate advanced search techniques and heuristics in solving the Rubik's Cube.


## Algorithm Overview

### Korf's Algorithm

Korf's Algorithm solves the Rubik's Cube using the following steps:

- **Problem Representation**: The cube is represented as a state tree where each node is a configuration.
- **Iterative Deepening A***: Combines depth-first search's space efficiency with breadth-first search's optimality.
- **Heuristics**: Pattern databases store precomputed optimal solutions for subproblems (e.g., corners, edges).

### Why Korf's Algorithm?

- Guarantees the optimal solution.
- Efficient use of memory with iterative deepening.
- Demonstrates advanced algorithmic concepts.

---


## Project Structure

The project is organized into several main components:

### Model
Contains different representations of the Rubik's Cube:
- **RubiksCube.h** - Base abstract class defining the interface
- **RubiksCube3d.cpp** - 3D array representation
- **RubiksCube1d.cpp** - Flattened 1D array representation

### Solver
Contains various search algorithms to solve the cube:
- **DFSSolver.h** - Depth-First Search
- **BFSSolver.h** - Breadth-First Search
- **IDDFSSolver.h** - Iterative Deepening DFS
- **IDAstarSolver.h** - IDA* (advanced heuristic search)

### PatternDatabases
Advanced techniques for faster solving:
- **CornerPatternDatabase.h** - Pattern database for corners
- **PermutationIndexer.h** - Indexes permutations efficiently
- **NibbleArray.h** - Compressed storage for database

## Key Features
- Multiple cube representations for comparative performance
- Various search algorithms with increasing sophistication
- Corner pattern database for efficient heuristic estimation in IDA*
- Ability to randomly shuffle and solve cubes
- Support for all standard Rubik's Cube moves (F, B, U, D, L, R and their variations)

## Implementation Details
The project implements:
- Efficient cube state representation and move application
- Hash functions for cube states to enable memoization
- Optimized pattern database generation and lookup
- Advanced corner indexing and orientation tracking

## Usage
The `main.cpp` file contains examples of how to use the different components to shuffle and solve Rubik's Cubes using the various algorithms.
