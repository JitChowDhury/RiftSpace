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
		void TickInternal(float deltaTime);
		void RenderInternal();
		virtual void Render();
		virtual void Tick(float deltaTime);

		sf::RenderWindow m_window;
		float mTargetFrameRate;
		sf::Clock mTickClock;
	};
}