#[cfg(test)]
mod utils;

pub struct Solution;

// start
impl Solution {
	pub fn check_if_exist(arr: Vec<i32>) -> bool {
		use std::collections::HashMap;

		let mut map: HashMap<i32, usize> = HashMap::new();

		for (i, n) in arr.iter().enumerate() {
			map.insert(*n, i);
		}

		for (i, n) in arr.iter().enumerate() {
			if map.get(&(*n * 2)).is_some_and(|idx| *idx != i) {
				return true;
			}
		}

		false
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
