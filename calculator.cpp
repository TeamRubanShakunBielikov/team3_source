#include "calculator.h"

Calculator::Calculator()
{

}

std::vector<std::vector<int>> Calculator::Parse_to_2x2(std::string arg)
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

std::vector<std::vector<int>> Calculator::Parse_to_3x3(std::string arg)
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

//Just remove common elements
std::string Calculator::addition_to_plural(std::string arg)
{
    std::string full="0123456789ABCDEF";

    for(int i=0;i<arg.size();++i)
    {
        full.erase(std::remove(full.begin(),full.end(),arg[i]),full.end());
    }

    return full;
}

//Mixed product must be 0
std::string Calculator::complanation(std::string arg)
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

//OPTIMIZE, PLS!!!!!
std::string Calculator::operations_wth_plurals(std::string arg)
{
    std::string A, B, Section, Union;

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

//Scalar product must be 0
std::string Calculator::orthogonality(std::string arg)
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

std::string Calculator::square_of_parallelegramm(std::string arg)
{
    std::vector<std::vector<int>> matrix = Parse_to_3x3(arg);


    int produce = (matrix[0][0]*matrix[1][0]) + (matrix[0][1]*matrix[1][1]);
    int len_a = sqrt(pow(matrix[0][0],2)+pow(matrix[0][1],2));
    int len_b = sqrt(pow(matrix[0][0],2)+pow(matrix[0][1],2));
    double temp = produce/(len_a*len_b);
    return std::to_string(static_cast<int>(len_a*len_b*sin(acos(temp))));
}

std::string Calculator::to_polar(std::string arg)
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

std::string Calculator::turn_point(std::string& arg)
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

std::string Calculator::volume_of_parallelepiped(std::string arg)
{
    std::vector<std::vector<int>> matrix = Parse_to_3x3(arg);


    int determ = (matrix[0][0]*matrix[1][1]*matrix[2][2]) + (matrix[0][1]*matrix[1][2]*matrix[2][0]) + (matrix[1][0]*matrix[0][2]*matrix[2][1])
            - (matrix[2][0]*matrix[1][1]*matrix[0][2]) - (matrix[0][1]*matrix[1][0]*matrix[2][2]) - (matrix[0][0]*matrix[1][2]*matrix[2][1]);

    return std::to_string(abs(determ));
}
