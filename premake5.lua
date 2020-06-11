-- premake5.lua

workspace "CoffeeDrive"
	architecture "x64"
	startproject "Sandbox"

	configurations 
	{
		"Debug",
		"Release",
		"Dist"
	}
	
	outputDir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
	
	-- DEPENDENCIES
	IncludeDir = {}
	IncludeDir['GLFW'] = "CoffeeDrive/vendor/GLFW/include"
	IncludeDir['spdlog'] = "CoffeeDrive/vendor/spdlog/include"
	
	include "CoffeeDrive/vendor/GLFW" -- Including the glfw premake script 


project "CoffeeDrive"
	location "CoffeeDrive"
	kind "SharedLib"
	language "c++"

	targetdir ("bin/"..outputDir.."/%{prj.name}")
	objdir ("bin-int/"..outputDir.."/%{prj.name}")

	pchheader "cf_pch.h"
	pchsource "CoffeeDrive/src/cf_pch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{IncludeDir.spdlog}",
		"%{IncludeDir.GLFW}"
	}

	links {
		"GLFW",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "on"
		systemversion "latest"

		defines
		{
			"CF_BUILD_DLL",
			"CF_PLATFORM_WINDOWS"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/"..outputDir.."/Sandbox")
		}

	filter "configurations:Debug"
		defines "CF_DEBUG"
		symbols "on"

	filter "configurations:Release"
		defines "CF_RELEASE"
		optimize "on"

	filter "configurations:Dist"
		defines "CF_DIST"
		optimize "on"


project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "c++"

	targetdir ("bin/"..outputDir.."/%{prj.name}")
	objdir ("bin-int/"..outputDir.."/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{IncludeDir.spdlog}",
		"CoffeeDrive/src"
	}

	links
	{
		"CoffeeDrive"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "on"
		systemversion "latest"

		defines
		{
			"CF_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "CF_DEBUG"
		symbols "on"

	filter "configurations:Release"
		defines "CF_RELEASE"
		optimize "on"

	filter "configurations:Dist"
		defines "CF_DIST"
		optimize "on"