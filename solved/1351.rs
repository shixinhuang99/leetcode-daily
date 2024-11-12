#[cfg(test)]
mod utils;

pub struct Solution;

// start
impl Solution {
	pub fn count_negatives(grid: Vec<Vec<i32>>) -> i32 {
		let mut count = 0;

		for row in grid {
			let idx = row.partition_point(|x| *x >= 0);
			count += row.len() - idx;
		}

		count as i32
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
