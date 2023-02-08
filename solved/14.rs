pub fn longest_common_prefix(strs: Vec<String>) -> String {
    let first = &strs[0];
    let rest = &strs[1..];

    for (i, ch) in first.char_indices() {
        for str in rest {
            if i >= str.len() || ch != str.chars().nth(i).unwrap() {
                return first[0..i].to_string();
            }
        }
    }

    strs[0].clone()
}
