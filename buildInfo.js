/**
 * @file stores shasums of files in a JSON file and compares them later
 */

const fs = require("fs")

/**
 * @template T
 * @param {(...unknown[])=> T} func - callback function
 * @returns {T | void} void if error
 */
const niceTry = (func) => {
    try {
        return func()
    } catch {}
}

const buildInfo = niceTry(() => require("./buildInfo.json")) ?? {},
    stdinBuffer = fs.readFileSync(0, "utf-8") // STDIN_FILENO = 0,
let checksum = stdinBuffer.toString().trim()

checksum = checksum.replace(/-/gui, "").trim()

if (buildInfo.lastCompile && buildInfo.lastCompile === checksum) {
    console.log(0)
} else {
    buildInfo.lastCompile = checksum

    fs.writeFile("buildInfo.json", JSON.stringify(buildInfo) + "\n", () => {
        console.log(1)
    })
}
