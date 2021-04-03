FROM docker.io/robocuplogistics/rcll-refbox:rc2021-evaluation
RUN dnf -y install net-tools nano

# Start script for the refbox loads config for refbox
COPY start.sh /start.sh
COPY refbox_config.yaml /etc/rcll-refbox/outerconfig.yaml

CMD ["/start.sh"]

