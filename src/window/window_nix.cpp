#include "constants.hpp"
#include "window.hpp"
//#include "map.hpp"
#include "user_interactions.hpp"

#include <GLFW/glfw3.h>
#include <unordered_map>

namespace window {

int32_t cursor_blink_ms() {
	return 1000;
}
int32_t double_click_ms() {
	return 500;
}

static sys::virtual_key glfw_key_to_virtual_key(int key) {
	switch (key) {
	case GLFW_KEY_SPACE: return sys::virtual_key::SPACE;
	case GLFW_KEY_APOSTROPHE: return sys::virtual_key::QUOTE;
	case GLFW_KEY_COMMA: return sys::virtual_key::COMMA;
	case GLFW_KEY_EQUAL: return sys::virtual_key::PLUS;
	case GLFW_KEY_MINUS: return sys::virtual_key::MINUS;
	case GLFW_KEY_PERIOD: return sys::virtual_key::PERIOD;
	case GLFW_KEY_SLASH: return sys::virtual_key::FORWARD_SLASH;
	case GLFW_KEY_0: return sys::virtual_key::NUM_0;
	case GLFW_KEY_1: return sys::virtual_key::NUM_1;
	case GLFW_KEY_2: return sys::virtual_key::NUM_2;
	case GLFW_KEY_3: return sys::virtual_key::NUM_3;
	case GLFW_KEY_4: return sys::virtual_key::NUM_4;
	case GLFW_KEY_5: return sys::virtual_key::NUM_5;
	case GLFW_KEY_6: return sys::virtual_key::NUM_6;
	case GLFW_KEY_7: return sys::virtual_key::NUM_7;
	case GLFW_KEY_8: return sys::virtual_key::NUM_8;
	case GLFW_KEY_9: return sys::virtual_key::NUM_9;
	case GLFW_KEY_SEMICOLON: return sys::virtual_key::SEMICOLON;
	//case GLFW_KEY_EQUAL: return sys::virtual_key::OEM_NEC_EQUAL;
	case GLFW_KEY_A: return sys::virtual_key::A;
	case GLFW_KEY_B: return sys::virtual_key::B;
	case GLFW_KEY_C: return sys::virtual_key::C;
	case GLFW_KEY_D: return sys::virtual_key::D;
	case GLFW_KEY_E: return sys::virtual_key::E;
	case GLFW_KEY_F: return sys::virtual_key::F;
	case GLFW_KEY_G: return sys::virtual_key::G;
	case GLFW_KEY_H: return sys::virtual_key::H;
	case GLFW_KEY_I: return sys::virtual_key::I;
	case GLFW_KEY_J: return sys::virtual_key::J;
	case GLFW_KEY_K: return sys::virtual_key::K;
	case GLFW_KEY_L: return sys::virtual_key::L;
	case GLFW_KEY_M: return sys::virtual_key::M;
	case GLFW_KEY_N: return sys::virtual_key::N;
	case GLFW_KEY_O: return sys::virtual_key::O;
	case GLFW_KEY_P: return sys::virtual_key::P;
	case GLFW_KEY_Q: return sys::virtual_key::Q;
	case GLFW_KEY_R: return sys::virtual_key::R;
	case GLFW_KEY_S: return sys::virtual_key::S;
	case GLFW_KEY_T: return sys::virtual_key::T;
	case GLFW_KEY_U: return sys::virtual_key::U;
	case GLFW_KEY_V: return sys::virtual_key::V;
	case GLFW_KEY_W: return sys::virtual_key::W;
	case GLFW_KEY_X: return sys::virtual_key::X;
	case GLFW_KEY_Y: return sys::virtual_key::Y;
	case GLFW_KEY_Z: return sys::virtual_key::Z;
	case GLFW_KEY_LEFT_BRACKET: return sys::virtual_key::OPEN_BRACKET;
	case GLFW_KEY_BACKSLASH: return sys::virtual_key::BACK_SLASH;
	case GLFW_KEY_RIGHT_BRACKET: return sys::virtual_key::CLOSED_BRACKET;
	case GLFW_KEY_GRAVE_ACCENT: return sys::virtual_key::TILDA;
	case GLFW_KEY_WORLD_1: return sys::virtual_key::NONE;
	case GLFW_KEY_WORLD_2: return sys::virtual_key::NONE;
	case GLFW_KEY_ESCAPE: return sys::virtual_key::ESCAPE;
	case GLFW_KEY_ENTER: return sys::virtual_key::RETURN;
	case GLFW_KEY_TAB: return sys::virtual_key::TAB;
	case GLFW_KEY_BACKSPACE: return sys::virtual_key::BACK;
	case GLFW_KEY_INSERT: return sys::virtual_key::INSERT;
	case GLFW_KEY_DELETE: return sys::virtual_key::DELETE_KEY;
	case GLFW_KEY_RIGHT: return sys::virtual_key::RIGHT;
	case GLFW_KEY_LEFT: return sys::virtual_key::LEFT;
	case GLFW_KEY_DOWN: return sys::virtual_key::DOWN;
	case GLFW_KEY_UP: return sys::virtual_key::UP;
	case GLFW_KEY_PAGE_UP: return sys::virtual_key::PRIOR;
	case GLFW_KEY_PAGE_DOWN: return sys::virtual_key::NEXT;
	case GLFW_KEY_HOME: return sys::virtual_key::HOME;
	case GLFW_KEY_END: return sys::virtual_key::END;
	case GLFW_KEY_CAPS_LOCK: return sys::virtual_key::CAPITAL;
	case GLFW_KEY_SCROLL_LOCK: return sys::virtual_key::SCROLL;
	case GLFW_KEY_NUM_LOCK: return sys::virtual_key::NUMLOCK;
	case GLFW_KEY_PRINT_SCREEN: return sys::virtual_key::PRINT;
	case GLFW_KEY_PAUSE: return sys::virtual_key::PAUSE;
	case GLFW_KEY_F1: return sys::virtual_key::F1;
	case GLFW_KEY_F2: return sys::virtual_key::F2;
	case GLFW_KEY_F3: return sys::virtual_key::F3;
	case GLFW_KEY_F4: return sys::virtual_key::F4;
	case GLFW_KEY_F5: return sys::virtual_key::F5;
	case GLFW_KEY_F6: return sys::virtual_key::F6;
	case GLFW_KEY_F7: return sys::virtual_key::F7;
	case GLFW_KEY_F8: return sys::virtual_key::F8;
	case GLFW_KEY_F9: return sys::virtual_key::F9;
	case GLFW_KEY_F10: return sys::virtual_key::F10;
	case GLFW_KEY_F11: return sys::virtual_key::F11;
	case GLFW_KEY_F12: return sys::virtual_key::F12;
	case GLFW_KEY_F13: return sys::virtual_key::F13;
	case GLFW_KEY_F14: return sys::virtual_key::F14;
	case GLFW_KEY_F15: return sys::virtual_key::F15;
	case GLFW_KEY_F16: return sys::virtual_key::F16;
	case GLFW_KEY_F17: return sys::virtual_key::F17;
	case GLFW_KEY_F18: return sys::virtual_key::F18;
	case GLFW_KEY_F19: return sys::virtual_key::F19;
	case GLFW_KEY_F20: return sys::virtual_key::F20;
	case GLFW_KEY_F21: return sys::virtual_key::F21;
	case GLFW_KEY_F22: return sys::virtual_key::F22;
	case GLFW_KEY_F23: return sys::virtual_key::F23;
	case GLFW_KEY_F24: return sys::virtual_key::F24;
	case GLFW_KEY_F25: return sys::virtual_key::NONE;
	case GLFW_KEY_KP_0: return sys::virtual_key::NUMPAD0;
	case GLFW_KEY_KP_1: return sys::virtual_key::NUMPAD1;
	case GLFW_KEY_KP_2: return sys::virtual_key::NUMPAD2;
	case GLFW_KEY_KP_3: return sys::virtual_key::NUMPAD3;
	case GLFW_KEY_KP_4: return sys::virtual_key::NUMPAD4;
	case GLFW_KEY_KP_5: return sys::virtual_key::NUMPAD5;
	case GLFW_KEY_KP_6: return sys::virtual_key::NUMPAD6;
	case GLFW_KEY_KP_7: return sys::virtual_key::NUMPAD7;
	case GLFW_KEY_KP_8: return sys::virtual_key::NUMPAD8;
	case GLFW_KEY_KP_9: return sys::virtual_key::NUMPAD9;
	case GLFW_KEY_KP_DECIMAL: return sys::virtual_key::DECIMAL;
	case GLFW_KEY_KP_DIVIDE: return sys::virtual_key::DIVIDE;
	case GLFW_KEY_KP_MULTIPLY: return sys::virtual_key::MULTIPLY;
	case GLFW_KEY_KP_SUBTRACT: return sys::virtual_key::SUBTRACT;
	case GLFW_KEY_KP_ADD: return sys::virtual_key::ADD;
	case GLFW_KEY_KP_ENTER: return sys::virtual_key::RETURN;
	case GLFW_KEY_LEFT_SHIFT: return sys::virtual_key::LSHIFT;
	case GLFW_KEY_LEFT_CONTROL: return sys::virtual_key::LCONTROL;
	case GLFW_KEY_LEFT_ALT: return sys::virtual_key::LMENU;
	case GLFW_KEY_LEFT_SUPER: return sys::virtual_key::LWIN;
	case GLFW_KEY_RIGHT_SHIFT: return sys::virtual_key::RSHIFT;
	case GLFW_KEY_RIGHT_CONTROL: return sys::virtual_key::RCONTROL;
	case GLFW_KEY_RIGHT_ALT: return sys::virtual_key::RMENU;
	case GLFW_KEY_RIGHT_SUPER: return sys::virtual_key::RWIN;
	case GLFW_KEY_MENU: return sys::virtual_key::MENU;
	case GLFW_KEY_UNKNOWN:
	default: return sys::virtual_key::NONE;
	}
}

bool is_key_depressed(sys::state const& game_state, sys::virtual_key key) {
	for (unsigned char ch = GLFW_KEY_SPACE; ch < 0xFF; ++ch)
		if (glfw_key_to_virtual_key(ch) == key)
			return glfwGetKey(game_state.win_ptr->window, ch) == GLFW_PRESS;
	return false;
}

void get_window_size(sys::state const& game_state, int& width, int& height) {
	glfwGetWindowSize(game_state.win_ptr->window, &width, &height);
}

bool is_in_fullscreen(sys::state const& game_state) {
	return (game_state.win_ptr) && game_state.win_ptr->in_fullscreen;
}

void set_borderless_full_screen(sys::state& game_state, bool fullscreen) {
	if(game_state.win_ptr && game_state.win_ptr->window) {
		// Unsure how it works, but it works
		sys::state* state = (sys::state*)glfwGetWindowUserPointer(game_state.win_ptr->window);
		int width, height;
		glfwGetFramebufferSize(game_state.win_ptr->window, &width, &height);
		state->x_size = width;
		state->y_size = height;

		GLFWmonitor* monitor = glfwGetPrimaryMonitor();

		if(fullscreen) {
			glfwGetWindowSize(game_state.win_ptr->window, &width, &height);
			const GLFWvidmode* mode = glfwGetVideoMode(monitor);
			glfwSetWindowMonitor(game_state.win_ptr->window, monitor, 0, 0, mode->width, mode->height, mode->refreshRate);
			game_state.win_ptr->in_fullscreen=true;
		} else {
			const GLFWvidmode* mode = glfwGetVideoMode(monitor);
			glfwSetWindowMonitor(game_state.win_ptr->window, nullptr, 0, 0, width, height, mode->refreshRate);
			glfwMaximizeWindow(game_state.win_ptr->window);
			game_state.win_ptr->in_fullscreen=false;
		}
	}
}

void close_window(sys::state& game_state) {
	// Signal to close window (should close = yes)
	glfwSetWindowShouldClose(game_state.win_ptr->window, 1);
}

sys::key_modifiers get_current_modifiers(GLFWwindow* window) {
	bool control =
			(glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS) || (glfwGetKey(window, GLFW_KEY_RIGHT_CONTROL) == GLFW_PRESS);
	bool alt = (glfwGetKey(window, GLFW_KEY_LEFT_ALT) == GLFW_PRESS) || (glfwGetKey(window, GLFW_KEY_RIGHT_ALT) == GLFW_PRESS);
	bool shift =
			(glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) || (glfwGetKey(window, GLFW_KEY_RIGHT_SHIFT) == GLFW_PRESS);
	uint32_t val = uint32_t(control ? sys::key_modifiers::modifiers_ctrl : sys::key_modifiers::modifiers_none) |
								 uint32_t(alt ? sys::key_modifiers::modifiers_alt : sys::key_modifiers::modifiers_none) |
								 uint32_t(shift ? sys::key_modifiers::modifiers_shift : sys::key_modifiers::modifiers_none);
	return sys::key_modifiers(val);
}

sys::key_modifiers get_current_modifiers(int glfw_mods) {
	uint32_t val =
			uint32_t((glfw_mods & GLFW_MOD_CONTROL) ? sys::key_modifiers::modifiers_ctrl : sys::key_modifiers::modifiers_none) |
			uint32_t((glfw_mods & GLFW_MOD_ALT) ? sys::key_modifiers::modifiers_alt : sys::key_modifiers::modifiers_none) |
			uint32_t((glfw_mods & GLFW_MOD_SHIFT) ? sys::key_modifiers::modifiers_shift : sys::key_modifiers::modifiers_none);
	return sys::key_modifiers(val);
}

static void glfw_error_callback(int error, char const* description) {
	emit_error_message(std::string{ "Glfw Error " } + std::to_string(error) + std::string{ description }, false);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	sys::state* state = (sys::state*)glfwGetWindowUserPointer(window);

	sys::virtual_key virtual_key = glfw_key_to_virtual_key(key);
	switch(action) {
	case GLFW_PRESS:
		state->on_key_down(virtual_key, get_current_modifiers(mods));
		break;
	case GLFW_RELEASE:
		state->on_key_up(virtual_key, get_current_modifiers(mods));
		break;
	case GLFW_REPEAT:
		switch(virtual_key) {
		case sys::virtual_key::RETURN: [[fallthrough]];
		case sys::virtual_key::BACK: [[fallthrough]];
		case sys::virtual_key::DELETE_KEY: [[fallthrough]];
		case sys::virtual_key::LEFT: [[fallthrough]];
		case sys::virtual_key::RIGHT: [[fallthrough]];
		case sys::virtual_key::UP: [[fallthrough]];
		case sys::virtual_key::DOWN:
			state->on_key_down(virtual_key, get_current_modifiers(mods));
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
}

static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos) {
	sys::state* state = (sys::state*)glfwGetWindowUserPointer(window);

	int32_t x = (xpos > 0 ? (int32_t)std::round(xpos) : 0);
	int32_t y = (ypos > 0 ? (int32_t)std::round(ypos) : 0);
	state->on_mouse_move(x, y, get_current_modifiers(window));

	if(glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS)
		state->on_mouse_drag(x, y, get_current_modifiers(window));

	state->mouse_x_position = x;
	state->mouse_y_position = y;
}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
	sys::state* state = (sys::state*)glfwGetWindowUserPointer(window);

	double xpos, ypos;
	glfwGetCursorPos(window, &xpos, &ypos);
	int32_t x = (xpos > 0 ? (int32_t)std::round(xpos) : 0);
	int32_t y = (ypos > 0 ? (int32_t)std::round(ypos) : 0);

	switch(action) {
	case GLFW_PRESS:
		if(button == GLFW_MOUSE_BUTTON_LEFT) {
			state->on_lbutton_down(x, y, get_current_modifiers(window));
			state->win_ptr->left_mouse_down = true;
		} else if(button == GLFW_MOUSE_BUTTON_RIGHT) {
			state->on_rbutton_down(x, y, get_current_modifiers(window));
		} else if(button == GLFW_MOUSE_BUTTON_MIDDLE) {
			state->on_mbutton_down(x, y, get_current_modifiers(window));
		}
		state->mouse_x_position = x;
		state->mouse_y_position = y;
		break;
	case GLFW_RELEASE:
		if(button == GLFW_MOUSE_BUTTON_LEFT) {
			state->on_lbutton_up(x, y, get_current_modifiers(window));
			state->win_ptr->left_mouse_down = false;
		} else if(button == GLFW_MOUSE_BUTTON_RIGHT) {
			state->on_rbutton_up(x, y, get_current_modifiers(window));
		} else if(button == GLFW_MOUSE_BUTTON_MIDDLE) {
			state->on_mbutton_up(x, y, get_current_modifiers(window));
		}
		state->mouse_x_position = x;
		state->mouse_y_position = y;
		break;
	}
}

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset) {
	sys::state* state = (sys::state*)glfwGetWindowUserPointer(window);

	double xpos, ypos;
	glfwGetCursorPos(window, &xpos, &ypos);
	int32_t x = (xpos > 0 ? (int32_t)std::round(xpos) : 0);
	int32_t y = (ypos > 0 ? (int32_t)std::round(ypos) : 0);

	sys::on_mouse_wheel(*state, x, y, get_current_modifiers(window), (float)yoffset);
	state->mouse_x_position = x;
	state->mouse_y_position = y;
}

