#include <iostream>
#include <string>
#include "calculator.h"

//PARSERS

std::string process(std::string id, std::string arg)
{
    Calculator Tor;
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
        return "";
    }
    else if(_id>=101 && _id<=120)
    {
        return Tor.orthogonality(arg);
    }
    else if(_id>=121 && _id<=140)
    {
        return Tor.complanation(arg);
    }
    else if(_id>=141 && _id<=160)
    {
        return Tor.volume_of_parallelepiped(arg);
    }
    else if(_id>=161 && _id<=180)
    {
        return Tor.square_of_parallelegramm(arg);
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
        return Tor.addition_to_plural(arg);
    }
    else if(_id>=241 && _id<=260)
    {
        //LOOK AT ME!!!!
        //NEED TO OPTIMIZATION!!!!!!!!!!
        return Tor.operations_wth_plurals(arg);
    }
    else if(_id>=261 && _id<=280)
    {
        //PARSER NEED TO OPTIMIZATION!!!!!!
        return Tor.to_polar(arg);
    }
    else if(_id>=281 && _id<=300)
    {
        //PARSER NEED TO OPTIMIZATION!!!!!!
        return Tor.turn_point(arg);
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
        return "";
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

    std::cout<<process(a5, b5)<<std::endl;
    return 0;
}
