#include<iostream>
#include <memory>
#include <SFML/Graphics.hpp>
#include "framework/Application.h"

int main()
{
    //allocating in heap cause application is large and stack memory is limited
    //rs::Application* app = new rs::Application();
    //app->Run();

    std::unique_ptr<rs::Application> app = std::make_unique<rs::Application>();
    app->Run();

}
