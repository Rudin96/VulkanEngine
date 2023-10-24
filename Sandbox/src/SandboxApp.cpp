#include "Vulkano.h"

class Sandbox : public Vulkano::Application 
{
public:
	Sandbox() 
	{

	}

	~Sandbox() 
	{

	}
};

Vulkano::Application* Vulkano::CreateApplication() {
	return new Sandbox();
}