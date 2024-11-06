#[cfg(test)]
mod utils;

pub struct Solution;

// start
impl Solution {
	pub fn number_of_steps(mut num: i32) -> i32 {
		let mut count = 0;

		while num != 0 {
			if num % 2 == 0 {
				num /= 2;
			} else {
				num -= 1;
			}
			count += 1;
		}

		count
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
