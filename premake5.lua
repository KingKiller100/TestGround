workspace "Stringify"
    architecture "x86_64"
    startproject "ToString"

    configurations
    {
        "Debug",
        "Release"
    }

    flags
    {
        "MultiProcessorCompile"
    }

    OutputDir = "%{cfg.buildcfg}_%{cfg.system}_%{cfg.architecture}\\"

project "ToString"
    location "ToString/"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++latest"
    characterset ("default")
	staticruntime "on"

    targetdir ("ToString/bin/" .. OutputDir .. "/%{prj.name}")
    objdir ("ToString/bin-int/" .. OutputDir .. "/%{prj.name}")

    -- pchheader "Precompile.hpp"
    -- pchsource "Krakoa/Source Files/Precompile.cpp"

    files
    {
        "Source Files/**.hpp",
        "Source Files/**.cpp",
        "cpp.hint"
    }

    includedirs
    {
        "Source Files/",
    }

    defines
	{
        "KLIB_SHORT_NAMESPACE",
        "_CRT_SECURE_NO_WARNINGS"
	}

    filter "system:Windows"
    systemversion "latest"

    defines
    {
        "_CRT_SECURE_NO_WARNINGS",
        "KLIB_LIB",
        "KLIB_WINDOWS_OS",
        "MSVC_PLATFORM_TOOLSET=$(PlatformToolsetVersion)"
    }

    filter "configurations:Debug"
        defines "KLIB_DEBUG"
        symbols "On"
        runtime "Debug"

    -- filter "configurations:Release"
    --     defines "KLIB_RELEASE"
    --     optimize "Full"
    --     runtime "Release"