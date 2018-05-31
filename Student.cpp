#pragma once
#include "Student.h"
#include<string>

std::string Student::GetFirstName()const {
	return this->firstName;
}

void Student::SetFirstName(std::string fname) {
	this->firstName = fname;
}

std::string Student::GetLastName()const {
	return this->lastName;
}

void Student::SetLastName(std::string lname) {
	this->lastName = lname;
}

std::string Student::GetStudentId() const {
	return this->studentId;
}

void Student::SetStudentId(std::string id) {
	this->studentId = id;
}

std::string Student::GetEmailAddress()const {
	return this->emailAddress;
}

void Student::SetEmailAddress(std::string email) {
	this->emailAddress = email;
}

std::string Student::GetStudentAge()const {
	return this->studentAge;
}

void Student::SetStudentAge(std::string age) {
	this->studentAge = age;
}

int* Student::GetCourseCompletionDays()const {
	return this->courseCompletionDays;
}

void Student::SetCourseCompletionDays(int* days) {
	if (this->courseCompletionDays != nullptr) {
		delete this->courseCompletionDays;
		this->courseCompletionDays = nullptr;
	}
	int newarray[3] = { 0 };
	for (int i = 0; i < 3; i++) {
		newarray[i] = days[i];
	}
	this->courseCompletionDays = newarray;
}

degreeList Student::getDegreeProgram() {
	return this->degreeType;
}

void Student::SetDegreeType(degreeList dt){

}

Student::Student() {

};

Student::Student(std::string id, std::string fname, std::string lname, std::string email, std::string age, int* days) {

};

Student::~Student() {
	delete[] courseCompletionDays;
	courseCompletionDays = nullptr;
	std::cout << "courseCompletionDays deleted" << std::endl;
}

void Student::print() {
	std::cout << GetStudentId()[1] << "\tFirstName: " << GetFirstName();
	std::cout << "\tLast Name: " << GetLastName() << "\tAge: " << GetStudentAge() << "\tdaysInCourse: " << std::flush;
	int* temp = this->GetCourseCompletionDays();
	std::cout << temp[0] << ", " << temp[1] << ", " << temp[2] << " ";
}