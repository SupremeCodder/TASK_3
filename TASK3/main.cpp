#include <iostream>
#include "ROV.h"

int main() {
    std::cout << "-------------------------------------------------" << std::endl;
    std::cout << "Commands list:" << std::endl;
    std::cout << "add - add new mission" << std::endl;
    std::cout << "del - removes a mission in position" << std::endl;
    std::cout << "insert - inserts mission in position" << std::endl;
    std::cout << "list - prints all missions" << std::endl;
    std::cout << "pos - prints position of ROV" << std::endl;
    std::cout << "-------------------------------------------------" << std::endl;
    std::cout << "Mission list:" << std::endl;
    std::cout << "dive - moves ROV to z point" << std::endl;
    std::cout << "lift - moves ROV to z point" << std::endl;
    std::cout << "move - moves ROV to (x,y) point" << std::endl;
    std::cout << "return - moves ROV to initial point" << std::endl;
    std::cout << "-------------------------------------------------" << std::endl;

    ROV	rov;

    Mission	*mission;
    Mission	*output;
    std::string	StringOfCommand;
    FileWriter	writer;

    while (true)
    {
        //ввод возможной команды
        std::cout << "Enter your command" << std::endl;
        std::cin >> StringOfCommand;

        if (StringOfCommand == "add")           rov.addMission();
        else if (StringOfCommand == "del")      rov.deleteMission();
        else if (StringOfCommand == "insert")   rov.insertMission();
        else if (StringOfCommand == "list")     rov.listMission();
        else if (StringOfCommand == "pos")      rov.printPosition();
        else std::cout << "Incorrect command" << std::endl;

        mission = *rov.getMissions().rbegin();
        if (mission && mission->returnTitle() == "return")
        {
            for (auto & it : rov.getMissions())
            {
                output = it;
                output->accept(writer);
            }
            writer.writeToFile();
            break;
        }
    }
    return 0;
}
