#pragma once

#ifdef ENGINE_PLATFORM_WINDOWS

extern GameEngine::Application* GameEngine::CreateApplication();

int main(int argc, char** archv)
{
	auto app = GameEngine::CreateApplication();
	app->Run();
	delete app;
}

#endif