#include "model.h"
#include "view.h"

int main()
{
	Model model;
	View view;
	char c;
	pair<string,string> data;
	string s,r;
	bool result;

	do
	{
		view.present("\n\n\tMenu:\n\n");
		view.present("\t1.\tAdd to database\n");
		view.present("\t2.\tLookup\n");
		view.present("\t3.\tReverse lookup\n");
		view.present("\t4.\tDump database\n");
		view.present("\t5.\tDelete entry\n");
		view.present("\tq.\tQuit\n\n\t");

		do
		{
			c = view.getchar();
		} while (c == '\n');
		view.getchar(); // 161207 removed if stuck or double read
		view.present("\n");

		switch (c)
		{
		case '1': // Add
            view.present("Add, input key value [pair]: ");
            //model.write(view.getdata());
            if (model.write(view.getdata())){   // 161207 anders, changed to handle faults
                view.present("sucessfully added item.");
            } else {
                view.present("failed to add item.");
            }
			break;
		case '2': // Lookup
            view.present("Lookup, input key [string]: ");
            s=view.getstring();
            if ( model.get(s,r) )
                view.present( s + " " + r );
			break;
		case '3':  // Reverse Lookup
            view.present("Reverse Lookup, input value [string]: ");
            s=view.getstring();
            if ( model.search(s) ) {
                if ( model.next(data,s) ) {
                    view.present( (string)data.first + " " + (string)data.second );
            }
            }
			break;
		case '4':  // Dump
            view.present("Dump\n");
            model.dump();
            while ( model.next(data) ) {
                    view.present( (string)data.first + " " + (string)data.second );
            }

			break;
		case '5':  // Delete
            view.present("Delete, input key: ");
            s=view.getstring();
            if ( model.erase(s) ) {
                view.present("successfully erased");
            } else {
                view.present("failed to erase.");
            }

            break; // 161207 anders
		}
	} while (!((c == 'q') || (c == 'Q')));

	return 0;
}
