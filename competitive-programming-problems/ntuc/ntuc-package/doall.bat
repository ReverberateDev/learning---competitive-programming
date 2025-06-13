rem   *** validation ***
call scripts\run-validator-tests.bat
call scripts\run-checker-tests.bat

rem    *** tests ***
md tests
call scripts\gen-input-via-stdout.bat "files\gen.exe random 1 100 3 10000" "tests\02" 2
call scripts\gen-input-via-stdout.bat "files\gen.exe random 1 1000000000 3 10000 --no-infinite" "tests\03" 3
call scripts\gen-input-via-stdout.bat "files\gen.exe random 1 100000000000000 1 10000 --p-min=2" "tests\04" 4
call scripts\gen-input-via-stdout.bat "files\gen.exe random 1 100000000000000 1 9999 --p-min=2" "tests\05" 5
call scripts\gen-input-via-stdout.bat "files\gen.exe random 50 100000 1 10000 --p-min=2" "tests\06" 6
call scripts\gen-input-via-stdout.bat "files\gen.exe random 100000 100 1 10000 --p-min=2" "tests\07" 7
call scripts\gen-input-via-stdout.bat "files\gen.exe random 100000 100000000000000 1 10000 --p-min=2" "tests\08" 8
call scripts\gen-input-via-stdout.bat "files\gen.exe random 100000 100000000000000 1 9998 --p-min=2" "tests\09" 9
call scripts\gen-input-via-stdout.bat "files\gen.exe random 100000 100000000000000 2 10000 --no-infinite" "tests\10" 10
call scripts\gen-input-via-stdout.bat "files\gen.exe random 100000 100000000000000 2 10000 --no-infinite --k-equals-total-stock" "tests\11" 11
call scripts\gen-input-via-stdout.bat "files\gen.exe random 50000 100000000000000 2 5000 --no-infinite" "tests\12" 12
call scripts\gen-input-via-stdout.bat "files\gen.exe random 100000 100000000000000 2 9999 --no-infinite" "tests\13" 13
call scripts\gen-input-via-stdout.bat "files\gen.exe random 100000 100000000000000 3 10000 --no-infinite" "tests\14" 14
call scripts\gen-input-via-stdout.bat "files\gen.exe random 100000 100000000000000 3 10000" "tests\15" 15
call scripts\gen-input-via-stdout.bat "files\gen.exe rev_sorted 100000 95000 10000" "tests\16" 16
call scripts\gen-input-via-stdout.bat "files\gen.exe long_long" "tests\17" 17
call scripts\gen-input-via-stdout.bat "files\gen.exe random 100000 100000000000000 3 10000 --no-infinite --k-equals-total-stock" "tests\18" 18
call scripts\gen-input-via-stdout.bat "files\gen.exe random 100000 100000000000000 0 10000" "tests\19" 19
call scripts\gen-input-via-stdout.bat "files\gen.exe random 100000 100000000000000 3 1" "tests\20" 20
call scripts\gen-input-via-stdout.bat "files\gen.exe random 100000 100000000000000 3 9997" "tests\21" 21
call scripts\gen-answer.bat tests\01 tests\01.a "tests" "1"
call scripts\gen-answer.bat tests\02 tests\02.a "tests" "2"
call scripts\gen-answer.bat tests\03 tests\03.a "tests" "2"
call scripts\gen-answer.bat tests\04 tests\04.a "tests" "2"
call scripts\gen-answer.bat tests\05 tests\05.a "tests" "2"
call scripts\gen-answer.bat tests\06 tests\06.a "tests" "3"
call scripts\gen-answer.bat tests\07 tests\07.a "tests" "3"
call scripts\gen-answer.bat tests\08 tests\08.a "tests" "3"
call scripts\gen-answer.bat tests\09 tests\09.a "tests" "3"
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

