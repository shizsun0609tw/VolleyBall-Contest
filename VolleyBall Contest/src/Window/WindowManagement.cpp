#include "include/Window/WindowManagement.h"

WindowManagement::WindowManagement()
{
}

WindowManagement::~WindowManagement()
{
	glfwDestroyWindow(window);
	glfwTerminate();
	exit(EXIT_SUCCESS);
}


bool WindowManagement::init(int w, int h) {
	// glfw init
	GLuint err = glfwInit();
	if (err != GLFW_TRUE) {
		cout << err << endl;
		getchar();
		return false;
	}
	// window init
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

	_var::width = w; _var::height = h;
	window = glfwCreateWindow(_var::width, _var::height, "VolleyBall Contest", NULL, NULL);
	glfwMakeContextCurrent(window);
	// glew init
	glewExperimental = GL_TRUE;
	err = glewInit();
	if (err != GLEW_OK) {
		cout << glewGetErrorString(err) << endl;
		getchar();
		return false;
	}

	//glfwSwapInterval(1);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glEnable(GL_BLEND);
	glEnable(GL_ALPHA_TEST);

	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glAlphaFunc(GL_GREATER, 0.8f);

	setCallbackFunction();


	_var::init();
	game = Game();

	return (window == NULL ? false : true);
}

void WindowManagement::setCallbackFunction() {
	glfwSetErrorCallback(error_callback);
	glfwSetKeyCallback(window, key_callback);
	glfwSetCursorPosCallback(window, mouse_cursor_callback);
	glfwSetScrollCallback(window, scroll_callback);
}

void WindowManagement::mainLoop() {
	while (!glfwWindowShouldClose(window)) {
		glfwGetFramebufferSize(window, &_var::width, &_var::height);
		glClearColor(0.5f, 0.5f, 0.5f, 1.f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glfwPollEvents();

		glUseProgram(_var::shader.shaderProgram);
		
		display();

		glUseProgram(0);

		glfwSwapBuffers(window);
	}
}

void WindowManagement::error_callback(int error, const char * description)
{
	cout << "Error: " << description << endl;
}

void WindowManagement::scroll_callback(GLFWwindow* window, double xoffset, double yoffset) {
	_var::eye.r -= yoffset;
}

void WindowManagement::mouse_cursor_callback(GLFWwindow* window, double xpos, double ypos) {
	_var::eye.theta = -xpos / _var::width * 180.f + 270.f;
	_var::eye.fi = ypos / _var::height * 90.f;
}

void WindowManagement::key_callback(GLFWwindow *window, int key, int scancode, int action, int mods) {
	Control::update(key, scancode, action, mods);
}

void WindowManagement::display() {
	glViewport(0, 0, _var::width, _var::height);

	game.run();
}

