#[cfg(test)]
mod utils;

pub struct Solution;

// start
impl Solution {
	pub fn sort_string(s: String) -> String {
		let mut ret = String::new();
		let mut cc = [0; 26];

		for ch in s.bytes() {
			cc[(ch - b'a') as usize] += 1;
		}

		while ret.len() != s.len() {
			for (i, cnt) in
				cc.iter_mut().enumerate().filter(|(_, cnt)| **cnt != 0)
			{
				ret.push(char::from(i as u8 + b'a'));
				*cnt -= 1;
			}
			for (i, cnt) in cc
				.iter_mut()
				.enumerate()
				.rev()
				.filter(|(_, cnt)| **cnt != 0)
			{
				ret.push(char::from(i as u8 + b'a'));
				*cnt -= 1;
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

	#[test_case(S!("aaaabbbbcccc"), S!("abccbaabccba"))]
	#[test_case(S!("rat"), S!("art"))]
	fn test_solution(s: String, ans: String) {
		assert_eq!(Solution::sort_string(s), ans);
	}
}
