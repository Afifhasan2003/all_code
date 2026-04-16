#include <bits/stdc++.h>
using namespace std;

// position of two point is given
double crossProduct(pair<double, double> a, pair<double, double> b) {
    return a.first * b.second - a.second * b.first;
}

void rotation(pair<double,double> & zeroPoint, pair<double,double> &p1, pair<double,double> &p2) {

    pair<double,double> vec1 = {p1.first - zeroPoint.first, p1.second - zeroPoint.second};
    pair<double,double> vec2 = {p2.first - zeroPoint.first, p2.second - zeroPoint.second};
    double cross = crossProduct(vec1, vec2);
    if (cross > 0) {
        cout << "first point is in anticlockwise direction" << endl;
    } else if (cross < 0) {
        cout << "first point is in clockwise direction" << endl;
    } else {
        cout << "they are Collinear" << endl;
    }
}


//while traveling from zero to point1 to point2, we are turning left or right at point1 or they are collinear
void turnAt_point1(pair<double,double> & zeroPoint, pair<double,double> &p1, pair<double,double> &p2) {
    pair<double,double> vec1 = {p1.first - zeroPoint.first, p1.second - zeroPoint.second};
    pair<double,double> vec2 = {p2.first - zeroPoint.first, p2.second - zeroPoint.second};
    double cross = crossProduct(vec1, vec2);
    if (cross > 0) {
        cout << "turn left" << endl;
    } else if (cross < 0) {
        cout << "turn right" << endl;
    } else {
        cout << "they are Collinear" << endl;
    }
}



int main() {
    
    return 0;
}