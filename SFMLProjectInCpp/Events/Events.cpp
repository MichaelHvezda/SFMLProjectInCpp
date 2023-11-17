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

			auto scaleX = event.size.width / static_cast<float>(size.x);
			auto scaleY = event.size.height / static_cast<float>(size.y);

			auto defau = window->getDefaultView().getSize();
			game->scale.x = event.size.width / static_cast<float>(defau.x);
			game->scale.y = event.size.height / static_cast<float>(defau.y);

			{
				auto pos = game->player->sprite->getPosition();
				auto rateX = pos.x / static_cast<float>(size.x);
				auto rateY = pos.y / static_cast<float>(size.y);

				game->player->sprite->setPosition(rateX * event.size.width, rateY * event.size.height);
				game->player->sprite->scale(scaleX, scaleY);
			}

			for (auto& proj : game->projectiles)
			{
				auto pos = proj->sprite->getPosition();
				auto rateX = pos.x / static_cast<float>(size.x);
				auto rateY = pos.y / static_cast<float>(size.y);

				proj->sprite->setPosition(rateX * event.size.width, rateY * event.size.height);
				proj->sprite->scale(scaleX, scaleY);

				proj->direction.x *= scaleX;
				proj->direction.y *= scaleY;
			}

			game->menu->Resize(sf::Vector2f(event.size.width, event.size.height), sf::Vector2f(scaleX, scaleY));

			break;
		}
		// we don't process other types of events
		default:
			break;
		}
	}
}