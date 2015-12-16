/*********************************************************************************************/
/*!
\file	Vec2D.h
\author Muhammad Nurhidayat Bin Suderman
\par	150576E@mymail.nyp.edu.sg
\brief
Vec2D is responsible for the coordinates of Dweller
*/
/*********************************************************************************************/
#ifndef VEC_2D_H
#define VEC_2D_H
/*********************************************************************************************/
/*!
Struct Vec2D:
\brief Vec2D is a struct that takes in position of the Dweller
*/
/*********************************************************************************************/
struct Vec2D
{
	double x;
	double y;

	Vec2D();
	Vec2D(double, double);
};

#endif