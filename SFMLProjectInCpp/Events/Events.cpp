#include <Events.hpp>
#include <KeyPress.hpp>

void ProcessEvents(sf::RenderWindow* window, Game* game) {

	sf::Event event;
	while (window->pollEvent(event))
	{
		//Logger("event", event.type);
		switch (event.type)
		{
			// window closed
		case sf::Event::Closed:
			window->close();
			Logger("window closed");
			break;

			// key pressed
		case sf::Event::KeyPressed:
			ProcessKeyPressed(window,event,game);
			break;
		case sf::Event::KeyReleased:
			ProcessKeyReleased(window, event, game);
			break;

		case sf::Event::Resized:
		{
			Logger("new width: ", event.size.width);
			Logger("new height: ", event.size.height);
			break;
		}

		// we don't process other types of events
		default:
			break;
		}
	}
}