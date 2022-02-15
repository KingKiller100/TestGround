#pragma once

#include <string>
#include <stdexcept>

namespace debug
{
	std::string ReportNestedExceptions( std::exception_ptr ePtr = std::current_exception() );
}
