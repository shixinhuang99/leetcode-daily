#[cfg(test)]
mod utils;

pub struct Solution;

// start
#[derive(PartialEq, Eq, Clone, Debug)]
pub struct ListNode {
	pub val: i32,
	pub next: Option<Box<ListNode>>,
}

impl ListNode {
	#[inline]
	fn new(val: i32) -> Self {
		ListNode { next: None, val }
	}
}

impl Solution {
	pub fn get_decimal_value(mut head: Option<Box<ListNode>>) -> i32 {
		let mut ret = 0;

		while let Some(node) = head {
			ret <<= 1;
			ret |= node.val;
			head = node.next;
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

	fn test_solution() {}
}
