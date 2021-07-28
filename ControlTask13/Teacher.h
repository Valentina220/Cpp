// teacher.h
#pragma once
#include "human.h"
#include <string>
class teacher : public human {
	//  онструктор класса teacher
public:
	teacher(
		std::string last_name,
		std::string name,
		std::string second_name,
		//  оличество учебных часов за семестр у преподавател€
		unsigned int work_time
	) : human(
		last_name,
		name,
		second_name
	) {
		this->work_time = work_time;
	}
	// ѕолучение количества учебных часов
	unsigned int get_work_time()
	{
		return this->work_time;
	}

	virtual const char* profession()
	{
		return "Ётот человек работает преподавателем.";
	}

	/*virtual void profession()
	{
		human::profession();
		std::cout << "Ётот человек работает преподавателем." << std::endl;
	}*/
private:
	// ”чебные часы
	unsigned int work_time;
};
