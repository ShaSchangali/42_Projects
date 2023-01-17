# Born2BeRoot - Guide
This project aims to introduce you to the wonderful world of virtualization. Creating a machine in VirtualBox under specific instructions and set up a Linux operating system while implementing strict rules in Shell.

## Questions & Answers
- Difference between Debian and CentOS?
- What is a Virtual Machine?
- What is the difference between aptitude and APT (Advanced Packaging Tool)?
- What is AppArmor?
- Password Rules
- What is LVM?
- UFW (Uncomplicated Firewall)
- What is SSH?
- What is Cron?

##
## Mandotary
- Downloading Virtual Machine
- Installing The Virtual Machine
- Accessing The Virtual Machine
- Starting The Virtual Machine
- Configurating The Virtual Machine
- Installing Git and Vim
- Installing and Configuring SSH (Secure Shell Host)
- Installing and Configuring UFW (Uncomplicated Firewall)
- Connecting to SSH
- Setting Password Policy
- Creating a Group
- Creating a User and Assigning them Into The Group
- Creating sudo.log
- Configuring Sudoers Group
- Crontab Configuation
- Create script monitorig.sh
- Creating Signature.txt
- Overview Commands (UFW, Group, Host, lsblk and SSH)

##
## Bonus
- Installing Lighttpd
- Installing & Configuring MariaDB
- Installing PHP
- Downloading & Configuring WordPress
- Configuring Lighttpd
- Installing & Configuring (FTP)
- Connecting to Server via FTP
##
## 
# Questions & Answers

### Difference between Debian and CentOS?
Debian is a lot easier to update then CentOS when a new version is released. Debian is more user-friendly and supports many libraries, filesystems and architecture. It also has more options for customisation. If you are a larger business CentOS offers more Enterprise features and excellent support for the Enterprise software.

##
### What is a Virtual Machine?
Is a resource that uses software instead of a physical computer to run programs or apps. Each VM has its own operating system and functions separately, so you can have more than one VM per machine. Can be used to test applications in a safe, separate environment. Works by using software to simulate virtual hardware and run on a host machine.

##
### What is the difference between aptitude and APT (Advanced Packaging Tool)?
* Aptitude is a high-level package manager while APT is lower level which can be used by other higher level package managers
* Aptitude is smarter and will automatically remove unused packages or suggest installation of dependent packages
* Apt will only do explicitly what it is told to do in the command line

##
### What is AppArmor?
Linux security system that provides Mandatory Access Control (MAC) security. Allows the system admin to restrict the actions that processes can perform. It is included by default with Debian. Run aa-status to check if it is running.

##
### Password Rules
We using the password quality checking library and there are two files the common-password file which sets the rules like upper and lower case characters, duplicate characters etc and the login.defs file which stores the password expiration rules (30 days etc).
* Sudo nano /etc/login.defs
* Sudo nano /etc/pam.d/common-password

##
### What is LVM
Logical Volume Manager – allows us to easily manipulate the partitions or logical volume on a storage device.

##
### UFW (Uncomplicated Firewall)
UFW is a interface to modify the firewall of the device without compromising security. You use it to configure which ports to allow connections to and which ports to close. This is useful in conjunction with SSH, can set a specific port for it to work with.

