workspace "wm"
configurations { "Debug", "Release" }

project "north_wm"
    targetdir    "bin/%{cfg.buildcfg}"
    objdir       "obj/%{cfg.buildcfg}"
    kind        "ConsoleApp"
    language  "C++"   
    targetdir "bin/%{cfg.buildcfg}"


    files { 
        "./src/**.h",
        "./src/**.hpp",
        "./src/**.c",
        "./src/**.cpp"
    }

    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols  "On"

    filter  "configurations:Release"
        defines  { "NDEBUG" }
        symbols  "Off"
        optimize "On"