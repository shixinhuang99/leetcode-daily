#[cfg(test)]
mod utils;

pub struct Solution;

// start
impl Solution {
    pub fn unique_occurrences(arr: Vec<i32>) -> bool {
        use std::collections::{HashMap, HashSet};

        let mut map: HashMap<i32, usize> = HashMap::new();

        for num in arr {
            map.entry(num).and_modify(|cnt| *cnt += 1).or_insert(1);
        }

        let len = map.values().len();
        let count_set: HashSet<&usize> = HashSet::from_iter(map.values());

        len == count_set.len()
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
