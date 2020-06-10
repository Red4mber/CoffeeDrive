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

project "CoffeeDrive"
	location "CoffeeDrive"
	kind "SharedLib"
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
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "on"
		systemversion "10.0.18362.0"

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
		"CoffeeDrive/vendor/spdlog/include",
		"CoffeeDrive/src"
	}

	links
	{
		"CoffeeDrive"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "on"
		systemversion "10.0.18362.0"

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