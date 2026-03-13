#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "view.h"
#include "controller.h"
#include "AnsiPrint.h"
#include "gameObjectFactory.h"
/**
 * Print my id
 * */
void
PrintMyID(std::string studId) {

    std::string str = "ID: " + studId;
    std::cout << AnsiPrint(str.c_str(),YELLOW,RED, true, true) << std::endl << std::endl;
}



int main(){
    // TODO 
    // Integrate the Simple MVC Pattern to run the program.
    
	
	std::srand(std::time(nullptr));
    View view;
    Controller ctrl(view);

    
    GameObjectFactory factory;
    auto objects = factory.create();

    
    
    ctrl.setObjects(objects);
    ctrl.run();

    // TODO
    // change to your student ID.
    PrintMyID("112703059");
}
