#[cfg(test)]
mod utils;

pub struct Solution;

// start
impl Solution {
	pub fn find_special_integer(arr: Vec<i32>) -> i32 {
		use std::collections::HashMap;

		let mut map: HashMap<i32, f32> = HashMap::new();
		let len = arr.len() as f32 / 4.0;

		for n in arr {
			map.entry(n).and_modify(|v| *v += 1.0).or_insert(1.0);
		}

		let mut ret = 0;

		for (k, v) in map {
			if v > len {
				ret = k;
				break;
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
