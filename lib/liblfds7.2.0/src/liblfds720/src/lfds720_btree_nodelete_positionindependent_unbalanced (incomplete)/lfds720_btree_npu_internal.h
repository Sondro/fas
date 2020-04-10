/***** the library-wide header file *****/
#include "../liblfds720_internal.h"

/***** enums *****/
enum lfds720_btree_npu_move
{
  LFDS720_BTREE_NPU_MOVE_INVALID,
  LFDS720_BTREE_NPU_MOVE_SMALLEST_FROM_RIGHT_CHILD,
  LFDS720_BTREE_NPU_MOVE_LARGEST_FROM_LEFT_CHILD,
  LFDS720_BTREE_NPU_MOVE_GET_PARENT,
  LFDS720_BTREE_NPU_MOVE_MOVE_UP_TREE
};

enum lfds720_btree_npu_delete_action
{
  LFDS720_BTREE_NPU_DELETE_SELF,
  LFDS720_BTREE_NPU_DELETE_SELF_REPLACE_WITH_LEFT_CHILD,
  LFDS720_BTREE_NPU_DELETE_SELF_REPLACE_WITH_RIGHT_CHILD,
  LFDS720_BTREE_NPU_DELETE_MOVE_LEFT
};

/***** private prototypes *****/

