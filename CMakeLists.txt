cmake_minimum_required(VERSION 3.8)
project(mindoom)

set(CMAKE_C_STANDARD 11)

INCLUDE(FindPkgConfig)

PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
PKG_SEARCH_MODULE(SDL2_MIXER REQUIRED SDL2_mixer>=2.0.0)
PKG_SEARCH_MODULE(SDL2_NET REQUIRED SDL2_net>=2.0.0)
PKG_SEARCH_MODULE(LIBPNG REQUIRED libpng)

include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_MIXER_INCLUDE_DIRS} ${SDL2_NET_INCLUDE_DIRS} ${LIBPNG_INCLUDE_DIRS} src src/doom)


set(COMMON_SOURCE_FILES src/i_system.c src/d_mode.c src/i_main.c src/i_timer.c src/m_argv.c src/m_misc.c src/net_common.c src/net_dedicated.c src/net_io.c src/net_packet.c src/net_query.c src/net_sdl.c src/net_server.c src/net_structrw.c)

set(GAME_FILES src/aes_prng.c src/d_event.c src/d_iwad.c src/d_loop.c src/d_mode.c src/gusconf.c src/i_cdmus.c src/i_input.c src/i_joystick.c src/i_sdlmusic.c src/i_sdlsound.c src/i_sound.c src/i_timer.c src/i_video.c src/i_videohr.c src/midifile.c src/mus2mid.c src/m_bbox.c src/m_cheat.c src/m_config.c src/m_controls.c src/m_fixed.c src/net_client.c src/sha1.c src/memio.c src/tables.c src/v_video.c src/w_checksum.c src/w_main.c src/w_wad.c src/w_file.c src/w_file_stdc.c src/w_file_posix.c src/w_merge.c src/z_zone.c src/net_loop.c)

set(DOOM_SOURCE src/doom/am_map.c src/doom/d_items.c src/doom/d_main.c src/doom/d_net.c src/doom/doomdef.c src/doom/doomstat.c src/doom/dstrings.c src/doom/f_wipe.c src/doom/g_game.c src/doom/hu_lib.c src/doom/hu_stuff.c src/doom/info.c src/doom/m_menu.c src/doom/m_random.c src/doom/p_ceilng.c src/doom/p_doors.c src/doom/p_enemy.c src/doom/p_floor.c src/doom/p_inter.c src/doom/p_lights.c src/doom/p_map.c src/doom/p_maputl.c src/doom/p_mobj.c src/doom/p_plats.c src/doom/p_pspr.c src/doom/p_saveg.c src/doom/p_setup.c src/doom/p_sight.c src/doom/p_spec.c src/doom/p_switch.c src/doom/p_telept.c src/doom/p_tick.c src/doom/p_user.c src/doom/r_bsp.c src/doom/r_data.c src/doom/r_draw.c src/doom/r_main.c src/doom/r_plane.c src/doom/r_segs.c src/doom/r_sky.c src/doom/r_things.c src/doom/s_sound.c src/doom/sounds.c src/doom/st_lib.c src/doom/st_stuff.c src/doom/statdump.c src/doom/wi_stuff.c)

add_library(doom STATIC ${COMMON_SOURCE_FILES} ${DOOM_SOURCE})

add_executable(mindoom ${COMMON_SOURCE_FILES} ${GAME_FILES})

target_compile_options(mindoom PUBLIC -Wall -Werror)
target_compile_options(doom PUBLIC -Wall -Werror)

target_link_libraries(doom ${SDL2_LIBRARIES} ${SDL2_NET_LIBRARIES} ${SDL2_MIXER_LIBRARIES} ${LIBPNG_LIBRARIES})
target_link_libraries(mindoom doom ${SDL2_LIBRARIES} ${SDL2_NET_LIBRARIES} ${SDL2_MIXER_LIBRARIES} ${LIBPNG_LIBRARIES})

