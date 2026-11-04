# COMP4300 Lab 3 - test three-way mux (5 ns delay)
vsim -voptargs=+acc work.threeway_mux
add wave -radix binary      /threeway_mux/which
add wave -radix hexadecimal /threeway_mux/input_0
add wave -radix hexadecimal /threeway_mux/input_1
add wave -radix hexadecimal /threeway_mux/input_2
add wave -radix hexadecimal /threeway_mux/output

force input_0 16#00000000
force input_1 16#11111111
force input_2 16#22222222

# which = 00 -> output 00000000 (input_0)
force which 00
run 30ns

# which = 01 -> output 11111111 (input_1)
force which 01
run 30ns

# which = 10 -> output 22222222 (input_2)
force which 10
run 30ns

# input_2 changes while selected -> output follows to ABCDEF01
force input_2 16#ABCDEF01
run 30ns

# which = 11 (invalid select) -> output 00000000
force which 11
run 30ns

wave zoom full
