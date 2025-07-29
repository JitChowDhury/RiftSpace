#include "framework/Application.h"

namespace rs
{
	Application::Application():m_window{sf::VideoMode(540,960),"RiftSpace"}
	{
	
	}

	void Application::Run()
	{
		while (m_window.isOpen())
		{
			sf::Event event;
			while (m_window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				{
					m_window.close();
				}
			}
		}
	}
}