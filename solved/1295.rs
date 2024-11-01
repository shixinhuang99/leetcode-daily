#[cfg(test)]
mod utils;

pub struct Solution;

// start
impl Solution {
	pub fn find_numbers(nums: Vec<i32>) -> i32 {
		fn count(mut n: i32) -> i32 {
			let mut cnt = 0;

			while n != 0 {
				n /= 10;
				cnt += 1;
			}

			cnt
		}

		nums.into_iter().fold(0, |acc, x| {
			if count(x) % 2 == 0 {
				acc + 1
			} else {
				acc
			}
		})
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
