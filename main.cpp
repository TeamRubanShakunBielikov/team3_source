#include <iostream>
#include <cmath>
#include<sstream>
#include <vector>
#include <algorithm>
#include <iomanip>

//PARSERS

std::vector<int> Parse_to_line(std::string arg)
{
    std::vector<int> line;
    std::string temp_s;
    for(int i =0;i<arg.length();++i)
    {
        int a=0;
        temp_s="";
        if(arg[i]>='0' && arg[i]<='9')
        {
            if(arg[i-1]=='-')
            {
                temp_s+=arg[i-1];
            }

            while(arg[i]>='0' && arg[i]<='9')
            {
                temp_s+=arg[i];
                i++;
            }
            a=stoi(temp_s);
            line.push_back(a);
        }
    }
    return line;
}

std::vector<std::vector<int>> Parse_to_2x4(std::string arg)
{
    std::vector<std::vector<int>> matrix;
    std::vector<int> temp;

    int jumper=0;
    for(int i=0; i<arg.length(); ++i)
    {
        std::string temp_s="";
        int a=0;
        if(arg[i]>='0' && arg[i]<='9')
        {
            if(arg[i-1]=='-')
            {
                temp_s+=arg[i-1];
            }

            while(arg[i]>='0' && arg[i]<='9')
            {
                temp_s+=arg[i];
                i++;
            }

            a=stoi(temp_s);

            if(jumper<4)
            {
                temp.push_back(a);
                jumper++;
            }
            else
            {
                matrix.push_back(temp);
                temp.erase(temp.begin(),temp.end());
                temp.shrink_to_fit();
                temp.push_back(a);
                jumper=1;
            }
        }
        else
        {
            if(i==arg.length()-1)
            {
                matrix.push_back(temp);
            }
            i++;
        }
    }
    return matrix;
}

std::vector<std::vector<int>> Parse_to_3x3(std::string arg)
{
    std::vector<std::vector<int>> matrix;
    std::vector<int> temp;

    std::string temp_s;
    int jumper=0;
    for(int i=0;i<arg.length();)
    {
        temp_s="";
        int a=0;
        if(arg[i]>='0' && arg[i]<='9')
        {
            if(arg[i-1]=='-')
            {
                temp_s+=arg[i-1];
            }

            while(arg[i]>='0' && arg[i]<='9')
            {
                temp_s+=arg[i];
                i++;
            }

            a = stoi(temp_s);

            if(jumper<3)
            {
                temp.push_back(a);
                jumper++;
            }
            else
            {
                matrix.push_back(temp);
                temp.erase(temp.begin(),temp.end());
                temp.shrink_to_fit();
                temp.push_back(a);
                jumper=1;
            }
        }
        else
        {
            if(i==arg.length()-1)
            {
                matrix.push_back(temp);
            }
            i++;
        }
    }
    return matrix;
}


std::vector<std::vector<int>> Parse_to_2x2(std::string arg)
{
    std::vector<std::vector<int>> matrix;
    std::vector<int> temp;

    int jumper=0;
    std::string temp_s;
    for(int i=0;i<arg.length();)
    {
        temp_s="";
        int a=0;
        if(arg[i]>='0' && arg[i]<='9')
        {
            if(arg[i-1]=='-')
            {
                temp_s+=arg[i-1];
            }

            while(arg[i]>='0' && arg[i]<='9')
            {
                temp_s+=arg[i];
                i++;
            }

            a=stoi(temp_s);

            if(jumper<2)
            {
                temp.push_back(a);
                jumper++;
            }
            else
            {
                matrix.push_back(temp);
                temp.erase(temp.begin(),temp.end());
                temp.shrink_to_fit();
                temp.push_back(a);
                jumper=1;
            }
        }

        else
        {
            if(i==arg.length()-1)
            {
                matrix.push_back(temp);
            }
            i++;
        }
    }
    return matrix;
}

