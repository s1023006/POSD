#include "term.h"
#include "iterator.h"

Iterator<Term *> *Term::createIterator() { return new usualIterator<Term *>(this); }
Iterator<Term *> *Term::createDFSIterator() { return new usualIterator<Term *>(this); }
Iterator<Term *> *Term::createBFSIterator() { return new usualIterator<Term *>(this); }
