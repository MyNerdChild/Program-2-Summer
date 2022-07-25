#include <string>

//Example input:
//Computer Science 1 , CIS 201 , MON , 6pm , Zoom , Room: N/A
//Biology 2 , BIO 102 , THU , 10:50am , Buliding C , Room: 205
//History 1 , HIS 101 , Online , N/A , N/A , Room: N/A

enum OPTIONS
{
    DISPLAY=1,
    LOOKUP,
    ADD,
    CLEAR,
    EXIT
};

struct Location
{
    std::string buildingAddr; //Building Name
    std::string roomNum; //Class room number
};

struct Course
{
    std::string name; //Course Name
    std::string courseID; //Course ID HIS 293
    std::string date; //Days user will be in class
    std::string time; //Time user will be in class
    Location area; //Struct Location, declaration area

};


