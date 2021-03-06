/**
* Example from https://www.gnu.org/software/bison/manual/html_node/A-Complete-C_002b_002b-Example.html
*/

// The implementation of the driver is straightforward. The parse member
// function deserves some attention. The error functions are simple stubs, they
// should actually register the located error messages and set error state.

#include "calc.driver.hh"
#include "parse/calc.tab.hh"

calc_driver::calc_driver () : trace_scanning (false), trace_parsing (false) {
  variables["one"] = 1;
  variables["two"] = 2;
}

calc_driver::~calc_driver () {
}

int calc_driver::parse (const std::string &f) {
  file = f;
  scan_begin ();
  yy::calc_parser parser (*this);
  parser.set_debug_level (trace_parsing);
  int res = parser.parse ();
  scan_end ();
  return res;
}

void calc_driver::error (const yy::location& l, const std::string& m) {
  std::cerr << l << ": " << m << std::endl;
}

void calc_driver::error (const std::string& m) {
  std::cerr << m << std::endl;
}

