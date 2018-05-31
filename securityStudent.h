#pragma once
#include <string>
class securityStudent : public Student{
public:
	securityStudent();
	securityStudent(
		std::string SID,
		std::string fname,
		std::string lname,
		std::string email,
		std::string age,
		int* courseCompletionDays,
		degreeList dt);
	~securityStudent();
	degreeList getDegreeProgram() const;
	void SetDegreeType(degreeList dt);
	void print();
};