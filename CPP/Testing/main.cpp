/* 
 * File:   main.cpp
 * Author: Beetoo
 *
 * Created on July 16, 2013, 4:19 PM
 */

#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

int main(int argc, char** argv) {
    int hist[] =  {6, 1, 5, 4, 5, 2, 6};
    int n = sizeof(hist)/sizeof(hist[0]);
    cout << "Maximum area is " << getMaxArea(hist, n);
    return 0;
}

