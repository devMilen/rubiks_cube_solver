#include <print>
#include <iostream>
#include <array>
#include "glew.h"
#include "glfw3.h"

class Color {
public:
    float r = 0, g = 0, b = 0;

	Color() {}

	Color(float r, float g, float b)
		:r(r), g(g), b(b) {
	}
};

const char* vertexShaderSource = R"glsl(
    #version 330 core
    layout (location = 0) in vec3 aPos;
    layout (location = 1) in vec3 given_color;
    
    out vec3 pixel_color;

    void main() {
        gl_Position = vec4(aPos, 1.0);
        pixel_color = given_color;
    }
)glsl";

const char* fragmentShaderSource = R"glsl(
    #version 330 core
    out vec4 FragColor;
    in vec3 pixel_color;

    void main() {
        FragColor = vec4(pixel_color, 1.0);
    }
)glsl";

unsigned int shaderProgram = 0, VAO = 0, VBO = 0;

GLFWwindow* window;

void setupTriangle(const std::array<Color, 3>& _tri_color_per_point) {
    const float vertices[] = {
     0.0f,  0.5f, 0.0f, _tri_color_per_point[0].r, _tri_color_per_point[0].g, _tri_color_per_point[0].b,
    -0.5f, -0.5f, 0.0f, _tri_color_per_point[1].r, _tri_color_per_point[1].g, _tri_color_per_point[1].b,
     0.5f, -0.5f, 0.0f, _tri_color_per_point[2].r, _tri_color_per_point[2].g, _tri_color_per_point[2].b,
    };

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(vertices[4])));
    glEnableVertexAttribArray(1);

    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, nullptr);
    glCompileShader(vertexShader);

    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, nullptr);
    glCompileShader(fragmentShader);

    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
}

void setupGlfwGlew() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(801, 600, "", nullptr, nullptr);
    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK) throw std::runtime_error("");
}

void render() {
    glUseProgram(shaderProgram);
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

void cleanup() {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteProgram(shaderProgram);
    glfwTerminate();
}

int main() {
    setupGlfwGlew();
    
    setupTriangle(std::array<Color, 3> {
        Color(1.0f, 0.0f, 0.0f),
        Color(0.0f, 1.0f, 0.0f),
        Color(0.0f, 0.0f, 1.0f)
    });
 
    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        render();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    cleanup();
	std::cin.get();
}
