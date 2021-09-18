#include "Core.hpp"
#include "../Scene/MainMenu/MainMenu.hpp"
#include "../Scene/Platform/Platform.hpp"
#include "../Entity/Player/Player.hpp"
#include "../Entity/Entity.hpp"

Core::Core()
{
	_lib = new Lib();
    _save = new Save();
    _save->addEntity(new Player());
	_scenes.push_back(new MainMenu(_save));
    _scenes.push_back(new Platform(_save));
}

void Core::switchScene(int id)
{
    if (id == -1) { _lib->close(); }
    for (int i = 0; i < _scenes.size(); i++)
    {
        if (_scenes[i]->getId() == id)
        {
            std::swap(_scenes[0], _scenes[i]);
            return;
        }
    }
}

void Core::use()
{
	while (_lib->getWindow().isOpen()) _scenes[0]->use(this);
}

Lib* Core::getLib()
{
    return _lib;
}

Save* Core::getSave()
{
    return _save;
}

Core::~Core()
{

}