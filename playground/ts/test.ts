import fs from 'fs'
import sol from './sol'

const fileContent = fs.readFileSync('./playground/ts/test.json', { encoding: 'utf-8' })
const data: any[] = JSON.parse(fileContent)

for (const i of data) {
  const res = sol(i)
  console.log(res)
}
