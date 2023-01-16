## Born2BeRoot

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

## Mandotary
- Downloading Virtual Machine
- Installing Virtual Machine
- Starting Virtual Machine
- Configurating Virtual Machine
- Connecting to SSH
- Configurating Virtual Machine
- Signature.txt
- Overview Commands (UFW, Group, Host, lsblk and SSH)

## Bonus
#### Installation Lighttpd MariaDB PHP (LLMP)
- Installing Lighttpd
- Installing & Configuring MariaDB
- Installing PHP
- Downloading & Configuring WordPress
- Configuring Lighttpd

#### File Transfer Protocol (FTP)
- Installing & Configuring FTP
- Connecting to Server via FTP




## Questions & Answers

### Difference between Debian and CentOS?
Debian is a lot easier to update then CentOS when a new version is released. Debian is more user-friendly and supports many libraries, filesystems and architecture. It also has more options for customisation. If you are a larger business CentOS offers more Enterprise features and excellent support for the Enterprise software. 

### What is a Virtual Machine?
Is a resource that uses software instead of a physical computer to run programs or apps. Each VM has its own operating system and functions separately, so you can have more than one VM per machine. Can be used to test applications in a safe, separate environment. Works by using software to simulate virtual hardware and run on a host machine.

### What is the difference between aptitude and APT (Advanced Packaging Tool)?
* Aptitude is a high-level package manager while APT is lower level which can be used by other higher level package managers
* Aptitude is smarter and will automatically remove unused packages or suggest installation of dependent packages
* Apt will only do explicitly what it is told to do in the command line

### What is AppArmor?
Linux security system that provides Mandatory Access Control (MAC) security. Allows the system admin to restrict the actions that processes can perform. It is included by default with Debian. Run aa-status to check if it is running.

### Password Rules
We using the password quality checking library and there are two files the common-password file which sets the rules like upper and lower case characters, duplicate characters etc and the login.defs file which stores the password expiration rules (30 days etc).
* Sudo nano /etc/login.defs
* Sudo nano /etc/pam.d/common-password

### What is LVM
Logical Volume Manager – allows us to easily manipulate the partitions or logical volume on a storage device. 

### UFW (Uncomplicated Firewall) 
UFW is a interface to modify the firewall of the device without compromising security. You use it to configure which ports to allow connections to and which ports to close. This is useful in conjunction with SSH, can set a specific port for it to work with.

### What is SSH?
SSH or Secure Shell is an authentication mechanism between a client and a host. It uses encryption techniques so that all communication between clients and hosts is done in encrypted form. User on Mac or Linux can use SSH the terminal to work on their server via SSH.

### What is Cron?
Cron or cron job is a command line utility to schedule commands or scripts to happen at specific intervals or a specific time each day. Useful if you want to set your server to restart at a specific time each day. 

- `cd /usr/local/bin` – to show monitoring.sh
- `sudo crontab -u root -e` – to edit the cron job
- `change script to */1 * * * * sleep 30s && script path` – to run it every 30 seconds, delete the line to stop the job from running.


## Downloading Virtual Machine
<img width="264" alt="Screen Shot 2022-06-24 at 12 18 12 PM" src="https://user-images.githubusercontent.com/58959408/175452234-79c7f008-10b2-4e4b-a602-95886d9e2508.png">

1. Click link <ins>**https://cdimage.debian.org/debian-cd/current/amd64/iso-cd/**

2. Download `debian-mac-xx.x.x-amd64-netinst.iso`

## Installing The Virtual Machine

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

## Accessing The Virtual Machine
#### ⚠️ NOTE: To increase the size, press `command` + `c` use the mouse to drag the screen to the size:

<img width="666" alt="178788620-61064b58-0c0c-4f48-815e-60b4a8eaecae" src="https://user-images.githubusercontent.com/58959408/181727316-9a16b307-ea00-4116-a20a-261512f63a20.png">
	
1. Use the arrow keys on your keyboard 🔼 🔽 and press `Enter` on `Install`

