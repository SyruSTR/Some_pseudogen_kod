//
// Created by grusted on 12/23/24.
//

#include "SimulationController.h"

#include <algorithm>
#include <unistd.h>

#include "robot.h"

SimulationController::SimulationController(){
  std::cout << "Simulation controller created" << std::endl;

  map = new GeneticThings::Map(8,50);

  for (int i = 0; i < 10; i++) {
    auto test_robot = map->addRobot_at_random_place(i);
    if (!test_robot)
      break;
    robots.push_back(test_robot);

  }
}

void SimulationController::deleteDeadRobots(){
  if (map) {
    //delete robot from system
    robots.erase(std::remove_if(robots.begin(),robots.end(),
      [this](GeneticThings::Robot* search_robot){
        if (!search_robot->is_alive()) {
          //delete robot from grid
          map->delete_object(search_robot->x,search_robot->y);
          return true;
        }
        return false;
      }),
      robots.end());

    //todo Maybe replace to the food
  }
}


void SimulationController::startSimulation(){

  map->printMap();

  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < robots.size(); j++) {
      robots[j]->execute_action();
    }
    deleteDeadRobots();
    sleep(1);
    map->printMap();
  }


}

SimulationController::~SimulationController() {
  delete map;
}
