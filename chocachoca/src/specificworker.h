/*
 *    Copyright (C) 2020 by YOUR NAME HERE
 *
 *    This file is part of RoboComp
 *
 *    RoboComp is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    RoboComp is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with RoboComp.  If not, see <http://www.gnu.org/licenses/>.
 */

/**
	\brief
	@author authorname
*/



#ifndef SPECIFICWORKER_H
#define SPECIFICWORKER_H

#include <map>
#include <genericworker.h>
#include <innermodel/innermodel.h>

class SpecificWorker : public GenericWorker
{
Q_OBJECT
const int HMIN=-2500, HMAX=2500, VMIN=-2500, VMAX=2500;
	struct vec{
		int v1;
		int v2;
	};
public:			
	SpecificWorker(MapPrx& mprx, bool startup_check);
	~SpecificWorker();
	bool setParams(RoboCompCommonBehavior::ParameterList params);



public slots:
	void compute();
	int startup_check();
	void initialize(int period);
	void initializeMatrix();
	void checkMatrix(int x, int z, float alpha);
	void turnMethod(RoboCompLaser::TLaserData ldata, float rot);
	void goAheadMethod();
	void checkDirection();
	
private:
	std::shared_ptr < InnerModel > innerModel;
	bool startup_check_flag;
	bool map[5000][5000];
	vec vecinos[9];
	int estado=0;

};

#endif
