//Default
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <Windows.h>
#include "..\..\Plugins\glew\include\GL\glew.h"
#include <gl\GL.h>
#include <gl\GLU.h>
#include <math.h>
#include <vector>
#include <map>
#include <fstream>
#include <string>


//Plugins
#include "..\..\Plugins\GLM\glm\glm.hpp"


//SDL

#include "..\..\Plugins\SDL\include\begin_code.h"
#include "..\..\Plugins\SDL\include\close_code.h"
#include "..\..\Plugins\SDL\include\SDL.h"
#include "..\..\Plugins\SDL\include\SDL_assert.h"
#include "..\..\Plugins\SDL\include\SDL_atomic.h"
#include "..\..\Plugins\SDL\include\SDL_audio.h"
#include "..\..\Plugins\SDL\include\SDL_bits.h"
#include "..\..\Plugins\SDL\include\SDL_blendmode.h"
#include "..\..\Plugins\SDL\include\SDL_clipboard.h"
#include "..\..\Plugins\SDL\include\SDL_config.h"
#include "..\..\Plugins\SDL\include\SDL_cpuinfo.h"
#include "..\..\Plugins\SDL\include\SDL_endian.h"
#include "..\..\Plugins\SDL\include\SDL_error.h"
#include "..\..\Plugins\SDL\include\SDL_events.h"
#include "..\..\Plugins\SDL\include\SDL_filesystem.h"
#include "..\..\Plugins\SDL\include\SDL_gamecontroller.h"
#include "..\..\Plugins\SDL\include\SDL_gesture.h"
#include "..\..\Plugins\SDL\include\SDL_haptic.h"
#include "..\..\Plugins\SDL\include\SDL_hints.h"
#include "..\..\Plugins\SDL\include\SDL_joystick.h"
#include "..\..\Plugins\SDL\include\SDL_keyboard.h"
#include "..\..\Plugins\SDL\include\SDL_keycode.h"
#include "..\..\Plugins\SDL\include\SDL_loadso.h"
#include "..\..\Plugins\SDL\include\SDL_log.h"
#include "..\..\Plugins\SDL\include\SDL_main.h"
#include "..\..\Plugins\SDL\include\SDL_messagebox.h"
#include "..\..\Plugins\SDL\include\SDL_mouse.h"
#include "..\..\Plugins\SDL\include\SDL_mutex.h"
#include "..\..\Plugins\SDL\include\SDL_name.h"
#include "..\..\Plugins\SDL\include\SDL_opengl.h"
#include "..\..\Plugins\SDL\include\SDL_opengles.h"
//#include "..\..\Plugins\SDL\include\SDL_opengles2.h"
#include "..\..\Plugins\SDL\include\SDL_pixels.h"
#include "..\..\Plugins\SDL\include\SDL_platform.h"
#include "..\..\Plugins\SDL\include\SDL_power.h"
#include "..\..\Plugins\SDL\include\SDL_quit.h"
#include "..\..\Plugins\SDL\include\SDL_rect.h"
#include "..\..\Plugins\SDL\include\SDL_render.h"
#include "..\..\Plugins\SDL\include\SDL_revision.h"
#include "..\..\Plugins\SDL\include\SDL_rwops.h"
#include "..\..\Plugins\SDL\include\SDL_scancode.h"
#include "..\..\Plugins\SDL\include\SDL_shape.h"
#include "..\..\Plugins\SDL\include\SDL_stdinc.h"
#include "..\..\Plugins\SDL\include\SDL_surface.h"
#include "..\..\Plugins\SDL\include\SDL_system.h"
#include "..\..\Plugins\SDL\include\SDL_syswm.h"
#include "..\..\Plugins\SDL\include\SDL_test.h"
#include "..\..\Plugins\SDL\include\SDL_test_assert.h"
#include "..\..\Plugins\SDL\include\SDL_test_common.h"
#include "..\..\Plugins\SDL\include\SDL_test_compare.h"
#include "..\..\Plugins\SDL\include\SDL_test_crc32.h"
#include "..\..\Plugins\SDL\include\SDL_test_font.h"
#include "..\..\Plugins\SDL\include\SDL_test_fuzzer.h"
#include "..\..\Plugins\SDL\include\SDL_test_harness.h"
#include "..\..\Plugins\SDL\include\SDL_test_images.h"
#include "..\..\Plugins\SDL\include\SDL_test_log.h"
#include "..\..\Plugins\SDL\include\SDL_test_md5.h"
#include "..\..\Plugins\SDL\include\SDL_test_random.h"
#include "..\..\Plugins\SDL\include\SDL_thread.h"
#include "..\..\Plugins\SDL\include\SDL_timer.h"
#include "..\..\Plugins\SDL\include\SDL_touch.h"
#include "..\..\Plugins\SDL\include\SDL_types.h"
#include "..\..\Plugins\SDL\include\SDL_version.h"
#include "..\..\Plugins\SDL\include\SDL_video.h"
