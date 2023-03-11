#include "../../headers/Command/command.hpp"

Command::Command(){
    commandId = 0;
}

Command::Command(int commandId){
    this->commandId=commandId;
}
