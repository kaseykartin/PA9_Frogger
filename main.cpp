/*
 * main.cpp
 *
 * Description: This is the entry point of the Froggy application.
 *              It creates an instance of the FroggyAppWrapper class and starts the application.
 *
 * Author: Brandon Xu
 * Date: 4/23/28
 */


#pragma once

#include "froggyappwrapper.hpp"
#include "test.hpp"

int main()
{

    // TEST CASES
    //Test t1;
    //t1.runTests();

    // NORMAL PLAYTHROUGH
    FroggyAppWrapper myApp;
    myApp.startApplication();


    return 0;
}
