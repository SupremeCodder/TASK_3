//
// Created by user on 26.12.2022.
//

#ifndef TASK3_VISITOR_H
#define TASK3_VISITOR_H

# include <fstream>
# include <iostream>

class Mission;
class Lift;
class Dive;
class Move;
class Return;

# include "Mission.h"

class Visitor {
public:
    virtual void    doLift(Lift	&l) = 0;
    virtual void	doDive(Dive &d) = 0;
    virtual void	doMove(Move &m) = 0;
    virtual void	doReturn(Return &r) = 0;
};

class	FileWriter : public Visitor {
private:
    std::fstream	myFile;
    int	_cnt = 1;

public:
    FileWriter();
//	~FileWriter();

    void    doLift(Lift	&l) override;
    void	doDive(Dive &d) override;
    void	doMove(Move &m) override;
    void	doReturn(Return &r) override;
    void	writeToFile();

};

class	ConsoleWriter : public Visitor {
private:
    int	_cnt;
public:
//	ConsoleWriter();

    void    doLift(Lift	&l) override;
    void	doDive(Dive &d) override;
    void	doMove(Move &m) override;
    void	doReturn(Return &r) override;
    void	setCnt(int cnt);
    int		getCnt();
};

#endif //TASK3_VISITOR_H
