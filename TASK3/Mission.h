//
// Created by user on 26.12.2022.
//

#ifndef TASK3_MISSION_H
#define TASK3_MISSION_H

class Visitor;
class FileWriter;

# include "Visitor.h"

class	Mission {
public:
    virtual	std::string	returnTitle() = 0;
    virtual void	accept(Visitor &v) = 0;
};

class	Dive : public Mission {
public:
    void	accept(Visitor &v) override;
    std::string	returnTitle() override;
    void	setDepth(double d);
    double	getDepth();
private:
    std::string mis = "dive";
    double	z;
};

class	Lift : public Mission {
public:
    void	accept(Visitor &v) override;
    std::string	returnTitle() override;
    void	setDepth(double d);
    double	getDepth();

private:
    std::string mis = "lift";
    double	z;
};

class	Move : public Mission {
public:
    void	accept(Visitor &v) override;
    std::string	returnTitle() override;
    void	setCoord(double x, double y);
    double	getX();
    double	getY();
private:
    double	x;
    double	y;
};

class	Return : public Mission {
private:
    double	x = 0;
    double	y = 0;
    double	z = 100;
public:
    void	accept(Visitor &v) override;
    double	getX();
    double	getY();
    double	getZ();
    std::string	returnTitle() override;
};


#endif //TASK3_MISSION_H
