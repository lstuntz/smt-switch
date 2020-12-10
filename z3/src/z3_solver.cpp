#include "z3_solver.h"

#include <inttypes.h>

#include <iostream>

#include <z3++.h>
// #include "z3_extensions.h"

using namespace std;

namespace smt {

/* CVC4 Op mappings */
const std::unordered_map<PrimOp, Z3_decl_kind> primop2kind( {
		{ And, Z3_OP_AND }, { Or, Z3_OP_OR }, { Xor, Z3_OP_XOR }, { Not,
				Z3_OP_NOT }, { Implies, Z3_OP_IMPLIES }, { Ite, Z3_OP_ITE }, {
				Iff, Z3_OP_IFF }, { Equal, Z3_OP_EQ }, { Distinct,
				Z3_OP_DISTINCT },
//      /* Uninterpreted Functions */
//      { Apply, ::CVC4::api::APPLY_UF },
		/* Arithmetic Theories */
		{ Plus, Z3_OP_ADD }, { Minus, Z3_OP_SUB }, { Negate, Z3_OP_UMINUS }, {
				Mult, Z3_OP_MUL }, { Div, Z3_OP_DIV }, { IntDiv, Z3_OP_IDIV }, {
				Lt, Z3_OP_LT }, { Le, Z3_OP_LE }, { Gt, Z3_OP_GT }, { Ge,
				Z3_OP_GE }, { Mod, Z3_OP_MOD },
//      { Abs, ::CVC4::api::ABS },
		{ Pow, Z3_OP_POWER }, { To_Real, Z3_OP_TO_REAL },
		{ To_Int, Z3_OP_TO_INT }, { Is_Int, Z3_OP_IS_INT },
//      /* Fixed Size BitVector Theory */
//      { Concat, ::CVC4::api::BITVECTOR_CONCAT },
//      // Indexed Op
//      { Extract, ::CVC4::api::BITVECTOR_EXTRACT },
//      { BVNot, ::CVC4::api::BITVECTOR_NOT },
//      { BVNeg, ::CVC4::api::BITVECTOR_NEG },
//      { BVAnd, ::CVC4::api::BITVECTOR_AND },
//      { BVOr, ::CVC4::api::BITVECTOR_OR },
//      { BVXor, ::CVC4::api::BITVECTOR_XOR },
//      { BVNand, ::CVC4::api::BITVECTOR_NAND },
//      { BVNor, ::CVC4::api::BITVECTOR_NOR },
//      { BVXnor, ::CVC4::api::BITVECTOR_XNOR },
//      { BVComp, ::CVC4::api::BITVECTOR_COMP },
//      { BVAdd, ::CVC4::api::BITVECTOR_PLUS },
//      { BVSub, ::CVC4::api::BITVECTOR_SUB },
//      { BVMul, ::CVC4::api::BITVECTOR_MULT },
//      { BVUdiv, ::CVC4::api::BITVECTOR_UDIV },
//      { BVSdiv, ::CVC4::api::BITVECTOR_SDIV },
//      { BVUrem, ::CVC4::api::BITVECTOR_UREM },
//      { BVSrem, ::CVC4::api::BITVECTOR_SREM },
//      { BVSmod, ::CVC4::api::BITVECTOR_SMOD },
//      { BVShl, ::CVC4::api::BITVECTOR_SHL },
//      { BVAshr, ::CVC4::api::BITVECTOR_ASHR },
//      { BVLshr, ::CVC4::api::BITVECTOR_LSHR },
//      { BVUlt, ::CVC4::api::BITVECTOR_ULT },
//      { BVUle, ::CVC4::api::BITVECTOR_ULE },
//      { BVUgt, ::CVC4::api::BITVECTOR_UGT },
//      { BVUge, ::CVC4::api::BITVECTOR_UGE },
//      { BVSlt, ::CVC4::api::BITVECTOR_SLT },
//      { BVSle, ::CVC4::api::BITVECTOR_SLE },
//      { BVSgt, ::CVC4::api::BITVECTOR_SGT },
//      { BVSge, ::CVC4::api::BITVECTOR_SGE },
//      // Indexed Op
//      { Zero_Extend, ::CVC4::api::BITVECTOR_ZERO_EXTEND },
//      // Indexed Op
//      { Sign_Extend, ::CVC4::api::BITVECTOR_SIGN_EXTEND },
//      // Indexed Op
//      { Repeat, ::CVC4::api::BITVECTOR_REPEAT },
//      // Indexed Op
//      { Rotate_Left, ::CVC4::api::BITVECTOR_ROTATE_LEFT },
//      // Indexed Op
//      { Rotate_Right, ::CVC4::api::BITVECTOR_ROTATE_RIGHT },
//      // Conversion
//      { BV_To_Nat, ::CVC4::api::BITVECTOR_TO_NAT },
//      // Indexed Op
//      { Int_To_BV, ::CVC4::api::INT_TO_BITVECTOR },
//      { Select, ::CVC4::api::SELECT },
//      { Store, ::CVC4::api::STORE },
//      { Forall, ::CVC4::api::FORALL },
//      { Exists, ::CVC4::api::EXISTS },
//      { Apply_Selector,::CVC4::api::APPLY_SELECTOR},
//      { Apply_Tester,::CVC4::api::APPLY_TESTER},
//      { Apply_Constructor,::CVC4::api::APPLY_CONSTRUCTOR}
		});

/* Z3Solver implementation */

void Z3Solver::set_opt(const std::string option, const std::string value) {
	throw NotImplementedException(
			"Term iteration not implemented for Z3 backend.");
}

void Z3Solver::set_logic(const std::string logic) {
	throw NotImplementedException(
			"Term iteration not implemented for Z3 backend.");
}

Term Z3Solver::make_term(bool b) const {
	expr z_term = ctx.bool_val(false);
	if (b) {
		z_term = ctx.bool_val(true);
	}

	return std::make_shared < Z3Term > (z_term, ctx);
}

Sort Z3Solver::make_sort(const DatatypeDecl &d) const {
	throw NotImplementedException("Z3Solver::make_sort");
}
;
DatatypeDecl Z3Solver::make_datatype_decl(const std::string &s) {
	throw NotImplementedException("Z3Solver::make_datatype_decl");
}
DatatypeConstructorDecl Z3Solver::make_datatype_constructor_decl(
		const std::string s) {
	throw NotImplementedException("Z3Solver::make_datatype_constructor_decl");
}
;
void Z3Solver::add_constructor(DatatypeDecl &dt,
		const DatatypeConstructorDecl &con) const {
	throw NotImplementedException("Z3Solver::add_constructor");
}
;
void Z3Solver::add_selector(DatatypeConstructorDecl &dt,
		const std::string &name, const Sort &s) const {
	throw NotImplementedException("Z3Solver::add_selector");
}
;
void Z3Solver::add_selector_self(DatatypeConstructorDecl &dt,
		const std::string &name) const {
	throw NotImplementedException("Z3Solver::add_selector_self");
}
;

Term Z3Solver::get_constructor(const Sort &s, std::string name) const {
	throw NotImplementedException("Z3Solver::get_constructor");
}
;
Term Z3Solver::get_tester(const Sort &s, std::string name) const {
	throw NotImplementedException("Z3Solver::get_testeer");
}
;

Term Z3Solver::get_selector(const Sort &s, std::string con,
		std::string name) const {
	throw NotImplementedException("Z3Solver::get_selector");
}
;

Term Z3Solver::make_term(int64_t i, const Sort &sort) const {
	SortKind sk = sort->get_sort_kind();
	expr z_term = ctx.bool_val(true);	//change me
	if (sk == INT) {
		z_term = ctx.int_val(i);
	} else if (sk == REAL) {
		z_term = ctx.real_val(i);
	} else if (sk == BV) {
		z_term = ctx.bv_val(sort->get_width(), i);//why did yices use const here
	} else {
		string msg("Can't create value ");
		msg += i;
		msg += " with sort ";
		msg += sort->to_string();
		throw IncorrectUsageException(msg);
	}

	return std::make_shared < Z3Term > (z_term, ctx);
}

Term Z3Solver::make_term(const std::string val, const Sort &sort,
		uint64_t base) const {
	expr z_term = ctx.bool_val(true);	//change me
	SortKind sk = sort->get_sort_kind();

	if (sk == BV) {
		z_term = ctx.bv_const(val.c_str(), sort->get_width());//why am i throwing out base?
	} else if (sk == REAL) {
		if (base != 10) {
			throw NotImplementedException(
					"Does not support base not equal to 10.");
		}

		z_term = ctx.real_const(val.c_str());
	} else if (sk == INT) {
		if (base != 10) {
			throw NotImplementedException(
					"Does not support base not equal to 10.");
		}
//		int i = stoi(val);
//		z_term = ctx.int_val(i);	//ugh why is this jumping between val and const

		z_term = ctx.int_const(val.c_str());
	} else {
		string msg("Can't create value ");
		msg += val;
		msg += " with sort ";
		msg += sort->to_string();
		throw IncorrectUsageException(msg);
	}

	return std::make_shared < Z3Term > (z_term, ctx);
}

Term Z3Solver::make_term(const Term &val, const Sort &sort) const {
	throw NotImplementedException(
			"Constant arrays not supported for Z3 backend.");
}

void Z3Solver::assert_formula(const Term &t) {
	throw NotImplementedException(
			"Term iteration not implemented for Z3 backend.");
}

Result Z3Solver::check_sat() {
	throw NotImplementedException(
			"Term iteration not implemented for Z3 backend.");
}

Result Z3Solver::check_sat_assuming(const TermVec &assumptions) {
	throw NotImplementedException(
			"Term iteration not implemented for Z3 backend.");
}

void Z3Solver::push(uint64_t num) {
	throw NotImplementedException(
			"Term iteration not implemented for Z3 backend.");
}

void Z3Solver::pop(uint64_t num) {
	throw NotImplementedException(
			"Term iteration not implemented for Z3 backend.");
}

Term Z3Solver::get_value(const Term &t) const {
	throw NotImplementedException(
			"Term iteration not implemented for Z3 backend.");
}

UnorderedTermMap Z3Solver::get_array_values(const Term &arr,
		Term &out_const_base) const {
	throw NotImplementedException(
			"Z3 does not support getting array values. Please use get_value on a "
					"particular select of the array.");
}

void Z3Solver::get_unsat_core(UnorderedTermSet &out) {
	throw NotImplementedException(
			"Term iteration not implemented for Z3 backend.");
}

Sort Z3Solver::make_sort(const std::string name, uint64_t arity) const {
	z3::sort z_sort = ctx.bool_sort();       //fix this

	if (!arity) {
		const char *c = name.c_str();
		z3::symbol func_name = ctx.str_symbol(c);
		z_sort = ctx.uninterpreted_sort(func_name);
	} else {
		throw NotImplementedException(
				"Z3 does not support uninterpreted type with non-zero arity.");
	}

	return std::make_shared < Z3Sort > (z_sort, ctx);
}

Sort Z3Solver::make_sort(SortKind sk) const {

	z3::sort z_sort = ctx.bool_sort();		//should be else

	if (sk == BOOL) {
		z_sort = ctx.bool_sort();
	} else if (sk == INT) {
		z_sort = ctx.int_sort();
	} else if (sk == REAL) {
		z_sort = ctx.real_sort();
	} else {
		std::string msg("Can't create sort with sort constructor ");
		msg += to_string(sk);
		msg += " and no arguments";
		throw IncorrectUsageException(msg.c_str());
	}

	Sort final_sort = std::make_shared < Z3Sort > (z_sort, ctx);
	return final_sort;
}

Sort Z3Solver::make_sort(SortKind sk, uint64_t size) const {
	z3::sort z_sort = ctx.bool_sort();		//should be else
	if (sk == BV) {
		z_sort = ctx.bv_sort(size);
	}
	return std::make_shared < Z3Sort > (z_sort, ctx);
}

Sort Z3Solver::make_sort(SortKind sk, const Sort &sort1) const {
	throw NotImplementedException(
			"Smt-switch does not have any sorts that take one sort parameter yet.");
}

Sort Z3Solver::make_sort(SortKind sk, const Sort &sort1,
		const Sort &sort2) const {
	if (sk == ARRAY) {
		std::shared_ptr<Z3Sort> cidxsort = std::static_pointer_cast < Z3Sort
				> (sort1);
		std::shared_ptr<Z3Sort> celemsort = std::static_pointer_cast < Z3Sort
				> (sort2);
		return std::make_shared < Z3Sort
				> (ctx.array_sort(cidxsort->type, celemsort->type), ctx);
	} else {
		std::string msg("Can't create sort with sort constructor ");
		msg += to_string(sk);
		msg += " and two Sort arguments";
		throw IncorrectUsageException(msg.c_str());
	}
}

Sort Z3Solver::make_sort(SortKind sk, const Sort &sort1, const Sort &sort2,
		const Sort &sort3) const {
	throw NotImplementedException(
			"Smt-switch does not have any sorts that take three sort parameters "
					"yet.");
}

Sort Z3Solver::make_sort(SortKind sk, const SortVec &sorts) const {
	z3::sort final_sort = ctx.bool_sort();		//should be else

	if (sk == FUNCTION) {
		if (sorts.size() < 2) {
			throw IncorrectUsageException(
					"Function sort must have >=2 sort arguments.");
		}

		// arity is one less, because last sort is return sort
		uint32_t arity = sorts.size() - 1;

		std::vector<z3::sort> zsorts;
		zsorts.reserve(arity);
		z3::sort z_sort = ctx.bool_sort();		//should be else

		for (uint32_t i = 0; i < arity; i++) {
			z_sort = std::static_pointer_cast < Z3Sort > (sorts[i])->type;
			zsorts.push_back(z_sort);
		}

		Sort sort = sorts.back();
		z_sort = std::static_pointer_cast < Z3Sort > (sort)->type;

		const char *c = "throwaway name";
		z3::symbol func_name = ctx.str_symbol(c);
		z3::func_decl z_func = ctx.function(func_name, arity, &zsorts[0],
				z_sort);

		return std::make_shared < Z3Sort > (final_sort, true, z_func, ctx);
	} else if (sorts.size() == 1) {
		return make_sort(sk, sorts[0]);
	} else if (sorts.size() == 2) {
		return make_sort(sk, sorts[0], sorts[1]);
	} else if (sorts.size() == 3) {
		return make_sort(sk, sorts[0], sorts[1], sorts[2]);
	} else {
		std::string msg("Can't create sort from sort constructor ");
		msg += to_string(sk);
		msg += " with a vector of sorts";
		throw IncorrectUsageException(msg.c_str());
	}

	return std::make_shared < Z3Sort > (final_sort, ctx);
}

Sort Z3Solver::make_sort(const Sort &sort_con, const SortVec &sorts) const {
	throw NotImplementedException(
			"Z3 does not support uninterpreted sort constructors");
}

Term Z3Solver::make_symbol(const std::string name, const Sort &sort) {
	throw NotImplementedException(
			"Term iteration not implemented for Z3 backend.");
}

Term Z3Solver::make_param(const std::string name, const Sort &sort) {
	throw NotImplementedException("make_param not supported by Z3 yet.");
}

Term Z3Solver::make_term(Op op, const Term &t) const {
	throw NotImplementedException(
			"Term iteration not implemented for Z3 backend.");
}

Term Z3Solver::make_term(Op op, const Term &t0, const Term &t1) const {
	throw NotImplementedException(
			"Term iteration not implemented for Z3 backend.");
}

Term Z3Solver::make_term(Op op, const Term &t0, const Term &t1,
		const Term &t2) const {
	throw NotImplementedException(
			"Term iteration not implemented for Z3 backend.");
}

Term Z3Solver::make_term(Op op, const TermVec &terms) const {
	throw NotImplementedException(
			"Term iteration not implemented for Z3 backend.");
}

void Z3Solver::reset() {
	throw NotImplementedException(
			"Term iteration not implemented for Z3 backend.");
}

void Z3Solver::reset_assertions() {
	throw NotImplementedException(
			"Term iteration not implemented for Z3 backend.");
}

Term Z3Solver::substitute(const Term term,
		const UnorderedTermMap &substitution_map) const {
	throw NotImplementedException(
			"Term iteration not implemented for Z3 backend.");
}

void Z3Solver::dump_smt2(std::string filename) const {
	throw NotImplementedException("Dumping smt2 not supported by Z3 backend.");
}

/* end Z3Solver implementation */

}  // namespace smt
