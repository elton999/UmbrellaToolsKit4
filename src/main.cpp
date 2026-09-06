#include "engine/umbrella_root.h"


int main()
{
	Umbrella::UmbrellaRoot umbrellaToolsKit = {};

	umbrellaToolsKit.StartUp();

	umbrellaToolsKit.RenderWindow->BackendIntegration->SetWindowName("Game made with UmbrellaToolsKit4");

	umbrellaToolsKit.Run();

	umbrellaToolsKit.ShutDown();

	return 0;
}
