#[cfg(test)]
mod utils;

pub struct Solution;

// start
impl Solution {
	pub fn smaller_numbers_than_current(mut nums: Vec<i32>) -> Vec<i32> {
		use std::collections::hash_map::{Entry, HashMap};

		let mut sorted = nums.clone();
		sorted.sort_unstable();

		let mut vi_map: HashMap<i32, i32> = HashMap::new();

		for (i, v) in sorted.into_iter().enumerate() {
			if let Entry::Vacant(e) = vi_map.entry(v) {
				e.insert(i as i32);
			}
		}

		for n in &mut nums {
			*n = vi_map[n];
		}

		nums
	}

	pub fn smaller_numbers_than_current_v2(mut nums: Vec<i32>) -> Vec<i32> {
		let mut cnt = [0; 101];

		for n in &nums {
			cnt[*n as usize] += 1;
		}

		for i in 1..cnt.len() {
			cnt[i] += cnt[i - 1];
		}

		for n in &mut nums {
			if *n != 0 {
				*n = cnt[*n as usize - 1];
			}
		}

		nums
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
