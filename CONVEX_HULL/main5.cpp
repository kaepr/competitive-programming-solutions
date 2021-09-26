#include<iostream>
#include<stack>
#include<algorithm>
#include<vector>
using namespace std;
using ll = long long;

struct point {    //define points for 2d plane
   ll x, y;
};

point p0; //used to another two points
point secondTop(stack<point> &stk) {
   point tempPoint = stk.top();
   stk.pop();
   point res = stk.top();    //get the second top element
   stk.push(tempPoint);      //push previous top again
   return res;
}
ll squaredDist(point p1, point p2) {
   return ((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}
ll direction(point a, point b, point c) {
   ll val = (b.y - a.y) * (c.x - b.x) - (b.x - a.x) * (c.y - b.y);
   if (val == 0)
      return 0;    //colinear
   else if (val < 0)
      return 2;    //anti-clockwise direction
   return 1;    //clockwise direction
}
ll comp(const void *point1, const void *point2) {
   point *p1 = (point*)point1;
   point *p2 = (point*)point2;
   ll dir = direction(p0, *p1, *p2);
   if (dir == 0)
      return (squaredDist(p0, *p2) >= squaredDist(p0, *p1)) ? -1LL : 1LL;
   return (dir == 2LL) ? -1LL : 1LL;
}
vector<point> findConvexHull(point points[], ll n) {
   vector<point> convexHullPoints;
   ll minY = points[0].y, min = 0;
   for (ll i = 1; i < n; i++) {
      ll y = points[i].y;
      //find bottom most or left most point
      if ((y < minY) || (minY == y) && points[i].x < points[min].x) {
         minY = points[i].y;
         min = i;
      }
   }
   swap(points[0], points[min]);    //swap min point to 0th location
   p0 = points[0];
   qsort(&points[1], n - 1LL, sizeof(point), comp);  //sort points from 1 place to end
   ll arrSize = 1;    //used to locate items in modified array
   for (ll i = 1; i < n; i++) {
      //when the angle of ith and (i+1)th elements are same, remove points
      while (i < n - 1 && direction(p0, points[i], points[i + 1]) == 0)
         i++;
      points[arrSize] = points[i];
      arrSize++;
   }
   if (arrSize < 3)
      return convexHullPoints;    //there must be at least 3 points, return empty list.
   //create a stack and add first three points in the stack
   stack<point> stk;
   stk.push(points[0]); stk.push(points[1]); stk.push(points[2]);
   for (ll i = 3; i < arrSize; i++) { //for remaining vertices
      while (direction(secondTop(stk), stk.top(), points[i]) != 2)
         stk.pop();    //when top, second top and ith point are not making left turn, remove point
      stk.push(points[i]);
   }
   while (!stk.empty()) {
      convexHullPoints.push_back(stk.top());    //add points from stack
      stk.pop();
   }
}


int main() {
   ll n;
   cin >> n;
   point points[n];
   for (ll i = 0; i < n; i++) {
      ll x, y;
      cin >> x >> y;
      point pt;
      pt.x = x;
      pt.y = y;
      points[i] = pt;
   }

   // point points[] = {{ -7, 8}, { -4, 6}, {2, 6}, {6, 4}, {8, 6}, {7, -2}, {4, -6}, {8, -7}, {0, 0},
   //    {3, -2}, {6, -10}, {0, -6}, { -9, -5}, { -8, -2}, { -8, 0}, { -10, 3}, { -2, 2}, { -10, 4}
   // };
   // int n = 18;
   vector<point> result;
   result = findConvexHull(points, n);
   cout << "Boundary points of convex hull are: " << endl;
   vector<point>::iterator it;
   for (it = result.begin(); it != result.end(); it++)
      cout << "(" << it->x << ", " << it->y << ") ";
}