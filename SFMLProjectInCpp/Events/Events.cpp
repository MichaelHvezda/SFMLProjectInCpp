#include <Events.hpp>


void ProcessEvents(Game* game)
{
	auto& window = game->window;
	auto size = window.getSize();
	sf::Event event;
	while (window.pollEvent(event))
	{
		//Logger("event", event.type);
		switch (event.type)
		{
			// window closed
		case sf::Event::Closed:
			window.close();
			Logger("window closed");
			break;

			// key pressed
		case sf::Event::KeyPressed:
			ProcessKeyPressed(event, game);
			break;
		case sf::Event::KeyReleased:
			ProcessKeyReleased(event, game);
			break;

		case sf::Event::MouseMoved:
			ProcessMouseMoved(event, game);
			break;
		case sf::Event::MouseButtonPressed:
			ProcessMousePressed(event, game);
			break;
		case sf::Event::MouseButtonReleased:
			ProcessMouseReleased(event, game);
			break;

		case sf::Event::Resized:
		{
			game->Resize(event, size);
			break;
		}
		// we don't process other types of events
		default:
			break;
		}
	}
}