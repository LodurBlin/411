#ifndef CL_APP_H
#define CL_APP_H
#include "cl_base.h"

class cl_app : public cl_base
{
public:
	cl_app() : cl_base("") {};
	void derevo();
	void print() const { print_hierarchy(); };
};
#endif