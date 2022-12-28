#include <iostream>
#include "ROV.h"

int main() {
    ROV	rov;
    Mission	*mission;
    Mission	*output;
    std::string	StringOfCommand;
    FileWriter	writer;

    ROV::help();

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
        else if (StringOfCommand == "help")     ROV::help();
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
