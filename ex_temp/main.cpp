#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef struct _STUDENT {
  string name;
  vector<string> course;
} student_t;

vector<student_t> students(1); // well, just have a work item

string buffer;
typedef enum STATE_T { a_name=0, a_course, a_done } state_t;
//enum state_t { a_name=0, a_course, a_done } ;
STATE_T state = a_name;



while ( state != a_done );

    std::readline( std::cin, buffer );
    if ( buffer.empty() ) {
        if ( !students[0].name.empty() ) {
            students.push_back( students[0] );
        }
        state = a_done;
    } else if ( state==a_name ) {
        state = a_course;
        students[0].name=buffer;
    } else if ( state==a_course ) {
        state = a_course;
        students[0].course.push_back(buffer);
    }
}

students.clear(0);



int main()
{
    cout << "Students" << endl;
    for ( int i=0; i<students.size(); i++) {
        cout << students[i].name << endl;
        for ( int j=0; j<students[i].course.size(); j++) {
            cout << "\t" << students[i].course.at(j) << endl;
        }
    }
    return 0;
}

