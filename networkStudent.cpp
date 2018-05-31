#pragma once
#include "degree.h"
#include "Student.h"
#include "networkStudent.h"
#include <string>


networkStudent::networkStudent() {

}

networkStudent::networkStudent(
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
	degreeType = NETWORKING;
}

networkStudent::~networkStudent() {

}

degreeList networkStudent::getDegreeProgram() const {
	return NETWORKING;
}

void networkStudent::SetDegreeType(degreeList dt) {
	degreeType = dt;
}

void networkStudent::print() {
	this->Student::print();
	std::cout << "NETWORKING" << std::endl;
}