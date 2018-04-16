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
expect "How much time will the flight take? (in minutes) " {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
send "240\r"
expect "How many movies are there in the list? " {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
send "6\r"
expect "Please write their lengths: " {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
send "60\r"
send "140\r"
send "160\r"
send "120\r"
send "100\r"
send "70\r"
expect "First movie: 140 minutes and Second movie: 100 minutes" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}