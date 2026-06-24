# pkg-time-services

Debian packaging repository for [time-services](https://github.com/quic/time-services), a daemon that synchronises time from the modem to the applications processor and maintains time offsets across reboots on Qualcomm platforms.

## Branches

- **main**: Workflow definitions (`.github/`), documentation, and repository configuration. No source code.
- **upstream/latest**: Tracks upstream source releases from [quic/time-services](https://github.com/quic/time-services).
- **qcom/debian/latest**: Active Debian packaging development. This is where day-to-day packaging work happens.
- **debian/qcom-next**: Packaging signed off as meeting Debian mainline standards, pending upstream inclusion.

## Workflows

The `main` branch includes the following workflows in the `.github/workflows/` directory:

- **qcom-preflight-checks.yml**: Sanity checks (repolinter, semgrep, copyright/licence detection, email checks, dependency review) run on all PRs and pushes.
- **stale-issues.yaml**: Manages stale issues.
- **build-debian-package.yml**: Builds the Debian package by invoking reusable workflows from [qcom-build-utils](https://github.com/qualcomm-linux/qcom-build-utils).
- **pr-pre-post-merge.yml**: Runs on PR open and post-merge.
- **promote-upstream.yml**: Promotes the packaging to a new upstream release.
- **release.yml**: Triggers a package release.

## License

pkg-time-services is licensed under the [BSD-3-Clause License](https://spdx.org/licenses/BSD-3-Clause.html). See [LICENSE.txt](LICENSE.txt) for the full licence text.
