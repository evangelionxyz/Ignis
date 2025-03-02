#pragma once
#include <gl/gl.h>

#define GL_CHECK()  while (glGetError() != GL_NO_ERROR) { LOG_ASSERT("GL_ERROR: {}", glGetError()); }