#[cfg(test)]
mod utils;

pub struct Solution;

// start
impl Solution {
	pub fn min_start_value(mut nums: Vec<i32>) -> i32 {
		let mut max = 1;

		for i in 0..nums.len() {
			if i != 0 {
				nums[i] += nums[i - 1];
			}
			let t = 1 - nums[i];
			if t > max {
				max = t;
			}
		}

		max
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
