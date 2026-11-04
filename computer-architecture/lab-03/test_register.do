# COMP4300 Lab 3 - test dlx_register (10 ns delay)
vsim -voptargs=+acc work.dlx_register
add wave -radix binary      /dlx_register/clock
add wave -radix hexadecimal /dlx_register/in_val
add wave -radix hexadecimal /dlx_register/out_val

# 0-50 ns: clock = 0, input present -> output stays 00000000 (nothing stored yet)
force clock 0
force in_val 16#11111111
run 50ns

# 50-100 ns: clock = 1 -> output becomes 11111111 at 60 ns
force clock 1
run 50ns

# 100-150 ns: input changes while clock = 1 -> output follows to 22222222 at 110 ns
force in_val 16#22222222
run 50ns

# 150-200 ns: clock = 0 -> output frozen at 22222222
force clock 0
run 50ns

# 200-250 ns: input changes while clock = 0 -> output STILL 22222222
force in_val 16#33333333
run 50ns

# 250-300 ns: clock = 1 again -> output becomes 33333333 at 260 ns
force clock 1
run 50ns

wave zoom full
