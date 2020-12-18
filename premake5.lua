workspace "TimC"
   architecture "x64"
   targetdir "build"
   configurations { "Debug", "Release" }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "TimC"
   location "TimC"
   kind "ConsoleApp"
   language "C++"
   cppdialect "C++17"
   targetdir ("bin/" .. outputdir .. "/%{prj.name}")

   files 
   { 
      "%{prj.name}/src/**.h",
      "%{prj.name}/src/**.c",
      "%{prj.name}/src/**.hpp",
      "%{prj.name}/src/**.cpp"
   }

   includedirs
   {
      "%{prj.name}/src"
   }

   filter "configurations:Debug"
      defines { "DEBUG" }
      symbols "On"

   filter "configurations:Release"
      defines { "RELEASE" }
      optimize "On"