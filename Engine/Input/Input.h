#pragma once

#include "../../Utils/Logger.h"
#include "../../DataTypes/Vector.h"
#include <functional>

struct GLFWwindow;

class Input
{
private:
	Vector2 mousePos;
	Vector2 prevMousePos;
	Vector2 mouseDelta;
	Vector2 mouseDeltaFromCenterWindow;

	Vector2 mouseDirFromCenterWindow;

	bool leftMouseButtonPressed = false;

	std::function<void(float)> scrollCallBack;
	std::function<void(Vector2)> mouseMoveCallBack;
	std::function<void()> leftMouseReleaseCallback;

	float scrollDir = 0.f;

	float rightInputVal = 0.f;

private:
	Input();

public:
	static void cursor_callback(GLFWwindow* window, double xPos, double yPos);
	static void keyboardKey_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
	static void scroll_callback(GLFWwindow* window, double xOffset, double yOffset);

	Vector2 GetMousePosition();
	Vector2 GetMouseDelta();

	Vector2 GetMouseDirectionFromCenterWindow();

	void CalculateMouseDelta();
	void CalculateMouseDeltaFromCenterWindow(GLFWwindow* window);

	Vector2 GetCenterOfWindow(GLFWwindow* window);

	float GetRightInputVal();

	void SetScrollCallback(const std::function<void(float)>& func);
	void SetCursorMoveCallback(const std::function<void(Vector2)>& func);
	void SetLeftMouseReleaseCallback(const std::function<void()>& func);

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