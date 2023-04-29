/*
 * Test.hpp
 *
 * Description: This file contains the declaration of the Test class, which is responsible for running various tests
 *              to verify the functionality of the game components.
 *
 * Author: Brandon Xu
 * Date: 4/28/23
 */


#pragma once

#include "froggyappwrapper.hpp"

using namespace std;

class Test
{
public:
    void testCalculateScore();
    void testMovement();
    void testCollision();
    void testMenu();
    void testControllers();
    void runTests();
};