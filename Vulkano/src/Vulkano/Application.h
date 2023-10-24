#pragma once

#include "Core.h"

namespace Vulkano {
	class VLK_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
	};

	//TO BE DEFINED BY CLIENT
	Application* CreateApplication();
}
