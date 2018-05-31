#pragma once
#include "degree.h"
#include "softwareStudent.h"
#include "Student.h"
#include <string>
#include <iostream>

softwareStudent::softwareStudent() {

}

softwareStudent::softwareStudent(
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
	degreeType = SOFTWARE;
}

softwareStudent::~softwareStudent() {

}

degreeList softwareStudent::getDegreeProgram() const {
	return SOFTWARE;
}

void softwareStudent::SetDegreeType(degreeList dt) {
	degreeType = dt;
}

void softwareStudent::print() {
	this->Student::print();
	std::cout << "SOFTWARE" << std::endl;
}