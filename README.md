# reason grammar for Tree-sitter

This repository contains a parser definition of the [reason](https://reason-lang.org/) language for the [Tree-sitter](https://tree-sitter.github.io/tree-sitter/) parser generator tool.

Athough Tree-sitter has many applications, the main intent of this parser is powering the [`nvim-treesitter-reason`](https://github.com/danielo515/nvim-tree-sitter-reason/) NeoVim plugin which may be used to improve development experience in the NeoVim + reason combo.

Queries for text objects are also included which help you to navigate, select, and modify reason code syntactically. For NeoVim, the [`nvim-treesitter-textobjects`](https://github.com/nvim-treesitter/nvim-treesitter-textobjects) plugin is required to use Tree-sitter text objects.

## Installation

- If you want reason Tree-sitter in NeoVim, refer to [`nvim-treesitter-reason`](https://github.com/danielo515/nvim-tree-sitter-reason/) installation notes;
- If you want it for other purposes, you probably know what to do.

## Contributing

Contributions are welcome. Here’s how you can help:

🙂 Provide a minimal reason snippet which produces an `(ERROR)` node or otherwise incorrect syntax tree. Open a new issue providing this snippet and the resulting syntax tree. You can use the following command to see the syntax tree:

```bash
yarn tree-sitter parse /path/to/your/snippet.res
```

🤩 Add a failing test case for a snippet which is valid reason but produces an incorrect syntax tree. Fix the `grammar.js`. Make sure nothing is broken: `make test test_wild` shows 100% test success. Open a pull request.
