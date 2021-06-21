#include"Resume.h"
#include "Controller.h"
Resume::Resume(std::unique_ptr<sf::RectangleShape>rect)
	:
	Command(move(rect))
{

}
void Resume::execute() {

	
}
