rem   *** validation ***
call scripts\run-validator-tests.bat
call scripts\run-checker-tests.bat

rem    *** tests ***
md tests
call scripts\gen-input-via-stdout.bat "files\gen.exe random 1 100 1" "tests\02" 2
call scripts\gen-input-via-stdout.bat "files\gen.exe random 1 1 1" "tests\03" 3
call scripts\gen-input-via-stdout.bat "files\gen.exe random 1 100 5" "tests\04" 4
call scripts\gen-input-via-stdout.bat "files\gen.exe max_mex 200000 0 200000" "tests\05" 5
call scripts\gen-input-via-stdout.bat "files\gen.exe k0_evens 200000 0 400000" "tests\06" 6
call scripts\gen-input-via-stdout.bat "files\gen.exe random 200000 0 150000" "tests\07" 7
call scripts\gen-input-via-stdout.bat "files\gen.exe random 200000 0 1000000" "tests\08" 8
call scripts\gen-input-via-stdout.bat "files\gen.exe k1_killer 3 1 10 1 2" "tests\09" 9
call scripts\gen-input-via-stdout.bat "files\gen.exe k1_killer 5 1 20 1 4" "tests\10" 10
call scripts\gen-input-via-stdout.bat "files\gen.exe k1_killer 200000 1 300000 1 100000" "tests\11" 11
call scripts\gen-input-via-stdout.bat "files\gen.exe max_mex 200000 1 200000" "tests\12" 12
call scripts\gen-input-via-stdout.bat "files\gen.exe random 200000 1 400000" "tests\13" 13
call scripts\gen-input-via-stdout.bat "files\gen.exe constructible 200000 998244353 1000000000 20" "tests\14" 14
call scripts\gen-input-via-stdout.bat "files\gen.exe constructible 200000 100 500 50" "tests\15" 15
call scripts\gen-input-via-stdout.bat "files\gen.exe constructible 200000 42 1000000000 100" "tests\16" 16
call scripts\gen-input-via-stdout.bat "files\gen.exe constructible 200000 200001 500000 1000" "tests\17" 17
call scripts\gen-input-via-stdout.bat "files\gen.exe constructible 200000 7 50000 5000" "tests\18" 18
call scripts\gen-input-via-stdout.bat "files\gen.exe constructible 200000 12345 200000 100000" "tests\19" 19
call scripts\gen-input-via-stdout.bat "files\gen.exe constructible 200000 199999 300000 190000" "tests\20" 20
call scripts\gen-input-via-stdout.bat "files\gen.exe max_mex 200000 987654321 200000" "tests\21" 21
call scripts\gen-input-via-stdout.bat "files\gen.exe small_mex 200000 987654321 1000000000" "tests\22" 22
call scripts\gen-input-via-stdout.bat "files\gen.exe rem_heavy 200000 5 100000 1000" "tests\23" 23
call scripts\gen-input-via-stdout.bat "files\gen.exe constructible 200000 1000000000 1000000000 5" "tests\24" 24
call scripts\gen-answer.bat tests\01 tests\01.a "tests" "1"
call scripts\gen-answer.bat tests\02 tests\02.a "tests" "2"
call scripts\gen-answer.bat tests\03 tests\03.a "tests" "2"
call scripts\gen-answer.bat tests\04 tests\04.a "tests" "2"
call scripts\gen-answer.bat tests\05 tests\05.a "tests" "3"
call scripts\gen-answer.bat tests\06 tests\06.a "tests" "3"
call scripts\gen-answer.bat tests\07 tests\07.a "tests" "3"
call scripts\gen-answer.bat tests\08 tests\08.a "tests" "3"
call scripts\gen-answer.bat tests\09 tests\09.a "tests" "4"
call scripts\gen-answer.bat tests\10 tests\10.a "tests" "4"
call scripts\gen-answer.bat tests\11 tests\11.a "tests" "4"
call scripts\gen-answer.bat tests\12 tests\12.a "tests" "4"
call scripts\gen-answer.bat tests\13 tests\13.a "tests" "4"
call scripts\gen-answer.bat tests\14 tests\14.a "tests" "5"
call scripts\gen-answer.bat tests\15 tests\15.a "tests" "5"
call scripts\gen-answer.bat tests\16 tests\16.a "tests" "5"
call scripts\gen-answer.bat tests\17 tests\17.a "tests" "5"
call scripts\gen-answer.bat tests\18 tests\18.a "tests" "5"
call scripts\gen-answer.bat tests\19 tests\19.a "tests" "5"
call scripts\gen-answer.bat tests\20 tests\20.a "tests" "5"
call scripts\gen-answer.bat tests\21 tests\21.a "tests" "5"
call scripts\gen-answer.bat tests\22 tests\22.a "tests" "5"
call scripts\gen-answer.bat tests\23 tests\23.a "tests" "5"
call scripts\gen-answer.bat tests\24 tests\24.a "tests" "5"

