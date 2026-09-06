#pragma once
#include <string>

class GraphicBackend
{
	protected:
		int _width = 1280;
		int _height = 720;
		std::string _windowName = "game";

	public:
		virtual void Init() {}
		virtual void Update() {}
		virtual void Close() {}

		virtual bool IsRunning() { return false; }
		virtual void SetSize(int wight, int height) {}
		virtual void SetWindowName(const std::string text) {}
};
