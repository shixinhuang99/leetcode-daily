#[cfg(test)]
mod utils;

pub struct Solution;

// start
impl Solution {
	pub fn find_lucky(arr: Vec<i32>) -> i32 {
		use std::collections::HashMap;

		let mut map: HashMap<i32, i32> = HashMap::new();

		for n in arr {
			map.entry(n).and_modify(|cnt| *cnt += 1).or_insert(1);
		}

		map.into_iter()
			.filter_map(|(v, cnt)| {
				if v == cnt {
					Some(v)
				} else {
					None
				}
			})
			.max()
			.unwrap_or(-1)
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
