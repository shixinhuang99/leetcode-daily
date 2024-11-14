#[cfg(test)]
mod utils;

pub struct Solution;

// start
impl Solution {
	pub fn lucky_numbers(matrix: Vec<Vec<i32>>) -> Vec<i32> {
		use std::collections::HashMap;

		let mut map: HashMap<i32, usize> = HashMap::new();

		for row in &matrix {
			let min = row.iter().min().unwrap();
			map.insert(*min, 0);
		}

		for i in 0..matrix[0].len() {
			let mut max = 0;
			for row in &matrix {
				if row[i] > max {
					max = row[i];
				}
			}
			map.entry(max).and_modify(|cnt| *cnt += 1).or_insert(0);
		}

		map.into_iter()
			.filter_map(|(n, cnt)| {
				if cnt >= 1 {
					Some(n)
				} else {
					None
				}
			})
			.collect()
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
