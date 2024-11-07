#[cfg(test)]
mod utils;

pub struct Solution;

// start
impl Solution {
	pub fn sort_by_bits(mut arr: Vec<i32>) -> Vec<i32> {
		fn count_ones(mut n: i32) -> i32 {
			let mut count = 0;
			while n != 0 {
				n &= n - 1;
				count += 1;
			}
			count
		}

		arr.sort_unstable_by(|a, b| {
			let ca = count_ones(*a);
			let cb = count_ones(*b);
			if ca == cb {
				return a.cmp(b);
			}
			ca.cmp(&cb)
		});

		arr
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
