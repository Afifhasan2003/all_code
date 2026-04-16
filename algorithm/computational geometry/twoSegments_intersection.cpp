#include <bits/stdc++.h>
using namespace std;

struct Point {
    long long x, y;
};

// cross product (orientation)
long long crossProduct(Point a, Point b, Point c) {
    // (b-a) x (c-a)
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

// check if bounding boxes intersect (line ab and cd)
bool boxIntersect(Point a, Point b, Point c, Point d) {

    if (max(a.x, b.x) < min(c.x, d.x)) return false;        //ab is on the left of cd
    if (max(c.x, d.x) < min(a.x, b.x)) return false;        //cd is on the left of ab
    if (max(a.y, b.y) < min(c.y, d.y)) return false;        //ab is below cd
    if (max(c.y, d.y) < min(a.y, b.y)) return false;        //cd is below ab
    return true;
}

// check if two segments intersect
bool segmentsIntersect(Point a, Point b, Point c, Point d) {

    if (!boxIntersect(a, b, c, d))
        return false;

    long long d1 = crossProduct(a, b, c);
    long long d2 = crossProduct(a, b, d);
    long long d3 = crossProduct(c, d, a);
    long long d4 = crossProduct(c, d, b);

    if (d1 == 0 && d2 == 0) 
        return true;   // collinear and bounding boxes already checked

    if (d1 * d2 < 0 && d3 * d4 < 0)
        return true;   // proper intersection
    return false;
}

int main() {

    Point p1, p2, p3, p4;

    cout << "Enter segment1 (x1 y1 x2 y2): ";
    // cin >> p1.x >> p1.y >> p2.x >> p2.y;
    p1.x = 0; p1.y = 0; p2.x = 4; p2.y = 4;

    cout << "Enter segment2 (x3 y3 x4 y4): ";
    // cin >> p3.x >> p3.y >> p4.x >> p4.y;
    p3.x = 0; p3.y = 4; p4.x = 4; p4.y = 0;

    if (segmentsIntersect(p1, p2, p3, p4))
        cout << "Segments intersect\n";
    else
        cout << "Segments do not intersect\n";

    return 0;
}