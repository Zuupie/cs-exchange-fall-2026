entity full_adder is
	port ( 
		carry_in, a_in, b_in : in bit;
		result, carry_out : out bit
);
end entity full_adder;

architecture behavior of full_adder is
begin
	adder_proc : process (carry_in, a_in, b_in)
	begin
		result <= a_in xor b_in xor carry_in after 10ns;
		carry_out <= (a_in and b_in) or (carry_in and (a_in xor b_in)) after 10ns;
	end process adder_proc;
end architecture behavior;