void character_callback(GLFWwindow* window, unsigned int codepoint) {
	sys::state* state = (sys::state*)glfwGetWindowUserPointer(window);
	if(state->ui_state.edit_target_internal) {
		state->on_text(codepoint);
	}
}

void on_window_change(GLFWwindow* window) {
	sys::state* state = (sys::state*)glfwGetWindowUserPointer(window);

	window_state t = window_state::normal;
	if(glfwGetWindowAttrib(window, GLFW_MAXIMIZED) == GLFW_MAXIMIZED)
		t = window_state::maximized;
	else if(glfwGetWindowAttrib(window, GLFW_ICONIFIED) == GLFW_ICONIFIED)
		t = window_state::minimized;

	// redo OpenGL viewport
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	state->on_resize(width, height, t);
	state->x_size = width;
	state->y_size = height;
}

void window_size_callback(GLFWwindow* window, int width, int height) {
	// on_window_change(window);
	// framebuffer_size_callback should be enough
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	on_window_change(window);
}

void window_iconify_callback(GLFWwindow* window, int iconified) {
	on_window_change(window);
}

void window_maximize_callback(GLFWwindow* window, int maximized) {
	on_window_change(window);
}

void focus_callback(GLFWwindow* window, int focused) {
	sys::state* state = (sys::state*)glfwGetWindowUserPointer(window);
	if(focused) {
		if(state->user_settings.mute_on_focus_lost) {
			sound::resume_all(*state);
		}
	} else {
		if(state->user_settings.mute_on_focus_lost) {
			sound::pause_all(*state);
		}
	}
}

