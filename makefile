1143:
	g++ '.\1143 Largest Common Substring\One.cpp' -o 'Largest Common Substring One.exe'
	g++ '.\1143 Largest Common Substring\Two.cpp' -o 'Largest Common Substring Two.exe'
	g++ '.\1143 Largest Common Substring\Three.cpp' -o 'Largest Common Substring Three.exe'


# if exist "114*" (for %S in (114*) do ( for %M in (%S\*.cpp) do ( echo %M ))) 

run:
	@if exist "$(PROBLEM)*" ( \
		if($(SOLUTION) == "") ( \
			for %%S in ($(PROBLEM)*) do ( \
				if exist "%%S\*.cpp" ( \
					for %%M in (%%S\*.cpp) do ( \
						g++ "%%M" -o "%%S_%%M.exe" \
					) \
				) else ( \
					echo Solution not found for problem %%S \
				) \
			) \
		) else ( \
			if exist "$(PROBLEM)\$(SOLUTION).cpp" ( \
				g++ "$(PROBLEM)\$(SOLUTION).cpp" -o "$(PROBLEM)_$(SOLUTION).exe" \
			) else ( \
				echo Solution not found for problem $(PROBLEM) \
			) \
		) \
	) else ( \
		echo Problem not found \
	)
	