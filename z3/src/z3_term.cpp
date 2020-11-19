#include "z3_term.h"
#include "exceptions.h"
#include "ops.h"
#include "z3_sort.h"

#include <unordered_map>

using namespace std;

namespace smt {

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
