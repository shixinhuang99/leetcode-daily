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
