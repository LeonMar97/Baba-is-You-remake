#pragma once
#include "Command.h"
#include<memory>
class Controller;
class NewGame : public Command{
public:
	NewGame(std::shared_ptr<Controller>& c);
	void execute()override;
private:
	std::shared_ptr<Controller>m_cntrl;
};	