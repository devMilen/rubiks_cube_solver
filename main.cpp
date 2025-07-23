#include <print>
#include <iostream>
#include <array>
#include "GL/glew.h"
#include "glfw3.h"

int main() {
	glfwInit();
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
	GLFWwindow* window = glfwCreateWindow(801, 600, "", nullptr, nullptr);
	while (!glfwWindowShouldClose(window))
		glfwPollEvents();
	glfwTerminate();
	std::print("STANAAAAA");
	std::cin.get();
}
