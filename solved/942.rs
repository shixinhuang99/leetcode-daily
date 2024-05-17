#[cfg(test)]
mod utils;

pub struct Solution;

// IDID
// 0
// 04
// 041
// 0413
// 04132

// III
// 0123

// DDD
// 0123
// 1023
// 1203
// 1230
// 2130
// 2310
// 3210

// IDDIID
// 0
// 06
// 065
// 0651
// 06512
// 065124
// 0651243

// start
impl Solution {
    pub fn di_string_match(s: String) -> Vec<i32> {
        let mut ret = vec![];
        let mut min = 0;
        let mut max = s.len() as i32;

        for ch in s.chars() {
            if ch == 'I' {
                ret.push(min);
                min += 1;
            } else if ch == 'D' {
                ret.push(max);
                max -= 1;
            }
        }

        ret.push(min);

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
