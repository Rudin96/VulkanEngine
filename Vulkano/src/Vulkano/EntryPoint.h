#pragma once

#ifdef VLK_PLATFORM_WINDOWS

extern Vulkano::Application* Vulkano::CreateApplication();

int main(int argc, char** argv) {
	printf("Vulkano Engine\n");
	auto app = Vulkano::CreateApplication();
	app->Run();
	delete app;
}

#endif