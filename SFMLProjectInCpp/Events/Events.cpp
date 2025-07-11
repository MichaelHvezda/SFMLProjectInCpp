#include <Events.hpp>


void ProcessEvents(sf::RenderWindow* window, Game* game)
{
	sf::Event event;
	auto size = window->getSize();
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
			ProcessKeyPressed(window, event, game);
			break;
		case sf::Event::KeyReleased:
			ProcessKeyReleased(window, event, game);
			break;

		case sf::Event::MouseMoved:
			ProcessMouseMoved(window, event, game);
			break;
		case sf::Event::MouseButtonPressed:
			ProcessMousePressed(window, event, game);
			break;
		case sf::Event::MouseButtonReleased:
			ProcessMouseReleased(window, event, game);
			break;

		case sf::Event::Resized:
		{
			Logger("new width: ", event.size.width);
			Logger("new height: ", event.size.height);
			sf::FloatRect visibleArea(0.f, 0.f, static_cast<float>(event.size.width), static_cast<float>(event.size.height));
			window->setView(sf::View(visibleArea));

			sf::Vector2f scale(event.size.width / static_cast<float>(size.x), event.size.height / static_cast<float>(size.y));

			auto defau = window->getDefaultView().getSize();
			game->scale.x = event.size.width / static_cast<float>(defau.x);
			game->scale.y = event.size.height / static_cast<float>(defau.y);

			game->ResizeAll(event.size, size);
			break;
		}
		// we don't process other types of events
		default:
			break;
		}
	}
}