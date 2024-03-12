#include <fstream>
#include <iosfwd>

void addStudentsDetails() {
    std::fstream file;

    file.open("student_info.csv", std::ios::out | std::ios::app);
}