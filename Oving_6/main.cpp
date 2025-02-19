#include "std_lib_facilities.h"
#include "CourseCatalog.h"
#include "FileUtils.h"
#include "bouncingBall.h"

int main()
{
	CourseCatalog c;
	int var;
	string var2;
	while(1){
		cout << endl;
		cout << "Velg hvilken kode du onsker aa teste" << endl;
		cin >> var;
		switch (var)
		{
		case 0:
			writeUserInputToFile("myFile.txt");
			break;
		case 1:
			addLineNumbers("myFilse.txt");
			break;
		case 2:
			c.addCourse("IFYT", "fysikk");
			c.addCourse("IMAT", "matte");
			c.addCourse("ESDI", "Systemdesign");
			break;
		case 3:
			var2 = c.getCourse("hei");
			cout << var2 << endl;
			break;

		case 4:
			cout << c;
			break;
		case 5:
			testCourseCatalog();
			break;
		case 6:
			c.saveToFile("myFile.txt");
			break;
		case 7:
			c.loadFromFile("myFile.txt");
			break;
		case 8:
			c.loadFromFile("myFile.txt");
			break;
		default:
			return 0;
		}
	}	
	return 0;
}