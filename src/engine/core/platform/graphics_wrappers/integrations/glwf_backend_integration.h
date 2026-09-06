#pragma once
#include "../graphic_backend.h"
#include "../../../debug/Log.h"

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include <sstream>

namespace Umbrella
{
	class GLWF_BackendIntegration : public GraphicBackend
	{
		private:
			GLFWwindow* _window;
		public:
			void Init() override;
			void Update() override;
			void Close() override;

			bool IsRunning() override;
			void SetSize(int wight, int height) override;
			void SetWindowName(const std::string text) override;
	};
};

