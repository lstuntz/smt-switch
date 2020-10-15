#include "z3_solver.h"

#include <inttypes.h>

#include <z3++.h>
// #include "z3_extensions.h"

using namespace std;

namespace smt {

/* Z3 Op mappings */
// typedef term_t (*yices_un_fun)(term_t);
// typedef term_t (*yices_bin_fun)(term_t, term_t);
// typedef term_t (*yices_tern_fun)(term_t, term_t, term_t);
// typedef term_t (*yices_variadic_fun)(uint32_t, term_t[]);

// TODO's:
// Pretty sure not implemented in Yices.
// Good candidates for extension.
//  To_Real,
//  BVComp,
//  BV_To_Nat,

// Arrays are represented as functions in Yices.
// I don't think const_array can be supported,
// unless we use Yices lambdas.
// Const_Array,

// const unordered_map<PrimOp, yices_un_fun> yices_unary_ops(
//     { { Not, yices_not },
//       { Negate, yices_neg },
//       { Abs, yices_abs },
//       { To_Int, yices_floor },
//       { Is_Int, yices_is_int_atom },
//       { BVNot, yices_bvnot },
//       { BVNeg, yices_bvneg } });

// const unordered_map<PrimOp, yices_bin_fun> yices_binary_ops(
//     { { And, yices_and2 },          { Or, yices_or2 },
//       { Xor, yices_xor2 },          { Implies, yices_implies },
//       { Iff, yices_iff },           { Plus, yices_add },
//       { Minus, yices_sub },         { Mult, yices_mul },
//       { Div, yices_division },      { Lt, yices_arith_lt_atom },
//       { IntDiv, yices_idiv },       { Le, yices_arith_leq_atom },
//       { Gt, yices_arith_gt_atom },  { Ge, yices_arith_geq_atom },
//       { Equal, yices_eq },          { Mod, yices_imod },
//       { Concat, yices_bvconcat2 },  { BVAnd, yices_bvand2 },
//       { BVOr, yices_bvor2 },        { BVXor, yices_bvxor2 },
//       { BVNand, yices_bvnand },     { BVNor, yices_bvnor },
//       { BVXnor, yices_bvxnor },     { BVAdd, yices_bvadd },
//       { BVSub, yices_bvsub },       { BVMul, yices_bvmul },
//       { BVUdiv, yices_bvdiv },      { BVUrem, yices_bvrem },
//       { BVSdiv, yices_bvsdiv },     { BVSrem, yices_bvsrem },
//       { BVSmod, yices_bvsmod },     { BVShl, yices_bvshl },
//       { BVAshr, yices_bvashr },     { BVLshr, yices_bvlshr },
//       { BVUlt, yices_bvlt_atom },   { BVUle, yices_bvle_atom },
//       { BVUgt, yices_bvgt_atom },   { BVUge, yices_bvge_atom },
//       { BVSle, yices_bvsle_atom },  { BVSlt, yices_bvslt_atom },
//       { BVSge, yices_bvsge_atom },  { BVSgt, yices_bvsgt_atom },
//       { Select, ext_yices_select }, { Apply, yices_application1 }

//     });

// const unordered_map<PrimOp, yices_tern_fun> yices_ternary_ops(
//     { { And, yices_and3 },
//       { Or, yices_or3 },
//       { Xor, yices_xor3 },
//       { Ite, yices_ite },
//       { BVAnd, yices_bvand3 },
//       { BVOr, yices_bvor3 },
//       { BVXor, yices_bvxor3 },
//       { Apply, yices_application2 },
//       { Store, ext_yices_store } });

// const unordered_map<PrimOp, yices_variadic_fun> yices_variadic_ops({
//     { And, yices_and },
//     { Or, yices_or },
//     { Xor, yices_xor },
//     { Distinct, yices_distinct }
//     // { BVAnd, yices_bvand } has different format.
// });

/* Z3Solver implementation */

void Z3Solver::set_opt(const std::string option, const std::string value)
{
  throw NotImplementedException(
      "Term iteration not implemented for Yices backend.");
}

void Z3Solver::set_logic(const std::string logic)
{
  throw NotImplementedException(
      "Term iteration not implemented for Yices backend.");
}

Term Z3Solver::make_term(bool b) const
{
  throw NotImplementedException(
      "Term iteration not implemented for Yices backend.");
}


Sort Z3Solver::make_sort(const DatatypeDecl & d) const {
  throw NotImplementedException("Z3Solver::make_sort");
};
DatatypeDecl Z3Solver::make_datatype_decl(const std::string & s)  {
    throw NotImplementedException("Z3Solver::make_datatype_decl");
}
DatatypeConstructorDecl Z3Solver::make_datatype_constructor_decl(
    const std::string s)
{
  throw NotImplementedException("Z3Solver::make_datatype_constructor_decl");
};
void Z3Solver::add_constructor(DatatypeDecl & dt, const DatatypeConstructorDecl & con) const {
  throw NotImplementedException("Z3Solver::add_constructor");
};
void Z3Solver::add_selector(DatatypeConstructorDecl & dt, const std::string & name, const Sort & s) const {
  throw NotImplementedException("Z3Solver::add_selector");
};
void Z3Solver::add_selector_self(DatatypeConstructorDecl & dt, const std::string & name) const {
  throw NotImplementedException("Z3Solver::add_selector_self");
};

Term Z3Solver::get_constructor(const Sort & s, std::string name) const  {
  throw NotImplementedException("Z3Solver::get_constructor");
};
Term Z3Solver::get_tester(const Sort & s, std::string name) const  {
  throw NotImplementedException("Z3Solver::get_testeer");
};

Term Z3Solver::get_selector(const Sort & s, std::string con, std::string name) const  {
  throw NotImplementedException("Z3Solver::get_selector");
};


Term Z3Solver::make_term(int64_t i, const Sort & sort) const
{
  throw NotImplementedException(
      "Term iteration not implemented for Yices backend.");
}

Term Z3Solver::make_term(const std::string val,
                             const Sort & sort,
                             uint64_t base) const
{
  throw NotImplementedException(
      "Term iteration not implemented for Yices backend.");
}

Term Z3Solver::make_term(const Term & val, const Sort & sort) const
{
  throw NotImplementedException(
      "Constant arrays not supported for Z3 backend.");
}

void Z3Solver::assert_formula(const Term & t)
{
  throw NotImplementedException(
      "Term iteration not implemented for Yices backend.");
}

Result Z3Solver::check_sat()
{
  throw NotImplementedException(
      "Term iteration not implemented for Yices backend.");
}

Result Z3Solver::check_sat_assuming(const TermVec & assumptions)
{
  throw NotImplementedException(
      "Term iteration not implemented for Yices backend.");
}

void Z3Solver::push(uint64_t num) { 
  throw NotImplementedException(
      "Term iteration not implemented for Yices backend.");
  }

void Z3Solver::pop(uint64_t num) { 
  throw NotImplementedException(
      "Term iteration not implemented for Yices backend.");
  }

Term Z3Solver::get_value(const Term & t) const
{
  throw NotImplementedException(
      "Term iteration not implemented for Yices backend.");
}

UnorderedTermMap Z3Solver::get_array_values(const Term & arr,
                                                Term & out_const_base) const
{
  throw NotImplementedException(
      "Yices does not support getting array values. Please use get_value on a "
      "particular select of the array.");
}

void Z3Solver::get_unsat_core(UnorderedTermSet & out)
{
  throw NotImplementedException(
      "Term iteration not implemented for Yices backend.");
}

Sort Z3Solver::make_sort(const std::string name, uint64_t arity) const
{
  throw NotImplementedException(
      "Term iteration not implemented for Yices backend.");
}

Sort Z3Solver::make_sort(SortKind sk) const
{
  throw NotImplementedException(
      "Term iteration not implemented for Yices backend.");
}

Sort Z3Solver::make_sort(SortKind sk, uint64_t size) const
{
  throw NotImplementedException(
      "Term iteration not implemented for Yices backend.");
}

Sort Z3Solver::make_sort(SortKind sk, const Sort & sort1) const
{
  throw NotImplementedException(
      "Smt-switch does not have any sorts that take one sort parameter yet.");
}

Sort Z3Solver::make_sort(SortKind sk,
                             const Sort & sort1,
                             const Sort & sort2) const
{
  throw NotImplementedException(
      "Term iteration not implemented for Yices backend.");
}

Sort Z3Solver::make_sort(SortKind sk,
                             const Sort & sort1,
                             const Sort & sort2,
                             const Sort & sort3) const
{
  throw NotImplementedException(
      "Smt-switch does not have any sorts that take three sort parameters "
      "yet.");
}

Sort Z3Solver::make_sort(SortKind sk, const SortVec & sorts) const
{
  throw NotImplementedException(
      "Term iteration not implemented for Yices backend.");
}

Sort Z3Solver::make_sort(const Sort & sort_con, const SortVec & sorts) const
{
  throw NotImplementedException(
      "Z3 does not support uninterpreted sort constructors");
}

Term Z3Solver::make_symbol(const std::string name, const Sort & sort)
{
  throw NotImplementedException(
      "Term iteration not implemented for Yices backend.");
}

Term Z3Solver::make_param(const std::string name, const Sort & sort)
{
  throw NotImplementedException("make_param not supported by Z3 yet.");
}

Term Z3Solver::make_term(Op op, const Term & t) const
{
  throw NotImplementedException(
      "Term iteration not implemented for Yices backend.");
}

Term Z3Solver::make_term(Op op, const Term & t0, const Term & t1) const
{
  throw NotImplementedException(
      "Term iteration not implemented for Yices backend.");
}

Term Z3Solver::make_term(Op op,
                             const Term & t0,
                             const Term & t1,
                             const Term & t2) const
{
  throw NotImplementedException(
      "Term iteration not implemented for Yices backend.");
}

Term Z3Solver::make_term(Op op, const TermVec & terms) const
{
  throw NotImplementedException(
      "Term iteration not implemented for Yices backend.");
}

void Z3Solver::reset()
{
  throw NotImplementedException(
      "Term iteration not implemented for Yices backend.");
}

void Z3Solver::reset_assertions() { 
  throw NotImplementedException(
      "Term iteration not implemented for Yices backend.");
  }

Term Z3Solver::substitute(const Term term,
                              const UnorderedTermMap & substitution_map) const
{
  throw NotImplementedException(
      "Term iteration not implemented for Yices backend.");
}

void Z3Solver::dump_smt2(std::string filename) const
{
  throw NotImplementedException(
      "Dumping smt2 not supported by Z3 backend.");
}

/* end Z3Solver implementation */

}  // namespace smt
