#[cfg(test)]
mod utils;

pub struct Solution;

// start
impl Solution {
	pub fn min_subsequence(mut nums: Vec<i32>) -> Vec<i32> {
		nums.sort_unstable_by(|a, b| b.cmp(a));

		let total = nums.iter().sum::<i32>();
		let mut sum = 0;
		let mut end = 0;

		for (i, n) in nums.iter().enumerate() {
			sum += n;
			if 2 * sum > total {
				end = i;
				break;
			}
		}

		nums[0..=end].to_vec()
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
