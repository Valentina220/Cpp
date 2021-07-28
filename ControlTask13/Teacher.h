// teacher.h
#pragma once
#include "human.h"
#include <string>
class teacher : public human {
	// ����������� ������ teacher
public:
	teacher(
		std::string last_name,
		std::string name,
		std::string second_name,
		// ���������� ������� ����� �� ������� � �������������
		unsigned int work_time
	) : human(
		last_name,
		name,
		second_name
	) {
		this->work_time = work_time;
	}
	// ��������� ���������� ������� �����
	unsigned int get_work_time()
	{
		return this->work_time;
	}

	virtual const char* profession()
	{
		return "���� ������� �������� ��������������.";
	}

	/*virtual void profession()
	{
		human::profession();
		std::cout << "���� ������� �������� ��������������." << std::endl;
	}*/
private:
	// ������� ����
	unsigned int work_time;
};
