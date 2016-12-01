// title: excersise vector of students
// revision:
//  2016-12-01 Anders, created

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// define a structure for a student, including a vector of course names
typedef struct _STUDENT
{
    string name;
    vector<string> course;
} student_t;

// define states for an input state machine
typedef enum STATE_T { a_idle=0, a_class=1, a_student=2, a_name=3,
                       a_course=4, a_done=5
                     } state_t;
//enum state_t { a_name, a_course, a_done } ;
state_t state = a_idle;




int main()
{
    vector<student_t> students(1); // well, just have a work item

    string buffer;
    unsigned int i,j;


    while ( state != a_done )
    {

        cout <<"["<<state<<"] ";
        cout.flush();
        std::getline( std::cin, buffer );
        //if ( buffer.empty() )
        if ( cin.fail() || cin.eof() ) { state=a_done; }
        if ( buffer.find("<class>")<buffer.size() )
        {
            state = a_student;
        }
        else if ( buffer.find("<student>")<buffer.size() )
        {
            state = a_name;
        }
        else if ( buffer.find("</student>")<buffer.size() )
        {
            if ( !students[0].name.empty() )
            {
                students.push_back( students[0] );
                // create a new empty element, not efficient
                //students.insert(students.begin(),1,student);
            }
            students[0].name="";
            students[0].course.clear();
            state = a_class;
        }
        else if ( buffer.find("</class>")<buffer.size() )
            state = a_done;
        //else if ( buffer.find("<course>") )
        //    state = a_course;
        else if ( state==a_name && !buffer.empty())
        {
            buffer.erase(buffer.find("<name>"),6);
            buffer.erase(buffer.find("</name>"),7);
            students[0].name.assign(buffer);
            state = a_course;
        }
        else if ( state==a_course && !buffer.empty() )
        {
            buffer.erase(buffer.find("<course>"),8);
            buffer.erase(buffer.find("</course>"),9);
            students[0].course.push_back(buffer);
            state = a_course;
        }

    }

    students.erase(students.begin());
    //students.erase(students.begin(),students.end());
   // students.erase(students.begin(),students.begin()+1);


    cout << "Students" << endl;
    for ( i=0; i<students.size(); i++)
    {
        cout << "Name : " << students[i].name << endl;
        for ( j=0; j<students[i].course.size(); j++)
        {
            cout << "\t" << students[i].course.at(j) << endl;
        }
    }
    cin.clear();
    cin>>i;
    return 0;
}


