#ifndef __SOPIPE_H__
#define __SOPIPE_H__

int sopipe_open(struct inode * inode, struct file * filp);
int sopipe_release(struct inode * inode, struct file * filp);
ssize_t sopipe_read(struct file * filp, char __user *buff, size_t count, loff_t * offp);
ssize_t sopipe_write(struct file * filp, const char __user *buff, size_t count, loff_t * offp);
static int __sopipe_read(unsigned char * c);
static int __sopipe_write(unsigned char c);

struct file_operations sopipe_fops = {
  .owner =  THIS_MODULE,
  .read =    sopipe_read,
  .write =   sopipe_write,
  .open =    sopipe_open,
  .release = sopipe_release,
};

#endif