![1*-tV-M-4g6MH8h6pWJ27bCg](https://user-images.githubusercontent.com/58959408/174728861-fb9435a5-04e5-402c-80a3-f366c9b51be8.png)

2. Press `enter` on `English - English` or your language of preference.

3. Press `enter` on `Australia` or the country your installing this Virtual Machine.

4. Press `enter` on `American English` or your keyboard of preference.

#### ⚠️ NOTE: create & use the same password for everything.

5. Create a Host Name as your login, with 42 at the end (eg. User42) 

6. Leave Domain name blank, press `enter` on Continue.
	
![1*81XjZBZg2bbNXunuxgnFPQ](https://user-images.githubusercontent.com/58959408/174729840-a85c3319-3a70-4922-9335-e4bb6f765ee9.png)

7. Create a Password for the Host Name
	
![1*ft498oj7syh4zVjI48U_tw](https://user-images.githubusercontent.com/58959408/174729894-d0fc794f-add8-49e7-9015-521f9e93958f.png)

8. Create a User Name without 42 at the end (eg. testUser) 
	
![1*rhJWnMKN0TPBZwqRey9OeQ](https://user-images.githubusercontent.com/58959408/174729939-06933a35-5dd1-4924-848e-78d2023bb66e.png)

9. Create a Password for the User Name

10. Press `enter` on your `Timezone`

11. Press `enter` on `Guided - use entire disk and set up encrypted LVM` (Second to last option from the list).
	
![1*CsSx-ALmn8mMxvWicsNVAQ](https://user-images.githubusercontent.com/58959408/174730389-03e5dcd7-9472-4cab-bf88-fe3cc4dc0f4c.png)

12. Press `enter` on Select Disk to Partition.
	
![1*BTLz5sT6noL_SVQ7eq3u-A](https://user-images.githubusercontent.com/58959408/174730452-e267df43-2883-4760-85c4-010970fee329.png)

13. Press `enter` on Select `Separate /home, /var, and /tmp paritions` (Last option from the list).
	
![1*r5zFPA7R_9BtIqwyOpCCVw](https://user-images.githubusercontent.com/58959408/174730481-2641b9c0-c50d-4f2b-9e71-3896a0760e10.png)

14. Select `Yes` and press `Enter` to write the changes to disks and configure LVM.
	
![1*NHdo3JbApICz0Co2epPLFA](https://user-images.githubusercontent.com/58959408/174730521-780f5eb2-4955-48df-8c59-af9914674ee7.png)

15. Press `Enter` to `cancel` Erasing data.
	
![1*KHmnCUJUWhf1minIdHNS4g](https://user-images.githubusercontent.com/58959408/174730626-c132041c-3070-405f-a8d8-60d620a1d770.png)

16. Create a Encryption passphrase
	
![1*B0QL-gX7rZW5-RJyTD1uWw](https://user-images.githubusercontent.com/58959408/174730733-f306e051-4b0e-40de-93ab-56f2cdce45d5.png)

17. Retype the Encryption passphrase that just created.
	
![1*xE1owXa0ttpvcioaEwnutA](https://user-images.githubusercontent.com/58959408/174730804-796f6db1-8b59-4f8e-900c-1416f957db30.png)

18. Type in `max`and press enter on `Continue` to assign the amount of volume group to use for guided partitioning.
	
![1*SUFMu-qy3rBwIe9B0Bq3kg](https://user-images.githubusercontent.com/58959408/174730857-2de10217-3d42-41ca-8f43-fc91fddb64c6.png)

19. Press enter on `Finish partitioning and write changes to disk`. 

<img width="806" alt="Screen_Shot_2022-09-05_at_5 33 43_PM" src="https://user-images.githubusercontent.com/58959408/188408125-7c93acc1-b37f-4b9f-8189-b3cc4a83da8c.png">

20. Press enter on `Yes` for Partition Disks.
	
![1*yfXpHyGD37OGAOX7qs1Avw](https://user-images.githubusercontent.com/58959408/174730895-f70df93e-eb7e-493c-9374-edf58a47408c.png)

21. Press enter on `No` for Configure the package manager.
	
![1*Mfb1YHt4K3pZJ12TF2dXAw](https://user-images.githubusercontent.com/58959408/174730933-615891f8-d9fa-4312-ad78-d691bd648773.png)

22. Press `enter` in the country that your in.
	
![1*vqV-bN3zDMqTBAKz_u548w](https://user-images.githubusercontent.com/58959408/174731009-ca532fcf-ac41-4cde-bdae-2cf18c8bf519.png)

23. Press `enter` on deb.debian.org.
	
![1*bLnFC6MebhW1-YZlI2n9_A](https://user-images.githubusercontent.com/58959408/174731066-6bef2e53-c891-477f-8a29-7e9984a6d911.png)

24. Leave this blank and press `enter` on continue.
	
![1*e08pS8shLNmhZuFUrmuBwA](https://user-images.githubusercontent.com/58959408/174731175-bf4949d2-a832-4a1f-9282-c91195203c84.png)

25. Press `enter` on `no` for Configuring popularity-contest.
	
![1*1I6fHG3MHuovrarqj9PNnA](https://user-images.githubusercontent.com/58959408/174731301-88d7c53d-f5e2-46c3-b221-a8b40f70f81f.png)

26. Deselect `SSH server` and `standard system utilities` by pressing the `Space key` and then press `enter` on `Continue`.
	
![1*lGsuAQEwT0WBhb4kdUMp9g](https://user-images.githubusercontent.com/58959408/174731387-b4859ded-9a9f-409a-a9c9-57d1ec77cbfd.png)

27. Press `enter` on `Yes` to Install the GRUB boot loader on a hard disk.
	
![1*b2qXPye_kX8EudSvbO4yww](https://user-images.githubusercontent.com/58959408/174731448-b7b22a70-de87-4535-b8aa-3fb3294c9661.png)

28. Press `enter` on /dev/sda
	
![174731491-7215eca8-f5e0-4862-a6ef-c49077c94cbe](https://user-images.githubusercontent.com/58959408/176393352-ed5223c7-ddf1-4c1f-97af-089be23572b2.png)

29. Press `enter` on `continue` to finish the installation.
	
![1*riuXLYYgESxdq-lpkivFXQ](https://user-images.githubusercontent.com/58959408/174731601-b5949892-28b5-4b5a-94dd-9b50e6f0662b.png)


## Starting Your Virtual Machine

1. Press enter on `Debian GNU/Linux` 

2. Enter your encryption password you had created before

3. Login in as the your_username you had created before

4. Type `lsblk` in your Virtual Machine to see the partition


## Configurating Your Virtual Machine

### Installing Sudo

1. Login in as the root user.
```
$ su -
Password:
#
```
2. Update the system
```
# apt-get update -y
```
3. Upgrade the system
```
# apt-get upgrade -y
```
4. Install Sudo 
```
# apt install sudo
```
5. Verify if sudo was successfully installed
```
# dpkg -l | grep sudo.
```
6. Add user in the sudo group 
```
# usermod -aG sudo your_username
```
7. Check if user is in sudo group)
```
# getent group sudo
```
8. Open sudoers file
```
# sudo visudo
```
9. Find in sudoers file - # User privilege specification
```
# your_username ALL=(ALL)
```

### Installing Git and Vim

1. install Git
```
# apt-get install git -y
```
2. Check Git Version
```
# git --version
```

### Installing and Configuring SSH (Secure Shell Host)

1. Install openssh-server
```
# sudo apt install openssh-server
```
2. Check SSH Server Status
```
# sudo systemctl status ssh
```
3. Open sshd_config file with VIM
```
# sudo vim /etc/ssh/sshd_config
```
4. Find this line `#Port22` 

5. Change the line to `Port 4242` without the # (Hash) in front of it

6. Save and Exit Vim

7. Check if the port settings are right
```
# sudo grep Port /etc/ssh/sshd_config
```
8. Restart the SSH Service 
```
# sudo service ssh restart
```

### Installing and Configuring UFW (Uncomplicated Firewall)

1. Type `apt-get install ufw` to install UFW
2. Type `sudo ufw enable` to inable UFW
3. Type `sudo ufw status numbered` to check the status of UFW
4. Type `sudo ufw allow ssh` to configure the Rules
5. Type `sudo ufw allow 4242` to configure the Port Rules
6. Lastly Type `sudo ufw status numbered` to check the status of UFW 4242 Port


## Connecting to SSH

0. To exit your Virtual Machine and use your mouse, press `command` on your Apple Keyboard and your mouse should appear
1. Go to your Virtual Box Program
2. Click on your Virtual Machine and select `Settings`
3. Click `Network` then `Adapter 1` then `Advanced` and then click on `Port Forwarding`
![1*rCj_FeuZ5Rm2abz48qhulg](https://user-images.githubusercontent.com/58959408/174720900-39eda7e0-9be8-453c-94f1-4aa1a6b10951.png)
4. Change the Host Port and Guest Port to `4242`
![1*61-KSUCFcerO1wPqBcYISg](https://user-images.githubusercontent.com/58959408/174720987-e8de3bf9-2ffa-40ca-9d5c-4d0dea9d0b30.png)
5. Then head back to your Virtual Machine
6. Type `sudo systemctl restart ssh` to restart your SSH Server
7. Type `sudo service sshd status` to check your SSH Status
8. Open an iTerm and type the following `ssh your_username@127.0.0.1 -p 4242`
9. In case an error occurs, then type `rm ~/.ssh/known_hosts` in your iTerm and then retype `ssh your_username@127.0.0.1 -p 4242`
10. Lastly type `exit` to quit your SSH iTerm Connection 


### Setting Password Policy

1. First type `sudo apt-get install libpam-pwquality` to install Password Quality Checking Library
2. Then type `sudo vim /etc/pam.d/common-password`

3. Find this line. `password		requisite		pam_deny.so` or
<img width="828" alt="Screen Shot 2022-07-29 at 6 40 34 PM" src="https://user-images.githubusercontent.com/58959408/181726262-8f8b7027-1929-4dda-8ac5-3957d3a1bd3a.png">
4. Add this to the end of that line `minlen=10 ucredit=-1 dcredit=-1 maxrepeat=3 reject_username difok=7 enforce_for_root`

- 4.1 The line should now look like this - `password  requisite     pam_pwquality.so  retry=3 minlen=10 ucredit=-1 dcredit=-1 maxrepeat=3 reject_username difok=7 enforce_for_root`
<img width="800" alt="179329787-1b718843-9272-43e4-8d92-8d83933cc938" src="https://user-images.githubusercontent.com/58959408/181725921-c1e6c2b1-9dd3-46c5-b738-111467bdb394.png">

5. Save and Exit Vim
6. Next type in your Virtual Machine `sudo vim /etc/login.defs`
7. Find this part `PASS_MAX_DAYS 9999` `PASS_MIN_DAYS 0` `PASS_WARN_AGE 7`
8. Change that part to `PASS_MAX_DAYS 30` and `PASS_MIN_DAYS 2` keep `PASS_WARN_AGE 7` as the same
9. Lastly type `sudo reboot` to reboot the change affects

### Part 6.2 - Creating a Group

1. First type `sudo groupadd user42` to create a group
2. Then type `sudo groupadd evaluating` to create an evaluating group
3. Lastly type `getent group` to check if the group has been created

### Part 6.3 - Creating a User and Assigning Them Into The Group

1. First type `cut -d: -f1 /etc/passwd` to check all local users
2. Type `sudo adduser new_username` to create a username - write down your new_username, as you will need this later on. 
- 2.1 Type `sudo usermod -aG user42 your_username`
- 2.2 Type `sudo usermod -aG evaluating your_new_username`
3. Type `getent group user42` to check if the user is the group
4. Type `getent group evaluating` to check the group
5. Type `groups` to see which groups the user account belongs to
6. Lastly type `chage -l your_new_username` to check if the password rules are working in users

### Part 6.4 - Creating sudo.log

1. First type `cd ~/../`
4. Then type `cd var/log`
5. Then type `mkdir sudo` (if it already exists, then continue to the next step).
6. Then type `cd sudo && touch sudo.log`
7. Then type `cd ~/../`

### Part 6.4.1 - Configuring Sudoers Group

1. First type `sudo nano /etc/sudoers` to go the sudoers file
2. Now edit your sudoers file to look like the following by adding in all of the defaults in the image below - ![1*N4Ad-9k0vfvnWKNC5q6MjQ](https://user-images.githubusercontent.com/58959408/174725518-0ebf1dac-4126-4869-9ba0-b1d05ce313c9.png)

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

### Part 6.5 - Crontab Configuation

1. Then type `apt-get install -y net-tools` to install the netstat tools
2. Then type `cd /usr/local/bin/`
3. Then type `touch monitoring.sh`
4. Lastly type `chmod 777 monitoring.sh`

### Part 6.5.1 - Copy Text Below onto Virtual Machine 

1. Copy this text (To copy the text below, hover with your mouse to the right corner of the text below and a copy icon will appear). 
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
2. Then open up a iTerm2 seperate from your Virtual Machine and type in iTerm `ssh your_host_name42@127.0.0.1 -p 4242` and then type your password, when it asks for it. 
3. Then type `cd /usr/local/bin`.
4. Then type `nano monitoring.sh` and paste the text above into the vim monitoring.sh you just created, by doing `command` + `v` on your Apple keyboard.
5. Save and Exit your `monitoring.sh`
- 5.1 - Then type `exit` to exit the iTerm SSH Login.
- 5.2 - Then go back to your Virtual Machine (not iTerm) and continue on with the steps below. 
6. Then type `sudo visudo` to open your sudoers file 
7. Add in this line `your_username ALL=(ALL) NOPASSWD: /usr/local/bin/monitoring.sh` under where its written %sudo ALL=(ALL:ALL) ALL
8. It should look like this
![1*l-7LtAqCon1gRkV3dY3qiQ](https://user-images.githubusercontent.com/58959408/174727595-11dbb2f9-9c34-4d11-870b-f832ea4a9224.png)
9. Then exit and save your sudoers file
10. Now type `sudo reboot` in your Virtual Machine to reboot sudo
11. Type `sudo /usr/local/bin/monitoring.sh` to execute your script as su (super user)
12. Type `sudo crontab -u root -e` to open the crontab and add the rule
13. Lastly at the end of the crontab, type the following `*/10 * * * * /usr/local/bin/monitoring.sh` this means that every 10 mins, this script will show


## Part 7 - Signature.txt (Last Part Before Defence)

⚠️ Warning: before you generate a signature number, turn off your Virtual Machine. ⚠️

1. Open iTerm and type `cd`
1. Then type `cd sgoinfre/students/<your_intra_username>/VirtualBox VMs`
2. Type `shasum VirtualBox.vdi` or whatever your Virtual Machine is called (This can take from a few seconds to 5 mins).
3. Copy the output number and create a signature.txt file and paste that number in the file. 
3. Now you submit the signature.txt file with the output number in it. 



### Part 8 - Commands for UFW, Group, Host, lsblk and SSH

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
- Restart your Virtual Machine.
- `sudo nano /etc/hosts` - change current hostname to new hostname
- `lsblk` to display the partitions
- `dpkg -l | grep sudo –` to show that sudo is installed
- `sudo ufw status numbered`
- `sudo ufw allow port-id`
- `sudo ufw delete rule number`
- `ssh your_user_id@127.0.0.1 -p 4242` -  do this in terminal to show that SSH to port 4242 is working

## BONUS

#### Step 1: Installing Lighttpd
Install *lighttpd* via `sudo apt install lighttpd`.
```
$ sudo apt install lighttpd
```
Verify whether *lighttpd* was successfully installed via `dpkg -l | grep lighttpd`.
```
$ dpkg -l | grep lighttpd
```
Allow incoming connections using Port 80 via `sudo ufw allow 80`.
```
$ sudo ufw allow 80
```

#### Step 2: Installing & Configuring MariaDB
Install *mariadb-server* via `sudo apt install mariadb-server`.
```
$ sudo apt install mariadb-server
```
Verify whether *mariadb-server* was successfully installed via `dpkg -l | grep mariadb-server`.
```
$ dpkg -l | grep mariadb-server
```
Start interactive script to remove insecure default settings via `sudo mysql_secure_installation`.
```
$ sudo mysql_secure_installation
Enter current password for root (enter for none): #Just press Enter (do not confuse database root with system root)
Set root password? [Y/n] n
Remove anonymous users? [Y/n] Y
Disallow root login remotely? [Y/n] Y
Remove test database and access to it? [Y/n] Y
Reload privilege tables now? [Y/n] Y
```
Log in to the MariaDB console via `sudo mariadb`.
```
$ sudo mariadb
MariaDB [(none)]>
```
Create new database via `CREATE DATABASE <database-name>;`.
```
MariaDB [(none)]> CREATE DATABASE <database-name>;
```
Create new database user and grant them full privileges on the newly-created database via `GRANT ALL ON <database-name>.* TO '<username-2>'@'localhost' IDENTIFIED BY '<password-2>' WITH GRANT OPTION;`.
```
MariaDB [(none)]> GRANT ALL ON <database-name>.* TO '<username-2>'@'localhost' IDENTIFIED BY '<password-2>' WITH GRANT OPTION;
```
Flush the privileges via `FLUSH PRIVILEGES;`.
```
MariaDB [(none)]> FLUSH PRIVILEGES;
```
Exit the MariaDB shell via `exit`.
```
MariaDB [(none)]> exit
```
Verify whether database user was successfully created by logging in to the MariaDB console via `mariadb -u <username-2> -p`.
```
$ mariadb -u <username-2> -p
Enter password: <password-2>
MariaDB [(none)]>
```
Confirm whether database user has access to the database via `SHOW DATABASES;`.
```
MariaDB [(none)]> SHOW DATABASES;
+--------------------+
| Database           |
+--------------------+
| <database-name>    |
| information_schema |
+--------------------+
```
Exit the MariaDB shell via `exit`.
```
MariaDB [(none)]> exit
```

#### Step 3: Installing PHP
Install *php-cgi* & *php-mysql* via `sudo apt install php-cgi php-mysql`.
```
$ sudo apt install php-cgi php-mysql
```
Verify whether *php-cgi* & *php-mysql* was successfully installed via `dpkg -l | grep php`.
```
$ dpkg -l | grep php
```

#### Step 4: Downloading & Configuring WordPress
Install *wget* via `sudo apt install wget`.
```
$ sudo apt install wget
```
Download WordPress to `/var/www/html` via `sudo wget http://wordpress.org/latest.tar.gz -P /var/www/html`.
```
$ sudo wget http://wordpress.org/latest.tar.gz -P /var/www/html
```
Extract downloaded content via `sudo tar -xzvf /var/www/html/latest.tar.gz`.
```
$ sudo tar -xzvf /var/www/html/latest.tar.gz
```
Remove tarball via `sudo rm /var/www/html/latest.tar.gz`.
```
$ sudo rm /var/www/html/latest.tar.gz
```
Copy content of `/var/www/html/wordpress` to `/var/www/html` via `sudo cp -r /var/www/html/wordpress/* /var/www/html`.
```
$ sudo cp -r /var/www/html/wordpress/* /var/www/html
```
Remove `/var/www/html/wordpress` via `sudo rm -rf /var/www/html/wordpress`
```
$ sudo rm -rf /var/www/html/wordpress
```
Create WordPress configuration file from its sample via `sudo cp /var/www/html/wp-config-sample.php /var/www/html/wp-config.php`.
```
$ sudo cp /var/www/html/wp-config-sample.php /var/www/html/wp-config.php
```
Configure WordPress to reference previously-created MariaDB database & user via `sudo vi /var/www/html/wp-config.php`.
```
$ sudo vi /var/www/html/wp-config.php
```
Replace the below
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

#### Step 5: Configuring Lighttpd
Enable below modules via `sudo lighty-enable-mod fastcgi; sudo lighty-enable-mod fastcgi-php; sudo service lighttpd force-reload`.
```
$ sudo lighty-enable-mod fastcgi
$ sudo lighty-enable-mod fastcgi-php
$ sudo service lighttpd force-reload
```

### #3: File Transfer Protocol *(FTP)*

#### Step 1: Installing & Configuring FTP
Install FTP via `sudo apt install vsftpd`.
```
$ sudo apt install vsftpd
```
Verify whether *vsftpd* was successfully installed via `dpkg -l | grep vsftpd`.
```
$ dpkg -l | grep vsftpd
```
Allow incoming connections using Port 21 via `sudo ufw allow 21`.
```
$ sudo ufw allow 21
```
Configure *vsftpd* via `sudo vi /etc/vsftpd.conf`.
```
$ sudo vi /etc/vsftpd.conf
```
To enable any form of FTP write command, uncomment below line:
```
31 #write_enable=YES
```
To set root folder for FTP-connected user to `/home/<username>/ftp`, add below lines:
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
To prevent user from accessing files or using commands outside the directory tree, uncomment below line:
```
114 #chroot_local_user=YES
```
To whitelist FTP, add below lines:
```
$ sudo vi /etc/vsftpd.userlist
$ echo <username> | sudo tee -a /etc/vsftpd.userlist
<~~~>
userlist_enable=YES
userlist_file=/etc/vsftpd.userlist
userlist_deny=NO
<~~~>
```

#### Step 2: Connecting to Server via FTP
FTP into your virtual machine via `ftp <ip-address>`.
```
$ ftp <ip-address>
```
Terminate FTP session at any time via `CTRL + D`.