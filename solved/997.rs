#[cfg(test)]
mod utils;

pub struct Solution;

// start
impl Solution {
    pub fn find_judge(n: i32, trust: Vec<Vec<i32>>) -> i32 {
        let mut v_trust = vec![0; n as usize + 1];
        let mut v_be_trusted = vec![0; n as usize + 1];

        for chunk in trust {
            v_trust[chunk[0] as usize] += 1;
            v_be_trusted[chunk[1] as usize] += 1;
        }

        for i in 1..=n as usize {
            if v_trust[i] == 0 && v_be_trusted[i] == n - 1 {
                return i as i32;
            }
        }

        -1
    }
}
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
