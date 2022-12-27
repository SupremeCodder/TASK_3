//
// Created by user on 26.12.2022.
//

#ifndef TASK3_ROV_H
#define TASK3_ROV_H

# include "Mission.h"
# include <list>
# include <iostream>

#define MAX_X 10000
#define MAX_Y 10000
#define MAX_Z 100

class ROV
{
private:
    double x;
    double y;
    double z;

    std::list<Mission*>	_missions;

    Mission*	createMission(std::string missionType);
public:
    ROV(double x = 0, double y = 0, double z = 100);
    ~ROV();

    bool	addMission();
    bool	insertMission();
    bool	deleteMission();
    void	listMission();
    void	printPosition();
    std::list<Mission*>	&getMissions();
};
#endif //TASK3_ROV_H
