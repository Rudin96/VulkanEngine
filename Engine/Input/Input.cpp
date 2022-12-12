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
	{
		if (key == GLFW_KEY_RIGHT)
		{
			getInstance().rightInputVal = 1.f;
		}
		if (key == GLFW_KEY_LEFT)
		{
			getInstance().rightInputVal = -1.f;
		}
		Logger::Log("Key pressed!");
	}
	if (action == GLFW_RELEASE)
	{
		getInstance().rightInputVal = 0.f;
	}
	//Logger::Log(action);
}

void Input::mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
	{
		getInstance().leftMouseButtonPressed = true;
		getInstance().SetPrevMousePosition(getInstance().GetMousePosition());
	}
	else
	{
		getInstance().leftMouseButtonPressed = false;
		getInstance().SetPrevMousePosition(Vector2(0.f));
	}
}

Vector2 Input::GetMousePosition()
{
	return Vector2(mousePos);
}

Vector2 Input::GetMouseDelta()
{
	if (getInstance().IsLeftMousePressed() && getInstance().prevMousePos != getInstance().mousePos)
	{
		mouseDelta = getInstance().mousePos - getInstance().prevMousePos;
		Logger::Log(mouseDelta);
	}
	else {
		mouseDelta = Vector2(0.f);
	}
	return Vector2(mouseDelta);
}

float Input::GetRightInputVal()
{
	return rightInputVal;
}

void Input::SetPrevMousePosition(const Vector2& pos)
{
	getInstance().prevMousePos = pos;
}

bool Input::IsLeftMousePressed()
{
	return leftMouseButtonPressed;
}
