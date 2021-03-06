@echo off
rmdir /q /s single_dir_for_windows_kernel                                                                                                                    1>nul 2>nul
mkdir single_dir_for_windows_kernel                                                                                                                          1>nul 2>nul

copy /y ..\..\src\lfds720_btree_addonly_unbalanced\*                                                           single_dir_for_windows_kernel\                1>nul 2>nul
copy /y ..\..\src\lfds720_freelist\*                                                                           single_dir_for_windows_kernel\                1>nul 2>nul
copy /y ..\..\src\lfds720_freelist_safe_memory_reclamation_generational\*                                      single_dir_for_windows_kernel\                1>nul 2>nul
copy /y ..\..\src\lfds720_freelist_safe_memory_reclamation_hazard_pointers\*                                   single_dir_for_windows_kernel\                1>nul 2>nul
copy /y ..\..\src\lfds720_hash_addonly\*                                                                       single_dir_for_windows_kernel\                1>nul 2>nul
copy /y ..\..\src\lfds720_list_addonly_singlylinked_ordered\*                                                  single_dir_for_windows_kernel\                1>nul 2>nul
copy /y ..\..\src\lfds720_list_addonly_singlylinked_unordered\*                                                single_dir_for_windows_kernel\                1>nul 2>nul
copy /y ..\..\src\lfds720_misc\*                                                                               single_dir_for_windows_kernel\                1>nul 2>nul
copy /y ..\..\src\lfds720_pseudo_random_number_generator\*                                                     single_dir_for_windows_kernel\                1>nul 2>nul
copy /y ..\..\src\lfds720_queue_bounded_manyproducer_manyconsumer\*                                            single_dir_for_windows_kernel\                1>nul 2>nul
copy /y ..\..\src\lfds720_queue_bounded_singleproducer_singleconsumer\*                                        single_dir_for_windows_kernel\                1>nul 2>nul
copy /y ..\..\src\lfds720_queue_unbounded_manyproducer_manyconsumer\*                                          single_dir_for_windows_kernel\                1>nul 2>nul
copy /y ..\..\src\lfds720_queue_unbounded_manyproducer_manyconsumer_safe_memory_reclamation_hazard_pointers\*  single_dir_for_windows_kernel\                1>nul 2>nul
copy /y ..\..\src\llfds720_queue_unbounded_singleproducer_singleconsumer\*                                     single_dir_for_windows_kernel\                1>nul 2>nul
copy /y ..\..\src\lfds720_ringbuffer\*                                                                         single_dir_for_windows_kernel\                1>nul 2>nul
copy /y ..\..\src\lfds720_safe_memory_reclamation_generational\*                                               single_dir_for_windows_kernel\                1>nul 2>nul
copy /y ..\..\src\lfds720_safe_memory_reclamation_hazard_pointers\*                                            single_dir_for_windows_kernel\                1>nul 2>nul
copy /y ..\..\src\lfds720_stack\*                                                                              single_dir_for_windows_kernel\                1>nul 2>nul
copy /y ..\..\src\lfds720_stack_safe_memory_reclamation_generational\*                                         single_dir_for_windows_kernel\                1>nul 2>nul
copy /y ..\..\src\singlethreaded_data_structures_for_liblfds_internal_use/libstds/src/stds_freelist\*          single_dir_for_windows_kernel\                1>nul 2>nul
copy /y ..\..\src\singlethreaded_data_structures_for_liblfds_internal_use/libstds/src/stds_list_du\*           single_dir_for_windows_kernel\                1>nul 2>nul

copy /y ..\..\src\liblfds720_internal.h                                                                        single_dir_for_windows_kernel\                1>nul 2>nul
copy /y sources.static                                                                                         single_dir_for_windows_kernel\sources         1>nul 2>nul

echo Windows kernel static library build directory structure created.
echo (Note the effects of this batch file are idempotent).

