/***** enums *****/
enum lfds720_queue_numm_query
{
  LFDS720_QUEUE_NUMM_QUERY_SINGLETHREADED_GET_COUNT,
  LFDS720_QUEUE_NUMM_QUERY_SINGLETHREADED_VALIDATE
};

/***** structures *****/
struct lfds720_queue_numm_element
{
  struct lfds720_queue_numm_element LFDS720_PAL_ALIGN(LFDS720_PAL_DOUBLE_POINTER_LENGTH_IN_BYTES)
    *volatile next[LFDS720_MISC_PAC_SIZE];

  void
    *key,
    *value,
    *user_state;
};

struct lfds720_queue_numm_state
{
  struct lfds720_queue_numm_element LFDS720_PAL_ALIGN(LFDS720_PAL_ATOMIC_ISOLATION_LENGTH_IN_BYTES)
    *volatile enqueue[LFDS720_MISC_PAC_SIZE],
    *volatile dequeue[LFDS720_MISC_PAC_SIZE];

  lfds720_pal_uint_t volatile LFDS720_PAL_ALIGN(LFDS720_PAL_ATOMIC_ISOLATION_LENGTH_IN_BYTES)
    aba_counter;

  void LFDS720_PAL_ALIGN(LFDS720_PAL_ATOMIC_ISOLATION_LENGTH_IN_BYTES)
    *user_state;

  struct lfds720_misc_backoff_state
    dequeue_backoff,
    enqueue_backoff;
};

/***** public macros and prototypes *****/
void lfds720_queue_numm_init_valid_on_current_logical_core( struct lfds720_queue_numm_state *qumms,
                                                            struct lfds720_queue_numm_element *qumme_dummy,
                                                            void *user_state );
  // TRD : used in conjunction with the #define LFDS720_MISC_MAKE_VALID_ON_CURRENT_LOGICAL_CORE_INITS_COMPLETED_BEFORE_NOW_ON_ANY_OTHER_LOGICAL_CORE

void lfds720_queue_numm_cleanup( struct lfds720_queue_numm_state *qumms,
                                void (*element_cleanup_callback)(struct lfds720_queue_numm_state *qumms, struct lfds720_queue_numm_element *qumme, enum lfds720_misc_flag dummy_element_flag) );

#define LFDS720_QUEUE_NUMM_GET_KEY_FROM_ELEMENT( queue_numm_element )             ( (queue_numm_element).key )
#define LFDS720_QUEUE_NUMM_SET_KEY_IN_ELEMENT( queue_numm_element, new_key )      ( (queue_numm_element).key = (void *) (lfds720_pal_uint_t) (new_key) )
#define LFDS720_QUEUE_NUMM_GET_VALUE_FROM_ELEMENT( queue_numm_element )           ( (queue_numm_element).value )
#define LFDS720_QUEUE_NUMM_SET_VALUE_IN_ELEMENT( queue_numm_element, new_value )  ( (queue_numm_element).value = (void *) (lfds720_pal_uint_t) (new_value) )
#define LFDS720_QUEUE_NUMM_GET_USER_STATE_FROM_STATE( queue_numm_state )          ( (queue_numm_state).user_state )

#define LFDS720_QUEUE_NUMM_GET_USER_STATE_FROM_ELEMENT( queue_numm_element )                ( (queue_numm_element).user_state )
#define LFDS720_QUEUE_NUMM_SET_USER_STATE_IN_ELEMENT( queue_numm_element, new_user_state )  ( (queue_numm_element).user_state = (new_user_state) )

void lfds720_queue_numm_enqueue( struct lfds720_queue_numm_state *qumms,
                                struct lfds720_queue_numm_element *qumme );

int lfds720_queue_numm_dequeue( struct lfds720_queue_numm_state *qumms,
                               struct lfds720_queue_numm_element **qumme );

void lfds720_queue_numm_query( struct lfds720_queue_numm_state *qumms,
                              enum lfds720_queue_numm_query query_type,
                              void *query_input,
                              void *query_output );

