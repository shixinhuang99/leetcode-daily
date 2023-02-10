mod sol;
mod utils;

use utils::{read_test_cases, format_table};
use sol::{Args, Answer};

fn main() {
    let test_cases =
        read_test_cases::<&str, Answer, Args>("input.json").unwrap();

    let table_str = format_table(test_cases);

    println!("{}", table_str);
}

#[cfg(test)]
mod tests {
    const SNAPSHOT: &'static str = r#" args                                     | answer | output | result 
------------------------------------------+--------+--------+--------
 Args { nums: [2, 7, 11, 15], target: 9 } | [0, 1] | [0, 1] |   [32m✔︎[39m    
 Args { nums: [3, 2, 4], target: 6 }      | [1, 2] | [1, 2] |   [32m✔︎[39m    
 Args { nums: [3, 3], target: 6 }         | [0, 1] | [0, 1] |   [32m✔︎[39m    "#;

    use serde::Deserialize;
    use crate::utils::{SolutionTrait, read_test_cases, format_table};

    use std::collections::HashMap;

    #[derive(Deserialize, Debug)]
    struct Args {
        nums: Vec<i32>,
        target: i32,
    }

    type Answer = Vec<i32>;

    impl SolutionTrait for Args {
        type Output = Answer;

        fn get_output(self) -> Self::Output {
            Solution::two_sum(self.nums, self.target)
        }
    }

    struct Solution;

    impl Solution {
        pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
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

    #[test]
    fn two_sum() {
        let test_cases =
            read_test_cases::<&str, Answer, Args>("input_two_sum.json")
                .unwrap();

        let table_str = format_table(test_cases);

        assert_eq!(SNAPSHOT, table_str)
    }
}
