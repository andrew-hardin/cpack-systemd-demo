# Create an RPM with a systemd service via CPack
This project uses CPack to create an RPM containing a systemd
service. I'm a novice when in comes to creating RPMs- _caveat emptor_.

Here's a utilitarian user's guide:
```bash
# Clone, build, and package the project.
mkdir build
cd build
cmake .. -DCMAKE_INSTALL_PREFIX=/opt/hello-world-service
make package

# Go ahead and install the RPM.
ls *.rpm
yum install ./hello-world-0.1-Linux.rpm

# Check the status of the service - should be stopped.
systemctl status hello-world

# Start the service, then check its status.
systemctl start hello-world
systemctl status hello-world

# Removing the RPM should cleanup all traces.
yum remove hello-world
systemctl status hello-world
```

## Upgrading from 0.1...
This project was fixed to support upgrades to the RPM package.
If you're creating your own RPMs, I strongly recommend testing
the upgrade process _before_ shipping.


## References
- [Fedora: Systemd Packaging](https://fedoraproject.org/wiki/Packaging:Systemd#Packaging)
- [Fedora: Systemd Scriptlets](https://docs.fedoraproject.org/en-US/packaging-guidelines/Scriptlets/#_systemd)
- [CPack: RPM Generator](https://cmake.org/cmake/help/latest/cpack_gen/rpm.html#cpack_gen:CPack%20RPM%20Generator)
- [Question: RPM upgrades](https://stackoverflow.com/questions/7398834/rpm-upgrade-uninstalls-the-rpm)
- [Blog: RPM upgrades](https://lkhill.com/rpm-postupgrade/)