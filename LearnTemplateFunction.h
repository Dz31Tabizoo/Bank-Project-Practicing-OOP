#pragma once
#include <iostream>




template<class T> 
class LearnTemplateFunction
{
private:

	T Number1, Number2;


///exemple Off classes
	template <typename R> T MayTemp(R X, R Y)
	{
		return (X > Y) ? X : Y;
	}

public:
	//constractor
	LearnTemplateFunction(T n1, T n2)
	{
		Number1 = n1;
		Number2 = n2;
	}

	T Add()
	{
		return Number1 + Number2;
	}

	T Subtruct()
	{
		return Number1 - Number2;
	}

	// defin objects
	// data type insade < > will replace T

	LearnTemplateFunction <int> OBJ1(12, 23);

	LearnTemplateFunction <float> OBJ2(12.4, 22, 5);
};

