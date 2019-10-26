tmp=$(ifconfig eth0 | grep "broadcast")
ip=${tmp:(-14)}
cd /etc/rcll-refbox/
sed "s/BROADCAST/$ip/g" outerconfig.yaml > config.yaml
set -e
source /root/.bashrc
/usr/local/bin/llsf-refbox &
sleep 1 
/usr/local/bin/rcll-refbox-instruct -m Carologistics -c GRIPS
sleep infinity
