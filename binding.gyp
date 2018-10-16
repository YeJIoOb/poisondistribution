{
	"targets": [{
		"target_name": "myModule",
		"include_dirs" : [
			"src",
			"<!(node -e \"require('nan')\")"
		],
    "cflags": ["-fexceptions"],
		"sources": [
			"src/alglib/ap.cpp",
      "src/alglib/integration.cpp",
      "src/alglib/interpolation.cpp",
      "src/alglib/alglibinternal.cpp",
      "src/alglib/linalg.cpp",
      "src/alglib/alglibmisc.cpp",
      "src/alglib/specialfunctions.cpp",
      "src/alglib/solvers.cpp",
      "src/alglib/optimization.cpp",
			"src/index.cc"
		]
	}]
}