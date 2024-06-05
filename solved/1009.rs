#[cfg(test)]
mod utils;

pub struct Solution;

// start
impl Solution {
    pub fn bitwise_complement(mut n: i32) -> i32 {
        if n == 0 {
            return 1;
        }
        let mut bits = vec![];
        while n > 0 {
            bits.push((n & 1) ^ 1);
            n >>= 1;
        }
        let mut ret = 0;
        for (i, v) in bits.iter().enumerate().rev() {
            ret += v * 2_i32.pow(i as u32);
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

    fn test_solution() {
        //
    }
}
