#include <libopencm3/usb/usbd.h>

#ifndef USB_H
#define USB_H

#include <stdio.h>

usbd_device *usb_setup(void);


#endif /* USB_H */