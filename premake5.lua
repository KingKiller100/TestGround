workspace "TestGround"
    architecture "x86_64"
    startproject "TestGround"

    configurations
    {
        "Test",
        "Release"
    }

    flags
    {
        "MultiProcessorCompile"
    }

    OutputDir = "%{cfg.buildcfg}_%{cfg.system}_%{cfg.architecture}\\"

IncludeDir = {}
IncludeDir["KLIB_CORE"] = "../kLibrary/Source Files/"
IncludeDir["KLIB_TEST"] = "../kLibrary/Tests/",

group "Subjects"
    include "../kLibrary/"
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
        "TestGround/Source Code/**.hpp",
        "TestGround/Source Code/**.cpp",
        -- "cpp.hint"
    }

    includedirs
    {
        "%{IncludeDir.KLIB_CORE}",
        "%{IncludeDir.KLIB_TEST}",
        "TestGround/Source Code/",
    }

    defines
	{
        "KLIB_SHORT_NAMESPACE",
        "_CRT_SECURE_NO_WARNINGS"
    }
    
    links
    {
        "kLibrary",
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

    filter "configurations:Test"
        defines
        {
            "KLIB_TEST",
        }
        symbols "On"
        runtime "Debug"

    filter "configurations:Release"
        defines
        { 
            "KLIB_RELEASE",
            "KLIB_TEST",
        }
        optimize "Full"
        runtime "Release"

    filter "configurations:Profile"
        defines "KLIB_PROFILE"
        optimize "Speed"
        runtime "Release"