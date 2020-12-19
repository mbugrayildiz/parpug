project "sandbox"
	kind "ConsoleApp"
	language "C"

	includedirs {
		(BASE_DIR .. "/parpug/inc")
	}
	files { "src/**.c" }
	links { "parpug" }
