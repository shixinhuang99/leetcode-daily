pub fn slice_eq_no_order<T>(v1: &[T], v2: &[T]) -> bool
where
    T: Eq + std::hash::Hash,
{
    use std::collections::HashSet;

    let set1: HashSet<&T> = HashSet::from_iter(v1);
    let set2: HashSet<&T> = HashSet::from_iter(v2);

    set1 == set2
}

pub fn str_slice_to_string_vec(ss: &[&str]) -> Vec<String> {
    ss.iter().map(|s| s.to_string()).collect()
}

#[cfg(all(feature = "test_utils", test))]
mod tests {
    use super::*;

    #[test]
    fn test_slice_eq_no_order() {
        assert!(slice_eq_no_order(&[1, 0], &[0, 1]));
    }
}
