#[cfg(test)]
mod utils;

pub struct Solution;

// start
impl Solution {
	pub fn min_time_to_visit_all_points(points: Vec<Vec<i32>>) -> i32 {
		let mut ret = 0;

		for pair in points.windows(2) {
			let dx = (pair[0][0] - pair[1][0]).abs();
			let dy = (pair[0][1] - pair[1][1]).abs();
			ret += dx.max(dy);
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

	#[test_case(vec_2d![[1,1],[3,4],[-1,0]], 7)]
	#[test_case(vec_2d![[3,2],[-2,2]], 5)]
	fn test_solution(points: Vec<Vec<i32>>, ans: i32) {
		assert_eq!(Solution::min_time_to_visit_all_points(points), ans);
	}
}
