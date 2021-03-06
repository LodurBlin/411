#ifndef CL_BASE_H
#define CL_BASE_H
#include <string>
#include <vector>
#include <memory>

class cl_base {
	std::string ob_name; //наименование
public:
	cl_base* p_predok{}; //указатель на головной об.
	std::vector<std::unique_ptr<cl_base>> spinogrizi; //массив указателей на подчиненных
	cl_base(std::string name, cl_base* p_predok = 0) : ob_name{ name }, p_predok{ p_predok } {}; //парам. конструктор с указ.  на  головной объект и имя объекта (имеет знач по умолч)

	void set_name(std::string name) { //определение имени
		ob_name = name;
	}
	std::string get_name() const { //получение имени
		return ob_name;
	}
	void add_spinogriz(std::unique_ptr<cl_base>&&); //добавление потомка в иерархию

	void print_hierarchy() const; //вывод наим об.

	cl_base* kto_otez();//получение указателя на головной объект

	void detdom(cl_base*); //переопределение головного объекта


};
#endif