std::string point_of_crossing(std::string arg)
{
//x:=((x1*y2-x2*y1)*(x4-x3)-(x3*y4-x4*y3)*(x2-x1))/((y1-y2)*(x4-x3)-(y3-y4)*(x2-x1));
//y:=((y3-y4)*x-(x3*y4-x4*y3))/(x4-x3);

//    (((x1<=x)and(x2>=x)and(x3<=x)and(x4>=x))or((y1<=y) and(y2>=y)and(y3<=y)and(y4>=y)))
    int x,y;
    std::vector<std::vector<int>> matrix = Parse_to_2x4(arg);
    x=((matrix[0][0]*matrix[0][3]-matrix[0][2]*matrix[0][1])*(matrix[1][2]-matrix[1][0])-(matrix[1][0]*matrix[1][3]-matrix[1][2]*matrix[1][1])*(matrix[0][2]-matrix[0][0]))/
      ((matrix[0][1]-matrix[0][3])*(matrix[1][2]-matrix[1][0])-(matrix[1][1]-matrix[1][3])*(matrix[0][2]-matrix[0][0]));
    y=(((matrix[1][1]-matrix[1][3])*x)-(matrix[1][0]*matrix[1][3]-matrix[1][2]*matrix[1][1]))/(matrix[1][2]-matrix[1][0]);

    if((matrix[0][1]<=x && matrix[0][2]>=x && matrix[1][0]<=x && matrix[1][2]>=x) || (matrix[0][1])<=y && matrix[0][3]>=y && matrix[1][1]<=y && matrix[1][3]>=y)
    {
        return "1";
    }
   return "0";
}

std::string exist_triangle(std::string arg)
{
    std::vector<int> line = Parse_to_line(arg);
    if(line[0]>line[1]+line[2])
    {
        return "0";
    }
    else if(line[1]>line[0]+line[2])
    {
        return "0";
    }
    else if(line[2]>line[0]+line[1])
    {
        return "0";
    }
    return "1";
}

//Scalar product must be 0
std::string orthogonality(std::string arg)
{
    std::vector<std::vector<int>> matrix=Parse_to_2x2(arg);

    int produce = (matrix[0][0]*matrix[1][0]) + (matrix[0][1]*matrix[1][1]);
    if(produce==0)
    {
        return "1";
    }
    else
    {
        return "0";
    }
}

std::string square_of_parellelegramm(std::string arg)
{
    std::vector<std::vector<int>> matrix = Parse_to_3x3(arg);

    int produce = (matrix[0][0]*matrix[1][0]) + (matrix[0][1]*matrix[1][1]);
    int len_a = sqrt(pow(matrix[0][0],2)+pow(matrix[0][1],2));
    int len_b = sqrt(pow(matrix[0][0],2)+pow(matrix[0][1],2));
    double temp = produce/(len_a*len_b);
    return std::to_string(static_cast<int>(len_a*len_b*sin(acos(temp))));
}

//Mixed product must be 0
std::string complanation(std::string arg)
{
    std::vector<std::vector<int>> matrix = Parse_to_3x3(arg);


    int determ = (matrix[0][0]*matrix[1][1]*matrix[2][2]) + (matrix[0][1]*matrix[1][2]*matrix[2][0]) + (matrix[1][0]*matrix[0][2]*matrix[2][1])
            - (matrix[2][0]*matrix[1][1]*matrix[0][2]) - (matrix[0][1]*matrix[1][0]*matrix[2][2]) - (matrix[0][0]*matrix[1][2]*matrix[2][1]);

    if(determ==0)
    {
        return "1";
    }
    else
    {
        return "0";
    }
}

std::string volume_of_parallelepiped(std::string arg)
{
    std::vector<std::vector<int>> matrix = Parse_to_3x3(arg);


    int determ = (matrix[0][0]*matrix[1][1]*matrix[2][2]) + (matrix[0][1]*matrix[1][2]*matrix[2][0]) + (matrix[1][0]*matrix[0][2]*matrix[2][1])
            - (matrix[2][0]*matrix[1][1]*matrix[0][2]) - (matrix[0][1]*matrix[1][0]*matrix[2][2]) - (matrix[0][0]*matrix[1][2]*matrix[2][1]);

    return std::to_string(abs(determ));
}


std::string addition_to_plural(std::string arg)
{
    std::string full="0123456789ABCDEF";

    for(int i=0;i<arg.size();++i)
    {
        full.erase(std::remove(full.begin(),full.end(),arg[i]),full.end());
    }

    return full;
}

