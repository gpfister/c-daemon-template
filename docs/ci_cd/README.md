# CI/CD workflows

## Dev container

A dev container is provided, which can serve to test locally the CI/CD actions
by reproducing the different steps inside.

## GitHub actions

GitHub actions can be found in the `.github/workflows` folder. There are two
triggered actions:

- pull_request.yaml, which is triggered when a PR is submitted;
- release.yaml, which is triggered when a release is published.

These actions will use the following _sub-actions_:

- build.yaml: Builds and cache the build result for a given board;
- test.yaml: Runs unit tests (it requires the build cached by build.yaml);
- publish.yaml: Publish the build code zipped along with the release version
  (it requires the build cached by build.yaml).

### Pull request and push

Pull request and push related actions consists in building and running unit
tests.

### Release

Release related action consists in building and uploading executables on the
created release.