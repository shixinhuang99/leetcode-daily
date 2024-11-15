#[cfg(test)]
mod utils;

pub struct Solution;

// start
impl Solution {
	pub fn max_score(s: String) -> i32 {
		let chs = s.chars().collect::<Vec<char>>();
		let mut one_total = 0;

		for ch in &chs {
			if *ch == '1' {
				one_total += 1;
			}
		}

		let mut zero = 0;
		let mut one = one_total;
		let mut max = 0;

		for ch in &chs[0..chs.len() - 1] {
			if *ch == '0' {
				zero += 1;
			} else if one > 0 {
				one -= 1;
			}
			let sum = zero + one;
			if sum > max {
				max = sum;
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
