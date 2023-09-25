fn main() {
	let sol = Solution {};
	sol.assert();
}

trait SolutionRunner {
	fn assert(&self) {
		for (input, ans) in self.gen_test_cases() {
			let ret = if ans == self.sol_proxy(&input) {
				"ok"
			} else {
				"wrong"
			};

			println!("{:?} -> {:?}: {}", input, ans, ret);
		}
	}

	fn sol_proxy(&self, input: &Input) -> Answer;

	fn gen_test_cases(&self) -> Vec<(Input, Answer)>;
}

#[derive(Debug, Clone)]
struct Input {
	nums: Vec<i32>,
	target: i32,
}

type Answer = Vec<i32>;

struct Solution;

impl Solution {
	pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
		use std::collections::hash_map::HashMap;

		let mut map: HashMap<i32, i32> = HashMap::with_capacity(nums.len());

		for (i, num) in nums.into_iter().enumerate() {
			if let Some(index) = map.get(&(target - num)) {
				return vec![*index, i as i32];
			}
			map.insert(num, i as i32);
		}

		panic!()
	}
}

impl SolutionRunner for Solution {
	fn sol_proxy(&self, input: &Input) -> Answer {
		let input = input.clone();
		Self::two_sum(input.nums, input.target)
	}

	fn gen_test_cases(&self) -> Vec<(Input, Answer)> {
		vec![
			(
				Input {
					nums: vec![2, 7, 11, 15],
					target: 9,
				},
				vec![0, 1],
			),
			(
				Input {
					nums: vec![3, 2, 4],
					target: 6,
				},
				vec![1, 2],
			),
			(
				Input {
					nums: vec![3, 3],
					target: 6,
				},
				vec![0, 1],
			),
		]
	}
}
