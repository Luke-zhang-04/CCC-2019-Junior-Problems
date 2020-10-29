#!/usr/bin/env node

import chokidar from "chokidar"
import childProcess from "child_process"

const resolveChildProcess = (err, stdout, stderr, resolve) => {
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
