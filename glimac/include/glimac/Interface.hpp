#pragma once
#include <imgui/imgui.h>
#include <imgui/imgui_impl_sdl.h>
#include <imgui/imgui_impl_opengl3.h>
#include <glimac/SDLWindowManager.hpp>
#include <GL/glew.h>
#include <iostream>
#include <vector>

SDL_Window* initialise_window();
SDL_GLContext initialise_context(SDL_Window* window);
ImGuiIO& initialise_ImGui(SDL_Window* window,SDL_GLContext gl_context);