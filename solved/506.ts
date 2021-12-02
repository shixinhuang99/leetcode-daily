function findRelativeRanks(score: number[]): string[] {
  const sourceMap = new Map(
    score.map((item, index) => {
      return [item, index]
    })
  )
  const medals = ['Gold Medal', 'Silver Medal', 'Bronze Medal']
  const sortScore = score.slice().sort((a, b) => b - a)
  const ans: string[] = Array(score.length)
  for (let i = 0, l = sortScore.length; i < l; i++) {
    const sourceIndex = sourceMap.get(sortScore[i])
    if (i < 3) {
      ans[sourceIndex] = medals[i]
    } else {
      ans[sourceIndex] = (i + 1).toString()
    }
  }
  return ans
}
