# Create an RPM with a systemd service via CPack
This is a bare-bones project that demonstrates how to create
an RPM using CPack that contains a systemd service. I'm a
novice when in comes to creating RPMs- _caveat emptor_.

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

## References
- [Fedora: Systemd Packaging](https://fedoraproject.org/wiki/Packaging:Systemd#Packaging)
- [Fedora: Systemd Scriptlets](https://docs.fedoraproject.org/en-US/packaging-guidelines/Scriptlets/#_systemd)
- [CPack: RPM Generator](https://cmake.org/cmake/help/latest/cpack_gen/rpm.html#cpack_gen:CPack%20RPM%20Generator)