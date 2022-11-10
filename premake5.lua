solution "wm"
    configurations { "Core" }
    
    project "wm"
        language "C++"
        targetdir "bin"
        objdir "obj"
        kind "ConsoleApp"
        files { "src/**.c", "src/**.h", "src/**.cpp", "src/**.hpp" }
        includedirs {"src"}
        optimize "On"
        libdirs { os.findlib("X11") }
        links {"X11"}