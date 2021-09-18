#ifndef MAINMENU_HPP_
#define MAINMENU_HPP_

#include "../IScene.hpp"
#include "../../Core/Core.hpp"

class MainMenu : public IScene
{
    public:
	    MainMenu(Save*);
	    ~MainMenu();

	    void use(Core*);
	    int getId();
};

#endif /* !MAINMENU_HPP_ */
