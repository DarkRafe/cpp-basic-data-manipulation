#pragma once
#include "degree.h"
#include "Student.h"
#include <string>
#include <vector>
class Roster {
public:
	void add_Student(std::string id, std::string fname, std::string lname, std::string email, std::string age, std::string day1, std::string day2, std::string day3, std::string degtype);
	void remove(std::string studentID);
	void printall();
	void printDaysInCourse(std::string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(degreeList degreeProgram);
	Roster();
	~Roster();
	std::vector<Student*> classRosterArray; 
};