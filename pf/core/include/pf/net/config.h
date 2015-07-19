/**
 * PAP Engine ( https://github.com/viticm/pap )
 * $Id config.h
 * @link https://github.com/viticm/pap for the canonical source repository
 * @copyright Copyright (c) 2013-2013 viticm( viticm@126.com )
 * @license
 * @user viticm<viticm@126.com>
 * @date 2013-12-31 17:34:43
 * @uses server and client net model base config file
 */
#ifndef PF_NET_CONFIG_H_
#define PF_NET_CONFIG_H_

#include "pf/base/config.h"

#define NET_OVER_SERVER_MAX 256
#define NET_ONESTEP_ACCEPT_DEFAULT 50 //ÿ֡���������ӵ�Ĭ��ֵ
#define NET_MANAGER_FRAME 100 //����֡��
#define NET_MANAGER_CACHE_SIZE 1024 //���������Ĭ�ϻ����С
#define NET_PACKET_FACTORYMANAGER_ALLOCMAX (1024 * 100)

extern bool g_net_stream_usepacket; //true ʹ�ð������� false��ʹ��

namespace pf_net {


namespace packet {

class Base;
class Dynamic;
class Factory;
class FactoryManager;

typedef PF_API struct queue_struct queue_t;
struct queue_struct {
  Base *packet;
  uint16_t connectionid;
  uint32_t flag;
  queue_struct();
  ~queue_struct();
}; //���������


}; //namespace packet

namespace connection {
class Base;
class Server;
class Pool;

namespace manager {

class Base;
#if __LINUX__ && defined(_PF_NET_EPOLL) /* { */
class Epoll;
#elif __WINDOWS__ && defined(_PF_NET_IOCP) /* }{ */
class Iocp;
#else /* }{ */
class Select;
#endif /* } */

typedef PF_API struct cache_struct cache_t;
struct cache_struct {
  packet::queue_t *queue;
  uint32_t head;
  uint32_t tail;
  uint32_t size;
  cache_struct();
  ~cache_struct();
}; //����������ṹ

}; //namespace manager

}; //namespace connection

namespace socket {

class Base;
class Server;
class Stream;
class InputStream;
class OutputStream;
class Encryptor;
class Compressor;

typedef struct streamdata_struct {
  char *buffer;
  uint32_t bufferlength;
  uint32_t bufferlength_max;
  uint32_t head;
  uint32_t tail;
  streamdata_struct() {
    buffer = NULL;
    bufferlength = 0;
    bufferlength_max = 0;
    head = 0;
    tail = 0;
  }
} streamdata_t;

}; //namespace socket

}; //namespace pf_net

#endif //PF_NET_CONFIG_H_
