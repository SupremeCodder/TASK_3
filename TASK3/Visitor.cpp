//
// Created by user on 26.12.2022.
//

#include "Visitor.h"

FileWriter::FileWriter()
{
    this->myFile.open("Mission.txt", std::ios::out);
    std::cout << "File is opened: " << myFile.is_open() << std::endl;
}

void	FileWriter::doLift(Lift &l) {
    this->myFile << "mission " << this->_cnt << ": Lift to z = " << l.getDepth() << std::endl;
    this->_cnt++;
}

void	FileWriter::doDive(Dive &d) {
    this->myFile << "mission " << this->_cnt << ": Dive to z = " << d.getDepth() << std::endl;
    this->_cnt++;
}

void 	FileWriter::doMove(Move &m) {
    this->myFile << "mission " << this->_cnt << ": Move to x = " << m.getX() << ", y = " << m.getY() << std::endl;
    this->_cnt++;
}

void	FileWriter::doReturn(Return &r) {
    this->myFile << "mission " << this->_cnt << ": Return to initial position and ending the mission: ";
    this->myFile << r.getX() << " " << r.getY() << " " << r.getZ() << std::endl;
    this->_cnt++;
}

void FileWriter::writeToFile() {
    this->myFile.flush();
}

void	ConsoleWriter::setCnt(int cnt) {
    this->_cnt = cnt;
}

int		ConsoleWriter::getCnt() {
    return (this->_cnt);
}

void	ConsoleWriter::doLift(Lift &l) {
    std::cout << "mission " << this->_cnt << ": Lift to z: " << l.getDepth() << std::endl;
    this->_cnt++;
}

void	ConsoleWriter::doDive(Dive &d) {
    std::cout << "mission " << this->_cnt << ": Dive to z: " << d.getDepth() << std::endl;
    this->_cnt++;
}

void 	ConsoleWriter::doMove(Move &m) {
    std::cout << "mission " << this->_cnt << ": Move to x: " << m.getX() << ", y: " << m.getY() << std::endl;
    this->_cnt++;
}

void	ConsoleWriter::doReturn(Return &r) {
    std::cout << "mission " << this->_cnt << ": Return to initial position and ending the mission: ";
    std::cout << r.getX() << " " << r.getY() << " " << r.getZ() << std::endl;
    this->_cnt++;
}