echo "Starting new refbox version from 16.12.2020!"
tmp=$(ifconfig eth0 | grep "broadcast")
read tmp6 tmp5 tmp4 tmp3 tmp2 ip <<<$(IFS=" "  echo $tmp)
cd /etc/rcll-refbox/
sed "s/BROADCAST/$ip/g" outerconfig.yaml > config.yaml
set -e
source /root/.bashrc
/usr/local/bin/llsf-refbox &
sleep 1 
/usr/local/bin/rcll-refbox-instruct -m Carologistics -c GRIPS
sleep infinity
