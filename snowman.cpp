//
// Created by david on 3/4/21.
//
#include "snowman.hpp"
#include <iostream>
#include <math.h>
#include <array>

using namespace std;
////this function makes a snowman with a given number
/// This will be the general pattern for our ASCII art snowmen:
///     HHHHH
///     HHHHH
///    X(LNR)Y
///    X(TTT)Y
///     (BBB)
///
/// the given nnumber should be as this form HNLRXYTB structure
/// H - for hat     N - for nose     L - for left eye     R - for right eye
/// x - for left arm     Y - for right arm    T - for torso     B - for Base
////all the given digits must be between 1 to 4

string ariel::snowman(int shape) {
    //the maximum and minimum number for shape
    const int min_s = 11111111;
    const int max_s = 44444444;
    //initialize the string answer
    string snowMan;

    //check if the number that we got from the user is in the right range
    if (shape >= min_s && shape <= max_s) {
        int temp = shape;
        const int ten =10;
        //all the options for building the snowman
        array<string, 4> hat = {"_===_", " ___ \n .....", "  _  \n  /_\\", " ___ \n (_*_)"};
        array<string, 4> noseMouth = {",", ".", "_", " "};
        array<string, 4> leftEye = {".", "o", "O", "-"};
        array<string, 4> rightEye = {".", "o", "O", "-"};
        array<string, 4> leftArmHigh = {" ", "\\", " ", " "};
        array<string, 4> leftArmLow = {"<", " ", "/", " "};
        array<string, 4> rightArmHigh = {" ", "/", " ", " "};
        array<string, 4> rightArmLow = {">", " ", "\\", " "};
        array<string, 4> torso = {" : ", "] [", "> <", "   "};
        array<string, 4> base = {" : ", "\" \"", "___", "   "};
        array<string, ten> chosenItems = {""};
        const int cap = 0;const int  nose = 1;const int lEye = 2;const int rEye = 3;const int  lArmH = 4;const int  lArmL = 5;const int rArmH = 6;const int rArmL = 7;const int body = 8;const int legs = 9;
        const int  one = 1;const int two = 2;const int three = 3;const int  four = 4;const int  five = 5;const int six = 6;const int seven = 7;const int eight = 8;



        //here we run 8 times and in each time we add one piece to the snowman
        for (int i = eight; i > 0; i--) {

            temp = (int) (shape % (int) pow(ten, i));
            temp = (int) (temp / (pow(ten, (i - one))));

            //I checked if we support the chosen digit
            if (temp > 4 || temp == 0) {
                throw string("one or more of the digits are larger then 4 or equal to zero \n");
            }

            //in order to get the index zero in the differnts arrays and not to pass the last one we reduce one from the "temp" - the temporary number that hold the values
            temp = temp - 1;

            switch (i) {

                //Hat
                case eight:
                    chosenItems.at(cap) = hat.at(temp);
                    break;
                    //Nose/Mouth
                case seven:
                    chosenItems.at(nose) = noseMouth.at(temp);
                    break;

                    //Left Eye
                case six:
                    chosenItems.at(lEye) = leftEye.at(temp);
                    break;

                    //Right Eye
                case five:
                    chosenItems.at(rEye) = rightEye.at(temp);
                    break;

                    //Left Arm
                case four:
                    chosenItems.at(lArmH) = leftArmHigh.at(temp);
                    chosenItems.at(lArmL) = leftArmLow.at(temp);
                    break;

                    //Right Arm
                case three:
                    chosenItems.at(rArmH) = rightArmHigh.at(temp);
                    chosenItems.at(rArmL) = rightArmLow.at(temp);
                    break;

                    //Torso
                case two:
                    chosenItems.at(body) = torso.at(temp);
                    break;

                    //Base
                case one:
                    chosenItems.at(legs) = base.at(temp);
                    break;

                default:
                    throw out_of_range("index out of range");
            }

        }
        //building the snowman

        // hat
        snowMan = " " + chosenItems[cap] + "\n";
        // face
        snowMan = snowMan + chosenItems[lArmH] + "(" + chosenItems[lEye] + chosenItems[nose] + chosenItems[rEye] + ")" +
                  chosenItems[rArmH] + "\n";
        // body
        snowMan = snowMan + chosenItems[lArmL] + "(" + chosenItems[body] + ")" + chosenItems[rArmL] + "\n";
        // base
        snowMan = snowMan + " (" + chosenItems[legs] + ")" + "\n";


    } else {
        throw string(
                "the number that use is grater then %d or smaller then %d,\npleas try again with the right number\n",
                max_s, min_s);
    }
    return snowMan;
}



