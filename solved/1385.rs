#[cfg(test)]
mod utils;

pub struct Solution;

// start
impl Solution {
	pub fn find_the_distance_value(
		arr1: Vec<i32>,
		arr2: Vec<i32>,
		d: i32,
	) -> i32 {
		arr1.iter().fold(0, |cnt, a| {
			if arr2.iter().all(|b| (*a - *b).abs() > d) {
				cnt + 1
			} else {
				cnt
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
