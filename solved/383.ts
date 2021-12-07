function canConstruct(ransomNote: string, magazine: string): boolean {
  const ransomNoteChCount = Array<number>(26).fill(0)
  const magazineChCount = Array<number>(26).fill(0)
  for (let i = 0, l = ransomNote.length; i < l; i++) {
    const index = ransomNote.charCodeAt(i) - 97
    ransomNoteChCount[index]++
  }
  for (let i = 0, l = magazine.length; i < l; i++) {
    const index = magazine.charCodeAt(i) - 97
    magazineChCount[index]++
  }
  for (let i = 0, l = ransomNoteChCount.length; i < l; i++) {
    if (ransomNoteChCount[i] > magazineChCount[i]) {
      return false
    }
  }
  return true
}

function canConstruct2(ransomNote: string, magazine: string): boolean {
  if (ransomNote.length > magazine.length) {
    return false
  }
  const count = Array<number>(26).fill(0)
  for (let i = 0, l = magazine.length; i < l; i++) {
    count[magazine.charCodeAt(i) - 97]++
  }
  for (let i = 0, l = ransomNote.length; i < l; i++) {
    const index = ransomNote.charCodeAt(i) - 97
    count[index]--
    if (count[index] < 0) {
      return false
    }
  }
  return true
}
