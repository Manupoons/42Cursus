# Born2beRoot

A system administration project: set up a secure Linux server inside a virtual machine, following strict rules.

**What the project covers**
- Creating and configuring a VM (Debian or Rocky), with an encrypted partition set up using LVM
- A strong password policy and user/group management with `sudo` rules
- SSH on a custom port, and a firewall (UFW or firewalld)
- Mandatory security modules (AppArmor or SELinux)
- A `monitoring.sh` script that broadcasts system information (architecture, CPU, RAM, disk, connections, ...) to all terminals every 10 minutes using `cron`

The VM disk image is not included in this repository.
