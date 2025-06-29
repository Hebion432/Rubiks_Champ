
// Created by Lakshya Mittal on 17-12-2021.
//

#include <bits/stdc++.h>
#include "Model/RubiksCube3dArray.cpp"
using namespace std;

int main() {
    RubiksCube3dArray object3DArray;
    object3DArray.print();

    if (object3DArray.isSolved()) cout << "SOLVED\n\n";
    else cout << "NOT SOLVED\n\n";


    object3DArray.u();
    object3DArray.print();

    object3DArray.l();
    object3DArray.print();

    object3DArray.f();
    object3DArray.print();

    object3DArray.r();
    object3DArray.print();

    object3DArray.b();
    object3DArray.print();


    object3DArray.d();
    object3DArray.print();


    if (object3DArray.isSolved()) cout << "SOLVED\n\n";
    else cout << "NOT SOLVED\n\n";


    object3DArray.dPrime();
    object3DArray.print();

    object3DArray.bPrime();
    object3DArray.print();


    object3DArray.rPrime();
    object3DArray.print();


    object3DArray.fPrime();
    object3DArray.print();


    object3DArray.lPrime();
    object3DArray.print();


    object3DArray.uPrime();
    object1dArray.uPrime();
    object3DArray.print();
    object1dArray.print();

    if (object3DArray.isSolved()) cout << "SOLVED\n\n";
    else cout << "NOT SOLVED\n\n";

    return 0;
}