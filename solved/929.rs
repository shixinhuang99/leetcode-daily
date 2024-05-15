#[cfg(test)]
mod utils;

pub struct Solution;

// start
impl Solution {
    pub fn num_unique_emails(emails: Vec<String>) -> i32 {
        use std::collections::HashSet;

        let mut set: HashSet<String> = HashSet::new();

        for email in emails {
            let (local, domain) = email.split_once('@').unwrap();
            let left = if let Some(ret) = local.split_once('+') {
                ret.0
            } else {
                local
            };
            let local_unique = left.replace('.', "");
            set.insert(format!("{}@{}", local_unique, domain));
        }

        set.len() as i32
    }
}
// end

#[cfg(test)]
mod tests {
    use super::*;
    use test_case::test_case;
    use utils::*;

    #[test_case(&["test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"], 2)]
    #[test_case(&["a@leetcode.com","b@leetcode.com","c@leetcode.com"], 3)]
    fn test_solution(emails: &[&str], ans: i32) {
        assert_eq!(
            Solution::num_unique_emails(
                emails.iter().map(|s| s.to_string()).collect()
            ),
            ans
        );
    }
}
