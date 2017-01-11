/*
 * SeqIO.cpp
 *
 *  Created on: Jul 23, 2015
 *      Author: zhengqi
 */
#include <fstream>
#include "SeqIO.h"

namespace EGriceLab {
using namespace std;

SeqIO::SeqIO(const string& filename, const string& alphabet, const string& format, Mode mode, bool verify) :
	filename(filename), abc(SeqCommons::getAlphabetByName(alphabet)), format(format), mode(mode) {
	/* check format support */
	if(!(format == "fasta" || format == "fastq"))
		throw invalid_argument("Unsupported file format '" + format + "'");
	else { } /* not possible */
	/* register exceptions */
	in.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	out.exceptions(std::ofstream::failbit | std::ofstream::badbit);

	/* open files */
	if(mode == READ)
		in.open(filename.c_str());
	else
		out.open(filename.c_str());
}

bool SeqIO::hasNextFasta() {
	char c = in.peek();
	return c != EOF && c == fastaHead;
}

bool SeqIO::hasNextFastq() {
	char c = in.peek();
	return c != EOF && c == fastqHead;
}

PrimarySeq SeqIO::nextFastaSeq() {
	string id, seq, desc;
	char tag;
	string line;
	tag = in.get();
	if(tag != fastaHead)
		throw ios_base::failure("inputfile " + filename + " is not a valid FASTA format");
	in >> id; // read the next word as id
	getline(in, desc); // read the remaining as desc
	while(in.peek() != EOF && in.peek() != fastaHead) {
		getline(in, line);
		seq += line;
	}
	return PrimarySeq(abc, id, seq, desc);
}

PrimarySeq SeqIO::nextFastqSeq() {
	string id, seq, desc, qual;
	char tag;
	string line;
	tag = in.get();
	if(tag != fastqHead)
		throw ios_base::failure("inputfile " + filename + " is not a valid FASTQ format");
	in >> id; // read the next word as id
	getline(in, desc); // read the remaining as desc
	getline(in, seq);  // read seq line
	getline(in, line); // ignore sep line
	getline(in, qual); // read qual line
	return PrimarySeq(abc, id, seq, desc, qual);
}

void SeqIO::writeFastaSeq(const PrimarySeq& seq) {
	out << fastaHead << seq.getId() << seq.getDesc() << endl;
	const char* seqPtr = seq.getSeq().c_str();
	for(size_t i = 0, r = seq.length(); i < seq.length(); i += kMaxFastaLine, r -= kMaxFastaLine) {
		out.write(seqPtr + i, r >= kMaxFastaLine ? kMaxFastaLine : r); /* use unformated write for performance */
		out.put('\n'); // do not flush for faster performance
	}
}

void SeqIO::writeFastqSeq(const PrimarySeq& seq) {
	out << fastqHead << seq.getId() << seq.getDesc() << endl;
	out << seq.getSeq() << endl;
	out << fastqSep << endl << seq.getQual() << endl;
}

} /* namespace EGriceLab */

