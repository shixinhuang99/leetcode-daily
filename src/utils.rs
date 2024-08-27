pub fn slice_eq_no_order<T>(v1: &mut [T], v2: &mut [T]) -> bool
where
	T: std::cmp::Ord,
{
	v1.sort();
	v2.sort();

	v1 == v2
}

pub fn str_slice_to_string_vec(ss: &[&str]) -> Vec<String> {
	ss.iter().map(|s| s.to_string()).collect()
}

#[cfg(all(feature = "test_utils", test))]
mod tests {
	use super::*;

	#[test]
	fn test_slice_eq_no_order() {
		assert!(slice_eq_no_order(&mut [1, 0], &mut [0, 1]));
	}
}
