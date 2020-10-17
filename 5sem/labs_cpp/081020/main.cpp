#include <iostream>
#include<cmath>

using namespace std;

struct Point {
    double x, y;
};

double **dist_matrix(Point *a, int n);
double rast(const Point &t1, const Point &t2);

int main() {
    int i, j, n;
    Point *t;
    double **r;
    n = 4;
    t = new Point[n];

    for (i = 0; i < n; i++)
        cin >> t[i].x >> t[i].y;

    for (i = 0; i < n; i++)
        cout << "mas x" << t[i].x << " y =" << t[i].y << endl;

    r = dist_matrix(t, n);

    for (i = 0; i < n - 1; i++) {
        cout << endl;
        for (j = i + 1; j < n; j++)
            cout << r[i][j] << " ";
    }

    cout<<" r 00 "<< r[0][1];
    cin >> i;

    return 0;
}

double rast(const Point &t1, const Point &t2) {
    double r;
    r = sqrt((t1.x - t2.x) * (t1.x - t2.x) + (t1.y - t2.y) * (t1.y - t2.y));
    return r;
}

double **dist_matrix(Point *a, int n) {
    double **p;
    int i, j;
    p = new double *[n];

    for (i = 0; i < n; i++)
        p[i] = new double[n];

    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
            p[i][j] = rast(a[i], a[j]);

    cout<<" ff r 00 "<< p[0][1];
    return p;
}