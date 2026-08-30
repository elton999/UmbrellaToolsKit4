#include <glad/glad.h>
#include "RenderManager.h"
#include "../../debug/Log.h"


void RenderManager::StartUp()
{
	if (!glfwInit()) return;

	const char* glsl_version = "#version 330";
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // Required on Mac
#endif

	// Create window with graphics context
	_window = glfwCreateWindow(1280, 720, "game", nullptr, nullptr);
	if (_window == nullptr) {
		glfwTerminate();
		return;
	}
	glfwMakeContextCurrent(_window);
	glfwSwapInterval(1); // Enable vsync
	Log::Msg("int game");

	// Initialize GLAD loader
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		Log::MsgError("Failed to initialize GLAD");
		return;
	}
}

void RenderManager::Run()
{
	glfwPollEvents();
	int display_w, display_h;
	glfwGetFramebufferSize(_window, &display_w, &display_h);
	glViewport(0, 0, display_w, display_h);
	glClearColor(0.45f, 0.55f, 0.60f, 1.00f);
	glClear(GL_COLOR_BUFFER_BIT);
	glfwSwapBuffers(_window);
}

void RenderManager::ShutDown()
{
	glfwDestroyWindow(_window);
	glfwTerminate();
}

bool RenderManager::IsRunning()
{
	return !glfwWindowShouldClose(_window);
}
