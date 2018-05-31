#pragma once
#include "degree.h"
#include "Student.h"
#include <string>
class softwareStudent : public Student{
public:
	softwareStudent();
	softwareStudent(
		std::string SID,
		std::string fname,
		std::string lname,
		std::string email,
		std::string age,
		int* courseCompletionDays,
		degreeList dt);
	~softwareStudent();
	degreeList getDegreeProgram() const;
	void SetDegreeType(degreeList dt);
	void print();
};