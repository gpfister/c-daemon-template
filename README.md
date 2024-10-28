[![Release](https://github.com/gpfister/c-daemon-template/actions/workflows/release.yaml/badge.svg)](https://github.com/gpfister/c-daemon-template/actions/workflows/release.yaml)
[![Contributor Covenant](https://img.shields.io/badge/Contributor%20Covenant-2.1-4baaaa.svg)](CODE_OF_CONDUCT.md)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE.md)

# Template - Kickstart your C daemon project

> Copyright © 2024, Greg PFISTER. MIT License.

## About

This is a template project that aim at been a kickstart for C daemon projects.

It provides:

- A base daemon project written in C.
- Instructions to set `Clion`, `Visual Studio Code`, `neovim` and `emacs` IDE.
- A dev container (to test build is similar conditions as in CI/CD)
- Actions for GitHub for build, unit test and release

### Roadmap of IDE instructions

1. `Clion`
2. `Visual Studio Code`
3. `neovim`
4. `emacs`

### Roadmap of CI/CD workflows

1. `GitHub`
2. `Bitbucket`
3. `Gitlab`

## Getting started

### Clone and adjust the kickstarter repo

First clone this repo in your favorite development folder, remove git:

```shell
cd ~/Development                                        && \  
git clone https://github.com/gpfister/gp-c-daemon-template.git && \  
mv gp-c-daemon-template my-project                             && \  
cd my-project                                     
rm -rf .git
```

Then, rename all instances of `gp-c-daemon-template` to `my-project`, as well as all
instances of `template` to `my_executable`:

```shell
git grep -z -l 'gp-c-daemon-template' | xargs -0 sed -i '' -e 's/gp-c-daemon-template/my-project/g' && \  
git grep -z -l 'template' | xargs -0 sed -i '' -e 's/template/my_executable/g'
```

At that point, you may want to adjust `LICENSE.md`, `README.md`, ... before
initiating `git` and making the first commit.

```shell
git init
git add .
git commit -m "First commit"
```

### Build files from command line

To build for debug and unit testing, create a build folder, generate build 
environment then run make command:

```shell
mkdir build/debug && cd build/debug
cmake -DCMAKE_BUILD_TYPE=Debug -DUNIT_TESTING=ON ../..
make -j 8
```

Alternatively you can build for release:

```shell
mkdir build/release && cd build/release
cmake -DCMAKE_BUILD_TYPE=Release ../..
make -j 8
```

### Unit testing

Assuming the build environment has been created using `-DUNIT_TESTING=ON`, you
can run unit test by running the `ctest` command.

To run unit tests with no detail:

```shell
ctest --parallel
```

To run unit tests with all details:

```shell
ctest --extra-verbose
```

To run and stop at the first error:

```shell
ctest --extra-verbose --stop-on-failure 
```

## IDE setup

Here are steps to set up various IDE in order to develop for this project.

### `Clion setup`

See [docs/clion/README.md](docs/clion/README.md).

### `Visual Studio Code setup`

See [docs/vscode/README.md](docs/vscode/README.md).

### `neovim` setup

See [docs/neovim/README.md](docs/neovim/README.md).

### `emacs` setup

See [docs/emacs/README.md](docs/emacs/README.md).

## CI/CD support

See [docs/ci_cd/README.md](docs/ci_cd/README.md)

## Contribution

Contributions are welcome. Please refer to the [code of conduct](./CODE_OF_CONDUCT.md).

## License

For more details, please read the [license](./LICENSE.md) terms.
