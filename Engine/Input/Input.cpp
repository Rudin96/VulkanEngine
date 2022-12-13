#include "Input.h"
#include <GLFW/glfw3.h>

Input::Input()
{

}

void Input::cursor_callback(GLFWwindow* window, double xPos, double yPos)
{
	getInstance().mousePos = Vector2(xPos, yPos) - getInstance().GetCenterOfWindow(window);
	getInstance().CalculateMouseDelta();
	getInstance().CalculateMouseDeltaFromCenterWindow(window);
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
}

Vector2 Input::GetMouseDirectionFromCenterWindow()
{
	return mousePos.Normalize();
}

void Input::SetLeftMouseReleaseCallback(const std::function<void()>& func)
{
	leftMouseReleaseCallback = func;
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
		getInstance().leftMouseReleaseCallback();
		getInstance().SetPrevMousePosition(Vector2(0.f));
	}
}

void Input::scroll_callback(GLFWwindow* window, double xOffset, double yOffset)
{
	getInstance().scrollDir = yOffset;
	getInstance().scrollCallBack(yOffset);
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

void Input::CalculateMouseDelta()
{
	if (getInstance().IsLeftMousePressed())
	{
		getInstance().mouseDelta = getInstance().mousePos - getInstance().prevMousePos;
		getInstance().mouseMoveCallBack(getInstance().mousePos);
	}
}

void Input::SetCursorMoveCallback(const std::function<void(Vector2)>& func)
{
	mouseMoveCallBack = func;
}

void Input::SetScrollCallback(const std::function<void(float)>& func)
{
	scrollCallBack = func;
}

Vector2 Input::GetCenterOfWindow(GLFWwindow* window)
{
	int width, height;
	glfwGetWindowSize(window, &width, &height);
	
	return Vector2(width / 2.f, height / 2.f);
}

void Input::CalculateMouseDeltaFromCenterWindow(GLFWwindow* window)
{
	if (getInstance().IsLeftMousePressed())
	{
		mouseDeltaFromCenterWindow = mousePos - GetCenterOfWindow(window);
	}
}

bool Input::IsLeftMousePressed()
{
	return leftMouseButtonPressed;
}
