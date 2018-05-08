#include <iostream>
#include <QStringList>
#include <QString>
#include<sstream>

using namespace std;

std::string orthogonality(std::string arg)
{
    std::pair<int, int> a;
    std::pair<int, int> b;

    int sum1=1;
    int sum2=1;

    bool flag = false;
    for(int i=0;i<arg.length();++i)
    {
        int a=0;
        if (arg[i] <= '9' && arg[i] >= '0')
        {
            if(arg[i-1]=='-')
            {
                a=(arg[i]-'0')*(-1);
            }
            else
            {
                a=(arg[i]-'0');
            }

            if(flag==false)
            {
                sum1*=a;
                flag=true;
            }
            else
            {
                flag=false;
                sum2*=a;
            }
        }
    }

    if((sum1+sum2)==0)
    {
        return "1";
    }
    else
    {
        return "0";
    }
}

std::string process(std::string id, std::string arg)
{
    int a=stoi(id);

    if(a<1 || a>896)
    {
        return "";
    }
    else if(a>=1 && a<=40)
    {
        return "";
    }
    else if(a>=41 && a<=60)
    {
        return "";
    }
    else if(a>=61 && a<=80)
    {
        return "";
    }
    else if(a>=81 && a<=100)
    {
        return "";
    }
    else if(a>=101 && a<=120)
    {
        return orthogonality(arg);
    }
    else if(a>=121 && a<=140)
    {
        return "";
    }
    else if(a>=141 && a<=160)
    {
        return "";
    }
    else if(a>=161 && a<=180)
    {
        return "";
    }
    else if(a>=181 && a<=200)
    {
        return "";
    }
    else if(a>=201 && a<=220)
    {
        return "";
    }
    else if(a>=221 && a<=240)
    {
        return "";
    }
    else if(a>=241 && a<=260)
    {
        return "";
    }
    else if(a>=261 && a<=280)
    {
        return "";
    }
    else if(a>=281 && a<=300)
    {
        return "";
    }
    else if(a>=301 && a<=320)
    {
        return "";
    }
    else if(a>=321 && a<=340)
    {
        return "";
    }
    else if(a>=341 && a<=360)
    {
        return "";
    }
    else if(a>=361 && a<=380)
    {
        return "";
    }
    else if(a>=381 && a<=400)
    {
        return "";
    }
    else if(a>=401 && a<=420)
    {
        return "";
    }
    else if(a>=421 && a<=440)
    {
        return "";
    }
    else if(a>=441 && a<=460)
    {
        return "";
    }
    else if(a>=461 && a<=480)
    {
        return "";
    }
    else if(a>=481 && a<=500)
    {
        return "";
    }
    else if(a>=501 && a<=520)
    {
        return "";
    }
    else if(a>=521 && a<=540)
    {
        return "";
    }
    else if(a>=541 && a<=560)
    {
        return "";
    }
    else if(a>=561 && a<=580)
    {
        return "";
    }
    else if(a>=581 && a<=600)
    {
        return "";
    }
    else if(a>=601 && a<=620)
    {
        return "";
    }
    else if(a>=621 && a<=640)
    {
        return "";
    }
    else if(a>=641 && a<=660)
    {
        return "";
    }
    else if(a>=661 && a<=680)
    {
        return "";
    }
    else if(a>=681 && a<=700)
    {
        return "";
    }
    else if(a>=701 && a<=720)
    {
        return "";
    }
    else if(a>=741 && a<=760)
    {
        return "";
    }
    else if(a>=761 && a<=780)
    {
        return "";
    }
    else if(a>=781 && a<=800)
    {
        return "";
    }
    else if(a>=801 && a<=820)
    {
        return "";
    }
    else if(a>=821 && a<=840)
    {
        return "";
    }
    else if(a>=841 && a<=860)
    {
        return "";
    }
    else if(a>=861 && a<=880)
    {
        return "";
    }
    else if(a>=881 && a<=896)
    {
        return "";
    }
}

int main()
{
    string a= "110";
    string b= "{1,0},{4,-2}";
    cout<<process(a, b)<<endl;
    return 0;
}
