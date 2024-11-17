#[cfg(test)]
mod utils;

pub struct Solution;

// start
impl Solution {
	pub fn create_target_array(nums: Vec<i32>, index: Vec<i32>) -> Vec<i32> {
		let mut ret = vec![];

		for (i, n) in nums.into_iter().enumerate() {
			ret.insert(index[i] as usize, n);
		}

		ret
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
