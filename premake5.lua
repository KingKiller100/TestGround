workspace "TestGround"
    architecture "x86_64"
    startproject "TestGround"

    configurations
    {
        "Test"
    }

    flags
    {
        "MultiProcessorCompile"
    }

    OutputDir = "%{cfg.buildcfg}_%{cfg.system}_%{cfg.architecture}\\"

IncludeDir = {}
IncludeDir["KLIB_CORE"] = "../kLibrary/Source/"
IncludeDir["KLIB_TEST"] = "../kLibrary/Tests/",

group "Subjects"
    include "../kLibrary/"
    include "../kLibrary/Tests/"
group ""
    
project "TestGround"
    location "TestGround/"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++latest"
    characterset ("default")
	staticruntime "on"
    symbols "On"
    runtime "Debug"
    
    targetdir ("bin/" .. OutputDir .. "/")
    objdir ("bin-int/" .. OutputDir .. "/")

    files
    {
        "TestGround/Src/**.hpp",
        "TestGround/Src/**.cpp",
    }

    includedirs
    {
        "%{IncludeDir.KLIB_TEST}",
        "%{IncludeDir.KLIB_CORE}",
        "TestGround/Source Code/",
    }

    defines
	{
        "KLIB_TEST",
        "KLIB_SHORT_NAMESPACE",
        "KLOG_OPT_DBG_STR",
        "_CRT_SECURE_NO_WARNINGS"
    }

    links
    {
        -- "kLibrary",
        "kTest",
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

