git clone --recurse-submodules git@github.com:4e4o/shinobi_hikvision_alarm_client.git  
mkdir shinobi_hik_alarm_build && cd shinobi_hik_alarm_build  
cmake -DCMAKE_BUILD_TYPE=Release ../shinobi_hikvision_alarm_client .  
cmake --build .  
sudo cmake --install .  

sudo systemctl daemon-reload  
sudo systemctl enable shinobi_hikvision_alarm_client.service  
sudo systemctl start shinobi_hikvision_alarm_client.service  
