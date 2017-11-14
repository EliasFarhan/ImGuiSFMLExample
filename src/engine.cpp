#include <engine.h>
#include "imgui.h"
#include "imgui-SFML.h"
#include <log.h>
void Engine::Init()
{
	window = new sf::RenderWindow(sf::VideoMode(800, 600), "ImGui + SFML = <3");
	window->setFramerateLimit(60);
	ImGui::SFML::Init(*window);

	shape.setRadius(100.f);
	shape.setFillColor(sf::Color::Green);


}
void Engine::Start()
{
	Log::GetInstance()->Msg("Hello world!");
	bool show_test_window = true;
	while (window->isOpen()) {
		sf::Event event;
		float col[4]{0.f,0.f,0.f,0.f};
		while (window->pollEvent(event)) {
			ImGui::SFML::ProcessEvent(event);

			if (event.type == sf::Event::Closed) {
				window->close();
			}
			if(event.type == sf::Event::MouseButtonPressed)
			{
				Log::GetInstance()->Msg("MOUSE CLICKED");
			}
		}

		ImGui::SFML::Update(*window, deltaClock.restart());

		ImGui::Begin("BUTTON TEST");
		if(ImGui::Button("BUTTON"))
		{
			Log::GetInstance()->Msg("CLICKED ON BUTTON");
		}
		ImGui::End();


		console.Draw();

		//ImGui::ShowTestWindow(&show_test_window);
		window->clear();
		window->draw(shape);
		ImGui::SFML::Render(*window);
		window->display();
	}

	ImGui::SFML::Shutdown();
	delete window;
}
