// -*- C++ -*-
#include <core/desktop/Application.h>
#include <core/desktop/GLWindow.h>

Application::Application(const string& title, const Dimension windowSize, App* app)
{
    window = unique_ptr<GLWindow>(new GLWindow(title, windowSize, false));
    window->setFrameLimit(60);

    this->app = app;
}

Application::~Application()
{
}

int Application::run()
{
    window->init();
    app->init(window->getSize());

    while (window->isOpen())
    {
        float frameTime = window->getFrameTime();

        window->processEvents();

        app->render();

        window->swapBuffers();
    }

    window->destroy();

    return EXIT_SUCCESS;
}
