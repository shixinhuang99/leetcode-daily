#[cfg(test)]
mod utils;

pub struct Solution;

// start
impl Solution {
	pub fn decompress_rl_elist(nums: Vec<i32>) -> Vec<i32> {
		let mut ret = vec![];

		for pair in nums.chunks_exact(2) {
			for _ in 0..pair[0] {
				ret.push(pair[1]);
			}
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