##
### What is SSH?
SSH or Secure Shell is an authentication mechanism between a client and a host. It uses encryption techniques so that all communication between clients and hosts is done in encrypted form. User on Mac or Linux can use SSH the terminal to work on their server via SSH.
##
### What is Cron?
Cron or cron job is a command line utility to schedule commands or scripts to happen at specific intervals or a specific time each day. Useful if you want to set your server to restart at a specific time each day. 
##
- `cd /usr/local/bin` – to show monitoring.sh
- `sudo crontab -u root -e` – to edit the cron job
- `change script to */1 * * * * sleep 30s && script path` – to run it every 30 seconds, delete the line to stop the job from running.
##
##
# ******MANDATORY******
##
# Downloading Virtual Machine
1. Click link <ins>**https://cdimage.debian.org/debian-cd/current/amd64/iso-cd/**
2. Download `debian-mac-xx.x.x-amd64-netinst.iso`
##
##
# Installing The Virtual Machine
1. Click `New`
2. Change Folder to `goinfre/students/your_intra_login/Virtual Machine Name` and click `continue`.
3. Set Memory Size to `1024 MB` and continue.
4. Click `Create a Virtual Hard Disk Now` and then click `Create` to create the Hard Disk.
5. Click `VDI (VirtualBox Disk Image)` and then click `Continue` to select VDI.
6. Click `Dyamically Allocated` and then click `Continue` to only use space on the Hard Disk.
7. Set Size as `12.00 GB` and then click `Continue`.
8. Click `Settings` and then click `Storage` to view the Virtual Machine Storage.
9. Click on `Optical Drive` (Optical Drive - far right blue small box).
10. Click on `Choose a disk file...` (2nd option in the drop down).
11. Click on the Virtual Machine file (.iso). 
12. Click on created `Virtual Machine` and then click `'ok` to confirm you Virtual Machine Storage.
13. Click `Start` (The Green Arrow ➡️) to start Virtual Machine.
##
##
# Accessing The Virtual Machine
#### ⚠️ NOTE: To increase the size, press `command` + `c` use the mouse to drag the screen to the size:
1.  Use the arrow keys on your keyboard 🔼 🔽 and press `Enter` on `Install`
2.  Press `enter` on `English - English` or your language of preference.
3.  Press `enter` on `Australia` or the country your installing this Virtual Machine.
4.  Press `enter` on `American English` or your keyboard of preference.
5.  Create a `Host Name` as your login, with `42` at the end (eg. intraName42) 
6.  Leave Domain name `blank`, press `enter` on Continue.
7.  Create a `Password` for the Host Name
8.  Create a `User Name without 42` at the end (eg. test_user)
9.  Create a Password for the User Name
10. Prss `enter` on your `Timezone`
11. Press `enter` on `Guided - use entire disk and set up encrypted LVM`
12. Press `enter` on Select Disk to Partition.
13. Press `enter` on Select `Separate /home, /var, and /tmp paritions` 
14. Select `Yes` and press `Enter` to write the changes to disks and configure LVM.
15. Press `Enter` to `cancel` Erasing data.
16. Create a `Encryption` passphrase
17. Retype the `Encryption` passphrase that just created.
18. Type in `max`and press enter on `Continue` to assign the amount of volume group for partitioning.
19. Press enter on `Finish partitioning and write changes to disk`. 
20. Press enter on `Yes` for Partition Disks.
21. Press enter on `No` for Configure the package manager.
22. Press `enter` in the country that your in.
23. Press `enter` on deb.debian.org.
24. Leave this blank and press `enter` on continue.
25. Press `enter` on `no` for Configuring popularity-contest.
26. Deselect `SSH server` and `standard system utilities` by pressing the `Space key` and  press `enter`
27. Press `enter` on `Yes` to Install the GRUB boot loader on a hard disk.
28. Press `enter` on /dev/sda
29. Press `enter` on `continue` to finish the installation.
##
##
# Starting The Virtual Machine
1. Press enter on `Debian GNU/Linux` 
2. Enter your `encryption password` that created before
3. Login in as the `your_username` you that created before
4. Type `lsblk` to see the partitions
##
##
# Configurating The Virtual Machine
1. Type `$ su -` to Login in as the root user.
2. Type `apt-get update -y` to update the system
3. Type `apt-get upgrade -y` to upgrade the system
4. Type `apt install sudo` to install sudo
5. Type `a$ dpkg -l | grep sudo` to check sudo was successfully installed
6. Type `usermod -aG sudo your_username` to add user in the sudo group 
7. Type `getent group sudo` to check if user is in sudo group)
8. Type `$ sudo visudo` to open sudoers filed
9. Find in sudoers file
```
#User privilege specification and Add
```
10. Add below `your_username ALL=(ALL)`
```
#User privilege specification and Add
your_username ALL=(ALL)
```
##
##
## Installing Git and Vim
1. Type `$ apt-get install git -y` to install Git
2. Type `git --version` Check Git Version
##
##
## Installing and Configuring SSH (Secure Shell Host)
1. Type `$ sudo apt install openssh-server` to install openssh-server
2. Type `$ sudo systemctl status ssh` to check SSH server status
3. Type `$ sudo vim /etc/ssh/sshd_config` to open sshd_config file with VIM
4. Find line below
```
#Port22
```
5. Replace line 
```
Port22
```
6. Type `$ apt-get install git -y` to install Git
7. Save and `exit` Vim with `:q`
8. Type `sudo grep Port /etc/ssh/sshd_config` to check port settings
7. Type ` sudo service ssh restart` to restart the SSH service
##
##
## Installing and Configuring UFW (Uncomplicated Firewall)
1. Type `apt-get install ufw` to install UFW
2. Type `sudo ufw enable` to inable UFW
3. Type `sudo ufw status numbered` to check the status of UFW
4. Type `sudo ufw allow ssh` to configure the Rules
5. Type `sudo ufw allow 4242` to configure the Port Rules
6. Type `sudo ufw status numbered` to check the status of UFW
##
##
## Connecting to SSH
#### ⚠️ NOTE: To exit Virtual Machine and use the mouse, press `command` on your Apple Keyboard
1. Open Virtual Box
2. Click on the Virtual Machine and select `Settings`
3. Click `Network` then `Adapter 1` then `Advanced` and then click on `Port Forwarding`
4. Change the Host Port and Guest Port to `4242`
5. Go back to the `Virtual Machine`
6. Type `sudo systemctl restart ssh` to restart the SSH Server
7. Type `sudo service sshd status` to check the SSH Status
8. Open `iTerm` and type `ssh your_username@127.0.0.1 -p 4242`
9. Type`exit` to quit SSH with iTerm Connection
###### ⚠️ WARNING: If an error occurs type `rm ~/.ssh/known_hosts` and retype Step 8
##
##
## Setting Password Policy
1. Type `sudo apt-get install libpam-pwquality` to install Password Quality Checking Library
2. Type`sudo vim /etc/pam.d/common-password`

