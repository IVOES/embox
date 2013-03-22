/**
 * @file
 * @brief
 *
 * @date 05.02.13
 * @author Ilia Vaprol
 */

#include <errno.h>
#include <stddef.h>

#include <drivers/iodev.h>


static const struct iodev_ops *curr_iodev;

int iodev_init(void) {
	return curr_iodev->init();
}

struct iodev_ops const*iodev_current(void) {
	return curr_iodev;
}

char iodev_getc(void) {
	return curr_iodev->getc();
}

void iodev_putc(char ch) {
	curr_iodev->putc(ch);
}

int iodev_kbhit(void) {
	return curr_iodev->kbhit();
}

void iodev_setup(const struct iodev_ops *new_iodev) {
	curr_iodev = new_iodev;
}
#if 0
int iodev_setup_diag(void) {
	iodev_setup(iodev_diag_ops);
	return 0;
}

int iodev_setup_video(void) {
	if (iodev_video_ops == NULL) {
		return -ENOSYS;
	}

	iodev_setup(iodev_video_ops);
	return 0;
}
#endif
