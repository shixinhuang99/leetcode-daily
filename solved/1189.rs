#[cfg(test)]
mod utils;

pub struct Solution;

// start
impl Solution {
	pub fn max_number_of_balloons(text: String) -> i32 {
		let mut b = 0;
		let mut a = 0;
		let mut l = 0;
		let mut o = 0;
		let mut n = 0;

		for ch in text.chars() {
			match ch {
				'b' => b += 1,
				'a' => a += 1,
				'l' => l += 1,
				'o' => o += 1,
				'n' => n += 1,
				_ => (),
			}
		}

		l /= 2;
		o /= 2;

		[b, a, l, o, n].into_iter().min().unwrap()
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
