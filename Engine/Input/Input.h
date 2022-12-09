#pragma once

#include "../../Utils/Logger.h"
#include "../../DataTypes/Vector.h"

struct GLFWwindow;

class Input
{
private:
	Vector2 mousePos;
	bool leftMouseButtonPressed = false;

private:
	Input();

public:
	static void cursor_callback(GLFWwindow* window, double xPos, double yPos);
	static void keyboardKey_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);


	Vector2 GetMousePosition();
	bool IsLeftMousePressed();

	static Input& getInstance()
	{
		static Input instance;

		return instance;
	}

	Input(Input const&) = delete;
	void operator=(Input const&) = delete;
};