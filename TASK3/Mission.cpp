//
// Created by user on 26.12.2022.
//

#include "Mission.h"

std::string	Dive::returnTitle() {
    return ("dive");
}

double	Dive::getDepth() {
    return (this->z);
}

void	Dive::setDepth(double temp) {
    this->z = temp;
}

void	Dive::accept(Visitor &v) {
    v.doDive(*this);
}

std::string	Lift::returnTitle() {
    return ("lift");
}

double	Lift::getDepth() {
    return (this->z);
}

void	Lift::setDepth(double d) {
    this->z = d;
}

void	Lift::accept(Visitor &v) {
    v.doLift(*this);
}

std::string Move::returnTitle() {
    return ("move");
}

double	Move::getX() {
    return (this->x);
}

double	Move::getY() {
    return (this->y);
}

void	Move::setCoord(double buff_x, double buff_y) {
    this->x = buff_x;
    this->y = buff_y;
}

void	Move::accept(Visitor &v) {
    v.doMove(*this);
}

std::string Return::returnTitle() {
    return ("return");
}

void Return::accept(Visitor &v) {
    v.doReturn(*this);
}

void Return::setInit(double x, double y, double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

double	Return::getX() {
    return (this->x);
}

double	Return::getY() {
    return (this->y);
}

double	Return::getZ() {
    return (this->z);
}