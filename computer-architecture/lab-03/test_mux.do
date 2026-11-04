# COMP4300 Lab 3 - test two-way mux (5 ns delay)
vsim -voptargs=+acc work.mux
add wave -radix binary      /mux/which
add wave -radix hexadecimal /mux/input_0
add wave -radix hexadecimal /mux/input_1
add wave -radix hexadecimal /mux/output

force input_0 16#0000AAAA
force input_1 16#1111BBBB

# which = 0 -> output 0000AAAA
force which 0
run 30ns

# which = 1 -> output 1111BBBB
force which 1
run 30ns

# input_1 changes while selected -> output follows to 2222CCCC
force input_1 16#2222CCCC
run 30ns

# input_0 changes while NOT selected -> output stays 2222CCCC
force input_0 16#0000DDDD
run 30ns

# which = 0 -> output 0000DDDD
force which 0
run 30ns

wave zoom full
