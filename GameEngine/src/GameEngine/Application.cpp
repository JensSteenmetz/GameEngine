#include "Application.h"

#include "Events/ApplicationEvent.h"
#include "Events/Event.h"
#include "Log.h"

namespace GameEngine
{

	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1200, 720);
		TRACE(e);

		while (true);
	}

}