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
		sf::RenderWindow m_window;
	};
}