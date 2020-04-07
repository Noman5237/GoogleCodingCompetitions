#include <bits/stdc++.h>

using namespace std;
int overlap(int l1, int r1, int l2, int r2)
{
    return (l2 < r1);
}
void check(int s, int e, int bit[], int b)
{
    int bit1[b+1] = {0}; //rev
    int bit2[b+1] = {0}; // com
    int bit3[b+1] = {0}; // rev and comp
    int bit4[b+1] = {0};
    int i;
    for(i=s;i<=e;i++)
    {
        bit1[i] = bit[b+1-i];
        bit2[i] = 1-bit[i];
        bit3[i] = 1 - bit[b+1-i];
        bit4[i] = bit[i];
    } // bit1[i] != bit3[i],  bit2[i] != bit4[i]
    cout << s << '\n';
    int bt;
    cin >> bt; // bt must be equal to bit1[i], bit2[i], bit3[i], bit4[i]
    if(bt == bit1[s])
        for(i=s;i<=e;i++)
            bit3[i] = bit1[i];
    else
        for(i=s;i<=e;i++)
            bit1[i] = bit3[i];
    if(bt == bit2[s])
        for(i=s;i<=e;i++)
            bit4[i] = bit2[i];
    else
        for(i=s;i<=e;i++)
            bit2[i] = bit4[i];
    for(i=(s+1);i<=e;i++)
        if(bit1[i] != bit2[i])
            break;
    if(i != (e+1))
    {
        cout << i << '\n';
        cin >> bt;
        if(bt == bit1[i])
            for(i=s;i<=e;i++)
                bit2[i] = bit1[i];
        else
            for(i=s;i<=e;i++)
                bit1[i] = bit2[i]; 
    }
    else
    {
        cout << e << '\n';
        cin >> bt;
    }
    for(i=s;i<=e;i++)
        bit[i] = bit1[i];
}
void func(int s, int e, int bit[])
{
    for(int i=s;i<=e;i++)
    {
        cout << i << '\n';
        int bt;
        cin >> bt;
        bit[i] = bt;
    }
}
int main() {
    int t, b;
    cin >> t >> b;
    for(int l = 1;l<=t;l++)
    {
        int i;
        if(b == 10)
        {
            int bit[b];
            for(i=0;i<b;i++)
            {
                cout << (i+1) << '\n';
                int bt;
                cin >> bt;
                bit[i] = bt;
            }
            for(i=0;i<b;i++)
                cout << bit[i];
            cout << '\n';
            char c;
            cin >> c;
        }
        else if(b == 20)
        {
            int bit[b+1] = {0};
            for(i=6;i<=15;i++)
            {
                cout << i << '\n';
                int bt;
                cin >> bt;
                bit[i] = bt;
            }
            check(6, 15, bit, b);
            // 12 queries done
            for(i=2;i<=5;i++)
            {
                cout << i << '\n';
                int bt;
                cin >> bt;
                bit[i] = bt;
            }
            for(i=16;i<=19;i++)
            {
                cout << i << '\n';
                int bt;
                cin >> bt;
                bit[i] = bt;
            }
            check(2, 19, bit, b);
            // 22 queries done
            cout << 1 << '\n';
            int bt;
            cin >> bt;
            bit[1] = bt;
            cout << 20 << '\n';
            cin >> bt;
            bit[20] = bt;
            // 24 queries done            
            for(i=1;i<=b;i++)
                cout << bit[i];
            cout << '\n';
            char c;
            cin >> c;
        }
        else
        {
            int bit[b+1] = {0};
            int j;
            func(46, 55, bit);
            check(46, 55, bit, b);
            // 12 queries
            for(i=42,j=56;i>=2,j<=96 ;i=i-4,j=j+4)
            {
                func(i, i+3, bit);
                func(j, j+3, bit);
                check(i, j+3, bit, b);
            }
            int bt;
            cout << 1 << '\n';
            cin >> bt;
            bit[1] = bt;
            cout << 100 << '\n';
            cin >> bt;
            bit[100] = bt;
            // 24 queries done            
            for(i=1;i<=b;i++)
                cout << bit[i];
            cout << '\n';
            char c;
            cin >> c;
        }
    }
}