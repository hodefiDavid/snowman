/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 * 
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * AUTHORS: <Please write your names here>
 * 
 * Date: 2021-02
 */

#include "doctest.h"
#include "snowman.hpp"
using namespace ariel;

#include <string>
using namespace std;


TEST_CASE("Good snowman code") {
    CHECK(snowman(11114411) == string("_===_\n(.,.)\n( : )\n( : )"));
    CHECK(snowman(11111111) == string("_===_\n(.,.)\n<( : )>\n( : )"));
    CHECK(snowman(22222222) == string("___\n.....\n(o.o)\n(] [)\n(" ")"));
    CHECK(snowman(33333333) == string("_\n/_\\n(O_O)\n/(> <)\\n(___)"));
    CHECK(snowman(44444444) == string("___\n(_*_)\n(- -)\n(   )\n(   )"));

    /* Add more checks here */
}


TEST_CASE("Bad snowman code") {
    CHECK_THROWS(snowman(555));
    CHECK_THROWS(snowman(22222229));
    CHECK_THROWS(snowman(22222292));
    CHECK_THROWS(snowman(22222922));
    CHECK_THROWS(snowman(22229222));
    CHECK_THROWS(snowman(22292222));
    CHECK_THROWS(snowman(22922222));
    CHECK_THROWS(snowman(29222222));
    CHECK_THROWS(snowman(92222222));
    CHECK_THROWS(snowman(2222));
    CHECK_THROWS(snowman(5));
    CHECK_THROWS(snowman(10));
    CHECK_THROWS(snowman(00000));
    CHECK_THROWS(snowman(00100));
    CHECK_THROWS(snowman(002));
    CHECK_THROWS(snowman(141141));
    CHECK_THROWS(snowman(141141));
    CHECK_THROWS(snowman(142221141));
    CHECK_THROWS(snowman(-1257));

    /* Add more checks here */
}
const int max_num = 44444444;
const int len = 8;
const int ten =10;
const int  four =  4;
const int  zero =  0;
const int  one =  1;
TEST_CASE("throws checks (good and bad snowman)") {

//
    const int min_num = 11111111;
    for (int i = min_num; i < max_num+one; i++) {
        int temp = i;
        int flag = one;
        for (int j = zero; j < len && flag == one; ++j) {
            int digit = temp%ten;
            temp = temp/ten;
            if (digit>four || digit == zero) {
                flag = zero;
            }
        }
        if (flag){
            CHECK_NOTHROW(snowman(i));
        } else{
//            CHECK_THROWS(snowman(i));
        }
    }
}


/* Add more test cases here */
//add test for each body part
