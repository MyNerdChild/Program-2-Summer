//Using at least two structures and one enum (create a .h file and include it in your program)
//1.Store at least 3 different course data in a file with the following information: Course name, Course ID, Meeting Day(s), and Times along with Location (Building & Room).
//  The file should be structured with each course on a separate line and each data item separated by a comma.
//2.Allow the user to display all courses
//3.Allow the user to look up a specific course based on Course ID stored
//4.Allow the user to add new courses
//5.Allow the user to continue to look up and add courses until they choose to exit (using loops)

#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
#include "stuctEnum.h"

using namespace std;


ifstream input; //Declaration to open file and read in it
ofstream output; //Declaration to open file and write in it

int menu(); //Function to display menu
void Openfile(); //Function to open all files
void Closefile();//Function to close all files

//Menu Functions
void DisplayAll(Course); //Display all the course in the file
void Lookup(Course); //Looks up course ID an display the course information
void AddCourses(Course); //Add courses to file
void ClearData(); //Clear all data in file
void Exit(); //Exits program

int main()
{
    //Display Welcome Message
   cout << "Welcome to course manager!" << endl;
   //Call menu function
   menu();
}

//Menu Function
int menu()
{
   Course info; //Struct named Course, declaration for the calling of functions that use the struct
   int option; //Declaration for varible for user to choose option

   do
    {
        //Display menu
       cout << "\nPlease choose an option." << endl
            << "   1. Display all users courses" << endl
            << "   2. Look up course (Course ID)" << endl
            << "   3. Add new courses" << endl
            << "   4. Clear all data" << endl
            << "   5. Exit" << endl;

        cin >> option;

       switch (option)
        {
           case DISPLAY:
                DisplayAll(info); //Call Display Function
                break;
           case LOOKUP:
                Lookup(info); //Call Lookup Function
                break;
           case ADD:
                AddCourses(info); //Call AddCourses Function
                break;
           case CLEAR:
                ClearData(); //Call ClearData Function
                break;
           case EXIT:
                Exit(); //Call Exit Funtion
                break;
           default:
                cout << "The option is invalid, please try again." << endl; //Display message if user choose none of the options
                break;
        }
     }while(option != 4);

}

/***********************************************************************************************************************************************************************************/

//Function to open all files
void Openfile()
{
   input.open("input.dat");  //open file to read and get data
   output.open("input.dat", std::ofstream::out | std::ofstream::app); //open file to write in file, file will not be cleared when 'output' is used
}

//Function to close all files
void Closefile()
{
    //Close all files
    input.close();
    output.close();
}

//Display all the course in the file
void DisplayAll(Course info)  //Read and print files
{

    Openfile(); //Call Openfile Function

    string str; //Declaration of variable string

    //If file is open
    if(input.is_open())
    {
        //While in file
        while(input)
        {
            getline(input, str); //get line from file into variable str
            cout << str << endl; //print str and end line
        }
    }

    Closefile(); //Call Closefile Function
}

//Lookup Function
void Lookup(Course info) //Looks up course ID an display the course information
{
    Openfile(); //Call Openfile Function

    string gLID, gID, gNID; //Declaration of string, strings give from user to compare to file IDs
    bool TF; //Declaration to compare strings

    //Display Message
    cout << "Enter in Course ID(e.g., HIS 389): ";
    cin >> gLID >> gNID; //prompt user for Letter ID and Number ID

    gID = " " + gLID + " " + gNID + " "; //Combine Letter ID and Number ID to get given ID

    //while in file
    while(input)
        {
            //get line for structs until comma then go to next struct input
            getline(input, info.name, ',');
            getline(input, info.courseID, ',');
            getline(input, info.date, ',');
            getline(input, info.time, ',');
            getline(input, info.area.buildingAddr, ',');
            getline(input, info.area.roomNum);

            TF = gID == info.courseID ; //Comparing given ID to current courseID

            if(TF == true) //If the bool is true print out all the course information for that course ID
            {
                cout << info.name << ", " << info.courseID << ", " << info.date << ", " << info.time << ", "
                     << info.area.buildingAddr << ", " << info.area.roomNum << endl;
            }

        }
    //Display message of why there may be a blank screen if the IDs don't match
    cout << "\n*If no courses display any information then there was no course that had the same as the given ID.*\n";


    Closefile(); //Call Closefile Function
}

//AddCourses Function
void AddCourses(Course info) //Add courses to file
{
    Openfile(); //Call Openfile Function

    //Display message
    cout << "Please enter in your course information: \n";

    //Prompt for course name
    cout<< "Course Name: ";
    getline(cin >>ws, info.name);

    //Prompt for  course ID
    cout << "Course ID(e.g., HIS 389): ";
    getline(cin >> ws, info.courseID);

    //Prompt for days in class
    cout << "Day(e.g., MON or MON FRI): ";
    getline(cin >> ws, info.date);

    //Prompt for time class starts
    cout << "Class starting time(e.g., 10:30pm): ";
    getline(cin >> ws, info.time);

    //Prompt for building name
    cout << "Building(e.g., Art Building E): ";
    getline(cin >>ws, info.area.buildingAddr);

    //Prompt for room number
    cout << "Room number(e.g., 328): ";
    getline(cin >> ws, info.area.roomNum);

    //Write new information into file
    output << info.name << " , " << info.courseID << " , " << info.date << " , " << info.time << " , "
     << info.area.buildingAddr << " , Room: " << info.area.roomNum << endl;

     Closefile(); //Call Closefile Function
}

//ClearData Function
void ClearData()//Clear all data in file
{
    char answer;

    //Prompt message to clear data
    cout << "Would you like to clear the file content? Y/N: ";
    cin >> answer;

    if(answer == 'Y' || answer == 'y')
    {
        output.close(); //closes output file

        output.open("input.dat"); //open unsavable output file, when close it will clear all information
        output << ""; //Cleared information to make sure file is cleared
        output.close(); //close file

        //Display message
        cout << "Your file information has been cleared.\n\n" << endl;
        output.open("input.dat", std::ofstream::out | std::ofstream::app); //open file to write in file, file will don't be cleared when 'output' is used

    }
    else //if user do want to clear file
    {
        //Display message
        cout << "Your file information has been saved.\n\n" << endl;
    }

    menu(); //Call menu function
}

//Exit Function
void Exit()//Display goodbye message and exits program
{
    //Display Goodbye message
    cout << "GoodBye!";

    //Exit program
    exit(0);
}