void create_window(sys::state& game_state, creation_parameters const& params) {
	game_state.win_ptr = std::make_unique<window_data_impl>();
	game_state.win_ptr->creation_x_size = params.size_x;
	game_state.win_ptr->creation_y_size = params.size_y;
	game_state.win_ptr->in_fullscreen = params.borderless_fullscreen;

	// Setup window
	glfwSetErrorCallback(glfw_error_callback);
	if(!glfwInit())
		emit_error_message("Failed to init glfw\n", true);

	glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // 3.2+ only
	glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);
	//glfwWindowHint(GLFW_SAMPLES, game_state.user_settings.antialias_level);

	// Create window with graphics context
	auto* window = glfwCreateWindow(params.size_x, params.size_y, NATIVE_PROGRAM_NAME, NULL, NULL);
	if(window == NULL)
		emit_error_message("Failed to create window\n", true);
	game_state.win_ptr->window = window;

	glfwSetWindowUserPointer(window, &game_state);


	// event callbacks
	glfwSetKeyCallback(window, key_callback);
	glfwSetCursorPosCallback(window, cursor_position_callback);
	glfwSetMouseButtonCallback(window, mouse_button_callback);
	glfwSetScrollCallback(window, scroll_callback);
	glfwSetCharCallback(window, character_callback);
	glfwSetWindowSizeCallback(window, window_size_callback);
	glfwSetWindowIconifyCallback(window, window_iconify_callback);
	glfwSetWindowMaximizeCallback(window, window_maximize_callback);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glfwSetWindowFocusCallback(window, focus_callback);
	glfwSetWindowSizeLimits(window, 640, 400, 2400, 1800);
	if(params.borderless_fullscreen){
		int width, height;
		glfwGetFramebufferSize(game_state.win_ptr->window, &width, &height);
		glfwGetWindowSize(game_state.win_ptr->window, &width, &height);
		const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
		glfwSetWindowMonitor(window, glfwGetPrimaryMonitor(), 0, 0, mode->width, mode->height, mode->refreshRate);
		game_state.win_ptr->in_fullscreen=true;
	}

	ogl::initialize_opengl(game_state);

	sound::initialize_sound_system(game_state);
	sound::start_music(game_state, game_state.user_settings.master_volume * game_state.user_settings.music_volume);

	on_window_change(window); // Init the window size

	change_cursor(game_state, cursor_type::busy);
	game_state.on_create();
	change_cursor(game_state, cursor_type::normal);

	while(!glfwWindowShouldClose(window)) {
		{
			std::unique_lock lock(game_state.ui_lock);
			game_state.ui_lock_cv.wait(lock, [&] { return !game_state.yield_ui_lock; });
			glfwPollEvents();
			// Run game code
			game_state.render();
			glfwSwapBuffers(window);
		}

		sound::update_music_track(game_state);
	}

	glfwDestroyWindow(window);
	glfwTerminate();
}

void change_cursor(sys::state& state, cursor_type type) {
	//TODO: Implement on linux
}

void emit_error_message(std::string const& content, bool fatal) {
	std::fprintf(stderr, "%s", content.c_str());
	if(fatal) {
		std::exit(EXIT_FAILURE);
	}
}

win32_text_services::win32_text_services() {
}
win32_text_services::~win32_text_services() {
}
void win32_text_services::start_text_services() {
}
void win32_text_services::end_text_services() {
}
void win32_text_services::on_text_change(text_services_object* ts, uint32_t old_start, uint32_t old_end, uint32_t new_end) {
}
void win32_text_services::on_selection_change(text_services_object* ts) {
}
bool win32_text_services::send_mouse_event_to_tso(text_services_object* ts, int32_t x, int32_t y, uint32_t buttons) {
	return false;
}
void win32_text_services::set_focus(sys::state& win, text_services_object* o) {
}
void win32_text_services::suspend_keystroke_handling() {
}
void win32_text_services::resume_keystroke_handling() {
}
text_services_object* win32_text_services::create_text_service_object(sys::state& win, ui::element_base& ei) {
	return nullptr;
}
void release_text_services_object(text_services_object* ptr) {
}

} // namespace window
