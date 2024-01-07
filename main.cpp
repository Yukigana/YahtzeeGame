#include <iostream>

#include "Yams.h"

using namespace std;

// g++ -o nomExec main.cpp  
// ./nomExec

int main()
{
    Yams* yams = new Yams();
    yams->launchGame();

    return 0;
}

