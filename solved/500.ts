function findWords(words: string[]): string[] {
  const res: string[] = []
  const cols = ['qwertyuiop', 'asdfghjkl', 'zxcvbnm']
  next: for (const word of words) {
    const targetCol = cols.find(
      (col) => col.indexOf(word[0].toLowerCase()) !== -1
    )
    if (!targetCol) {
      continue
    }
    for (const ch of word.toLowerCase()) {
      if (targetCol.indexOf(ch) === -1) {
        continue next
      }
    }
    res.push(word)
  }
  return res
}
