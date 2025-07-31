#include <iostream>
#include "framework/Application.h"

namespace rs
{
	Application::Application() :m_window{ sf::VideoMode(540,960),"RiftSpace" }, mTargetFrameRate{ 60 }, mTickClock{}
	{
	
	}

    void Application::Run()
    {
        mTickClock.restart(); // Starts or restarts the clock to track frame time

        float accumulatedTime = 0.f;

        // Target time per frame in seconds.
        // If target framerate = 60 FPS, then targetDeltaTime = 1 / 60 = 0.01666... sec
        float targetDeltaTime = 1.f / mTargetFrameRate;

        while (m_window.isOpen())
        {
            // Handle events like closing the window
            sf::Event event;

            while (m_window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                {
                    m_window.close();
                }
            }

            // Adds the time passed since last frame to the accumulated time
            // Suppose 0.017s passed since last frame, that is added to accumulatedTime
            accumulatedTime += mTickClock.restart().asSeconds(); // deltatime

            // We process the game logic as many times as needed to "catch up" with real-time
            // This allows the logic to run at a fixed rate (like 60 FPS), regardless of actual render rate
            while (accumulatedTime > targetDeltaTime)
            {
                accumulatedTime -= targetDeltaTime;
                TickInternal(targetDeltaTime);
                RenderInternal();
                // If enough time has passed for one logic update (more than targetDeltaTime),
                // we update game logic (Tick), and reduce the accumulated time


                // We call Tick() with the fixed timestep so movement, physics, etc. are consistent

                // Then render the frame. This could be done after one or multiple logic updates.
            }
        }
    }
	void Application::TickInternal(float deltaTime)
	{
        Tick(deltaTime);
		std::cout << "ticking at frameRate: " << 1.f / deltaTime << std::endl;
	}
	void Application::RenderInternal()
	{
		m_window.clear();//first clear prev frame
        Render();//draw
        m_window.display();//display then
       
	}

    void Application::Render()
    {
        sf::RectangleShape rect{ sf::Vector2f{100,100} };
        rect.setOrigin(50, 50);
        rect.setPosition(m_window.getSize().x / 2, m_window.getSize().y / 2);
        rect.setFillColor(sf::Color::Green);
        m_window.draw(rect);
    }

    void Application::Tick(float deltaTime)
    {
        
    }
}