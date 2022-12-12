#pragma once

#include "../../Utils/Logger.h"
#include "../../DataTypes/Vector.h"

struct GLFWwindow;

class Input
{
private:
	Vector2 mousePos;
	Vector2 prevMousePos;
	Vector2 mouseDelta;
	bool leftMouseButtonPressed = false;

	float rightInputVal = 0.f;

private:
	Input();

public:
	static void cursor_callback(GLFWwindow* window, double xPos, double yPos);
	static void keyboardKey_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);

	Vector2 GetMousePosition();
	Vector2 GetMouseDelta();

	float GetRightInputVal();

	void SetPrevMousePosition(const Vector2& pos);

	bool IsLeftMousePressed();

	static Input& getInstance()
	{
		static Input instance;

		return instance;
	}

	Input(Input const&) = delete;
	void operator=(Input const&) = delete;
};