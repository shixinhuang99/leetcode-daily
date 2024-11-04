#[cfg(test)]
mod utils;

pub struct Solution;

// start
impl Solution {
	pub fn subtract_product_and_sum(mut n: i32) -> i32 {
		let mut product = 1;
		let mut sum = 0;

		while n != 0 {
			let cur = n % 10;
			product *= cur;
			sum += cur;
			n /= 10;
		}

		product - sum
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