3. Find line below
```
password requisite pam_deny.so
```
4. Add Line `minlen=10 ucredit=-1 dcredit=-1 maxrepeat=3 reject_username difok=7 enforce_for_root`
```
password requisite pam_deny.so minlen=10 ucredit=-1 dcredit=-1 maxrepeat=3 reject_username difok=7 enforce_for_root
```
5. Save and `Exit Vim`
6. Next type in your Virtual Machine `sudo vim /etc/login.defs`
7. Find line below 
```
PASS_MAX_DAYS 9999` `PASS_MIN_DAYS 0` `PASS_WARN_AGE 7
```
8. Replace line below
```
PASS_MAX_DAYS 30` `PASS_MIN_DAYS 2` `PASS_WARN_AGE 7
```
9. Type `sudo reboot` to reboot the change affects
##
##
## Creating a Group
1. Type `sudo groupadd user42` to create a group
2. Type`sudo groupadd evaluating` to create an evaluating group
3. Type `getent group` to check if the group has been created
##
##
## Creating a User and Assigning Them Into The Group
1. Type `cut -d: -f1 /etc/passwd` to check all local users
2. Type `sudo adduser new_username` to create a username 
3. Type `sudo usermod -aG user42 your_username` to add `your_username` to `user42`
4. Type `sudo usermod -aG evaluating your_new_username` to add `new_user` to group `evaluating`
5. Type `getent group user42` to check if the user is the group
6. Type `getent group evaluating` to check the group
7. Type `groups` to see which groups the user account belongs to
8. Type `chage -l your_new_username` to check if the password rules are working
##
##
## Creating sudo.log
1. Type`cd ~/../`
4. Type `cd var/log`
5. Type `mkdir sudo` (if it already exists, then continue to the next step).
6. Type `cd sudo && touch sudo.log`
7. Type `cd ~/../`
##
##
## Configuring Sudoers Group
1. Type `sudo nano /etc/sudoers` to open the sudoers file
2. Adding in sudoers file all of the defaults
```
Defaults	env_reset
Defaults	mail_badpass
Defaults	secure_path="/usr/local/sbin:/usr/local/bin:/usr/bin:/sbin:/bin"
Defaults	badpass_message="Password is wrong, please try again!"
Defaults	passwd_tries=3
Defaults	logfile="/var/log/sudo.log"
Defaults	log_input, log_output
Defaults	requiretty
```
![1*N4Ad-9k0vfvnWKNC5q6MjQ](https://user-images.githubusercontent.com/58959408/174725518-0ebf1dac-4126-4869-9ba0-b1d05ce313c9.png)
##
##
## Crontab Configuation
1. Type `apt-get install -y net-tools` to install the netstat tools
2. Type `cd /usr/local/bin/`
3. Type `touch monitoring.sh`
4. Type `chmod 777 monitoring.sh`
##
##
## Create script monitorig.sh
#### ⚠️ NOTE: To copy the text below, hover with the mouse to the right corner of the text below and a copy icon will appear
1. Copy text below
```
#!/bin/bash
arc=$(uname -a)
pcpu=$(grep "physical id" /proc/cpuinfo | sort | uniq | wc -l) 
vcpu=$(grep "^processor" /proc/cpuinfo | wc -l)
fram=$(free -m | awk '$1 == "Mem:" {print $2}')
uram=$(free -m | awk '$1 == "Mem:" {print $3}')
pram=$(free | awk '$1 == "Mem:" {printf("%.2f"), $3/$2*100}')
fdisk=$(df -BG | grep '^/dev/' | grep -v '/boot$' | awk '{ft += $2} END {print ft}')
udisk=$(df -BM | grep '^/dev/' | grep -v '/boot$' | awk '{ut += $3} END {print ut}')
pdisk=$(df -BM | grep '^/dev/' | grep -v '/boot$' | awk '{ut += $3} {ft+= $2} END {printf("%d"), ut/ft*100}')
cpul=$(top -bn1 | grep '^%Cpu' | cut -c 9- | xargs | awk '{printf("%.1f%%"), $1 + $3}')
lb=$(who -b | awk '$1 == "system" {print $3 " " $4}')
lvmu=$(if [ $(lsblk | grep "lvm" | wc -l) -eq 0 ]; then echo no; else echo yes; fi)
ctcp=$(ss -neopt state established | wc -l)
ulog=$(users | wc -w)
ip=$(hostname -I)
mac=$(ip link show | grep "ether" | awk '{print $2}')
cmds=$(journalctl _COMM=sudo | grep COMMAND | wc -l)
wall "	#Architecture: $arc
	#CPU physical: $pcpu
	#vCPU: $vcpu
	#Memory Usage: $uram/${fram}MB ($pram%)
	#Disk Usage: $udisk/${fdisk}Gb ($pdisk%)
	#CPU load: $cpul
	#Last boot: $lb
	#LVM use: $lvmu
	#Connections TCP: $ctcp ESTABLISHED
	#User log: $ulog
	#Network: IP $ip ($mac)
	#Sudo: $cmds cmd"
```
2. Open `iTerm2` and Type `ssh your_host_name42@127.0.0.1 -p 4242` to login
3. Type `cd /usr/local/bin`.
4. Type `nano monitoring.sh` and paste the text into the vim monitoring.sh
5. Save and Exit the `monitoring.sh` script
6. Type `exit` to exit the iTerm SSH Login.
7. Type `sudo visudo` to open the sudoers file
8. Add the line below at the end of the file
```
your_username ALL=(ALL) NOPASSWD: /usr/local/bin/monitoring.sh
```
![1*l-7LtAqCon1gRkV3dY3qiQ](https://user-images.githubusercontent.com/58959408/174727595-11dbb2f9-9c34-4d11-870b-f832ea4a9224.png)

9. `Exit` and `Save` the sudoers file
10. Type`sudo reboot` to reboot sudo
11. Type `sudo /usr/local/bin/monitoring.sh` to execute  script as super user
12. Type `sudo crontab -u root -e` to open the crontab 
13. Add following rule  into crontab
```
*/10 * * * * /usr/local/bin/monitoring.sh
```
##
##
## Signature.txt
⚠️ Warning: before you generate a signature number, turn off your Virtual Machine. ⚠️

1. Open iTerm and type `cd`
1. Type `cd goinfre/students/<your_intra_username>/VirtualBox VMs`
2. Type `shasum VirtualBox.vdi` or what the Virtual Machine is called
3. Copy the output number and create a signature.txt file and paste that number in the file.
##
##
## Commands for UFW, Group, Host, lsblk and SSH
- `sudo ufw status`
- `sudo systemctl status ssh`
- `getent group sudo`
- `getent group user42`
- `sudo adduser new username`
- `sudo groupadd groupname`
- `sudo usermod -aG groupname username`
- `sudo chage -l username` - check password expire rules
- `hostnamectl`
- `hostnamectl set-hostname new_hostname` - to change the current hostname
- `sudo restart` - Restart the Virtual Machine.
- `sudo nano /etc/hosts` - change current hostname to new hostname
- `lsblk` to display the partitions
- `dpkg -l | grep sudo –` to show that sudo is installed
- `sudo ufw status numbered`
- `sudo ufw allow port-id`
- `sudo ufw delete rule number`
- `ssh your_user_id@127.0.0.1 -p 4242` -  to show that SSH to port 4242 is working
##
##
# ******BONUS******
##
## Installing Lighttpd
1. Type `sudo apt install lighttpd` to install lighttpd
2. Type `dpkg -l | grep lighttpd` to check lighttpd was successfully installed
3. Type `sudo ufw allow 80` to allow incoming connections using Port 80
##
##
## Installing & Configuring MariaDB
1. Type `sudo apt install mariadb-server` to install mariadb-server
2. Type `dpkg -l | grep mariadb-server` to check mariadb-serve was successfully installed
3. Type `sudo mysql_secure_installation` Start interactive script to remove insecure default settings
```
Enter current password for root (enter for none): #Just press Enter (do not confuse database root with system root)
Set root password? [Y/n] n
Remove anonymous users? [Y/n] Y
Disallow root login remotely? [Y/n] Y
Remove test database and access to it? [Y/n] Y
Reload privilege tables now? [Y/n] Y
```
4. Type `sudo mariadb` to log in to the MariaDB console settings
5. Type `CREATE DATABASE <database-name>;` to create new database
6. Type to Create new database user and grant them full privileges
```
GRANT ALL ON <database-name>.* TO '<username-2>'@'localhost' IDENTIFIED BY '<password-2>' WITH GRANT OPTION;
```
7. Type `FLUSH PRIVILEGES;` to flush the privileges
8. type `exit` to exit the MariaDB shell
9. Type `mariadb -u <username-2> -p`to check  database user was successfully created by logging in to the MariaDB
10. Type `SHOW DATABASES;` to confirm whether database user has access to the database via .
11. Type `exit` to Exit the MariaDB shell
```
MariaDB [(none)]> exit;
+--------------------+
| Database           |
+--------------------+
| <database-name>    |
| information_schema |
+--------------------+
```

##
##
## Installing PHP
4. Type `sudo apt install php-cgi php-mysql` to Install php-cgi & php-mysql
5. Type `dpkg -l | grep php` to check php-cgi & php-mysql as successfully installed

##
##
## Downloading & Configuring WordPress
5. Type `sudo apt install wget` to Install wget
6. Type `sudo wget http://wordpress.org/latest.tar.gz -P /var/www/html` to download WordPress
7. Type `sudo tar -xzvf /var/www/html/latest.tar.gz` to extract downloaded content
8. Type `sudo rm /var/www/html/latest.tar.gz` to remove tarball
9. Type `sudo cp -r /var/www/html/wordpress/* /var/www/html` to copy content of `/var/www/html/wordpress` to `/var/www/html`
10. Type `/var/www/html/wordpress` to remove `/var/www/html/wordpress`
11. Type `sudo cp /var/www/html/wp-config-sample.php /var/www/html/wp-config.php` to create WordPress configuration file
12. Type `sudo vi /var/www/html/wp-config.php` to configure WordPress to reference previously-created MariaDB 
13. Replace the below lines
```
23 define( 'DB_NAME', 'database_name_here' );^M
26 define( 'DB_USER', 'username_here' );^M
29 define( 'DB_PASSWORD', 'password_here' );^M
```
with:
```
23 define( 'DB_NAME', '<database-name>' );^M
26 define( 'DB_USER', '<username-2>' );^M
29 define( 'DB_PASSWORD', '<password-2>' );^M
```
##
##
## Configuring Lighttpd
Type and enable below modules
```
$ sudo lighty-enable-mod fastcgi
$ sudo lighty-enable-mod fastcgi-php
$ sudo service lighttpd force-reload
```
##
##
## File Transfer Protocol *(FTP)*

1. Type `sudo apt install vsftpd` to install FTP
2. Type `sdpkg -l | grep vsftpd` to check vsftpd was successfully installed
3. Type `sudo ufw allow 21` to allow incoming connections using Port 21
4. Type `sudo apt install vsftpd` to install FTP
5. Type `sudo vi /etc/vsftpd.conf` to Configure ftp conf file
6. To enable any form of FTP write command, uncomment below line:
```
31 #write_enable=YES
```
#### To set root folder for FTP-connected user to `/home/<username>/ftp`, add below lines:
```
$ sudo mkdir /home/<username>/ftp
$ sudo mkdir /home/<username>/ftp/files
$ sudo chown nobody:nogroup /home/<username>/ftp
$ sudo chmod a-w /home/<username>/ftp
<~~~>
user_sub_token=$USER
local_root=/home/$USER/ftp
<~~~>
```

#### To prevent user from accessing files or using commands outside the directory tree, uncomment below line:
```
114 #chroot_local_user=YES
```
#### To whitelist FTP, add below lines:
```
$ sudo vi /etc/vsftpd.userlist
$ echo <username> | sudo tee -a /etc/vsftpd.userlist
<~~~>
userlist_enable=YES
userlist_file=/etc/vsftpd.userlist
userlist_deny=NO
<~~~>
```
##
##
## Connecting to Server via FTP
1. Type `ftp <ip-address>` to accsess FTP 
2. Press `CTRL + D` to terminate FTP session at any time
##
##