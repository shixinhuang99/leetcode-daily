#[cfg(test)]
mod utils;

pub struct Solution;

// start
impl Solution {
    pub fn remove_outer_parentheses(s: String) -> String {
        let mut ret = String::new();
        let mut stack = String::new();
        for ch in s.chars() {
            if ch == ')' {
                stack.pop();
            }
            if !stack.is_empty() {
                ret.push(ch);
            }
            if ch == '(' {
                stack.push(ch);
            }
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
