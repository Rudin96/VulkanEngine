#include "Input.h"
#include <GLFW/glfw3.h>

Input::Input()
{

}

void Input::cursor_callback(GLFWwindow* window, double xPos, double yPos)
{
	getInstance().mousePos = Vector2(xPos, yPos);
}

void Input::keyboardKey_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (action == 1)
		Logger::Log("Key pressed!");
	//Logger::Log(action);
}

void Input::mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
		getInstance().leftMouseButtonPressed = true;
	else
		getInstance().leftMouseButtonPressed = false;
}

Vector2 Input::GetMousePosition()
{
	return Vector2(mousePos);
}

bool Input::IsLeftMousePressed()
{
	return leftMouseButtonPressed;
}
