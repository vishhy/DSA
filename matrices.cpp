#include <iostream>
using namespace std;

class matrix
{
private:
    int r, c;
    int a[4][4];

public:
    void set_mat(unsigned int, unsigned int);
    void show_mat();
    matrix operator+(matrix m);
    matrix operator*(matrix m);
    void diag(matrix m);
    matrix transpose();
    void operator=(matrix m);
};

void matrix::set_mat(unsigned int x, unsigned int y)
{
    r = x, c = y;
    for (int j = 1; j <= r; j++)
    {
        for (int i = 1; i <= c; i++)
        {
            cout << "Enter the element a[" << j << "][" << i << "]" << endl;
            cin >> a[j][i];
        }
    }
}
void matrix::show_mat()
{
    cout << "The matrix is: " << endl;
    for (int j = 1; j <= r; j++)
    {
        for (int i = 1; i <= c; i++)
        {
            cout << a[j][i] << "\t";
        }
        cout << endl;
    }
}
matrix matrix::operator+(matrix m)
{
    matrix t;
    if (r > m.r)
        t.r = r;
    else
        t.r = m.r;
    if (c > m.c)
        t.c = c;
    else
        t.c = m.c;
    for (int j = 1; j <= t.r; j++)
    {
        for (int i = 1; i <= t.c; i++)
        {
            t.a[j][i] = a[j][i] + m.a[j][i];
        }
    }
    return t;
}

matrix matrix::operator*(matrix m)
{
    matrix t;
    if (r > m.r)
        t.r = r;
    else
        t.r = m.r;
    if (c > m.c)
        t.c = c;
    else
        t.c = m.c;
    for (int j = 1; j <= t.r; j++)
    {
        for (int i = 1; i <= t.c; i++)
        {
            int sum = 0;
            for (int k = 1; k <= t.r; k++)
            {
                sum = sum + a[j][k] * m.a[k][i];
            }
            t.a[j][i] = sum;
        }
    }
    return t;
}
void matrix::diag(matrix m)
{
    matrix t;
    if (r > m.r)
        t.r = r;
    else
        t.r = m.r;
    if (c > m.c)
        t.c = c;
    else
        t.c = m.c;
    int sum = 0, sum1 = 0;
    for (int j = 1; j <= t.r; j++)
    {
        int i;
        for (i = 1; i <= t.c; i++)
        {
            if (i == j)
                sum = sum + a[j][i];
            if (i + j == (t.r + 1))
                sum1 = sum1 + m.a[j][i];
        }
    }
    cout << "The sum of the diagonal elements for both the matrices is: " << sum + sum1 << endl;
}
matrix matrix::transpose()
{
    matrix t;
    t.r = r, t.c = c;
    for (int j = 1; j <= t.r; j++)
    {
        for (int i = 1; i <= t.c; i++)
        {
            t.a[i][j] = a[j][i];
        }
    }
    return t;
}
void matrix::operator=(matrix m)
{
    r = m.r;
    c = m.c;
    for (int j = 1; j <= r; j++)
    {
        for (int i = 1; i <= c; i++)
        {
            a[j][i] = m.a[j][i];
        }
    }
}
int main()
{
    matrix m1, m2, m3, m4, m5, m6;
    m1.set_mat(3, 3);
    m1.show_mat();
    m2.set_mat(3, 3);
    m2.show_mat();
    m3 = m1 + m2;
    m3.show_mat();
    m4 = m1 * m2;
    m4.show_mat();
    m1.diag(m2);
    m5.set_mat(3, 3);
    m5.show_mat();
    m6 = m5.transpose();
    m6.show_mat();
    return 0;
}
