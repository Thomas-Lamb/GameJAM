NAME =	Havane

SRC		=	Capacity/Balise/Balise.cpp \
			Capacity/Shoot/Shoot.cpp \
			Capacity/Speed/Speed.cpp \
			Core/Core.cpp \
			Entity/Zombie/Zombie.cpp \
			Entity/Player/Player.cpp \
			Entity/Entity.cpp \
			Lib/Lib.cpp \
			Lib/Button.cpp \
			Save/Save.cpp \
			Scene/IScene.cpp \
			Scene/GameOver/GameOver.cpp \
			Scene/MainMenu/MainMenu.cpp \
			Scene/Platform/Platform.cpp \
			main.cpp \

OBJS	=	$(SRC:.cpp=.o)

all:	$(OBJS)
		g++ -o $(NAME) $(OBJS) -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -g3

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re:		fclean all
