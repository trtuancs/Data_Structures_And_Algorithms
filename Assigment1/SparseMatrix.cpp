#include"SparseMatrix.h"

void SparseMatrix::setAt(unsigned row, unsigned col, double val) {
	rangeCheck(row, col);
	// YOUR CODE HERE
	bool co = false;
	Element k = Element(row,col,val) ;
	if (val != 0) {
		if (size == 0) {
			this->insertAt(0, k);
		}
		else {
			for (int i = 0; i < size; i++) {
				if ((storage[i].row == row) && (storage[i].col == col)) {
					storage[i].val = val;
					co = true;
					break;
				}
			}
			if (co == false) {
				this->insertAt(size, k);
				for (int m = 0; m < size - 1; m++) {
					for (int n = 0; n < size - m - 1; n++) {
						if (storage[n].row > storage[n + 1].row) {
							k = storage[n + 1];
							storage[n + 1] = storage[n];
							storage[n] = k;
						}
						if (storage[n].row == storage[n + 1].row  && storage[n].col > storage[n + 1].col) {
							k = storage[n + 1];
							storage[n + 1] = storage[n];
							storage[n] = k;
						}
					}
				}

			}
		}
	}
	
}

double SparseMatrix::getAt(unsigned row, unsigned col) {
	rangeCheck(row, col);
	// YOUR CODE HERE
	for (int i = 0; i < size; i++) {
		if (storage[i].col == col && storage[i].row == row) {
			return storage[i].val;
			break;
		}
	}
	return 0;
}

SparseMatrix* SparseMatrix::transpose() {
	SparseMatrix* result = NULL;
	// YOUR CODE HERE 

	result = new SparseMatrix(this->ncol, this->nrow);
	//result->nrow = this->ncol;
	//result->ncol = this->nrow;

	for (int i = 0; i < size; i++){
		result->setAt(storage[i].col, storage[i].row, storage[i].val);
	}

	return result;
}

double SparseMatrix::trace() {
	if (nrow != ncol)
		throw "TraceOfNoneSquareMatrix";
	double result = 0;
	// YOUR CODE HERE
	for (int i = 0; i < size; i++){
		if (storage[i].row == storage[i].col) {
			result = result + storage[i].val;
		}
	}
	return result;
}

SparseMatrix* SparseMatrix::add(const SparseMatrix& b) {
	if (nrow != b.nrow || ncol != b.ncol)
		throw "MismatchedDimensions";


	SparseMatrix* result = NULL;
	// YOUR CODE HERE
//	result = new SparseMatrix(nrow, ncol);
	result = this;
	for(int i = 0; i < b.size; i++){
		bool co =false;
		for(int j = 0; j < this->size; j++){
			if ((b.storage[i].row == this->storage[j].row) && (b.storage[i].col == this->storage[j].col)) {
				co =true;
				result->storage[j].val = this->storage[j].val + b.storage[i].val;
				break;
			}
		}
		if (co == false) {
			result->setAt(b.storage[i].row,b.storage[i].col,b.storage[i].val);
		}
	}
	

	return result;
}


SparseMatrix* SparseMatrix::multiplyPointWise(const SparseMatrix& b) {
	
	if (nrow != b.nrow || ncol != b.ncol)
		throw "MismatchedDimensions";
	SparseMatrix* result = NULL;
	// YOUR CODE HERE
	result = new SparseMatrix(nrow, b.ncol);
	for(int i = 0; i < b.size; i++){
		for(int j = 0; j < this->size; j++){
			if( (b.storage[i].row == this->storage[j].row) && (b.storage[i].col == this->storage[j].col)){
				result->setAt(this->storage[j].row,this->storage[j].col,this->storage[j].val * b.storage[i].val);
			//	result->storage[j].val = this->storage[j].val * b.storage[i].val;
				break;
			}
		}
	}
	return result;
}