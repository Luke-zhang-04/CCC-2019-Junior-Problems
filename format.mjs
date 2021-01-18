#!/usr/bin/env node

/**
 * @file autoformatting and file watching with black for Python and clang-format
 * for C++
 * @see {@link https://github.com/psf/black}
 * @see {@link https://clang.llvm.org/docs/ClangFormat.html}
 */

import chokidar from "chokidar"
import childProcess from "child_process"


const resolveChildProcess = (err, stdout, stderr) => {
    err && console.error(err)
    stderr && console.error(stderr)
    stdout && console.log(stdout)
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
        console.log("Formatting")

        if (path.includes(".cpp")) {
            childProcess.exec(
                `clang-format ${path} -style=file -i`,
                resolveChildProcess,
            )
        } else if (path.includes(".py")) {
            childProcess.exec(`black ${path}`, resolveChildProcess)
        }
    })
}
