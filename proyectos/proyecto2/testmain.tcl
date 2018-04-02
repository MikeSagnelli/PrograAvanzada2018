#!/usr/bin/expect -f

# For colors
proc capability cap {expr {![catch {exec tput -S << $cap}]}}
proc colorterm {} {expr {[capability setaf] && [capability setab]}}
proc tput args {exec tput -S << $args >/dev/tty}
array set color {black 0 red 1 green 2 yellow 3 blue 4 magenta 5 cyan 6 white 7}
proc foreground x {exec tput -S << "setaf $::color($x)" > /dev/tty}
proc background x {exec tput -S << "setab $::color($x)" > /dev/tty}
proc reset {} {exec tput sgr0 > /dev/tty}

#Test the program
eval spawn [lrange $argv 0 end]

#Put your test case here
send "4\r"
send "2 1\r"
send "^\r"
send "^\r"
send "2 2\r"
send ">v\r"
send "^<\r"
send "3 3\r"
send "...\r"
send ".^.\r"
send "...\r"
send "1 1\r"
send ".\r"
expect "Case #0: 1" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
expect "Case #1: 0" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
expect "Case #2: IMPOSSIBLE" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
expect "Case #3: 0" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}