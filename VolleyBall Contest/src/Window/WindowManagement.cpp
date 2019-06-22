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
}

void WindowManagement::mainLoop() {
	while (!glfwWindowShouldClose(window)) {
		glfwGetFramebufferSize(window, &_var::width, &_var::height);
		glClearColor(0.5f, 0.5f, 0.5f, 1.f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		Control::reset();

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

void WindowManagement::key_callback(GLFWwindow *window, int key, int scancode, int action, int mods) {
	Control::key = key;
	Control::scancode = scancode;
	Control::action = action;
	Control::mods = mods;
	/*
	switch (key) {
	case GLFW_KEY_W:
		_var::eye.fi += (_var::eye.fi < 84.f ? 5.f : 0.f);
		break;
	case GLFW_KEY_A:
		_var::eye.theta -= 5;
		break;
	case GLFW_KEY_S:
		_var::eye.fi -= (_var::eye.fi > -84.f ? 5.f : 0.f);
		break;
	case GLFW_KEY_D:
		_var::eye.theta += 5;
		break;
	case GLFW_KEY_Q:
		_var::eye.r += 1;
		break;
	case GLFW_KEY_E:
		_var::eye.r -= 1;
		break;
	default:
		break;
	}
	*/
}

void WindowManagement::display() {
	glViewport(0, 0, _var::width, _var::height);

	_var::update();

	game.run();
}

