#[cfg(test)]
mod utils;

pub struct Solution;

// start
impl Solution {
	pub fn generate_the_string(n: i32) -> String {
		if n % 2 == 0 {
			format!("{}{}", "a".repeat(n as usize - 1), "b")
		} else {
			"a".repeat(n as usize)
		}
	}
}
// end

#[cfg(test)]
mod tests {
	use super::*;
	use test_case::test_case;
	use utils::*;

	fn test_solution() {}
}
