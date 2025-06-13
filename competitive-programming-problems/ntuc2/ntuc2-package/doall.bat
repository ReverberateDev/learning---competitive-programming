rem   *** validation ***
call scripts\run-validator-tests.bat
call scripts\run-checker-tests.bat

rem    *** tests ***
md tests
call scripts\gen-input-via-stdout.bat "files\gen.exe --n=1 --q=1 --max_val=10" "tests\02" 2
call scripts\gen-input-via-stdout.bat "files\gen.exe --n=2 --q=50 --max_val=1 --p_create=1.0" "tests\03" 3
call scripts\gen-input-via-stdout.bat "files\gen.exe --n=1000 --q=1000 --max_val=100" "tests\04" 4
call scripts\gen-input-via-stdout.bat "files\gen.exe --n=500 --q=500 --max_val=1e9 --p_create=0.6 --p_destroy=0.3" "tests\05" 5
call scripts\gen-input-via-stdout.bat "files\gen.exe --n=2000 --q=2000 --max_val=1e9 --p_create=0.5 --p_destroy=0.4" "tests\06" 6
call scripts\gen-input-via-stdout.bat "files\gen.exe --n=2000 --q=2000 --max_val=1e9 --p_create=0.4 --p_destroy=0.5" "tests\07" 7
call scripts\gen-input-via-stdout.bat "files\gen.exe --n=200000 --q=200000 --max_val=1000000 --p_create=0.5 --p_destroy=0.4" "tests\08" 8
call scripts\gen-input-via-stdout.bat "files\gen.exe --n=200000 --q=200000 --min_val=999900 --max_val=1000000 --p_create=0.6 --p_destroy=0.3" "tests\09" 9
call scripts\gen-input-via-stdout.bat "files\gen.exe --n=200000 --q=1000 --max_val=1000000" "tests\10" 10
call scripts\gen-input-via-stdout.bat "files\gen.exe --n=1000 --q=200000 --max_val=1000000 --p_create=0.5 --p_destroy=0.4" "tests\11" 11
call scripts\gen-input-via-stdout.bat "files\gen.exe --n=200000 --q=200000 --min_val=1000001 --max_val=2000000 --p_create=0.5 --p_destroy=0.4" "tests\12" 12
call scripts\gen-input-via-stdout.bat "files\gen.exe --n=200000 --q=200000 --max_val=1000000000 --p_create=0.6 --p_destroy=0.3" "tests\13" 13
call scripts\gen-input-via-stdout.bat "files\gen.exe --n=200000 --q=200000 --max_val=1000000000 --p_create=0.5 --p_destroy=0.5" "tests\14" 14
call scripts\gen-input-via-stdout.bat "files\gen.exe --n=200000 --q=200000 --min_val=900000000 --max_val=1000000000" "tests\15" 15
call scripts\gen-answer.bat tests\01 tests\01.a "tests" "1"
call scripts\gen-answer.bat tests\02 tests\02.a "tests" "2"
call scripts\gen-answer.bat tests\03 tests\03.a "tests" "2"
call scripts\gen-answer.bat tests\04 tests\04.a "tests" "2"
call scripts\gen-answer.bat tests\05 tests\05.a "tests" "2"
call scripts\gen-answer.bat tests\06 tests\06.a "tests" "2"
call scripts\gen-answer.bat tests\07 tests\07.a "tests" "2"
call scripts\gen-answer.bat tests\08 tests\08.a "tests" "3"
call scripts\gen-answer.bat tests\09 tests\09.a "tests" "3"
call scripts\gen-answer.bat tests\10 tests\10.a "tests" "3"
call scripts\gen-answer.bat tests\11 tests\11.a "tests" "3"
call scripts\gen-answer.bat tests\12 tests\12.a "tests" "4"
call scripts\gen-answer.bat tests\13 tests\13.a "tests" "4"
call scripts\gen-answer.bat tests\14 tests\14.a "tests" "4"
call scripts\gen-answer.bat tests\15 tests\15.a "tests" "4"

