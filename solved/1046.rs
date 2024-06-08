#[cfg(test)]
mod utils;

pub struct Solution;

// start
impl Solution {
    pub fn last_stone_weight(stones: Vec<i32>) -> i32 {
        use std::collections::BinaryHeap;

        let mut pq = BinaryHeap::from_iter(stones);

        while pq.len() > 1 {
            let a = pq.pop().unwrap();
            let b = pq.pop().unwrap();
            let diff = a - b;
            if diff > 0 {
                pq.push(diff);
            }
        }

        pq.pop().unwrap_or(0)
    }
}

// impl Solution {
//     pub fn last_stone_weight(mut stones: Vec<i32>) -> i32 {
//         stones.sort_unstable();

//         while stones.len() > 1 {
//             let a = stones.pop().unwrap();
//             let b = stones.pop().unwrap();
//             let diff = a - b;
//             if diff > 0 {
//                 let idx = stones.partition_point(|n| *n < diff);
//                 stones.insert(idx, diff);
//             }
//         }

//         stones.pop().unwrap_or(0)
//     }
// }
// end

#[cfg(test)]
mod tests {
    use super::*;
    use test_case::test_case;
    use utils::*;

    fn test_solution() {
        //
    }
}
