#include <print>
#include <iostream>
<<<<<<< HEAD
#include <array>
=======
>>>>>>> d565b62dce78fe55945b9e450259f0e3ea2f951c
#include "glfw3.h"

int main() {
	glfwInit();
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
<<<<<<< HEAD
	GLFWwindow* window = glfwCreateWindow(801, 600, "", nullptr, nullptr);
	while (!glfwWindowShouldClose(window))
		glfwPollEvents();
	glfwTerminate();
	std::cin.get();
=======
	GLFWwindow* window = glfwCreateWindow(800, 600, "", nullptr, nullptr);
	while (!glfwWindowShouldClose(window))
		glfwPollEvents();
	std::print("is done repository: {} he he he", true);
	std::cin.get();//alahagbar
>>>>>>> d565b62dce78fe55945b9e450259f0e3ea2f951c
}
