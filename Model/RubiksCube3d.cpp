//
// Created by Amit Kumar 09/03/2025
//

#include "RubiksCube.h"

class RubiksCube3d : public RubiksCube {
private:

    // 90degree clcokwise turn
    void rotateFace(int ind) {
        char temp_arr[3][3] = {};
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                temp_arr[i][j] = cube[ind][i][j];
            }
        }
        for (int i = 0; i < 3; i++) cube[ind][0][i] = temp_arr[2 - i][0];
        for (int i = 0; i < 3; i++) cube[ind][i][2] = temp_arr[0][i];
        for (int i = 0; i < 3; i++) cube[ind][2][2 - i] = temp_arr[i][2];
        for (int i = 0; i < 3; i++) cube[ind][2 - i][0] = temp_arr[2][2 - i];
    }

public:
    char cube[6][3][3]{};

    // constructor - set up a solved cube
    RubiksCube3d() {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++)
                    cube[i][j][k] = getColorLetter(COLOR(i));
            }
        }
    }


    // and since we have made and enum class we have to return COLOR::BLUE

    // it returns the color of a specific cell
    // using this only we are implementing the print function in the header file only
    COLOR getColor(FACE face, unsigned row, unsigned col) const override {
        char color = cube[int(face)][row][col]; //int(face) changes it to integer
        switch (color) {
            case 'B':
                return COLOR::BLUE;
            case 'R':
                return COLOR::RED;
            case 'G':
                return COLOR::GREEN;
            case 'O':
                return COLOR::ORANGE;
            case 'Y':
                return COLOR::YELLOW;
            default:
                return COLOR::WHITE;
        }
    }

    //checks whether the Rubik’s Cube is in a solved or not
    bool isSolved() const override {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    if (this->cube[i][j][k] == getColorLetter(COLOR(i))) continue;
                    return false;
                }
            }
        }
        return true;
    }





    RubiksCube &uPrime() override{
        rotateFace(0);
        char a[3];
        for(int i=0;i<3;i++){
            a[i]=cube[1][0][i];
            cube[1][0][i]=cube[4][0][i];
        }
        for(int i=0;i<3;i++){
            cube[4][0][i]=cube[3][0][i];
        }
        for(int i=0;i<3;i++){
            cube[3][0][i]=cube[2][0][i];
        }
        for(int i=0;i<3;i++){
            cube[2][0][i]=a[i];
        }

        return *this;
    }
    RubiksCube &u() override{
        this->uPrime();
        this->uPrime();
        this->uPrime();
        return *this;
    }
    RubiksCube &u2() override{
        this->uPrime();
        this->uPrime();
        return *this;
    }

    RubiksCube &l() override{
        rotateFace(1);
        char a[3];
        for(int i=0;i<3;i++){
            a[i]=cube[5][i][0];
            cube[5][i][0]=cube[2][i][0];
        }
        for(int i=0;i<3;i++){
            cube[2][i][0]=cube[0][i][0];
        }
        for(int i=0;i<3;i++){
            cube[0][i][0]=cube[4][2-i][2];
        }
        for(int i=0;i<3;i++){
            cube[4][i][2]=a[2-i];
        }
        return *this;
    }
    RubiksCube &lPrime() override{
        this->l();
        this->l();
        this->l();
        return *this;
    }
    RubiksCube &l2() override{
        this->l();
        this->l();
        return *this;
    }

    RubiksCube &f() override{
        rotateFace(2);
        char a[3];
        for(int i=0;i<3;i++){
            a[i]=cube[0][2][i];
            cube[0][2][i]=cube[1][2-i][2];
        }
        for(int i=0;i<3;i++){
            cube[1][i][2]=cube[5][0][i];
        }
        for(int i=0;i<3;i++){
            cube[5][0][i]=cube[3][2-i][0];
        }
        for(int i=0;i<3;i++){
            cube[3][i][0]=a[i];
        }

        return *this;
    }
    RubiksCube &fPrime() override{
        this->f();
        this->f();
        this->f();
        return *this;
    }
    RubiksCube &f2() override{
        this->f();
        this->f();
        return *this;
    }

    RubiksCube &r()override {
        rotateFace(3);
        char a[3];
        for(int i=0;i<3;i++){
            a[i]=cube[0][i][2];
            cube[0][i][2]=cube[2][i][2];
        }
        for(int i=0;i<3;i++){
            cube[2][i][2]=cube[5][i][2];
        }
        for(int i=0;i<3;i++){
            cube[5][i][2]=cube[4][2-i][0];
        }
        for(int i=0;i<3;i++){
            cube[4][i][0]=a[2-i];
        }
        return *this;
    }

    RubiksCube &rPrime() override{
        this-> r();
        this-> r();
        this-> r();

        return *this;
    }

    RubiksCube &r2() override{
        this-> r();
        this-> r();

        return *this;
    }

    RubiksCube &b() override{
        rotateFace(4);

        char a[3];

        for(int i=0;i<3;i++){
            a[i]=cube[0][0][i];
            cube[0][0][i]=cube[3][i][2];
        }
        for(int i=0;i<3;i++){
            cube[3][i][2]=cube[5][2][2-i];
        }
        for(int i=0;i<3;i++){
            cube[5][2][i]=cube[1][i][0];
        }
        for(int i=0;i<3;i++){
            cube[1][i][0]=a[2-i];
        }

        return *this;
    }

    RubiksCube &bPrime() override{
        this -> b();
        this -> b();
        this -> b();
        return *this;
    }
    RubiksCube &b2() override{
        this -> b();
        this -> b();
        return *this;
    }

    RubiksCube &d() override{
        rotateFace(5);

        char a[3];
        for(int i=0;i<3;i++){
            a[i]=cube[1][2][i];
            cube[1][2][i]=cube[4][2][i];
        }
        for(int i=0;i<3;i++){
            cube[4][2][i]=cube[3][2][i];
        }
        for(int i=0;i<3;i++){
            cube[3][2][i]=cube[2][2][i];
        }
        for(int i=0;i<3;i++){
            cube[2][2][i]=a[i];
        }

        return *this;
    }

    RubiksCube &dPrime() override{
        this->d();
        this->d();
        this->d();

        return *this;
    }
    RubiksCube &d2() override{
        this->d();
        this->d();

        return *this;
    }


    bool operator==(const RubiksCube3d &r1) const {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    if (r1.cube[i][j][k] != cube[i][j][k]) return false;
                }
            }
        }
        return true;
    }

    RubiksCube3d &operator=(const RubiksCube3d &r1) {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    cube[i][j][k] = r1.cube[i][j][k];
                }
            }
        }
        return *this;
    }
};

struct Hash3d {
    size_t operator()(const RubiksCube3d &r1) const {
        string str = "";
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    str += r1.cube[i][j][k];
                }
            }
        }
        return hash<string>()(str); // predefine functon to create hash -> return size_t
    }
};