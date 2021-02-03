#!/usr/bin/env node

// Using vscode run on save is preferred

/**
 * @file autoformatting and file watching with black for Python and clang-format
 * for C++
 * @see {@link https://github.com/psf/black}
 * @see {@link https://clang.llvm.org/docs/ClangFormat.html}
 */

import chokidar from "chokidar"
import childProcess from "child_process"

let start = Date.now()

const resolveChildProcess = (err, stdout, stderr) => {
    err && console.error(err)
    stderr && console.error(stderr)
    stdout && console.log(stdout)

    if (!err && !stderr && !stdout) {
        console.log("All done!\n")
    }

    console.log(`Done in ${Date.now() - start}ms`)
}


childProcess.exec(
    "clang-format **/*.cpp -style=file -i &\n black **/*.py &\n wait",
    resolveChildProcess,
)

if (process.argv.includes("--watch") || process.argv.includes("-w")) {
    console.log("Watching for changes...")
    chokidar.watch(
        "**",
        {
            usePolling: true,
            atomic: 1250,
        },
    ).on("change", async (path) => {
        if (path.includes(".cpp")) {
            console.clear()
            console.log("Formatting . . .\n")
            start = Date.now()

            childProcess.exec(
                `clang-format ${path} -style=file -i`,
                resolveChildProcess,
            )
        } else if (path.includes(".py")) {
            console.clear()
            console.log("Formatting . . .\n")
            start = Date.now()

            childProcess.exec(`black ${path}`, resolveChildProcess)
        }
    })
}
