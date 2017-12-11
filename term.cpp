#include "term.h"
#include "iterator.h"

Iterator<Term *> *Term::createIterator() { return new usualIterator<Term *>(this); }
