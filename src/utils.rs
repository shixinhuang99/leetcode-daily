pub fn slice_eq_no_order<T>(v1: &mut [T], v2: &mut [T]) -> bool
where
	T: std::cmp::Ord,
{
	v1.sort();
	v2.sort();

	v1 == v2
}

#[cfg(all(feature = "test_utils", test))]
mod tests {
	use super::*;

	#[test]
	fn test_slice_eq_no_order() {
		assert!(slice_eq_no_order(&mut [1, 0], &mut [0, 1]));
	}
}

pub trait VecExt {
    type Output;

    fn to_elements_owned(&self) -> Vec<Self::Output>;
}

impl VecExt for Vec<&str> {
    type Output = String;

    fn to_elements_owned(&self) -> Vec<String> {
        self.iter().map(|s| s.to_string()).collect()
    }
}
