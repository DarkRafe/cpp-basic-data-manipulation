#pragma once
#include "degree.h"
#include "Student.h"
#include "securityStudent.h"
#include <string>
securityStudent::securityStudent() {

}

securityStudent::securityStudent(
	std::string SID,
	std::string fname,
	std::string lname,
	std::string email,
	std::string age,
	int* days,
	degreeList dt) {
	studentId = SID;
	firstName = fname;
	lastName = lname;
	emailAddress = email;
	studentAge = age;
	courseCompletionDays = new int[3];
	for (int i = 0; i < 3; i++) {
		courseCompletionDays[i] = days[i];
	}
	degreeType = SECURITY;
}

securityStudent::~securityStudent() {

}

degreeList securityStudent::getDegreeProgram() const {
	return SECURITY;
}

void securityStudent::SetDegreeType(degreeList dt) {
	degreeType = dt;
}

void securityStudent::print() {
	this->Student::print();
	std::cout << "SECURITY" << std::endl;
}