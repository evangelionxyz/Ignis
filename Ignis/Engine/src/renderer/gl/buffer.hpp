#ifndef BUFFER_HPP
#define BUFFER_HPP
#include <core/object.hpp>

class GLBuffer : public Object {
protected:
    u32 m_id = 0;
};

#endif //BUFFER_HPP
