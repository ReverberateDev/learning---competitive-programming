rem   *** validation ***
call scripts\run-validator-tests.bat
call scripts\run-checker-tests.bat

rem    *** tests ***
md tests
call scripts\gen-input-via-stdout.bat "files\everythingGen.exe -q 1000000 -trainerCnt 10000 -canReuseNames 0 -chanceQuery 50 -labsUsed 5000" "tests\02" 2
call scripts\gen-input-via-stdout.bat "files\everythingGen.exe -q 1000000 -trainerCnt 100 -canReuseNames 0 -chanceQuery 50 -labsUsed 50" "tests\03" 3
call scripts\gen-input-via-stdout.bat "files\everythingGen.exe -q 1000000 -trainerCnt 1000 -canReuseNames 0 -chanceQuery 50 -labsUsed 500" "tests\04" 4
call scripts\gen-input-via-stdout.bat "files\everythingGen.exe -q 1000000 -trainerCnt 100 -canReuseNames 0 -chanceQuery 20 -labsUsed 50" "tests\05" 5
call scripts\gen-input-via-stdout.bat "files\everythingGen.exe -q 1000000 -trainerCnt 1000 -canReuseNames 0 -chanceQuery 20 -labsUsed 500" "tests\06" 6
call scripts\gen-input-via-stdout.bat "files\everythingGen.exe -q 1000000 -trainerCnt 10000 -canReuseNames 0 -chanceQuery 20 -labsUsed 5000" "tests\07" 7
call scripts\gen-input-via-stdout.bat "files\everythingGen.exe -q 1000000 -trainerCnt 100 -canReuseNames 0 -chanceQuery 80 -labsUsed 50" "tests\08" 8
call scripts\gen-input-via-stdout.bat "files\everythingGen.exe -q 1000000 -trainerCnt 1000 -canReuseNames 0 -chanceQuery 80 -labsUsed 500" "tests\09" 9
call scripts\gen-input-via-stdout.bat "files\everythingGen.exe -q 1000000 -trainerCnt 10000 -canReuseNames 0 -chanceQuery 80 -labsUsed 5000" "tests\10" 10
call scripts\gen-input-via-stdout.bat "files\everythingGen.exe -q 1000 -trainerCnt 10000 -canReuseNames 1 -chanceQuery 50 -labsUsed 5000" "tests\11" 11
call scripts\gen-input-via-stdout.bat "files\everythingGen.exe -q 1000 -trainerCnt 100 -canReuseNames 1 -chanceQuery 50 -labsUsed 50" "tests\12" 12
call scripts\gen-input-via-stdout.bat "files\everythingGen.exe -q 1000 -trainerCnt 1000 -canReuseNames 1 -chanceQuery 50 -labsUsed 500" "tests\13" 13
call scripts\gen-input-via-stdout.bat "files\everythingGen.exe -q 1000 -trainerCnt 100 -canReuseNames 1 -chanceQuery 20 -labsUsed 50" "tests\14" 14
call scripts\gen-input-via-stdout.bat "files\everythingGen.exe -q 1000 -trainerCnt 1000 -canReuseNames 1 -chanceQuery 20 -labsUsed 500" "tests\15" 15
call scripts\gen-input-via-stdout.bat "files\everythingGen.exe -q 1000 -trainerCnt 10000 -canReuseNames 1 -chanceQuery 20 -labsUsed 5000" "tests\16" 16
call scripts\gen-input-via-stdout.bat "files\everythingGen.exe -q 1000 -trainerCnt 100 -canReuseNames 1 -chanceQuery 80 -labsUsed 50" "tests\17" 17
call scripts\gen-input-via-stdout.bat "files\everythingGen.exe -q 1000 -trainerCnt 1000 -canReuseNames 1 -chanceQuery 80 -labsUsed 500" "tests\18" 18
call scripts\gen-input-via-stdout.bat "files\everythingGen.exe -q 1000 -trainerCnt 10000 -canReuseNames 1 -chanceQuery 80 -labsUsed 5000" "tests\19" 19
call scripts\gen-input-via-stdout.bat "files\everythingGen.exe -q 100000 -trainerCnt 10000 -canReuseNames 1 -chanceQuery 50 -labsUsed 5000" "tests\20" 20
call scripts\gen-input-via-stdout.bat "files\everythingGen.exe -q 100000 -trainerCnt 100 -canReuseNames 1 -chanceQuery 50 -labsUsed 50" "tests\21" 21
call scripts\gen-input-via-stdout.bat "files\everythingGen.exe -q 100000 -trainerCnt 1000 -canReuseNames 1 -chanceQuery 50 -labsUsed 500" "tests\22" 22
call scripts\gen-input-via-stdout.bat "files\everythingGen.exe -q 100000 -trainerCnt 100 -canReuseNames 1 -chanceQuery 20 -labsUsed 50" "tests\23" 23
call scripts\gen-input-via-stdout.bat "files\everythingGen.exe -q 100000 -trainerCnt 1000 -canReuseNames 1 -chanceQuery 20 -labsUsed 500" "tests\24" 24
call scripts\gen-input-via-stdout.bat "files\everythingGen.exe -q 100000 -trainerCnt 10000 -canReuseNames 1 -chanceQuery 20 -labsUsed 5000" "tests\25" 25
call scripts\gen-input-via-stdout.bat "files\everythingGen.exe -q 100000 -trainerCnt 100 -canReuseNames 1 -chanceQuery 80 -labsUsed 50" "tests\26" 26
call scripts\gen-input-via-stdout.bat "files\everythingGen.exe -q 100000 -trainerCnt 1000 -canReuseNames 1 -chanceQuery 80 -labsUsed 500" "tests\27" 27
call scripts\gen-input-via-stdout.bat "files\everythingGen.exe -q 100000 -trainerCnt 10000 -canReuseNames 1 -chanceQuery 80 -labsUsed 5000" "tests\28" 28
call scripts\gen-input-via-stdout.bat "files\everythingGen.exe -q 1000000 -trainerCnt 10000 -canReuseNames 1 -chanceQuery 50 -labsUsed 5000" "tests\29" 29
call scripts\gen-input-via-stdout.bat "files\everythingGen.exe -q 1000000 -trainerCnt 100 -canReuseNames 1 -chanceQuery 50 -labsUsed 50" "tests\30" 30
call scripts\gen-input-via-stdout.bat "files\everythingGen.exe -q 1000000 -trainerCnt 1000 -canReuseNames 1 -chanceQuery 50 -labsUsed 500" "tests\31" 31
call scripts\gen-input-via-stdout.bat "files\everythingGen.exe -q 1000000 -trainerCnt 100 -canReuseNames 1 -chanceQuery 20 -labsUsed 50" "tests\32" 32
call scripts\gen-input-via-stdout.bat "files\everythingGen.exe -q 1000000 -trainerCnt 1000 -canReuseNames 1 -chanceQuery 20 -labsUsed 500" "tests\33" 33
call scripts\gen-input-via-stdout.bat "files\everythingGen.exe -q 1000000 -trainerCnt 10000 -canReuseNames 1 -chanceQuery 20 -labsUsed 5000" "tests\34" 34
call scripts\gen-input-via-stdout.bat "files\everythingGen.exe -q 1000000 -trainerCnt 100 -canReuseNames 1 -chanceQuery 80 -labsUsed 50" "tests\35" 35
call scripts\gen-input-via-stdout.bat "files\everythingGen.exe -q 1000000 -trainerCnt 1000 -canReuseNames 1 -chanceQuery 80 -labsUsed 500" "tests\36" 36
call scripts\gen-input-via-stdout.bat "files\everythingGen.exe -q 1000000 -trainerCnt 10000 -canReuseNames 1 -chanceQuery 80 -labsUsed 5000" "tests\37" 37
call scripts\gen-input-via-stdout.bat "files\everythingGen.exe -q 1000000 -trainerCnt 100000 -canReuseNames 1 -chanceQuery 5 -labsUsed 50" "tests\38" 38
call scripts\gen-input-via-stdout.bat "files\everythingGen.exe -q 1000000 -trainerCnt 100000 -canReuseNames 1 -chanceQuery 5 -labsUsed 500000" "tests\39" 39
call scripts\gen-input-via-stdout.bat "files\everythingGen.exe -q 1000000 -trainerCnt 100000 -canReuseNames 1 -chanceQuery 95 -labsUsed 50" "tests\40" 40
call scripts\gen-input-via-stdout.bat "files\everythingGen.exe -q 1000000 -trainerCnt 100000 -canReuseNames 1 -chanceQuery 95 -labsUsed 500000" "tests\41" 41
call scripts\gen-input-via-stdout.bat "files\everythingGen.exe -q 1000000 -trainerCnt 1000000 -canReuseNames 1 -chanceQuery 5 -labsUsed 1000000" "tests\42" 42
call scripts\gen-answer.bat tests\01 tests\01.a "tests" ""
call scripts\gen-answer.bat tests\02 tests\02.a "tests" ""
call scripts\gen-answer.bat tests\03 tests\03.a "tests" ""
call scripts\gen-answer.bat tests\04 tests\04.a "tests" ""
call scripts\gen-answer.bat tests\05 tests\05.a "tests" ""
call scripts\gen-answer.bat tests\06 tests\06.a "tests" ""
call scripts\gen-answer.bat tests\07 tests\07.a "tests" ""
call scripts\gen-answer.bat tests\08 tests\08.a "tests" ""
call scripts\gen-answer.bat tests\09 tests\09.a "tests" ""
call scripts\gen-answer.bat tests\10 tests\10.a "tests" ""
call scripts\gen-answer.bat tests\11 tests\11.a "tests" ""
call scripts\gen-answer.bat tests\12 tests\12.a "tests" ""
call scripts\gen-answer.bat tests\13 tests\13.a "tests" ""
call scripts\gen-answer.bat tests\14 tests\14.a "tests" ""
call scripts\gen-answer.bat tests\15 tests\15.a "tests" ""
call scripts\gen-answer.bat tests\16 tests\16.a "tests" ""
call scripts\gen-answer.bat tests\17 tests\17.a "tests" ""
call scripts\gen-answer.bat tests\18 tests\18.a "tests" ""
call scripts\gen-answer.bat tests\19 tests\19.a "tests" ""
call scripts\gen-answer.bat tests\20 tests\20.a "tests" ""
call scripts\gen-answer.bat tests\21 tests\21.a "tests" ""
call scripts\gen-answer.bat tests\22 tests\22.a "tests" ""
call scripts\gen-answer.bat tests\23 tests\23.a "tests" ""
call scripts\gen-answer.bat tests\24 tests\24.a "tests" ""
call scripts\gen-answer.bat tests\25 tests\25.a "tests" ""
call scripts\gen-answer.bat tests\26 tests\26.a "tests" ""
call scripts\gen-answer.bat tests\27 tests\27.a "tests" ""
call scripts\gen-answer.bat tests\28 tests\28.a "tests" ""
call scripts\gen-answer.bat tests\29 tests\29.a "tests" ""
call scripts\gen-answer.bat tests\30 tests\30.a "tests" ""
call scripts\gen-answer.bat tests\31 tests\31.a "tests" ""
call scripts\gen-answer.bat tests\32 tests\32.a "tests" ""
call scripts\gen-answer.bat tests\33 tests\33.a "tests" ""
call scripts\gen-answer.bat tests\34 tests\34.a "tests" ""
call scripts\gen-answer.bat tests\35 tests\35.a "tests" ""
call scripts\gen-answer.bat tests\36 tests\36.a "tests" ""
call scripts\gen-answer.bat tests\37 tests\37.a "tests" ""
call scripts\gen-answer.bat tests\38 tests\38.a "tests" ""
call scripts\gen-answer.bat tests\39 tests\39.a "tests" ""
call scripts\gen-answer.bat tests\40 tests\40.a "tests" ""
call scripts\gen-answer.bat tests\41 tests\41.a "tests" ""
call scripts\gen-answer.bat tests\42 tests\42.a "tests" ""

