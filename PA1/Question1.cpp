

//Question 1
//Problem 3.14
const_iterator operator+( int k ) const{
	//This is the current Node
	const_iterator curr = *this;
			
	for(int i = 0; i < k; ++i)
		curr.current = curr.current->next;
			
     return curr;
	}
	

//Question 1 
//Problem 3.16
//In main list class
reverse_iterator rbegin(){
	return (reverse_iterator(this->tail));
}
reverse_iterator rtail() {
	return(reverse_itrator(this->head));
}
const_reverse_iterator rbegin()cons{
	return (reverse_iterator(this->tail));
}
const_reverse_iterator rtail() const{
	return(reverse_itrator(this->head));
}



	


