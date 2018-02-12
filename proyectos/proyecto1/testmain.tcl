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
expect "Please write your sequence string: " {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
send "6C QD 6S KS 7S *\r"
send "*QHS\r"
expect "YES" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
expect "7S KS 6S 6C *6D QDS" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}