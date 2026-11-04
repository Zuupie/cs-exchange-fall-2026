-- COMP4300 Lab 3: Aubie datapath building blocks
--   dlx_register, reg_file, mux, threeway_mux, pcplusone
-- Uses types from dlx_types and routines from bv_arithmetic (from Lab 2).
-- Note: use clauses apply only to the next design unit, so they are
-- repeated before each entity.

---------------------------------------------------------------------
-- 32-bit single-value register (10 ns delay)
-- While clock = 1 the input is copied to the output;
-- while clock = 0 the output is frozen.
---------------------------------------------------------------------
use work.dlx_types.all;

entity dlx_register is
  port(in_val  : in  dlx_word;
       clock   : in  bit;
       out_val : out dlx_word);
end entity dlx_register;

architecture behavior of dlx_register is
begin
  reg_proc : process (in_val, clock)
  begin
    if clock = '1' then
      out_val <= in_val after 10 ns;
    end if;
    -- clock = '0': no assignment, so out_val keeps its last value
  end process reg_proc;
end architecture behavior;


---------------------------------------------------------------------
-- Register file R0-R31 (15 ns read delay, no output on write)
-- readnotwrite = 1: data_out <= registers(reg_number)
-- readnotwrite = 0: registers(reg_number) := data_in
---------------------------------------------------------------------
use work.dlx_types.all;
use work.bv_arithmetic.all;

entity reg_file is
  port(data_in      : in  dlx_word;
       readnotwrite : in  bit;
       clock        : in  bit;
       data_out     : out dlx_word;
       reg_number   : in  register_index);
end entity reg_file;

architecture behavior of reg_file is
begin
  reg_file_proc : process (data_in, readnotwrite, clock, reg_number)
    type reg_type is array (0 to 31) of dlx_word;
    variable registers : reg_type;  -- every register starts at all zeros
  begin
    if clock = '1' then
      if readnotwrite = '1' then
        -- read: data_in is ignored
        data_out <= registers(bv_to_natural(reg_number)) after 15 ns;
      else
        -- write: store immediately, data_out not meaningful
        registers(bv_to_natural(reg_number)) := data_in;
      end if;
    end if;
  end process reg_file_proc;
end architecture behavior;


---------------------------------------------------------------------
-- Two-way multiplexer
-- which = 0 -> input_0, which = 1 -> input_1
---------------------------------------------------------------------
use work.dlx_types.all;

entity mux is
  generic(prop_delay : Time := 5 ns);
  port(input_1, input_0 : in  dlx_word;
       which            : in  bit;
       output           : out dlx_word);
end entity mux;

architecture behavior of mux is
begin
  mux_proc : process (input_1, input_0, which)
  begin
    if which = '1' then
      output <= input_1 after prop_delay;
    else
      output <= input_0 after prop_delay;
    end if;
  end process mux_proc;
end architecture behavior;


---------------------------------------------------------------------
-- Three-way multiplexer
-- which = 00 -> input_0, 01 -> input_1, 10 -> input_2
-- which = 11 is not a valid select code: output all zeros
---------------------------------------------------------------------
use work.dlx_types.all;

entity threeway_mux is
  generic(prop_delay : Time := 5 ns);
  port(input_2, input_1, input_0 : in  dlx_word;
       which                     : in  threeway_muxcode;
       output                    : out dlx_word);
end entity threeway_mux;

architecture behavior of threeway_mux is
begin
  threeway_proc : process (input_2, input_1, input_0, which)
  begin
    case which is
      when "00"   => output <= input_0 after prop_delay;
      when "01"   => output <= input_1 after prop_delay;
      when "10"   => output <= input_2 after prop_delay;
      when others => output <= (others => '0') after prop_delay;
    end case;
  end process threeway_proc;
end architecture behavior;


---------------------------------------------------------------------
-- PC incrementer
-- On a rising clock edge (0 -> 1), output <= input + 1 (unsigned).
-- Overflow simply wraps around to zero.
---------------------------------------------------------------------
use work.dlx_types.all;
use work.bv_arithmetic.all;

entity pcplusone is
  generic(prop_delay : Time := 5 ns);
  port(input  : in  dlx_word;
       clock  : in  bit;
       output : out dlx_word);
end entity pcplusone;

architecture behavior of pcplusone is
begin
  pc_proc : process (input, clock)
    constant one_word : dlx_word := (0 => '1', others => '0');
  begin
    -- only act when the clock has just changed to 1
    if clock'event and clock = '1' then
      output <= bv_addu(input, one_word) after prop_delay;
    end if;
  end process pc_proc;
end architecture behavior;
