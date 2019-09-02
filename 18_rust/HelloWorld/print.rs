fn main() {
	println!("{} days", 31);

	println!("{0}, this is {1}. {1}, thi is {0}", "Alice", "Bob");
	
	// named arguments
	println!("{subject} {verb} {object}",
			object = "the lazy dog",
			subject = "the quick brown fox",
			verb = "jumps over");
	
	//formatting
	println!("{} of {:b} people know binary, the other half doens't", 1, 2);		
			
}
