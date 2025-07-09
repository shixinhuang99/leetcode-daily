#[cfg(test)]
mod utils;

pub struct Solution;

// start
impl Solution {
	pub fn construct_rectangle(area: i32) -> Vec<i32> {
		let mut w = (area as f32).sqrt().floor() as i32;

		while area % w != 0 {
			w -= 1;
		}

		vec![area / w, w]
	}
}
// end

#[cfg(test)]
mod tests {
	use super::*;
	use test_case::test_case;
	use utils::*;

	#[test_case(4, vec![2, 2])]
	#[test_case(37, vec![37, 1])]
	#[test_case(122122, vec![427, 286])]
	fn test_solution(area: i32, ans: Vec<i32>) {
		assert_eq!(Solution::construct_rectangle(area), ans);
	}
}
