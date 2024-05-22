#[cfg(test)]
mod utils;

pub struct Solution;

// start
impl Solution {
    pub fn add_to_array_form(num: Vec<i32>, mut k: i32) -> Vec<i32> {
        let mut ret = vec![];
        let mut i = num.len() - 1;
        let mut j = 0;

        while j < num.len() || k > 0 {
            if j < num.len() {
                k += num[i];
            }
            ret.push(k % 10);
            k /= 10;
            j += 1;
            i -= 1;
        }

        ret.reverse();

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
