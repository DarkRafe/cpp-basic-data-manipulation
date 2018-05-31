#pragma once
#include "degree.h"
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
class Student {
public:
	std::string GetFirstName()const;
	void SetFirstName(std::string fname);
	std::string GetLastName()const;
	void SetLastName(std::string lname);
	std::string GetStudentId() const;
	void SetStudentId(std::string id);
	std::string GetEmailAddress()const;
	void SetEmailAddress(std::string email);
	std::string GetStudentAge()const;
	void SetStudentAge(std::string age);
	int* GetCourseCompletionDays()const;
	void SetCourseCompletionDays(int* days);
	virtual degreeList getDegreeProgram();
	virtual void SetDegreeType(degreeList dt);
	virtual void print() = 0;
	Student();
	Student(std::string id, std::string fname, std::string lname, std::string email, std::string age, int * days);
	~Student();
	std::string studentId;
	std::string firstName;
	std::string lastName;
	std::string emailAddress;
	std::string studentAge;
	int* courseCompletionDays;
	degreeList degreeType;
};