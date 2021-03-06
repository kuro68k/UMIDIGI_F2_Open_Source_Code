#ifndef __CUST_BARO_H__
#define __CUST_BARO_H__

#define B_CUST_I2C_ADDR_NUM 2

struct baro_hw {
    const char *name;
    int i2c_num;    /*!< the i2c bus used by the chip */
    int direction;  /*!< the direction of the chip */
    unsigned char   i2c_addr[B_CUST_I2C_ADDR_NUM];
};
struct baro_hw* get_cust_baro(const char *name);
#endif

