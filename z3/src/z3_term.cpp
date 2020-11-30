#include "z3_term.h"
#include "exceptions.h"
#include "ops.h"
#include "z3_sort.h"

#include <unordered_map>

using namespace std;

namespace smt {

//// the kinds CVC4 needs to build an OpTerm for an indexed op
//const std::unordered_map<::CVC4::api::Kind, size_t> kind2numindices(
//    { { ::CVC4::api::BITVECTOR_EXTRACT, 2 },
//      { ::CVC4::api::BITVECTOR_ZERO_EXTEND, 1 },
//      { ::CVC4::api::BITVECTOR_SIGN_EXTEND, 1 },
//      { ::CVC4::api::BITVECTOR_REPEAT, 1 },
//      { ::CVC4::api::BITVECTOR_ROTATE_LEFT, 1 },
//      { ::CVC4::api::BITVECTOR_ROTATE_RIGHT, 1 },
//      { ::CVC4::api::INT_TO_BITVECTOR, 1 } });
//
//const std::unordered_map<::CVC4::api::Kind, PrimOp> kind2primop(
//    { { ::CVC4::api::AND, And },
//      { ::CVC4::api::OR, Or },
//      { ::CVC4::api::XOR, Xor },
//      { ::CVC4::api::NOT, Not },
//      { ::CVC4::api::IMPLIES, Implies },
//      { ::CVC4::api::ITE, Ite },
//      { ::CVC4::api::EQUAL, Equal },
//      { ::CVC4::api::DISTINCT, Distinct },
//      /* Uninterpreted Functions */
//      { ::CVC4::api::APPLY_UF, Apply },
//      /* Arithmetic Theories */
//      { ::CVC4::api::PLUS, Plus },
//      { ::CVC4::api::MINUS, Minus },
//      { ::CVC4::api::UMINUS, Negate },
//      { ::CVC4::api::MULT, Mult },
//      { ::CVC4::api::DIVISION, Div },
//      { ::CVC4::api::LT, Lt },
//      { ::CVC4::api::LEQ, Le },
//      { ::CVC4::api::GT, Gt },
//      { ::CVC4::api::GEQ, Ge },
//      { ::CVC4::api::INTS_MODULUS, Mod },
//      { ::CVC4::api::ABS, Abs },
//      { ::CVC4::api::POW, Pow },
//      { ::CVC4::api::TO_REAL, To_Real },
//      { ::CVC4::api::TO_INTEGER, To_Int },
//      { ::CVC4::api::IS_INTEGER, Is_Int },
//      /* Fixed Size BitVector Theory */
//      { ::CVC4::api::BITVECTOR_CONCAT, Concat },
//      // Indexed Op
//      { ::CVC4::api::BITVECTOR_EXTRACT, Extract },
//      { ::CVC4::api::BITVECTOR_NOT, BVNot },
//      { ::CVC4::api::BITVECTOR_NEG, BVNeg },
//      { ::CVC4::api::BITVECTOR_AND, BVAnd },
//      { ::CVC4::api::BITVECTOR_OR, BVOr },
//      { ::CVC4::api::BITVECTOR_XOR, BVXor },
//      { ::CVC4::api::BITVECTOR_NAND, BVNand },
//      { ::CVC4::api::BITVECTOR_NOR, BVNor },
//      { ::CVC4::api::BITVECTOR_XNOR, BVXnor },
//      { ::CVC4::api::BITVECTOR_COMP, BVComp },
//      { ::CVC4::api::BITVECTOR_PLUS, BVAdd },
//      { ::CVC4::api::BITVECTOR_SUB, BVSub },
//      { ::CVC4::api::BITVECTOR_MULT, BVMul },
//      { ::CVC4::api::BITVECTOR_UDIV, BVUdiv },
//      { ::CVC4::api::BITVECTOR_SDIV, BVSdiv },
//      { ::CVC4::api::BITVECTOR_UREM, BVUrem },
//      { ::CVC4::api::BITVECTOR_SREM, BVSrem },
//      { ::CVC4::api::BITVECTOR_SMOD, BVSmod },
//      { ::CVC4::api::BITVECTOR_SHL, BVShl },
//      { ::CVC4::api::BITVECTOR_ASHR, BVAshr },
//      { ::CVC4::api::BITVECTOR_LSHR, BVLshr },
//      { ::CVC4::api::BITVECTOR_ULT, BVUlt },
//      { ::CVC4::api::BITVECTOR_ULE, BVUle },
//      { ::CVC4::api::BITVECTOR_UGT, BVUgt },
//      { ::CVC4::api::BITVECTOR_UGE, BVUge },
//      { ::CVC4::api::BITVECTOR_SLT, BVSlt },
//      { ::CVC4::api::BITVECTOR_SLE, BVSle },
//      { ::CVC4::api::BITVECTOR_SGT, BVSgt },
//      { ::CVC4::api::BITVECTOR_SGE, BVSge },
//      // Indexed Op
//      { ::CVC4::api::BITVECTOR_ZERO_EXTEND, Zero_Extend },
//      // Indexed Op
//      { ::CVC4::api::BITVECTOR_SIGN_EXTEND, Sign_Extend },
//      // Indexed Op
//      { ::CVC4::api::BITVECTOR_REPEAT, Repeat },
//      // Indexed Op
//      { ::CVC4::api::BITVECTOR_ROTATE_LEFT, Rotate_Left },
//      // Indexed Op
//      { ::CVC4::api::BITVECTOR_ROTATE_RIGHT, Rotate_Right },
//      // Conversion
//      { ::CVC4::api::BITVECTOR_TO_NAT, BV_To_Nat },
//      // Indexed Op
//      { ::CVC4::api::INT_TO_BITVECTOR, Int_To_BV },
//      { ::CVC4::api::SELECT, Select },
//      { ::CVC4::api::STORE, Store },
//      { ::CVC4::api::FORALL, Forall },
//      { ::CVC4::api::EXISTS, Exists },
//      // Datatype
//      { ::CVC4::api::APPLY_CONSTRUCTOR, Apply_Constructor },
//      { ::CVC4::api::APPLY_TESTER, Apply_Tester },
//      { ::CVC4::api::APPLY_SELECTOR, Apply_Selector } });
//
//// struct for hashing
//CVC4::api::TermHashFunction termhash;

// Z3TermIter implementation

//Z3TermIter::Z3TermIter(const Z3TermIter & it)
//{
//  throw NotImplementedException(
//      "Term iteration not implemented for Z3 backend.");
//}

Z3TermIter& Z3TermIter::operator=(const Z3TermIter &it) {
	throw NotImplementedException(
			"Term iteration = not implemented for Z3 backend.");
}

void Z3TermIter::operator++() {
	throw NotImplementedException(
			"Term iteration ++ not implemented for Z3 backend.");
}

const Term Z3TermIter::operator*() {
	throw NotImplementedException(
			"Term iteration * not implemented for Z3 backend.");
}

TermIterBase* Z3TermIter::clone() const {
	throw NotImplementedException(
			"Term iteration clone not implemented for Z3 backend.");
}

bool Z3TermIter::operator==(const Z3TermIter &it) {
	throw NotImplementedException(
			"Term iteration == not implemented for Z3 backend.");
}

bool Z3TermIter::operator!=(const Z3TermIter &it) {
	throw NotImplementedException(
			"Term iteration != not implemented for Z3 backend.");
}

bool Z3TermIter::equal(const TermIterBase &other) const {
	throw NotImplementedException(
			"Term iteration equal not implemented for Z3 backend.");
}

// end Z3TermIter implementation

// Z3Term implementation

size_t Z3Term::hash() const {
	throw NotImplementedException("hash not implemented for Z3 backend.");
}

bool Z3Term::compare(const Term &absterm) const {
	throw NotImplementedException("compare not implemented for Z3 backend.");
}

Op Z3Term::get_op() const {
	throw NotImplementedException("get_op not implemented for Z3 backend.");
}

Sort Z3Term::get_sort() const {
	throw NotImplementedException("get_sort not implemented for Z3 backend.");
}

bool Z3Term::is_symbol() const {
	throw NotImplementedException("is_symbol not implemented for Z3 backend.");
}

bool Z3Term::is_param() const {
	throw NotImplementedException(
			"Z3 backend does not support parameters yet.");
}

bool Z3Term::is_symbolic_const() const {
	throw NotImplementedException(
			"is_symbolic_const not implemented for Z3 backend.");
}

bool Z3Term::is_value() const {
	throw NotImplementedException("is_value not implemented for Z3 backend.");
}

string Z3Term::to_string() {
	return const_to_string();
//	throw NotImplementedException("to_string not implemented for Z3 backend.");
}

uint64_t Z3Term::to_int() const {
	throw NotImplementedException("to_int not implemented for Z3 backend.");
}

TermIter Z3Term::begin() {
	throw NotImplementedException("begin not implemented for Z3 backend.");
}

TermIter Z3Term::end() {
	throw NotImplementedException("end not implemented for Z3 backend.");
}

std::string Z3Term::print_value_as(SortKind sk) {
	throw NotImplementedException(
			"print_value_as not implemented for Z3 backend.");
}

string Z3Term::const_to_string() const {
	return term.to_string();
}

// end Z3Term implementation

}// namespace smt
