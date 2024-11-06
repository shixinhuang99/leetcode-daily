#[cfg(test)]
mod utils;

pub struct Solution;

// start
impl Solution {
	pub fn array_rank_transform(mut arr: Vec<i32>) -> Vec<i32> {
		use std::collections::hash_map::{Entry, HashMap};

		let mut sorted = arr.clone();
		sorted.sort_unstable();
		let mut map: HashMap<i32, i32> = HashMap::new();

		let mut sn = 1;
		for n in sorted {
			if let Entry::Vacant(e) = map.entry(n) {
				e.insert(sn);
				sn += 1;
			}
		}

		for n in &mut arr {
			*n = map[n];
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

	#[test_case(vec![40,10,20,30], vec![4,1,2,3])]
	#[test_case(vec![100,100,100], vec![1,1,1])]
	#[test_case(vec![37,12,28,9,100,56,80,5,12], vec![5,3,4,2,8,6,7,1,3])]
	#[test_case(vec![10], vec![1])]
	#[test_case(vec![], vec![])]
	fn test_solution(arr: Vec<i32>, ans: Vec<i32>) {
		assert_eq!(Solution::array_rank_transform(arr), ans);
	}
}
