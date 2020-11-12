workspace "TestGround"
    architecture "x86_64"
    startproject "TestGround"

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

IncludeDir = {}
IncludeDir["KLIB"] = "kLibrary/Source Files/"

group "Subjects"
    include "kLibrary/"
group ""
    
project "TestGround"
    location "TestGround/"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++latest"
    characterset ("default")
	staticruntime "on"

    targetdir ("bin/" .. OutputDir .. "/%{prj.name}")
    objdir ("bin-int/" .. OutputDir .. "/%{prj.name}")

    files
    {
        "%{IncludeDir.KLIB}",
        "TestGround/Source Code/**.hpp",
        "TestGround/Source Code/**.cpp",
        -- "cpp.hint"
    }

    includedirs
    {
        "%{IncludeDir.KLIB}",
        "TestGround/Source Code/",
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