#include "Input.h"
#include <GLFW/glfw3.h>

Input* Input::GetInstance()
{
	return nullptr;
}

Input::Input()
{

}

void Input::cursor_callback(GLFWwindow* window, double xPos, double yPos)
{
	
}

void Input::keyboardKey_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (action == 1)
		Logger::Log("Key pressed!");
	//Logger::Log(action);
}

Vector2 Input::GetMousePosition()
{
	return Vector2(mousePos);
}
