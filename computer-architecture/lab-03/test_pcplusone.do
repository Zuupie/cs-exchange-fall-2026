# COMP4300 Lab 3 - test pcplusone (5 ns delay, acts on rising clock edge)
vsim -voptargs=+acc work.pcplusone
add wave -radix binary      /pcplusone/clock
add wave -radix hexadecimal /pcplusone/input
add wave -radix hexadecimal /pcplusone/output

# clock 0, input 0 -> no edge yet, output stays 00000000
force clock 0
force input 16#00000000
run 20ns

# rising edge -> output 00000001
force clock 1
run 20ns

# input changes while clock stays 1 -> NO change (no new edge), output 00000001
force input 16#00000005
run 20ns

# next rising edge -> output 00000006
force clock 0
run 20ns
force clock 1
run 20ns

# carry across many bits: 0000FFFF + 1 -> 00010000
force clock 0
force input 16#0000FFFF
run 20ns
force clock 1
run 20ns

# wrap-around: FFFFFFFF + 1 -> 00000000
force clock 0
force input 16#FFFFFFFF
run 20ns
force clock 1
run 20ns

wave zoom full