//LOOK AT ME!!!!
//NEED TO OPTIMISATION!!!!!!!!!!
std::string operations_wth_plurals(std::string arg)
{
    std::string A, B, Section, Union, DiffA_B, DiffB_A;

    //PARSE
    size_t pos= arg.find(",");
    for(int i=0;i<arg.size();++i)
    {
        if(arg[i]!=',')
        {
            A.push_back(arg[i]);
        }
        else
        {
            B=arg.substr(pos+1);
            break;
        }
    }

    //UNION
    Union=A+B;

    for(int i = 0; i < Union.size(); i++)
    {
        int j = i+1;
        while (j<Union.size())
        {
            if(Union[i]==Union[j])
            {
                Union.erase(j,1);
            }
            else
            {
                j++;
            }
        }
    }

    //SECTION
    for(int i=0;i<A.size();++i)
    {
        for(int j=0;j<B.size();++j)
        {
            if(B[j]==A[i])
            {
                Section.push_back(B[j]);
            }
        }
    }

    //DiffA_B
    for(int i=0;i<A.size();++i)
    {
        for(int j=0;j<B.size();++j)
        {

            if(B[j]==A[i])
            {
                A.erase(std::remove(A.begin(),A.end(),A[i]),A.end());
            }
        }
    }

    //DiffB_A
    for(int i=0;i<B.size();++i)
    {
        for(int j=0;j<A.size();++j)
        {
            if(B[i]==A[j])
            {
                B.erase(std::remove(B.begin(),B.end(),B[i]),B.end());
            }
        }
    }

    return std::to_string(Union.size())+","+std::to_string(Section.size())+","+std::to_string(A.size())+","+std::to_string(B.size());
}

std::string to_polar(std::string arg)
{
    std::vector<double> Point;
#define PI 3.14159265

    //PARSE
    for(int i=0;i<arg.length();++i)
    {
        std::string temp_s="";
        int a=0;
        if(arg[i]>='0' && arg[i]<='9')
        {
            if(arg[i-1]=='-')
            {
                temp_s+=arg[i-1];
            }

            while(arg[i]>='0' && arg[i]<='9')
            {
                temp_s+=arg[i];
                i++;
            }

            a = stoi(temp_s);

            Point.push_back(a);
        }
    }

    std::stringstream stream, stream1;
    stream << std::fixed << std::setprecision(2) << sqrt(pow(Point[0],2)+pow(Point[1],2));
    stream1 << std::fixed << std::setprecision(2) << atan(Point[1]/Point[0])*180/PI;
    std::string temp = stream.str();
    temp+=","+stream1.str();
    return temp;
}

std::string turn_point(std::string& arg)
{
#define PI 3.14159265
    arg+=",as100as";
    std::vector<std::vector<int>> matrix=Parse_to_2x2(arg);

    std::stringstream stream, stream1;
    stream << std::fixed <<std::setprecision(2) << ( (matrix[0][0]*cos(matrix[1][0]*(PI/180))) - (matrix[0][1]*sin(matrix[1][0]*(PI/180))) );
    stream1 << std::fixed <<std::setprecision(2) << ( (matrix[0][0]*sin(matrix[1][0]*(PI/180))) + (matrix[0][1]*cos(matrix[1][0]*(PI/180))) );
    std::string temp = stream.str();
    temp+=","+stream1.str();
    return temp;
}


