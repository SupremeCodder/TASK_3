//
// Created by user on 26.12.2022.
//

#include "ROV.h"

ROV::ROV()
{
    x = 0;
    y = 0;
    z = 100;
}

ROV::~ROV() = default;

std::list<Mission *> &ROV::getMissions()
{
    return (this->_missions);
}

//В подпрограмме выделяется динамическая память под новую миссию
Mission *ROV::createMission(std::string missionType)
{
    if (missionType == "dive")
    {
        Dive	*dive;
        double	buff_z;

        //ввод требуемой глубины аппарата
        std::cout << "Enter z: " << std::endl;
        std::cin >> buff_z;

        if (this->z < buff_z)
        {
            std::cout << "Use mission /lift/ instead" << std::endl;
            return (nullptr);
        }


        //проверка условий 0 < z < 100
        if (buff_z < 0 || buff_z > MAX_Z)
        {
            std::cout << "Incorrect data" << std::endl;
            return (nullptr);
        }
        else
        {
            std::cout << "Added new mission" << std::endl;
            dive = new Dive();

            dive->setDepth(buff_z);
            this->z = buff_z;
            return (dive);
        }
    }
    else if (missionType == "lift")
    {
        Lift	*lift;
        double	buff_z;

        //ввод требуемой глубины аппарата
        std::cout << "Enter z: " << std::endl;
        std::cin >> buff_z;

        if (this->z > buff_z)
        {
            std::cout << "Use mission /dive/ instead" << std::endl;
            return (nullptr);
        }

        //проверка условий 0 < z < 100
        if ( buff_z < 0 || buff_z > MAX_Z)
        {
            std::cout << "Wrong input. No mission is added." << std::endl;
            return (nullptr);
        }
        else
        {
            std::cout << "Added new mission" << std::endl;
            lift = new Lift();

            lift->setDepth(buff_z);
            this->z = buff_z;

            return (lift);
        }
    }
    else if (missionType == "move") {
        Move	*move;
        double buff_x;
        double buff_y;

        //ввод требуемых (x,y) аппарата
        std::cout << "Enter x: " << std::endl;
        std::cin >> buff_x;
        std::cout << "Enter y: " << std::endl;
        std::cin >> buff_y;

        if (buff_x < 0 || buff_y < 0 || buff_x > MAX_X || buff_y > MAX_Y) {
            std::cout << "Incorrect data" << std::endl;
            return (nullptr);
        }
        else {
            std::cout << "Added new mission" << std::endl;
            move = new Move();
            move->setCoord(buff_x, buff_y);
            this->x = buff_x;
            this->y = buff_y;
            return (move);
        }
    }
    else if (missionType == "return")
    {
        Return	*ret;

        ret = new Return();
        std::cout << "Returning to initial point..." << std::endl;
        return (ret);
    }
    else {
        std::cout << "Mission type input incorrect. No mission is added." << std::endl;
        return (nullptr);
    }
}

bool ROV::addMission()
{
    Mission	*mission;
    std::string	missionType;

    std::cout << "Enter your mission" << std::endl;
    std::cin >> missionType;

    mission = this->createMission(missionType);

    if (mission != nullptr)
    {
        this->_missions.push_back(mission);
        return (true);
    }
    return (false);
}

bool	ROV::insertMission()
{
    Mission	*mission;
    std::string	missionType;
    int	id;

    std::cout << "Enter mission pos to insert" << std::endl;
    std::cin >> id;
    if (id <= 0 || id > this->_missions.size()) {
        std::cout << "Incorrect data" << std::endl;
        return (false);
    }
    std::cout << "Enter your mission" << std::endl;
    std::cin >> missionType;
    mission = this->createMission(missionType);
    if (missionType == "return")
    {
        std::cout << "Can't insert Return mission. Make it with command Add" << std::endl;
        return (false);
    }
    else {
        auto it = this->_missions.begin();
        for (int i = 1; i < id; ++i) {
            it++;
        }
        this->_missions.insert(it, mission);
        return (true);
    }
}

bool	ROV::deleteMission() {
    int	id;

    std::cout << "Enter mission pos to delete" << std::endl;
    std::cin >> id;
    if (id <= 0 || id > this->_missions.size()) {
        std::cout << "Incorrect position" << std::endl;
        return (false);
    }
    else {
        auto it = this->_missions.begin();
        for (int i = 1; i < id; ++i) {
            it++;
        }
        this->_missions.erase(it);
        std::cout << "Mission in pos " << id << " is deleted" << std::endl;
        return (true);
    }
}


void ROV::listMission()
{
    Mission	*output;
    ConsoleWriter	writer;

    writer.setCnt(1);

    if (this->_missions.empty())
    {
        std::cout << "No missions entered" << std::endl;
        return;
    }
    else
    for (auto it = this->getMissions().begin(); it != this->getMissions().end(); ++it) {
        output = *it;
        output->accept(writer);
    }
}

void ROV::printPosition() const {
    std::cout << "ROV z: " << this->z << ", x: " << this->x << ", y: " << this->y << std::endl;
}

void ROV::help()
{
    std::cout << "-------------------------------------------------" << std::endl;
    std::cout << "Commands list:" << std::endl;
    std::cout << "add - add new mission" << std::endl;
    std::cout << "del - removes a mission in position" << std::endl;
    std::cout << "insert - inserts mission in position" << std::endl;
    std::cout << "list - prints all missions" << std::endl;
    std::cout << "pos - prints position of ROV" << std::endl;
    std::cout << "help - prints possible commands and missions" << std::endl;
    std::cout << "-------------------------------------------------" << std::endl;
    std::cout << "Mission list:" << std::endl;
    std::cout << "dive - moves ROV to z point" << std::endl;
    std::cout << "lift - moves ROV to z point" << std::endl;
    std::cout << "move - moves ROV to (x,y) point" << std::endl;
    std::cout << "return - moves ROV to initial point" << std::endl;
    std::cout << "-------------------------------------------------" << std::endl;
}