#include "../../headers/Command/command.hpp"

/* ctor*/
Command::Command(){
    commandId = 0;
}

Command::Command(int commandId){
    this->commandId=commandId;
}

/* getter */
int Command::getCommandId(){
    return commandId;
}