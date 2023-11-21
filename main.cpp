#include <imgui-sfml/imgui-SFML.h>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Network.hpp>

#include <app.h>

int main()
{
    App app;

    sf::RenderWindow window(sf::VideoMode(800, 600), "Example");
    window.setFramerateLimit(60);
    if(ImGui::SFML::Init(window)) {
        sf::Clock deltaClock;
        while (window.isOpen()) {
            sf::Event event{};
            while (window.pollEvent(event)) {
                ImGui::SFML::ProcessEvent(window, event);

                if (event.type == sf::Event::Closed) {
                    window.close();
                }
            }
            ImGui::SFML::Update(window, deltaClock.restart());

            app.display(window.getSize().x, window.getSize().y);

            window.clear();
            ImGui::SFML::Render(window);
            window.display();
        }
        ImGui::SFML::Shutdown();
    }
    return 0;
}
