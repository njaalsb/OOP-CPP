#include "CourseCatalog.h"
#include <ostream>
#include <fstream>
#include <filesystem>

// BEGIN: 3a
void CourseCatalog::addCourse(const string& key, const string& value){
    CourseCatalog::courses.insert({key, value});
    string temp;
    temp = CourseCatalog::courses.at(key);
}
// END: 3a

// BEGIN: 3b
void CourseCatalog::removeCourse(const string& key){
    CourseCatalog::courses.erase(key);
}
// END: 3b

// BEGIN: 3c
string CourseCatalog::getCourse(const string& key) const{
    string temp;
    temp = CourseCatalog::courses.at(key);
    return temp;
}
// END: 3c

// BEGIN: 3d
ostream& operator<<(ostream& os, const CourseCatalog& cc){

    for(const auto&  lokke : cc.courses){
        os << lokke.first << ":" << lokke.second << endl;
    }
    return os;
}
// END: 3d

// BEGIN: 3e
void testCourseCatalog(){
    CourseCatalog cat;
    cat.addCourse("TDT4110","Informasjonsteknologi grunnkurs");
    cat.addCourse("TDT4102","Prosedyre- og objektorientert programmering");
    cat.addCourse("TMA4100","Matematikk 1");
    cout << cat;
}
// END: 3e

// BEGIN: 3g
void CourseCatalog::saveToFile(const std::string& filename) const{
    std::filesystem::path fileName{filename};
	std::ofstream outputStream{fileName}; 

    if(!outputStream){
        cout << "Klarte ikke å åpne filen" << endl;
    }

    outputStream << *this;
}
// END: 3g

// BEGIN: 3h
void CourseCatalog::loadFromFile(const std::string& filename){
    std::ifstream inputStream(filename);
    std::string nextLine;

    if (!inputStream) { 
        std::cout << "Fikk ikke aapnet filen " << filename << std::endl;
        return;
    }

    while (std::getline(inputStream, nextLine)) { 
        std::istringstream ss(nextLine);
        std::string key, value;

        if (std::getline(ss, key, ':') && std::getline(ss, value)) {
            addCourse(key, value);
            std::cout << " Key: " << key << " | Value: " << value << std::endl; 
        }
    }
    CourseCatalog::saveToFile("test.txt");
    inputStream.close();
}
// END: 3h