#[cfg(test)]
mod utils;

pub struct Solution;

// start
impl Solution {
    pub fn find_complement(mut num: i32) -> i32 {
        let mut i = 0;
        let mut n = num;
        while n > 0 {
            n >>= 1;
            i += 1;
        }
        num = !num;
        num <<= 32 - i;
        num >>= 32 - i;

        num
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
