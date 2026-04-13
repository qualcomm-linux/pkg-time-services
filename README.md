# Time-Daemon

**Time-services Daemon** to sync time from Modem to APPS and maintain time across reboots (even if the modem is not network camped).

## Compilation Steps
### 1. Download and Install qmi-framework
Follow the instructions from the repository to compile and install qmi-framework:
```sh
https://github.com/quic/qmi-framework/
```
### 2. Navigate to the project directory:
```sh
cd time-services
```
### 4. Build the project:
```sh
autoreconf --install
./configure --with_qmi_prefix <absolute path to qmi-framework>
make
make install
```
By default, ```./configure``` command will configure the project to install compiled libraries and
binaires in system's  ```/usr/bin``` directory.
To install libraries and binaries in custom directory, you can specify the directory by passing
```--prefix``` flag.
For example: ```./configure --with-qmif-prefix=<absolute path to qmi-framework> --prefix=$(pwd)/install```

Alternatively, you can also run the below script, passing the required compiler as an argument:
```sh
./build_script.sh --with_qmi_prefix <absolute path to qmi-framework>
```
For, ARM based targets:
```sh
./build_script.sh --host aarch64-linux-gnu --with_qmi_prefix <absolute path to qmi-framework>
```
By default, it will compile for X86 target.
## License
Time-services is licensed under the BSD 3-clause "New" or "Revised" License.
