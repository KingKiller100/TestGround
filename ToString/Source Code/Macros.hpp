#pragma once

#define ONLY_TYPE(type) std::decay_t<std::remove_pointer_t<type>>
#define USE_RESULT [[nodiscard]]

#define CAST(type, src) static_cast<type>(src)
