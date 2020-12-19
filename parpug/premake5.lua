project "parpug"
	kind "SharedLib"
	language "C"

	includedirs { "inc" }
	files { "inc/**.h", "src/**.c" }
