#include <print>
#include <iostream>
#include "glfw3.h"

int main() {
	glfwInit();
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
	GLFWwindow* window = glfwCreateWindow(800, 600, "", nullptr, nullptr);
	while (!glfwWindowShouldClose(window))
		glfwPollEvents();
	std::print("is done repository: {} he he he", true);
	std::cin.get();//alahagbar
}