std::string process(std::string id, std::string arg)
{
    int _id=stoi(id);

    if(_id<1 || _id>896)
    {
        return "";
    }
    else if(_id>=1 && _id<=40)
    {
        return "";
    }
    else if(_id>=41 && _id<=60)
    {
        return "";
    }
    else if(_id>=61 && _id<=80)
    {
        return "";
    }
    else if(_id>=81 && _id<=100)
    {
        return exist_triangle(arg);
    }
    else if(_id>=101 && _id<=120)
    {
        return orthogonality(arg);
    }
    else if(_id>=121 && _id<=140)
    {
        return complanation(arg);
    }
    else if(_id>=141 && _id<=160)
    {
        return volume_of_parallelepiped(arg);
    }
    else if(_id>=161 && _id<=180)
    {
        return square_of_parellelegramm(arg);
    }
    else if(_id>=181 && _id<=200)
    {
        return "";
    }
    else if(_id>=201 && _id<=220)
    {
        return "";
    }
    else if(_id>=221 && _id<=240)
    {
        return addition_to_plural(arg);
    }
    else if(_id>=241 && _id<=260)
    {
        return operations_wth_plurals(arg);
    }
    else if(_id>=261 && _id<=280)
    {
        return to_polar(arg);
    }
    else if(_id>=281 && _id<=300)
    {
        return turn_point(arg);
    }
    else if(_id>=301 && _id<=320)
    {
        return "";
    }
    else if(_id>=321 && _id<=340)
    {
        return "";
    }
    else if(_id>=341 && _id<=360)
    {
        return "";
    }
    else if(_id>=361 && _id<=380)
    {
        //DOESN'T WORK WITH PARALLEL SEGMENTS
        return point_of_crossing(arg);
    }
    else if(_id>=381 && _id<=400)
    {
        return "";
    }
    else if(_id>=401 && _id<=420)
    {
        return "";
    }
    else if(_id>=421 && _id<=440)
    {
        return "";
    }
    else if(_id>=441 && _id<=460)
    {
        return "";
    }
    else if(_id>=461 && _id<=480)
    {
        return "";
    }
    else if(_id>=481 && _id<=500)
    {
        return "";
    }
    else if(_id>=501 && _id<=520)
    {
        return "";
    }
    else if(_id>=521 && _id<=540)
    {
        return "";
    }
    else if(_id>=541 && _id<=560)
    {
        return "";
    }
    else if(_id>=561 && _id<=580)
    {
        return "";
    }
    else if(_id>=581 && _id<=600)
    {
        return "";
    }
    else if(_id>=601 && _id<=620)
    {
        return "";
    }
    else if(_id>=621 && _id<=640)
    {
        return "";
    }
    else if(_id>=641 && _id<=660)
    {
        return "";
    }
    else if(_id>=661 && _id<=680)
    {
        return "";
    }
    else if(_id>=681 && _id<=700)
    {
        return "";
    }
    else if(_id>=701 && _id<=720)
    {
        return "";
    }
    else if(_id>=741 && _id<=760)
    {
        return "";
    }
    else if(_id>=761 && _id<=780)
    {
        return "";
    }
    else if(_id>=781 && _id<=800)
    {
        return "";
    }
    else if(_id>=801 && _id<=820)
    {
        return "";
    }
    else if(_id>=821 && _id<=840)
    {
        return "";
    }
    else if(_id>=841 && _id<=860)
    {
        return "";
    }
    else if(_id>=861 && _id<=880)
    {
        return "";
    }
    else if(_id>=881 && _id<=896)
    {
        return "";
    }
}

int main()
{
    //FOR ORTHOGONALITY
    std::string a= "110";
    std::string b= "{1,2},{2,-1}";

    //FOR SQUARE OF PARALLELEGRAMM
    std::string a1= "175";
    std::string b1= "{0,1},{1,5}";

    //FOR COMPLANATION
    std::string c="130";
    std::string d="{1,1,1},{1,3,1},{2,2,2}";

    //FOR VOLUME OF PARALELEPIPED
    std::string c1="141";
    std::string d1="{19,-4,17},{-5,11,-9},{14,-2,19}";

    //FOR ADDIRIONAL TO PLURAL
    std::string a2="230";
    std::string b2="579ABCE";

    //FOR COUNT IN UNION, SECTION, DIFFERENCE
    std::string a3="250";
    std::string b3="05A,7C";

    //FOR TO POLAR
    std::string a4="270";
    std::string b4="20,15";

    //FOR TURNING OF A POINT
    std::string a5="290";
    std::string b5="{4,0},90";

    //FOR EXISTING TRIANGLE
    std::string a6="85";
    std::string b6="20,10,5";

    //FOR POINT OF CROSSING
    std::string a7="362";
    std::string b7="{3,7},{4,-8},{1,9},{15,-4}";

    std::cout<<process(a7, b7)<<std::endl;
    return 0;
}
