#pragma once
#include<SFML\Graphics.hpp>
namespace rs
{
	class Application
	{
	public:
		Application();
		void Run();
	private:
		void Tick(float deltaTime);
		void Render();

		sf::RenderWindow m_window;
		float mTargetFrameRate;
		sf::Clock mTickClock;
	};
}