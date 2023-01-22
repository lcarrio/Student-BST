#include <string>
#include <vector>
#include "student_db.h"
#include <cmath>

namespace cop3530 {

student_info::student_info() {}
student_info::student_info(std::string name, double gpa): name(name), gpa(gpa) {}

std::string student_info::get_name() const {
    return name;
}

double student_info::get_gpa() const {
    return gpa;
}

bool student_info::operator==(const student_info &other) const {
   return name == other.name && std::abs(gpa-other.gpa) < 0.000000001;
}

student_db::student_db() {

}

student_db::~student_db() {

}

void student_db::insert(const int student_id, const std::string &student_name, const double gpa) {
    student_info s(student_name,gpa);
    studentTree.insert(student_id,s);
}

void student_db::erase(const int student_id) {
    studentTree.erase(student_id);
}

student_info& student_db::lookup(const int student_id) {
    return(studentTree.at(student_id));
}

bool student_db::empty() const {
    return studentTree.empty();
}

size_t student_db::size() const {
    return studentTree.size();
}

std::vector<std::pair<int, student_info>> student_db::get_all_students() {
    return studentTree.inorder_contents();
}

}
