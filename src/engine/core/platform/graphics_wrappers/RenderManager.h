#pragma once

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include <sstream>

class RenderManager
{
	private:
		GLFWwindow* _window;

	public:
		void StartUp();
		void Run();
		void ShutDown();

		bool IsRunning();
};
