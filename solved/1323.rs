#[cfg(test)]
mod utils;

pub struct Solution;

// start
impl Solution {
	pub fn maximum69_number(num: i32) -> i32 {
		let s = num.to_string().replacen('6', "9", 1);
		s.parse::<i32>().unwrap_or(num)
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
