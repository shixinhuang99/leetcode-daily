pub fn slice_eq_no_order<T>(v1: &[T], v2: &[T]) -> bool
where
    T: Eq + std::hash::Hash,
{
    use std::collections::HashSet;

    let set1: HashSet<&T> = HashSet::from_iter(v1);
    let set2: HashSet<&T> = HashSet::from_iter(v2);

    set1 == set2
}

#[cfg(all(feature = "test_utils", test))]
mod tests {
    use super::*;

    #[test]
    fn test_slice_eq_no_order() {
        assert!(slice_eq_no_order(&[1, 0], &[0, 1]));
    }
}
