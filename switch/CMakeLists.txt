cmake_minimum_required(VERSION 3.12)

project(postal)

# export a JSON compilation database for clangd
set (CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

# platform detection
set (PLATFORM_DETECTION PLATFORM_SWITCH)

# force C++ version
set (CMAKE_CXX_STANDARD 11)

# external dependencies
find_package(SDL2 REQUIRED)
if (TARGET SDL2::SDL2)
		set(SDL2_LIBRARIES SDL2::SDL2)
endif()

# main executable
set (TARGET_POSTAL postal)
add_executable(${TARGET_POSTAL})
target_sources(${TARGET_POSTAL} PRIVATE
	../src/Anim3D.cpp
	../src/AnimThing.cpp
	../src/BufQ.cpp
	../src/GameSettings.cpp
	../src/IdBank.cpp
	../src/InputSettings.cpp
	../src/InputSettingsDlg.cpp
	../src/MemFileFest.cpp
	../src/MenuSettings.cpp
	../src/MenuTrans.cpp
	../src/Personatorium.cpp
	../src/PowerUp.cpp
	../src/SampleMaster.cpp
	../src/SndRelay.cpp
	../src/SoundThing.cpp
	../src/StockPile.cpp
	../src/TexEdit.cpp
	../src/Thing3d.cpp
	../src/TriggerRegions.cpp
	../src/aivars.cpp
	../src/alphablitforpostal.cpp
	../src/ball.cpp
	../src/band.cpp
	../src/barrel.cpp
	../src/bouy.cpp
	../src/bulletFest.cpp
	../src/camera.cpp
	../src/character.cpp
	../src/chunk.cpp
	../src/crawler.cpp
	../src/credits.cpp
	../src/cutscene.cpp
	../src/deathWad.cpp
	../src/demon.cpp
	../src/dispenser.cpp
	../src/doofus.cpp
	../src/dude.cpp
	../src/encrypt.cpp
	../src/explode.cpp
	../src/fire.cpp
	../src/fireball.cpp
	../src/firebomb.cpp
	../src/flag.cpp
	../src/flagbase.cpp
	../src/game.cpp
	../src/gameedit.cpp
	../src/grenade.cpp
	../src/grip.cpp
	../src/heatseeker.cpp
	../src/hood.cpp
	../src/input.cpp
	../src/item3d.cpp
	../src/keys.cpp
	../src/localize.cpp
	../src/logtab.cpp
	../src/main.cpp
	../src/menus.cpp
	../src/mine.cpp
	../src/napalm.cpp
	../src/navnet.cpp
	../src/net.cpp
	../src/organ.cpp
	../src/ostrich.cpp
	../src/person.cpp
	../src/play.cpp
	../src/pylon.cpp
	../src/realm.cpp
	../src/rocket.cpp
	../src/scene.cpp
	../src/score.cpp
	../src/sentry.cpp
	../src/settings.cpp
	../src/smash.cpp
	../src/thing.cpp
	../src/title.cpp
	../src/toolbar.cpp
	../src/trigger.cpp
	../src/update.cpp
	../src/warp.cpp
	../src/weapon.cpp
	../src/yatime.cpp
	../src/RSPiX/Src/BLUE/unix/Bdebug.cpp
	../src/RSPiX/Src/BLUE/unix/Bjoy.cpp
	../src/RSPiX/Src/BLUE/unix/Bkey.cpp
	../src/RSPiX/Src/BLUE/unix/Bmain.cpp
	../src/RSPiX/Src/BLUE/unix/Bmouse.cpp
	../src/RSPiX/Src/BLUE/unix/Btime.cpp
	../src/RSPiX/Src/BLUE/unix/Bdisp.cpp
	../src/RSPiX/Src/BLUE/unix/Bsound.cpp
	../src/RSPiX/Src/GREEN/Hot/hot.cpp
	../src/RSPiX/Src/GREEN/Image/Image.cpp
	../src/RSPiX/Src/GREEN/Image/Imagecon.cpp
	../src/RSPiX/Src/GREEN/Image/ImageFile.cpp
	../src/RSPiX/Src/GREEN/InputEvent/InputEvent.cpp
	../src/RSPiX/Src/GREEN/Mix/mix.cpp
	../src/RSPiX/Src/GREEN/Mix/MixBuf.cpp
	../src/RSPiX/Src/GREEN/Image/pal.cpp
	../src/RSPiX/Src/GREEN/Image/PalFile.cpp
	../src/RSPiX/Src/GREEN/Sample/sample.cpp
	../src/RSPiX/Src/GREEN/Snd/snd.cpp
	../src/RSPiX/Src/GREEN/SndFx/SndFx.cpp
	../src/RSPiX/Src/GREEN/Task/task.cpp
	../src/RSPiX/Src/GREEN/3D/pipeline.cpp
	../src/RSPiX/Src/GREEN/3D/render.cpp
	../src/RSPiX/Src/GREEN/3D/types3d.cpp
	../src/RSPiX/Src/GREEN/3D/zbuffer.cpp
	../src/RSPiX/Src/GREEN/BLiT/alphablit.cpp
	../src/RSPiX/Src/GREEN/BLiT/BLIT.cpp
	../src/RSPiX/Src/GREEN/BLiT/BLITINIT.cpp
	../src/RSPiX/Src/GREEN/BLiT/BLiTT.cpp
	../src/RSPiX/Src/GREEN/BLiT/CFNT.cpp
	../src/RSPiX/Src/GREEN/BLiT/Fspr1.cpp
	../src/RSPiX/Src/GREEN/BLiT/FSPR8.cpp
	../src/RSPiX/Src/GREEN/BLiT/line.cpp
	../src/RSPiX/Src/GREEN/BLiT/mono.cpp
	../src/RSPiX/Src/GREEN/BLiT/Rotate96.cpp
	../src/RSPiX/Src/GREEN/BLiT/RPrint.cpp
	../src/RSPiX/Src/GREEN/BLiT/ScaleFlat.cpp
	../src/RSPiX/Src/ORANGE/GameLib/ANIMSPRT.cpp
	../src/RSPiX/Src/ORANGE/Attribute/attribute.cpp
	../src/RSPiX/Src/ORANGE/GUI/btn.cpp
	../src/RSPiX/Src/ORANGE/Channel/channel.cpp
	../src/RSPiX/Src/ORANGE/color/colormatch.cpp
	../src/RSPiX/Src/ORANGE/DirtRect/DirtRect.cpp
	../src/RSPiX/Src/ORANGE/color/dithermatch.cpp
	../src/RSPiX/Src/ORANGE/GUI/dlg.cpp
	../src/RSPiX/Src/ORANGE/GUI/edit.cpp
	../src/RSPiX/Src/ORANGE/File/file.cpp
	../src/RSPiX/Src/ORANGE/QuickMath/FixedPoint.cpp
	../src/RSPiX/Src/ORANGE/GUI/guiItem.cpp
	../src/RSPiX/Src/ORANGE/IFF/iff.cpp
	../src/RSPiX/Src/ORANGE/ImageTools/lasso.cpp
	../src/RSPiX/Src/ORANGE/Laymage/laymage.cpp
	../src/RSPiX/Src/ORANGE/GUI/ListBox.cpp
	../src/RSPiX/Src/ORANGE/GUI/ListContents.cpp
	../src/RSPiX/Src/ORANGE/Meter/meter.cpp
	../src/RSPiX/Src/ORANGE/MsgBox/MsgBox.cpp
	../src/RSPiX/Src/ORANGE/GUI/MultiBtn.cpp
	../src/RSPiX/Src/ORANGE/MultiGrid/MultiGrid.cpp
	../src/RSPiX/Src/ORANGE/MultiGrid/MultiGridIndirect.cpp
	../src/RSPiX/Src/ORANGE/GUI/ProcessGui.cpp
	../src/RSPiX/Src/ORANGE/Debug/profile.cpp
	../src/RSPiX/Src/ORANGE/GUI/PushBtn.cpp
	../src/RSPiX/Src/ORANGE/QuickMath/QuickMath.cpp
	../src/RSPiX/Src/ORANGE/QuickMath/Fractions.cpp
	../src/RSPiX/Src/ORANGE/GameLib/Region.cpp
	../src/RSPiX/Src/ORANGE/RString/rstring.cpp
	../src/RSPiX/Src/ORANGE/GUI/scrollbar.cpp
	../src/RSPiX/Src/ORANGE/GameLib/SHAPES.cpp
	../src/RSPiX/Src/ORANGE/Parse/SimpleBatch.cpp
	../src/RSPiX/Src/ORANGE/GameLib/SPRITE.cpp
	../src/RSPiX/Src/ORANGE/str/str.cpp
	../src/RSPiX/Src/ORANGE/GUI/txt.cpp
	../src/RSPiX/Src/CYAN/Unix/uDialog.cpp
	../src/RSPiX/Src/CYAN/Unix/uColors.cpp
	../src/RSPiX/Src/CYAN/Unix/uPath.cpp
	../src/WishPiX/Menu/menu.cpp
	../src/WishPiX/Prefs/prefline.cpp
	../src/WishPiX/Prefs/prefs.cpp
	../src/WishPiX/ResourceManager/resmgr.cpp
	../src/WishPiX/Spry/spry.cpp

	../src/HardwareSettings.cpp
	../src/HardwareSettings.h
)

# remove multiplayer specific sources
#target_sources(${TARGET_POSTAL} PRIVATE
#	../src/Log.cpp
#	../src/NetBrowse.cpp
#	../src/NetClient.cpp
#	../src/NetDlg.cpp
#	../src/NetServer.cpp
#	../src/ProtoBSDIP.cpp
#	../src/netmsgr.cpp
#	../src/socket.cpp
#)

target_compile_options(${TARGET_POSTAL} PRIVATE -fsigned-char)
target_compile_options(${TARGET_POSTAL} PRIVATE -Wall -Werror -Wno-overloaded-virtual -Wno-deprecated-declarations)

target_compile_definitions(${TARGET_POSTAL} PRIVATE ${PLATFORM_DETECTION})
target_compile_definitions(${TARGET_POSTAL} PRIVATE LOCALE=US)
target_compile_definitions(${TARGET_POSTAL} PRIVATE TARGET=POSTAL_2015)
target_compile_definitions(${TARGET_POSTAL} PRIVATE ALLOW_TWINSTICK)
target_compile_definitions(${TARGET_POSTAL} PRIVATE "$<$<CONFIG:DEBUG>:_DEBUG>")
target_compile_definitions(${TARGET_POSTAL} PRIVATE EDITOR_DISABLED)
target_compile_definitions(${TARGET_POSTAL} PRIVATE MULTIPLAYER_DISABLED MULTIPLAYER_REMOVED)
target_compile_definitions(${TARGET_POSTAL} PRIVATE TRACENASSERT)

target_include_directories(${TARGET_POSTAL} PRIVATE
	../src
	../src/RSPiX
	../src/RSPiX/Inc
	../src/RSPiX/Src
	../src/RSPiX/Src/BLUE
	../src/RSPiX/Src/BLUE/unix
	../src/RSPiX/Src/CYAN
	../src/RSPiX/Src/CYAN/Unix
	../src/RSPiX/Src/ORANGE
	../src/RSPiX/Src/ORANGE/CDT
	../src/RSPiX/Src/ORANGE/GameLib
	../src/RSPiX/Src/ORANGE/File
	../src/RSPiX/Src/ORANGE/Multigrid
	../src/RSPiX/Src/GREEN/Image
	../src/WishPiX
	../src/WishPiX/Spry
	${SDL2_INCLUDE_DIRS}
)

target_link_libraries(${TARGET_POSTAL} PRIVATE ${SDL2_LIBRARIES})

set (NACP_OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/${TARGET_POSTAL}.nacp")
nx_generate_nacp(OUTPUT ${NACP_OUTPUT})
nx_create_nro("PostalSwitch" TARGET ${TARGET_POSTAL} NACP ${NACP_OUTPUT} ROMFS romfs)
