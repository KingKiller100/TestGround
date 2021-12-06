#pragma once

#include <string>
#include <stdexcept>

namespace debug
{
	std::string UnwrapNestedExceptions( std::exception_ptr ePtr = std::current_exception() );
}
