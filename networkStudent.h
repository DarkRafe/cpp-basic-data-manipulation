#pragma once
#include <string>
class networkStudent : public Student{
public:
	networkStudent();
	networkStudent(
		std::string SID,
		std::string fname,
		std::string lname,
		std::string email,
		std::string age,
		int* courseCompletionDays,
		degreeList dt);
	~networkStudent();
	degreeList getDegreeProgram() const;
	void SetDegreeType(degreeList dt);
	void print();
};