#include <bits/stdc++.h>
using namespace std;

struct Point {
    long long x, y;
};

Point pivot;    //value
Point pivot_given; //value for second function

// cross product (orientation)
long long crossProduct(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

// distance squared (used when angles are same)
long long distSq(Point a, Point b) {
    return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}

// sorting by polar angle with pivot (points on the right come first (so counterclockwise order))
bool compare(Point a, Point b) {
    long long cp = crossProduct(pivot, a, b);

    if (cp == 0)
        return distSq(pivot, a) < distSq(pivot, b);

    return cp > 0;
}

// sorting for given pivot
bool compare_given(Point a, Point b) {
    long long cp = crossProduct(pivot_given, a, b);

    if (cp == 0)
        return distSq(pivot_given, a) < distSq(pivot_given, b);

    return cp > 0;
}

vector<Point> grahamScan(vector<Point> &points) {

    int n = points.size();

    // find pivot (lowest on  y axis, if multiple at same level then lowest x)
    int pos = 0;
    for (int i = 1; i < n; i++) {
        if (points[i].y < points[pos].y ||
           (points[i].y == points[pos].y && points[i].x < points[pos].x))
            pos = i;
    }

    swap(points[0], points[pos]);
    pivot = points[0];

    // sort by polar angle
    sort(points.begin() + 1, points.end(), compare);  //left points are at the end, so we are sorting in counterclockwise order

    stack<Point> st;

    st.push(points[0]);     //pivot
    st.push(points[1]);     //rightmost point (first point after pivot in sorted order)
    st.push(points[2]);

    for (int i = 3; i < n; i++) {

        while (st.size() >= 2) {
            Point previousPoint = st.top();
            st.pop();
            Point previousOfpreviousPoint = st.top();

            if (crossProduct(previousOfpreviousPoint, previousPoint, points[i]) > 0) {  //if true, then turned left on previousPoint, so we are good, otherwise we need to pop previousPoint and check again with new top of stack(next iteration)
                st.push(previousPoint);
                break;
            }
        }

        st.push(points[i]);
    }

    vector<Point> hull;

    while (!st.empty()) {
        hull.push_back(st.top());
        st.pop();
    }

    reverse(hull.begin(), hull.end());

    return hull;
}

vector<Point> grahamScan_startingGiven(vector<Point> &points, Point givenPivot) {

    int n = points.size();

    pivot_given = givenPivot;

    // move given pivot to index 0
    int pos = -1;
    for(int i=0;i<n;i++){
        if(points[i].x == givenPivot.x && points[i].y == givenPivot.y){
            pos = i;
            break;
        }
    }

    if(pos != -1)
        swap(points[0], points[pos]);

    // sort by polar angle
    sort(points.begin() + 1, points.end(), compare_given);

    stack<Point> st;

    st.push(points[0]);
    st.push(points[1]);
    st.push(points[2]);

    for (int i = 3; i < n; i++) {

        while (st.size() >= 2) {
            Point top = st.top();
            st.pop();
            Point previousPoint = st.top();

            if (crossProduct(previousPoint, top, points[i]) > 0) {
                st.push(top);
                break;
            }
        }

        st.push(points[i]);
    }

    vector<Point> hull;

    while (!st.empty()) {
        hull.push_back(st.top());
        st.pop();
    }

    reverse(hull.begin(), hull.end());

    return hull;
}



int main() {

    int n;
    // cin >> n;
     n = 8;
    
    vector<Point> points(n);

    // for (int i = 0; i < n; i++)
    //     cin >> points[i].x >> points[i].y;

    points[0] = {0, 0};
    points[1] = {1, 1};
    points[2] = {2, 0};
    points[3] = {0, 2};
    points[4] = {1, 0};
    points[5] = {0, 1};
    points[6] = {2, 1};
    points[7] = {1, 2};

    vector<Point> copyPoints = points;

    vector<Point> hull1 = grahamScan(points);
    vector<Point> hull2 = grahamScan_startingGiven(copyPoints, copyPoints[3]);

    cout << "Convex Hull:\n";
    for (auto p : hull1)
        cout << p.x << " " << p.y << endl;

    cout << "Convex Hull (starting given pivot):\n";
    for (auto p : hull2)
        cout << p.x << " " << p.y << endl;

    return 0;
}