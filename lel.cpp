#include <iostream>
using namespace std;

#define in cin>>
#define out cout<<

int main()
{
    int n, m, v, t=0, c, cmax=0, cmin=0;

    in n;
    m=n;

    while (n--) in v, t+=v;

    while(m--)
    {
        in c;
        if(c>cmax)	cmax=c;
        else if(c>cmin and c<=cmax)	cmin=c;
    }

    c=cmax+cmin;

    if(t<=c)	out "YES\n";
    else		out "NO\n";

    return 0;
}