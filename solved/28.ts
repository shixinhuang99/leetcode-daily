function strStr(haystack: string, needle: string): number {
  if (!needle.length) {
    return 0
  }
  let res = -1
  for (let i = 0, l = haystack.length, ll = needle.length; l - i >= ll; i++) {
    let match = true
    for (let j = 0; j < ll; j++) {
      if (needle[j] !== haystack[j + i]) {
        match = false
        break
      }
    }
    if (match) {
      res = i
      break
    }
  }
  return res
};

function strStr2(haystack: string, needle: string): number {
  return haystack.indexOf(needle)
};

/**
 * @todo KMP
 */
function strStr3(haystack: string, needle: string): number {
  
};
