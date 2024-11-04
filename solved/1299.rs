#[cfg(test)]
mod utils;

pub struct Solution;

// start
impl Solution {
	pub fn replace_elements(mut arr: Vec<i32>) -> Vec<i32> {
		fn find_max(items: &[i32], idx: usize) -> Option<(i32, usize)> {
			let mut max = -1;
			let mut idx_of_max = 0;

			for (i, &v) in items.iter().enumerate().skip(idx + 1) {
				if v > max {
					max = v;
					idx_of_max = i;
				}
			}

			if max == -1 {
				None
			} else {
				Some((max, idx_of_max))
			}
		}

		let mut i = 0;

		while i < arr.len() {
			if let Some((max, j)) = find_max(&arr, i) {
				while i < j {
					arr[i] = max;
					i += 1;
				}
			} else {
				arr[i] = -1;
				break;
			}
		}

		arr
	}
}
// end

#[cfg(test)]
mod tests {
	use super::*;
	use test_case::test_case;
	use utils::*;

	#[test_case(vec![17,18,5,4,6,1], vec![18,6,6,6,1,-1])]
	fn test_solution(arr: Vec<i32>, ans: Vec<i32>) {
		assert_eq!(Solution::replace_elements(arr), ans);
	}
}
