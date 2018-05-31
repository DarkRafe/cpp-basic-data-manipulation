#pragma once
#include "roster.h"
#include "networkStudent.h"
#include "securityStudent.h"
#include "softwareStudent.h"
#include<string>
#include<iostream>
#include<sstream>
#include<vector>

int main(int argc, char** argv) {
	std::string const  studentData[] =
	{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Derik,Wolz,derikwolz@gmail.com,36,6,7,20,SOFTWARE"
	};
	std::cout << "C867 Scripting and Programming" << std::endl;
	std::cout << "using C++" << std::endl;
	std::cout << "820472" << std::endl;
	std::cout << "Derik Wolz" << std::endl << std::flush;
	Roster MyRoster;
	for (int i = 0; i < 5; ++i) {
		std::string id, fname, lname, email, age, day1, day2, day3, degtype = { "" };
		std::vector<int> days(3);
		std::istringstream sss(studentData[i]);
		std::getline(sss, id, ',');
		std::getline(sss, fname, ',');
		std::getline(sss, lname, ',');
		std::getline(sss, email, ',');
		std::getline(sss, age, ',');
		std::getline(sss, day1, ',');
		std::getline(sss, day2, ',');
		std::getline(sss, day3, ',');
		std::getline(sss, degtype, ',');
		MyRoster.add_Student(id, fname, lname, email, age, day1, day2, day3, degtype);
	}
	MyRoster.printall();
	MyRoster.printInvalidEmails();
	for (unsigned int i = 0; i < (MyRoster.classRosterArray.size()); i++) {
		MyRoster.printDaysInCourse(MyRoster.classRosterArray.at(i)->GetStudentId());
	}
	MyRoster.printByDegreeProgram(SOFTWARE);
	MyRoster.remove("A3");
	MyRoster.remove("A3");
	std::cout << "Main : End" << std::endl;
}

void Roster::add_Student(std::string id, std::string fname, std::string lname, std::string email, std::string age, std::string day1, std::string day2, std::string day3, std::string degtype) {
	int days[3];
	days[0] = stoi(day1);
	days[1] = stoi(day2);
	days[2] = stoi(day3);

	if (degtype == "NETWORK")
		this->classRosterArray.push_back(new networkStudent(id, fname, lname, email, age, days, NETWORKING));
	if (degtype == "SOFTWARE")
		this->classRosterArray.push_back(new softwareStudent(id, fname, lname, email, age, days, SOFTWARE));
	if (degtype == "SECURITY")
		this->classRosterArray.push_back(new securityStudent(id, fname, lname, email, age, days, SECURITY));
	return;
}

void Roster::remove(std::string studentID) {
	for (unsigned int i = 0; i < this->classRosterArray.size(); i++) {
		if (this->classRosterArray[i]->GetStudentId() == studentID) {

			std::cout << "Removing " << classRosterArray[i]->GetFirstName() << " " <<
				classRosterArray[i]->GetLastName() << " from array" << std::endl;
			delete this->classRosterArray[i];
			this->classRosterArray[i] = nullptr;
			this->classRosterArray.erase(this->classRosterArray.begin() + i); 
			return;
		}
	}
	std::cout << "A Student with ID: " << studentID << " was not found." << std::endl;
}

void Roster::printall() {
	for (unsigned int i = 0; i < this->classRosterArray.size(); ++i) {
		classRosterArray[i]->print();
	}
}

void Roster::printDaysInCourse(std::string studentID) { 
	for (unsigned int i = 0; i < this->classRosterArray.size(); ++i) {
		if (this->classRosterArray[i]->GetStudentId() == studentID) {
			int* days = classRosterArray[i]->GetCourseCompletionDays();
			double temp = (static_cast<double>(days[0]) +
				static_cast<double>(days[1]) +
				static_cast<double>(days[2])) / 3;
			std::cout << temp << std::endl;
		}
	}
}

void Roster::printInvalidEmails() {
	for (unsigned int i = 0; i < this->classRosterArray.size(); i++) {
		if ((this->classRosterArray[i]->GetEmailAddress().find(' ') != std::string::npos) ||
			(this->classRosterArray[i]->GetEmailAddress().find('@') == std::string::npos) || 
			(this->classRosterArray[i]->GetEmailAddress().find('.') == std::string::npos))
			std::cout << this->classRosterArray[i]->GetEmailAddress() << std::endl;
	}
	//Note: per my instructions, A valid email should include an at sign ('@') and period ('.') and should not include a space (' ').
	//ordinarily a regular expression comparison would be used, but this was required
}

void Roster::printByDegreeProgram(degreeList degreeProgram) {
	for (unsigned int i = 0; i < this->classRosterArray.size(); ++i) {
		if (this->classRosterArray[i]->getDegreeProgram() == degreeProgram) {
			this->classRosterArray[i]->print();
		}
	}
}

Roster::Roster() {

}


Roster::~Roster() {
	std::cout << "Roster is destroyed" << std::endl;
}