#define Serial_modbus Serial1
void Modbus_read(uint8_t *buf, uint16_t len);
void recv_cb(rui_lora_p2p_recv_t data);
void send_cb(void);
bool init_lora(double freq);
bool lora_send(int size_msg, uint8_t *msg);