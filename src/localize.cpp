////////////////////////////////////////////////////////////////////////////////
//
// Copyright 2016 RWS Inc, All Rights Reserved
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of version 2 of the GNU General Public License as published by
// the Free Software Foundation
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along
// with this program; if not, write to the Free Software Foundation, Inc.,
// 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
//
// localize.cpp
// Project: Postal
//
// This module deals with localization issues.
//
// History:
//		11/19/96 MJR	Started.
//
//		01/21/97	JMI	Added g_pszAssetsMissingError for when the condition occurs
//							that is an error when the assets are unfound by the nostril.
//
//		01/22/97	JMI	Added g_pszSaveFileQuery.
//
//		01/22/97 MJR	Added g_pszBadCDPath, g_pszBadHDPath, g_pszBadVDPath
//
//		02/03/97	JMI	Added g_pszBadNoSakDirPath[].
//
//		04/11/97	JMI	Added g_pszSaveDemoTitle and g_pszGeneralWriteError.
//
//		04/16/97 MJR	Added a few more messages and cleaned up text for others.
//
//							And then added a few more video messages, too.
//
//		04/21/97 MJR	Created generic version of "bad path" message.
//
//		05/14/97	JMI	Added g_pszPickedUpMessage_ld_s for CDude.
//
//		06/03/97	JMI	Changed g_pszAudioModeError to g_pszAudioModeGeneralError
//							and added g_pszAudioModeInUseError, 
//							g_pszAudioModeNoDeviceError, 
//							g_pszAudioModeNotSupportedError.
//
//		06/04/97	JMI	Added g_pszNotOnCDROM.
//
//		06/06/97	JMI	Changed message for g_pszPickedUpMessage_ld_s and its name
//							to g_pszPickedUpMessage_s.
//
//		06/14/97 MJR	Added/enhanced general file error messages.
//
//		07/13/97	JMI	Changed g_pszAudioModeNotSupportedError to 
//							g_pszAudioModeNotSupportedError_s and changed to ask the
//							user if they want to try the vanilla mode.
//							Also, changed the other audio errors to include the
//							sprintf format parameters in their names.
//							Also, added g_pszAudioVanillaModeNotSupportedError_s for
//							the case when the hardware does not support the vanilla 
//							mode.
//
//		07/18/97 BRH	Added strings for new dialogs for loading and saving 
//							games.
//
//		07/21/97	JMI	Added g_pszNoWeaponButHaveAmmo_s and g_pszNoWeapon_s.
//
//		07/28/97	JMI	Added g_pszDispenserNoDispenseeTypeChosen.
//
//    07/30/97	BRH	Added death messages that come up when the CDude dies.
//
//		08/05/97	JMI	Added g_pszDontHaveExecuteWeapon_s and 
//							g_pszDontHaveSuicideWeapon_s.
//							Also, made g_sLocalizeNumDeadMessages get its value based
//							on the number of elements in g_apszDeathMessages[] so we
//							don't have to worry about keeping that up to date.
//
//		08/12/97	JMI	Added g_pszGenericBrowseFor_s_Title and 
//							g_pszGenericMustBeRelativePath_s.
//
//		08/17/97	JMI	Got rid of m_szMessages and all message related functions
//							and variables from CDude since we are now using the toolbar 
//							for dude status feedback to the user.  This includes:  
//							MsgTypeInfo, m_lNextStatusUpdateTime, m_lMsgUpdateDoneTime, 
//							m_print, m_bClearedStatus, m_szMessages[], m_sDeadMsgNum, 
//							ms_amtfMessages[], ms_u8FontForeIndex, ms_u8FontBackIndex,
//							ms_u8FontShadowIndex, DrawStatus(), StatusChange(), 
//							MessageChange(), Message(), UpdateFontColors(), 
//							CPowerUp::ms_apszPowerUpTypeNames[], 
//							CPowerUp::GetDescription(), and some strings and a string
//							array in localize.*.
//
//		08/20/97	JMI	Added g_pszDontDropYourselfMORON.
//
//		08/21/97	JMI	Added g_pszDoofusCannotFindNavNet_EditMode_hu_hu and
//							g_pszDoofusCannotFindNavNet_PlayMode_hu_hu.
//
//		08/25/97	JMI	Added g_pszCannotOpenSoundFiles_s_s.
//
//		08/27/97	JMI	Upgraded g_pszCannotOpenSoundFiles_s_s message.
//
//		09/09/97 MJR	Changed g_pszBadBlueInit to include reference to DirectX.
//
//					MJR	Further changed g_pszBadBlueInit to include NT info.
//
//		09/11/97	JMI	Added g_pszPlayOneRealmOnlyMessage.
//
//		09/18/97	JMI	Added localization vars for menus.
//
//		09/18/97	JMI	Added localization vars for SampleMaster categories.
//
//		09/19/97	JMI	Columnized menu strings so it would be easier to copy
//							and paste from here into Excel and back.
//
//		09/23/97	JMI	Added localizable sections for menus for US/UK, FRENCH, &
//							GERMAN.
//
//		09/24/97 BRH	Made ini file based on LOCALE.
//
//		09/26/97	JMI	Added French & German for Menus.
//
//		09/29/97	JMI	Added g_pszNoSoundFiles.
//
//		09/30/97	JMI	g_pszCantFindAssets was missing the word 'in' in the 
//							clause "you may need to change the  '%s =' entry the file  
//							PREFS_FILE to specify where the APP_NAME files are 
//							located" between 'entry' and 'the file'.
//
//		09/30/97 BRH	Changed postalUK.ini to postalEU.ini since it applies
//							to all of the foreign versions.
//
//		10/07/97	JMI	Changed PostalEU.ini to PostalUK.INI, PostalFr.INI, and
//							PostalGr.INI.
//
//		10/07/97 BRH	Added Score localizations to the file.
//
//		10/09/97	JMI	Added g_pszVideoChangeDepthErrorUnderGDI_s and modified
//							g_pszVideoChangeDepthError to only mention the part about
//							Windows' help under Win32.
//
//		10/13/97	JMI	Added g_pszControlsMenu_UseJoystick to localizable texts.
//
//		12/04/97 BRH	Added g_pszStartSinglePlayerMenu_AddOn.
//
//		03/05/98 BRH	Added g_pszWrongCD message that tells the player that they
//							must have the original Postal CD in the drive in order to
//							play the Postal Add on Pack.
//
//		09/27/99	JMI	Added conditions for LOCALE == JAPAN.
//
//		10/07/99	JMI	Added conditions for TARGET == JAPAN_ADD_ON and 
//							TARGET == SUPER_POSTAL.
//
//		11/28/99 MJR	For JAPAN_ADD_ON changed the .ini file to "Postal.ini" so
//							that the installation process is easier, since it can then
//							just use the same .ini as the original version of Postal.
//
//		12/02/99 MJR	Changed JAPAN_ADD_ON back to using a special .ini file.
//
//		02/04/00 MJR	Added g_pszPromptForOriginalCD.
//
//		03/30/00 MJR	Moved APP_NAME and PREFS_FILE macro definitions into
//							CompileOptions.h.
//							Switched to using new START_MENU_ADDON_ITEM macro to
//							control whether there's an add-on item on the START menu.
//							Added new POSTAL_PLUS text.
//
//		04/02/00 MJR	Major changes to lots of error messages.  The idea was to
//							reduce the verbage and instead refer the user to the
//							help files for details.
//
//		04/03/00 MJR	New text for POSTAL_PLUS start menu items.
//
//		06/25/01	MJR	Added some new messages.
//
//		05/07/03 MJR	Changed error messages that said "CD-ROM drive" to say
//						"drive it was installed from".  This should help clear
//						up confusion for people that have multiple drives such
//						as DVD, CD-R, etc.
//
////////////////////////////////////////////////////////////////////////////////
#define LOCALIZE_CPP

#include "RSPiX.h"
#include "localize.h"
#include "CompileOptions.h"
#include "realm.h"

////////////////////////////////////////////////////////////////////////////////
// Macros/types/etc.
////////////////////////////////////////////////////////////////////////////////

// Determines the number of elements in the passed array at compile time.
#define NUM_ELEMENTS(a)		(sizeof(a) / sizeof(a[0]) )


// Message used in a few places
#define CD_DRIVE_CHANGE_MESSAGE		"If you added (or removed) a drive to your system after the game was installed, try putting the CD in another drive (if you have more than one) or re-install the game."

#define ADVANCED_USERS_CHANGE_PATH	"For advanced users: Instead of re-installing you can edit the '" PREFS_FILE"' file and change the '%s' entry in the [%s] section to the correct drive letter."

////////////////////////////////////////////////////////////////////////////////
// Variables/data
////////////////////////////////////////////////////////////////////////////////

const char g_pszAppName[] = APP_NAME;

const char g_pszCriticalErrorTitle[] = APP_NAME;

const char g_pszBadBlueInit[] =
	"A system incompatibility has been detected."
	"\n\n"
#ifdef WIN32
	"Updating your video and/or sound drivers may solve this problem."
	"\n\n"
#endif
	"See code R100 in " APP_NAME " Help for more information.";

const char g_pszVideoModeError[] =
	"The required display settings (%s) were reported by the system as being available, "
	"but could not be set properly."
	"\n\n"
	"An updated video driver may solve this problem.  "
	"Contact your video card vendor for more help."
	"\n\n"
	"See code R101 in " APP_NAME " Help for more information.";

const char g_pszVideoChangeDepthError[] =
	"The required display settings (%s) could not be set properly."
	"\n\n"
	"The required number of colors is different from your current settings."
	"\n\n"
	"Change your color settings before running " APP_NAME "."
	"\n\n"
	"See code R102 in " APP_NAME " Help for more information.";

const char g_pszVideoDepthError[] =
	"The required display settings (%s) could not be set properly."
	"\n\n"
	"Your video card does not appear to support this number of colors."
	"\n\n"
	"An updated video driver could solve this, but it is more likely due to limitations "
	"of your video card hardware.  Contact your video card vendor for more help."
	"\n\n"
	"See code R103 in " APP_NAME " Help for more information.";

const char g_pszVideoResolutionError[] =
	"The required display settings (%s) could not be set properly."
	"\n\n"
	"Your video card does not appear to support this pixel area (resolution) with this "
	"number of colors."
	"\n\n"
	"An updated video driver could solve this, but it is more likely due to limitations "
	"of your video card hardware.  Contact your video card vendor for more help."
	"\n\n"
	"See code R104 in " APP_NAME " Help for more information.";

const char g_pszVideoPagesError[] =
	"The required display settings (%s) could not be set properly."
	"\n\n"
	"Your video card does not appear to support this number of pages at these settings."
	"\n\n"
	"An updated video driver could solve this, but it is more likely due to limitations "
	"of your video card hardware.  Contact your video card vendor for more help."
	"\n\n"
	"See code R105 in " APP_NAME " Help for more information.";

const char	g_pszVideoChangeDepthErrorUnderGDI_s[]	=
	"The required display settings (%s) could not be set properly because you are not "
	"using DirectX."
	"\n\n"
	"You can manually change your color settings before running " APP_NAME ", but "
	"we recommend using DirectX, which allows " APP_NAME " to use any color depth."
	"\n\n"
	"See code R106 in " APP_NAME " Help for more information.";

const char g_pszAudioModeGeneralError_s[] =
	"The required audio mode (%s) could not be set properly."
	"\n\n"
	"If the audio device is or was being used, it may be available once the current "
	"sound is done.  Choose 'Retry' if you want to try again."
	"\n\n"
	"If there is no audio device or it does not support the required mode, you can "
	"choose 'Ignore' to continue without audio."
	"\n\n"
	"If you want to stop the program, choose 'Abort'.";

const char g_pszAudioModeInUseError_s[]	=
	"The required audio mode (%s) could not be set properly."
	"\n\n"
	"The audio device is or was being used, it may be available once the current "
	"sound is done.  Choose 'Retry' if you want to try again."
	"\n\n"
	"If you would like to continue without sound from " APP_NAME ", you can "
	"choose 'Ignore'."
	"\n\n"
	"If you want to stop the program, choose 'Abort'.";

const char g_pszAudioModeNoDeviceError_s[]	=
	"The required audio mode (%s) could not be set properly."
	"\n\n"
	"There is no audio device or the driver is incorrectly installed or missing."
	"\n\n"
	"If you want to continue without audio, choose 'Yes'."
	"\n"
	"If you want to stop the program, choose 'No'."
	"\n\n"
	"Would you like to continue without audio?";

const char g_pszAudioModeNotSupportedError_s[]	=
	"The audio mode (%s) could not be set properly."
	"\n\n"
	"The audio device does not support this mode."
	"\n\n"
	"If you want to stop the program, choose 'Abort'."
	"\n\n"
	"If you want to try another simpler mode that might work "
	"choose 'Retry'."
	"\n\n"
	"If you want to continue without audio, choose 'Ignore'.";

const char g_pszAudioVanillaModeNotSupportedError_s[]	=
	"The audio mode (%s) could not be set properly."
	"\n\n"
	"The audio device does not support this mode."
	"\n\n"
	"If you want to continue without audio, choose 'Yes'."
	"\n"
	"If you want to stop the program, choose 'No'."
	"\n\n"
	"Would you like to continue without audio?";

const char g_pszPrefFileName[] = PREFS_FILE;

const char g_pszPrefOpenError[] =
	"The preference file '" PREFS_FILE "' could not be opened."
	"\n\n"
	"See code A100 in " APP_NAME " Help for more information.";

const char g_pszPrefReadError[] =
	"An error occurred while reading from '" PREFS_FILE "'."
	"\n\n"
	"See code A101 in " APP_NAME " Help for more information.";

const char g_pszPrefWriteError[] =
	"An error occurred while saving to '" PREFS_FILE "'."
	"\n\n"
	"Any settings that you may have made will not be saved."
	"\n\n"
	"See code A102 in " APP_NAME " Help for more information.";

const char g_pszPrefReadOnly[] =
	"The file '" PREFS_FILE "' is set to 'READ-ONLY'."
	"\n\n"
	"Any settings that you may have made will not be saved."
	"\n\n"
	"See code A103 in " APP_NAME " Help for more information.";

const char g_pszTitleError[] =
	"An error occurred during the title sequence."
	"\n\n"
	"See code A104 in " APP_NAME " Help for more information.";

const char g_pszCantFindAssets[] =
	"One or more required files could not be found."
	"\n\n"
	CD_DRIVE_CHANGE_MESSAGE
	"\n\n"
	"See code A105 in " APP_NAME " Help for more information.";

const char g_pszWrongCD[] =
	"The original Postal CD is not in the drive it was installed from."
	"\n\n"
	"The CD in the drive does not appear to be the original Postal CD."
	"\n\n"
	"Please insert the original Postal CD and click on Retry.";

const char g_pszPromptForOriginalCD[] =
	"Please make sure the original Postal CD\n"
	"is in the drive it was installed from.";

const char g_pszNotOnCDROM[] =
	"Please insert the " APP_NAME " CD into the drive you used to install it."
	"\n\n"
	CD_DRIVE_CHANGE_MESSAGE
	"\n\n"
	"See code A106 in " APP_NAME " Help for more information.";

const char g_pszGeneralError[] =
	"An error has occurred.  This application cannot proceed."
	"\n\n"
	"See code A107 in " APP_NAME " Help for more information.";

const char g_pszBadPath_s_s[] =
	"One or more file locations for the game are invalid."
	"\n\n"
	CD_DRIVE_CHANGE_MESSAGE
	"\n\n"
	ADVANCED_USERS_CHANGE_PATH
	"\n\n"
	"See code A108 in " APP_NAME " Help for more information.";

const char g_pszBadCDPath_s_s[] =
	"Make sure the " APP_NAME " CD is in the drive you used to install it."
	"\n\n"
	CD_DRIVE_CHANGE_MESSAGE
	"\n\n"
	ADVANCED_USERS_CHANGE_PATH
	"\n\n"
	"See code A108 in " APP_NAME " Help for more information.";

const char g_pszCannotOpenSoundFiles_s_s[]	=
	"Your audio hardware supports %s, but the " APP_NAME " file(s) associated with that "
	"sound format were not installed."
	"\n\n"
	"See code A109 in " APP_NAME " Help for more information.";

const char g_pszNoSoundFiles[]	=
	"There is no sound file installed."
	"\n\n"
	"Please run " APP_NAME " Setup and choose a sound option."
	"\n\n"
	"See code A110 in " APP_NAME " Help for more information.";


const char	g_pszAssetsMissingError[] =
	"One or more files needed by the editor could not be found.";

const char	g_pszSaveFileQuery[]	=
	"Save file before this operation?";

const char g_pszSaveDemoTitle[]	=
	"Save Demo";

const char g_pszSaveGameTitle[] = 
	"Choose a name for your saved game";

const char g_pszSaveGameErrorTitle[] = 
	"Error saving file";

const char g_pszSaveGameErrorText[] = 
	"Your game could not be saved.  Check to see if your disk is full.";

const char g_pszLoadGameTitle[] = 
	"Choose the game you wish to restore";

const char	g_pszFileOpenError_s[] =
	"Unable to open the file '%s'."
	"\n\n"
	"The file may be missing or corrupted, or you may not have permission to open it.";

const char	g_pszFileReadError_s[] =
	"An error has occurred while reading from the file '%s'."
	"\n\n"
	"The file may be corrupted, or you may not have permission to access it.";

const char	g_pszFileWriteError_s[] =
	"An error has occurred while writing to the file '%s'."
	"\n\n"
	"The file may be corrupted, or you may not have permission to write to it.";


const char g_pszDispenserNoDispenseeTypeChosen[]	=
	"You must choose a dispensee type or Cancel.";

const char g_pszGenericBrowseFor_s_Title[]	=
	"Browse for %s";

const char	g_pszGenericMustBeRelativePath_s[]	=
	"You must choose a file below path \"%s\".\n";

const char g_pszDontDropYourselfMORON[]	=
	"You don't really want to drop yourself!!\n"; 
	
const char g_pszDoofusCannotFindNavNet_EditMode_hu_hu[]	=
	"Doofus with ID %hd found that ID %hd (its NavNet ID) was not "
	"a NavNet.\n";

const char g_pszDoofusCannotFindNavNet_PlayMode_hu_hu[] =
	"A character with ID %hd was unable to locate its NavNet with "
	"ID %hd.\n";

const char g_pszPlayOneRealmOnlyMessage[]	=
	"This version of " APP_NAME " only allows you to play the"
	"\n"
	"levels that it came with."
	"\n";


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////// Misc  ///////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

// NOTICE: These aren't currently available in any language other than english!
#if ENGLISH_LOCALE
	const char g_pszEditorDisabled[]			=	"The editor is not available in this demo version.";
	const char g_pszMultiplayerDisabled[]		=	"Multiplayer is not available in this demo version.";
	const char g_pszBuy[]							=	"You can order the full version of the game from"
																"\n\n"
																"         www.gopostal.com"
																"\n\n"
																"You know you want it... what are you waiting for?!";
#elif LOCALE == GERMAN
#elif LOCALE == FRENCH
#endif


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////// Menus ///////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

#if ENGLISH_LOCALE ////////////////////////////////////////////////////////////

	const char	g_pszMainMenu_Title[]							= MAIN_MENU_TITLE;
	const char g_pszMainMenu_Start[]							= "START";
	const char g_pszMainMenu_Options[]							= "OPTIONS";
	const char g_pszMainMenu_Editor[]							= "EDITOR";
	const char g_pszMainMenu_Buy[]								= "ORDER INFO";
	const char g_pszMainMenu_Exit[]								= "EXIT";

	const char g_pszVerifyExitMenu_Title[]					= "REALLY EXIT?";
	const char g_pszVerifyExitMenu_Yes[]						= "YES";
	const char g_pszVerifyExitMenu_No[]						= "NO";

	const char g_pszVerifyQuitMenu_Title[]					= "REALLY QUIT?";
	const char g_pszVerifyQuitMenu_Yes[]						= "YES";
	const char g_pszVerifyQuitMenu_No[]						= "NO";

	const char g_pszGameMenu_Title[]							= "GAME";
	const char g_pszGameMenu_Continue[]						= "CONTINUE";
	const char g_pszGameMenu_Save[]								= "SAVE";
	const char g_pszGameMenu_Options[]							= "OPTIONS";
	const char g_pszGameMenu_Quit[]								= "QUIT";

	const char g_pszEditorMenu_Title[]							= "EDITOR";
	const char g_pszEditorMenu_Continue[]						= "CONTINUE";
	const char g_pszEditorMenu_Options[]						= "OPTIONS";
	const char g_pszEditorMenu_Quit[]							= "QUIT";

	const char g_pszOptionsMenu_Title[]						= "OPTIONS";
	const char g_pszOptionsMenu_Video[]						= "VIDEO";
	const char g_pszOptionsMenu_Audio[]						= "AUDIO";
	const char g_pszOptionsMenu_Controls[]					= "CONTROLS";
	const char g_pszOptionsMenu_Multiplayer[]				= "MULTIPLAYER";
	const char g_pszOptionsMenu_Performance[]				= "PERFORMANCE";
	const char g_pszOptionsMenu_Difficulty[]					= "DIFFICULTY";
	const char g_pszOptionsMenu_Crosshair[]					= "CROSSHAIR";

	const char g_pszDifficultyMenu_Title[]					= "DIFFICULTY";
	const char g_pszDifficultyMenu_SetDifficulty[]			= "SET";

	const char g_pszOrganMenu_Title[]							= "SOUND TEST";
	const char g_pszOrganMenu_SpecialKeysHeading[]			= "SPECIAL KEYS";
	const char g_pszOrganMenu_NumericKeysFunction[]		= "  0 thru 9 - PLAY A SOUND";
	const char g_pszOrganMenu_AlphaKeysFunction[]			= "  A thru Z - PLAY A SOUND";
	const char g_pszOrganMenu_TabKeyFunction[]				= "  TAB - NEXT SET OF SOUNDS";
	const char g_pszOrganMenu_Exit[]							= "EXIT";

	const char g_pszAudioMenu_Title[]							= "AUDIO";
	const char g_pszAudioMenu_Mixer[]							= "MIXER";
	const char g_pszAudioMenu_SoundTest[]						= "SOUND TEST";

	const char g_pszVideoMenu_Title[]							= "VIDEO";
	const char g_pszVideoMenu_Gamma[]							= "GAMMA";

	const char g_pszControlsMenu_Title[]						= "CONTROLS";
	const char g_pszControlsMenu_KeyboardSetup[]			= "KEYBOARD SETUP";
	const char g_pszControlsMenu_MouseSetup[]				= "MOUSE SETUP";
	const char g_pszControlsMenu_JoystickSetup[]			= "X CONTROLLER SETUP";
	const char g_pszControlsMenu_TurningSpeeds[]			= "TURNING SPEEDS";
	const char g_pszControlsMenu_UseMouse[]					= "USE MOUSE";
	const char g_pszControlsMenu_HorizMouseSensitivity[]	= "HORIZ MOUSE SENS.";
	const char g_pszControlsMenu_VertMouseSensitivity[]	= "VERT MOUSE SENS.";

	const char g_pszKeyboardSetupMenu_Title[]				= "KEYBOARD SETUP";

	const char g_pszMouseSetupMenu_Title[]					= "MOUSE SETUP";

	const char g_pszJoystickSetupMenu_Title[]				= "X CONTROLLER SETUP";

	const char g_pszPerformanceMenu_Title[]					= "PERFORMANCE";
	const char g_pszPerformanceMenu_Transparency[]			= "TRANSPARENCY";
	const char g_pszPerformanceMenu_3dLighting[]			= "3D LIGHTING";
	const char g_pszPerformanceMenu_Particles[]				= "PARTICLES";
	const char g_pszPerformanceMenu_DynamicVolume[]		= "DYNAMIC VOLUME";
	const char g_pszPerformanceMenu_AmbientSounds[]		= "AMBIENT SOUNDS";

	const char g_pszRotationSetupMenu_Title[]				= "TURNING SPEEDS ";
	const char g_pszRotationSetupMenu_RunningSlow[]		= "RUNNING (SLOW)";
	const char g_pszRotationSetupMenu_RunningFast[]		= "RUNNING (FAST)";
	const char g_pszRotationSetupMenu_StandingSlow[]		= "STANDING (SLOW)";
	const char g_pszRotationSetupMenu_StandingFast[]		= "STANDING (FAST)";
	const char g_pszRotationSetupMenu_TapDegrees[]			= "TAP DEGREES";
	const char g_pszRotationSetupMenu_RestoreDefaults[]	= "RESTORE DEFAULTS";
	const char g_pszRotationSetupMenu_RestoreDefaultsOld[] = "RESTORE OLD DEFAULTS";

	const char g_pszVolumesMenu_Title[]						= "AUDIO MIXER";

	const char g_pszStartGameMenu_Title[]						= "START GAME";
	const char g_pszStartGameMenu_SinglePlayer[]			= "SINGLE PLAYER";
	const char g_pszStartGameMenu_Multiplayer[]				= "MULTIPLAYER";
	const char g_pszStartGameMenu_Demo[]						= "DEMO";

	const char g_pszStartSinglePlayerMenu_Title[]			= "SINGLE PLAYER";
#if defined(START_MENU_ADDON_ITEM)
	#if TARGET == JAPAN_ADD_ON
		const char g_pszStartSinglePlayerMenu_New[]			= "GO POSTAL IN THE USA";
		const char g_pszStartSinglePlayerMenu_AddOn[]		= "GO POSTAL IN JAPAN";
	#elif TARGET == POSTAL_PLUS
		const char g_pszStartSinglePlayerMenu_New[]			= "NEW GAME (ALL LEVELS)";
		const char g_pszStartSinglePlayerMenu_AddOn[]		= "SPECIAL DELIVERY LEVELS";
	#elif TARGET == POSTAL_2015
		const char g_pszStartSinglePlayerMenu_New[]		= "NEW GAME";
		const char g_pszStartSinglePlayerMenu_AddOn[]		= "SPECIAL DELIVERY";
	#else
		#error Strings must be customized for current TARGET
	#endif
#else
	#if TARGET == SUPER_POSTAL
		const char g_pszStartSinglePlayerMenu_New[]			= "GO POSTAL ALL OVER";
	#elif (TARGET == POSTAL_PLUS || TARGET == POSTAL_2015)
		const char g_pszStartSinglePlayerMenu_New[]			= "NEW GAME";
	#else
		#error Strings must be customized for current TARGET
	#endif
#endif
	const char g_pszStartSinglePlayerMenu_LoadLevel[]		= "LOAD LEVEL";
	const char g_pszStartSinglePlayerMenu_LoadGame[]		= "LOAD GAME";
	const char g_pszStartSinglePlayerMenu_Challenge[]		= "GAUNTLET CHALLENGE";

	const char g_pszStartChallengeMenu_Title[]				= "CHALLENGE";
	const char g_pszStartChallengeMenu_Gauntlet[]			= "THE GAUNTLET";
	const char g_pszStartChallengeMenu_Timed[]				= "TIMED";
	const char g_pszStartChallengeMenu_Goal[]				= "GOAL";
	const char g_pszStartChallengeMenu_Flag[]				= "FLAG";
	const char g_pszStartChallengeMenu_CheckPoint[]		= "CHECKPOINT";

	const char g_pszStartMultiplayerMenu_Title[]			= "MULTIPLAYER";
	const char g_pszStartMultiplayerMenu_Join[]				= "JOIN GAME";
	const char g_pszStartMultiplayerMenu_Host[]				= "HOST GAME";
	const char g_pszStartMultiplayerMenu_Options[]			= "OPTIONS";


	const char g_pszJoinGameMenu_Title[]						= "JOIN GAME";
	const char g_pszJoinGameMenu_Browse[]						= "BROWSE (LAN only)";
	const char g_pszJoinGameMenu_ConnectTo[]					= "CONNECT TO";

	const char g_pszHostGameMenu_Title[]						= "HOST GAME";
	const char g_pszHostGameMenu_Start[]						= "START";

	const char g_pszStartDemoMenu_Title[]						= "DEMO";
	const char g_pszStartDemoMenu_Browse[]					= "BROWSE";
	const char g_pszStartDemoMenu_Play[]						= "PLAY";
	const char g_pszStartDemoMenu_Record[]					= "RECORD";

	const char g_pszMultiplayerSetupMenu_Title[]			= "MULTIPLAYER";
	const char g_pszMultiplayerSetupMenu_Name[]				= "NAME";
	const char g_pszMultiplayerSetupMenu_Color[]			= "COLOR";
	const char g_pszMultiplayerSetupMenu_Protocol[]		= "PROTOCOL";
	const char g_pszMultiplayerSetupMenu_Connection[]		= "CONNECTION";

	// Keep at end -- was not in original localizable text.
	const char g_pszControlsMenu_UseJoystick[]				= "USE X CONTROLLER";

#elif LOCALE == GERMAN	///////////////////////////////////////////////////////

	const char	g_pszMainMenu_Title[]							= MAIN_MENU_TITLE;
	const char g_pszMainMenu_Start[]							= "SPIEL STARTEN";
	const char g_pszMainMenu_Options[]							= "OPTIONEN";
	const char g_pszMainMenu_Editor[]							= "EDITOR";
	const char g_pszMainMenu_Buy[]								= "ORDER INFO";
	const char g_pszMainMenu_Exit[]								= "BEENDEN";

	const char g_pszVerifyExitMenu_Title[]					= "WIRKLICH BEENDEN?";
	const char g_pszVerifyExitMenu_Yes[]						= "JA";
	const char g_pszVerifyExitMenu_No[]						= "NEIN";

	const char g_pszVerifyQuitMenu_Title[]					= "WIRKLICH BEENDEN?";
	const char g_pszVerifyQuitMenu_Yes[]						= "JA";
	const char g_pszVerifyQuitMenu_No[]						= "NEIN";

	const char g_pszGameMenu_Title[]							= "SPIEL";
	const char g_pszGameMenu_Continue[]						= "WEITER";
	const char g_pszGameMenu_Save[]								= "SPEICHERN";
	const char g_pszGameMenu_Options[]							= "OPTIONEN";
	const char g_pszGameMenu_Quit[]								= "BEENDEN";

	const char g_pszEditorMenu_Title[]							= "EDITOR";
	const char g_pszEditorMenu_Continue[]						= "WEITER";
	const char g_pszEditorMenu_Options[]						= "OPTIONEN";
	const char g_pszEditorMenu_Quit[]							= "BEENDEN";

	const char g_pszOptionsMenu_Title[]						= "OPTIONEN";
	const char g_pszOptionsMenu_Video[]						= "VIDEO";
	const char g_pszOptionsMenu_Audio[]						= "AUDIO";
	const char g_pszOptionsMenu_Controls[]					= "STEUERUNG";
	const char g_pszOptionsMenu_Multiplayer[]				= "MEHRERE SPIELER";
	const char g_pszOptionsMenu_Performance[]				= "LEISTUNG";
	const char g_pszOptionsMenu_Difficulty[]					= "SCHWIERIGKEIT";

	const char g_pszDifficultyMenu_Title[]					= "SCHWIERIGKEIT";
	const char g_pszDifficultyMenu_SetDifficulty[]			= "";

	const char g_pszOrganMenu_Title[]							= "SOUND-TEST";
	const char g_pszOrganMenu_SpecialKeysHeading[]			= "SONDERTASTEN";
	const char g_pszOrganMenu_NumericKeysFunction[]		= "0 BIS 9 - SOUND ABSPIELEN";
	const char g_pszOrganMenu_AlphaKeysFunction[]			= "A BIS Z - SOUND ABSPIELEN";
	const char g_pszOrganMenu_TabKeyFunction[]				= "TAB - NACHSTE SOUND-REIHE";
	const char g_pszOrganMenu_Exit[]							= "BEENDEN";

	const char g_pszAudioMenu_Title[]							= "AUDIO";
	const char g_pszAudioMenu_Mixer[]							= "MISCHPULT";
	const char g_pszAudioMenu_SoundTest[]						= "SOUND-TEST";

	const char g_pszVideoMenu_Title[]							= "VIDEO";
	const char g_pszVideoMenu_Gamma[]							= "GAMMA";

	const char g_pszControlsMenu_Title[]						= "STEUERUNG";
	const char g_pszControlsMenu_KeyboardSetup[]			= "TASTATUR-SETUP";
	const char g_pszControlsMenu_MouseSetup[]				= "MAUS-SETUP";
	const char g_pszControlsMenu_JoystickSetup[]			= "JOYSTICK-SETUP";
	const char g_pszControlsMenu_TurningSpeeds[]			= "DREHGESCHWINDIGKEITEN";
	const char g_pszControlsMenu_UseMouse[]					= "MAUS VERWENDEN";
	const char g_pszControlsMenu_HorizMouseSensitivity[]	= "HORIZONTALE MAUSBEWEGUNG";
	const char g_pszControlsMenu_VertMouseSensitivity[]	= "VERTIKALE MAUSBEWEGUNG";

	const char g_pszKeyboardSetupMenu_Title[]				= "TASTATUR-SETUP";

	const char g_pszMouseSetupMenu_Title[]					= "MAUS-SETUP";

	const char g_pszJoystickSetupMenu_Title[]				= "JOYSTICK-SETUP";

	const char g_pszPerformanceMenu_Title[]					= "LEISTUNG";
	const char g_pszPerformanceMenu_Transparency[]			= "TRANSPARENZ";
	const char g_pszPerformanceMenu_3dLighting[]			= "3D-BELEUCHTUNG";
	const char g_pszPerformanceMenu_Particles[]				= "PARTIKEL";
	const char g_pszPerformanceMenu_DynamicVolume[]		= "DYNAMISCHE LAUTSTARKE";
	const char g_pszPerformanceMenu_AmbientSounds[]		= "UMGEBENDE KLANGE";

	const char g_pszRotationSetupMenu_Title[]				= "DREHGESCHWINDIGKEITEN";
	const char g_pszRotationSetupMenu_RunningSlow[]		= "LAUFT (LANGSAM)";
	const char g_pszRotationSetupMenu_RunningFast[]		= "LAUFT (SCHNELL)";
	const char g_pszRotationSetupMenu_StandingSlow[]		= "STEHT (LANGSAM)";
	const char g_pszRotationSetupMenu_StandingFast[]		= "STEHT (SCHNELL)";
	const char g_pszRotationSetupMenu_TapDegrees[]			= "TIPPEN GRADE";
	const char g_pszRotationSetupMenu_RestoreDefaults[]	= "ZURUCKSETZEN";

	const char g_pszVolumesMenu_Title[]						= "AUDIO-MISCHPULT";

	const char g_pszStartGameMenu_Title[]						= "SPIEL STARTEN";
	const char g_pszStartGameMenu_SinglePlayer[]			= "EINZELSPIELER";
	const char g_pszStartGameMenu_Multiplayer[]				= "MEHRERE SPIELER";
	const char g_pszStartGameMenu_Demo[]						= "DEMO";

	const char g_pszStartSinglePlayerMenu_Title[]			= "EINZELSPIELER";
	const char g_pszStartSinglePlayerMenu_New[]				= "ORIGINAL SPIEL";	// Mike's lame translation
	const char g_pszStartSinglePlayerMenu_AddOn[]			= "ADD-ON SPIEL"		// Mike's lame translation
	const char g_pszStartSinglePlayerMenu_LoadLevel[]		= "EBENE LADEN";
	const char g_pszStartSinglePlayerMenu_LoadGame[]		= "SPIEL LADEN";
	const char g_pszStartSinglePlayerMenu_Challenge[]		= "HERAUSFORDERUNG";

	const char g_pszStartChallengeMenu_Title[]				= "HERAUSFORDERUNG";
	const char g_pszStartChallengeMenu_Gauntlet[]			= "SPIESSRUTEN";
	const char g_pszStartChallengeMenu_Timed[]				= "ZEIT NEHMEN";
	const char g_pszStartChallengeMenu_Goal[]				= "ZIEL";
	const char g_pszStartChallengeMenu_Flag[]				= "FLAGGE";
	const char g_pszStartChallengeMenu_CheckPoint[]		= "CHECKPOINT";

	const char g_pszStartMultiplayerMenu_Title[]			= "MEHRERE SPIELER";
	const char g_pszStartMultiplayerMenu_Join[]				= "MITSPIELEN";
	const char g_pszStartMultiplayerMenu_Host[]				= "HOST-SPIEL";
	const char g_pszStartMultiplayerMenu_Options[]			= "OPTIONEN";


	const char g_pszJoinGameMenu_Title[]						= "MITSPIELEN";
	const char g_pszJoinGameMenu_Browse[]						= "DURCHSUCHEN";
	const char g_pszJoinGameMenu_ConnectTo[]					= "VERBINDEN MIT";

	const char g_pszHostGameMenu_Title[]						= "HOST-SPIEL";
	const char g_pszHostGameMenu_Start[]						= "START";

	const char g_pszStartDemoMenu_Title[]						= "DEMO";
	const char g_pszStartDemoMenu_Browse[]					= "DURCHSUCHEN";
	const char g_pszStartDemoMenu_Play[]						= "ABSPIELEN";
	const char g_pszStartDemoMenu_Record[]					= "AUSZEICHNEN";

	const char g_pszMultiplayerSetupMenu_Title[]			= "MEHRERE SPIELER";
	const char g_pszMultiplayerSetupMenu_Name[]				= "NAME";
	const char g_pszMultiplayerSetupMenu_Color[]			= "FARBE";
	const char g_pszMultiplayerSetupMenu_Protocol[]		= "PROTOKOLL";
	const char g_pszMultiplayerSetupMenu_Connection[]		= "VERBINDUNG";

	// Keep at end -- was not in original localizable text.
	const char g_pszControlsMenu_UseJoystick[]				= "JOYSTICK VERWENDEN";

#elif LOCALE == FRENCH	///////////////////////////////////////////////////////

	const char	g_pszMainMenu_Title[]							= MAIN_MENU_TITLE;
	const char g_pszMainMenu_Start[]							= "DEMARRER";
	const char g_pszMainMenu_Options[]							= "OPTIONS";
	const char g_pszMainMenu_Editor[]							= "EDITEUR";
	const char g_pszMainMenu_Buy[]								= "ORDER INFO";
	const char g_pszMainMenu_Exit[]								= "QUITTER";

	const char g_pszVerifyExitMenu_Title[]					= "VRAIMENT SORTIR ?";
	const char g_pszVerifyExitMenu_Yes[]						= "OUI";
	const char g_pszVerifyExitMenu_No[]						= "NON";

	const char g_pszVerifyQuitMenu_Title[]					= "VRAIMENT QUITTER ?";
	const char g_pszVerifyQuitMenu_Yes[]						= "OUI";
	const char g_pszVerifyQuitMenu_No[]						= "NON";

	const char g_pszGameMenu_Title[]							= "JEU";
	const char g_pszGameMenu_Continue[]						= "CONTINUER";
	const char g_pszGameMenu_Save[]								= "ENREGISTRER";
	const char g_pszGameMenu_Options[]							= "OPTIONS";
	const char g_pszGameMenu_Quit[]								= "QUITTER";

	const char g_pszEditorMenu_Title[]							= "EDITEUR";
	const char g_pszEditorMenu_Continue[]						= "CONTINUER";
	const char g_pszEditorMenu_Options[]						= "OPTIONS";
	const char g_pszEditorMenu_Quit[]							= "QUITTER";

	const char g_pszOptionsMenu_Title[]						= "OPTIONS";
	const char g_pszOptionsMenu_Video[]						= "VIDEO";
	const char g_pszOptionsMenu_Audio[]						= "AUDIO";
	const char g_pszOptionsMenu_Controls[]					= "COMMANDES";
	const char g_pszOptionsMenu_Multiplayer[]				= "JOUEURS MULTIPLES";
	const char g_pszOptionsMenu_Performance[]				= "PERFORMANCE";
	const char g_pszOptionsMenu_Difficulty[]					= "DIFFICULTE";

	const char g_pszDifficultyMenu_Title[]					= "DIFFICULTE";
	const char g_pszDifficultyMenu_SetDifficulty[]			= "DEFINIR";

	const char g_pszOrganMenu_Title[]							= "TEST SONORE";
	const char g_pszOrganMenu_SpecialKeysHeading[]			= "TOUCHES SPECIALES";
	const char g_pszOrganMenu_NumericKeysFunction[]		= "0 A 9 - JOUER UN SON";
	const char g_pszOrganMenu_AlphaKeysFunction[]			= "A A Z - JOUER UN SON";
	const char g_pszOrganMenu_TabKeyFunction[]				= "TAB - PROCHAIN JEU DE SONS";
	const char g_pszOrganMenu_Exit[]							= "QUITTER";

	const char g_pszAudioMenu_Title[]							= "AUDIO";
	const char g_pszAudioMenu_Mixer[]							= "MIXER";
	const char g_pszAudioMenu_SoundTest[]						= "TEST SONORE";

	const char g_pszVideoMenu_Title[]							= "VIDEO";
	const char g_pszVideoMenu_Gamma[]							= "GAMMA";

	const char g_pszControlsMenu_Title[]						= "COMMANDES";
	const char g_pszControlsMenu_KeyboardSetup[]			= "CONFIGURATION CLAVIER";
	const char g_pszControlsMenu_MouseSetup[]				= "CONFIGURATION SOURIS";
	const char g_pszControlsMenu_JoystickSetup[]			= "CONFIGURATION DE LA MANETTE DE JEU";
	const char g_pszControlsMenu_TurningSpeeds[]			= "VITESSES DE ROTATION";
	const char g_pszControlsMenu_UseMouse[]					= "UTILISER LA SOURIS";
	const char g_pszControlsMenu_HorizMouseSensitivity[]	= "SOURIS HORIZONTALE";
	const char g_pszControlsMenu_VertMouseSensitivity[]	= "SOURIS VERTICALE";

	const char g_pszKeyboardSetupMenu_Title[]				= "CONFIGURATION CLAVIER";

	const char g_pszMouseSetupMenu_Title[]					= "CONFIGURATION SOURIS";

	const char g_pszJoystickSetupMenu_Title[]				= "CONFIGURATION DE LA MANETTE DE JEU";

	const char g_pszPerformanceMenu_Title[]					= "PERFORMANCE";
	const char g_pszPerformanceMenu_Transparency[]			= "TRANSPARENCE";
	const char g_pszPerformanceMenu_3dLighting[]			= "ECLAIRAGE 3D";
	const char g_pszPerformanceMenu_Particles[]				= "PARTICULES";
	const char g_pszPerformanceMenu_DynamicVolume[]		= "VOLUME DYNAMIQUE";
	const char g_pszPerformanceMenu_AmbientSounds[]		= "SONS AMBIANTS";

	const char g_pszRotationSetupMenu_Title[]				= "VITESSES DE ROTATION";
	const char g_pszRotationSetupMenu_RunningSlow[]		= "COURIR (LENTEMENT)";
	const char g_pszRotationSetupMenu_RunningFast[]		= "COURIR (VITE)";
	const char g_pszRotationSetupMenu_StandingSlow[]		= "SE TENIR DEBOUT (LENTEMENT)";
	const char g_pszRotationSetupMenu_StandingFast[]		= "SE TENIR DEBOUT (VITE)";
	const char g_pszRotationSetupMenu_TapDegrees[]			= "DEGRES DE FRAPPE";
	const char g_pszRotationSetupMenu_RestoreDefaults[]	= "DEFAUT";

	const char g_pszVolumesMenu_Title[]						= "MIXER AUDIO";

	const char g_pszStartGameMenu_Title[]						= "DEMARRE LE JEU";
	const char g_pszStartGameMenu_SinglePlayer[]			= "JOUEUR UNIQUE";
	const char g_pszStartGameMenu_Multiplayer[]				= "JOUEURS MULTIPLES";
	const char g_pszStartGameMenu_Demo[]						= "DEMO";

	const char g_pszStartSinglePlayerMenu_Title[]			= "JOUEUR UNIQUE";
	const char g_pszStartSinglePlayerMenu_New[]				= "CHARGER ORIGINAL";	// Mike's lame translation
	const char g_pszStartSinglePlayerMenu_AddOn[]			= "CHARGER ADD-ON";		// Mike's lame translation
	const char g_pszStartSinglePlayerMenu_LoadLevel[]		= "CHARGER LE NIVEAU";
	const char g_pszStartSinglePlayerMenu_LoadGame[]		= "CHARGER LE JEU";
	const char g_pszStartSinglePlayerMenu_Challenge[]		= "DEFI";

	const char g_pszStartChallengeMenu_Title[]				= "DEFI";
	const char g_pszStartChallengeMenu_Gauntlet[]			= "LE GANT";
	const char g_pszStartChallengeMenu_Timed[]				= "CHRONOMETRE";
	const char g_pszStartChallengeMenu_Goal[]				= "BUT";
	const char g_pszStartChallengeMenu_Flag[]				= "DRAPEAU";
	const char g_pszStartChallengeMenu_CheckPoint[]		= "CONTROLE";

	const char g_pszStartMultiplayerMenu_Title[]			= "JOUEURS MULTIPLES";
	const char g_pszStartMultiplayerMenu_Join[]				= "JOINDRE LE JEU";
	const char g_pszStartMultiplayerMenu_Host[]				= "ANIMER LE JEU";
	const char g_pszStartMultiplayerMenu_Options[]			= "OPTIONS";


	const char g_pszJoinGameMenu_Title[]						= "JOINDRE LE JEU";
	const char g_pszJoinGameMenu_Browse[]						= "PARCOURIR (RESEAU LOCAL UNIQUEMENT)";
	const char g_pszJoinGameMenu_ConnectTo[]					= "SE CONNECTER A";

	const char g_pszHostGameMenu_Title[]						= "ANIMER LE JEU";
	const char g_pszHostGameMenu_Start[]						= "DEMARRER";

	const char g_pszStartDemoMenu_Title[]						= "DEMO";
	const char g_pszStartDemoMenu_Browse[]					= "PARCOURIR";
	const char g_pszStartDemoMenu_Play[]						= "JOUER";
	const char g_pszStartDemoMenu_Record[]					= "ENREGISTRER";

	const char g_pszMultiplayerSetupMenu_Title[]			= "JOUEURS MULTIPLES";
	const char g_pszMultiplayerSetupMenu_Name[]				= "NOM";
	const char g_pszMultiplayerSetupMenu_Color[]			= "COULEUR";
	const char g_pszMultiplayerSetupMenu_Protocol[]		= "PROTOCOLE";
	const char g_pszMultiplayerSetupMenu_Connection[]		= "CONNEXION";

	// Keep at end -- was not in original localizable text.
	const char g_pszControlsMenu_UseJoystick[]				= "UTILISER LA MANETTE DE JEU";

#endif

////////////////////////////////////////////////////////////////////////////////
///////////////////////////// Sample Master ////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

#if ENGLISH_LOCALE

	const char* g_apszSoundCategories[]	=
		{
		"GENERAL",		
		"SOUNDTRACK",			
		"WEAPONS",			
		"FEEDBACK",		
		"DESTRUCTION",	
		"AMBIENT",		
		"DEMON",			
		"SHOUTING",			
		"PAIN",
		"SUFFERING"
		};

#elif LOCALE == GERMAN

	const char* g_apszSoundCategories[]	=
		{
		"ALLGEMEIN",
		"SOUNDTRACK",
		"WAFFEN",
		"FEEDBACK",
		"ZERSTORUNG",
		"UMGEBUNG",
		"DAMON",
		"GESCHREI",
		"SCHMERZEN",
		"LEIDEN",
		};

#elif LOCALE == FRENCH

	const char* g_apszSoundCategories[]	=
		{
		"GENERAL",
		"PISTE MUSICALE",
		"ARMES",
		"FEED-BACK",
		"DESTRUCTION",
		"AMBIANTE",
		"DEMON",
		"CRIS",
		"DOULEUR",
		"SOUFFRANCE",
		};

#endif

////////////////////////////////////////////////////////////////////////////////
// Score module
////////////////////////////////////////////////////////////////////////////////

#if ENGLISH_LOCALE // ScoreDisplayText

const char* g_apszScoreDisplayText[CRealm::TotalScoringModes] = 
	{
	"      Population %d                        Hostiles %d   Killed %d (%d%% / %d%%)",	// Standard
	" Time Remaining %d:%2.2d                                Kills %d",				// Timed
	" Time Remaining %d:%2.2d            Kills %d               Remaining %d / %d",		// TimedGoal
	" Time Remaining %d:%2.2d",																	// TimedFlag
	" Kills %d                     Remaining %d            Time Elapsed %d:%2.2d",// Goal
	" Time Elapsed %d:%2.2d",																		// CaptureFlag
	" Clock %d:%2.2d    You have %d flags    Flags Remaining %d",						// Checkpoint
	"Time Remaining %d:%2.2d",																		// MPTimed
	"Time Remaining %d:%2.2d",																		// MPFrag
	"",																									// MPLastMan,
	"",																									// MPCaptureFlag
	"",																									// MPTimedFlag,
	"",																									// MPTimedFrag
	"",																									// MPLastManFrag
	"",																									// MPLastManTimed
	""																										// MPLastManTimedFrag
	};

#elif LOCALE == GERMAN
const char* g_apszScoreDisplayText[CRealm::TotalScoringModes] = 
	{
	"      Leute %d                        Feinden %d   Totungen %d (%d%%)",	// Standard
	" Verbleibende Zeit %d:%2.2d                                Totungen %d",				// Timed
	" Verbleibende Zeit %d:%2.2d        Totungen %d           Verbleibend %d",		// TimedGoal
	" Verbleibende Zeit %d:%2.2d",																	// TimedFlag
	" Totungen %d             Verbleibend %d         Vergangene Zeit %d:%2.2d",// Goal
	" Vergangene Zeit %d:%2.2d",																		// CaptureFlag
	" Uhr %d:%2.2d    Sie haben %d Flaggen    Verbleibende Flaggen %d",						// Checkpoint
	"Verbleibende Zeit %d:%2.2d",																		// MPTimed
	"Verbleibende Zeit %d:%2.2d",																		// MPFrag
	"",																									// MPLastMan,
	"",																									// MPCaptureFlag
	"",																									// MPTimedFlag,
	"",																									// MPTimedFrag
	"",																									// MPLastManFrag
	"",																									// MPLastManTimed
	""																										// MPLastManTimedFrag
	};

#elif LOCALE == FRENCH
const char* g_apszScoreDisplayText[CRealm::TotalScoringModes] = 
	{
	"      Personnes %d                        Ennemis %d   Victimes %d (%d%%)",	// Standard
	" Temps restant %d:%2.2d                                Victimes %d",				// Timed
	" Temps restant %d:%2.2d            Kills %d               Remaining %d",		// TimedGoal
	" Temps restant %d:%2.2d",																	// TimedFlag
	" Victimes %d                 Restant %d            Temps ecoule %d:%2.2d",// Goal
	" Temps ecoule %d:%2.2d",																		// CaptureFlag
	" Horloge %d:%2.2d    Vous avez %d drapeaux    Drapeaux restants %d",						// Checkpoint
	"Temps restant %d:%2.2d",																		// MPTimed
	"Temps restant %d:%2.2d",																		// MPFrag
	"",																									// MPLastMan,
	"",																									// MPCaptureFlag
	"",																									// MPTimedFlag,
	"",																									// MPTimedFrag
	"",																									// MPLastManFrag
	"",																									// MPLastManTimed
	""																										// MPLastManTimedFrag
	};
#endif // ScoreDisplayText

#if ENGLISH_LOCALE // ScoreGoalText
const char* g_apszScoreGoalText[CRealm::TotalScoringModes] = 
	{
	"      You must kill %d%% of the hostiles.",												// Standard
	" Score as many kills as possible in the time remaining.",							// Timed
	" Kill everyone before time runs out.",													// TimedGoal
	" Capture the flag before time runs out.",												// TimedFlag
	" Kill %d People in as little time as possible.",										// Goal
	" Capture the flag in as little time as possible.",									// CaptureFlag
	" Grab as many flags as possible before time runs out.",								// Checkpoint
	" The player with the most kills when time expires is the winner",				// MPTimed
	" The first player to get %d kills wins",													// MPFrag
	"",																									// MPLastMan,
	"",																									// MPCaptureFlag
	"",																									// MPTimedFlag
	" Try to reach %d kills before time expires",											// MPTimedFrag
	"",																									// MPLastManFrag
	"",																									// MPLastManTimed
	" There are no time or kill limits on this game - play as long as you like"	// MPLastManTimedFrag 

	};

#elif LOCALE == GERMAN
const char* g_apszScoreGoalText[CRealm::TotalScoringModes] = 
	{
	"      Sie mussen %d%% Feinde toten.",												// Standard
	" Erzielen Sie in der verbleibenden Zeit su viele Totungen wie moglich.",							// Timed
	" Toten Sie jeden vor Ablauf der Zeit.",													// TimedGoal
	" Nehmen Sie vor Ablauf der Zeit die Flagge ein.",												// TimedFlag
	" Toten Sie so schnell wie moglich %d Leute.",										// Goal
	" Nehmen Sie so schnell wie moglich die Flagge ein.",									// CaptureFlag
	" Holen Sie sich vor Ablauf der Zeit so viele Flaggen wie moglich.",								// Checkpoint
	" Der Spieler, dar nach Ablauf der Zeit die meisten Totungen hat, ist der Sieger",				// MPTimed
	" Der erste Spieler mit %d Totungen hat gewonnen",													// MPFrag
	"",																									// MPLastMan,
	"",																									// MPCaptureFlag
	"",																									// MPTimedFlag
	" Versuchen Sie, vor Ablauf der Zeit %d Totungen zu erreichen",											// MPTimedFrag
	"",																									// MPLastManFrag
	"",																									// MPLastManTimed
	" In diesem Spiel gibt es keine Ziet- oder Totungsbeschrakungen - spielen Sie so lange wie Sie wollen"	// MPLastManTimedFrag 

	};

#elif LOCALE == FRENCH
const char* g_apszScoreGoalText[CRealm::TotalScoringModes] = 
	{
	"      Vous devez tuer %d%% ennemis.",												// Standard
	" Faites autant de victimes que possible dans le delai restant.",							// Timed
	" Tuez tout le monde avant l'expiration du delai.",													// TimedGoal
	" Capturez le drapeau avant l'expiration du delai.",												// TimedFlag
	" Tuez %d personnes aussi vite que possible.",										// Goal
	" Capturez le drapeau aussi vite que possible.",									// CaptureFlag
	" Saisissez autant de drapeaux que possible avant l'expiration dudelai.",								// Checkpoint
	" Le joueur ayant fait le plus de victimes a l'expiration du delai est le gagnant",				// MPTimed
	" Le premier joueur faisant %d victimes gagne le jeu.",													// MPFrag
	"",																									// MPLastMan,
	"",																									// MPCaptureFlag
	"",																									// MPTimedFlag
	" Essayez de faire %d victimes avant l'expiration du delai",											// MPTimedFrag
	"",																									// MPLastManFrag
	"",																									// MPLastManTimed
	" Aucune limite de temps ou de victimes dans ce jeu - jouez aussi longtemps que vous le souhaitez."	// MPLastManTimedFrag 

	};
#endif // ScoreGoalText

#if ENGLISH_LOCALE // ScoreUnits
// Units for the various scoring types.
const char* g_apszScoreUnits[]	=
		{
		"",				// Standard.
		"Kills",			// Timed.
		"",				// Timed goal.
		"",				// Timed flag.
		"",				// Goal.
		"",				// Capture the flag.
		"Flags",			// Checkpoint.
		"Frags",			// Multiplayer timed.
		"Frags",			// Multiplayer Frag limited.
		"Frags",			// Multiplayer last man standing.
		"Frags",			// Multiplayer capture the flag.
		"Frags",			// Multiplayer Timed capture the flag.
		"Frags",			// Multiplayer timed frags.
		"Frags",			// Multiplayer last man frag limited.
		"Frags",			// Multiplayer last man with time limit.
		"Frags",			// Multiplayer last man frag and time limited.
		};

#elif LOCALE == GERMAN
const char* g_apszScoreUnits[]	=
		{
		"",				// Standard.
		"Totungen",			// Timed.
		"",				// Timed goal.
		"",				// Timed flag.
		"",				// Goal.
		"",				// Capture the flag.
		"Flaggen",			// Checkpoint.
		"Totungen",			// Multiplayer timed.
		"Totungen",			// Multiplayer Frag limited.
		"Totungen",			// Multiplayer last man standing.
		"Totungen",			// Multiplayer capture the flag.
		"Totungen",			// Multiplayer Timed capture the flag.
		"Totungen",			// Multiplayer timed frags.
		"Totungen",			// Multiplayer last man frag limited.
		"Totungen",			// Multiplayer last man with time limit.
		"Totungen",			// Multiplayer last man frag and time limited.
		};

#elif LOCALE == FRENCH
const char* g_apszScoreUnits[]	=
		{
		"",				// Standard.
		"tues",			// Timed.
		"",				// Timed goal.
		"",				// Timed flag.
		"",				// Goal.
		"",				// Capture the flag.
		"Drapeaux",			// Checkpoint.
		"tues",			// Multiplayer timed.
		"tues",			// Multiplayer Frag limited.
		"tues",			// Multiplayer last man standing.
		"tues",			// Multiplayer capture the flag.
		"tues",			// Multiplayer Timed capture the flag.
		"tues",			// Multiplayer timed frags.
		"tues",			// Multiplayer last man frag limited.
		"tues",			// Multiplayer last man with time limit.
		"tues",			// Multiplayer last man frag and time limited.
		};
#endif // ScoreUnits

#if ENGLISH_LOCALE // ScoreExplanations
// Explanations for the various scoring types.
const char* g_apszScoreExplanations[]	=
		{
		"",												// Standard.
		"Most kills in %s",							// Timed.
		"Best times for killing %d hostiles",	// Timed goal.
		"Best times for capturing the flag",	// Timed flag.
		"Best times for killing %d hostiles",	// Goal.
		"Best times for capturing the flag",	// Capture the flag.
		"Most flags collected",						// Checkpoint.
		"Top %d Scores",								// Multiplayer timed.
		"Top %d Scores",								// Multiplayer frag.
		"Top %d Scores",								// Multiplayer last man standing.
		"Top %d Scores",								// Multiplayer capture the flag.
		"Top %d Scores",								// Multiplayer Timed capture the flag.
		"Top %d Scores",								// Multiplayer timed frags.
		"Top %d Scores",								// Multiplayer last man frag limited.
		"Top %d Scores",								// Multiplayer last man with time limit.
		"Top %d Scores",								// Multiplayer last man frag and time limited.
		};

#elif LOCALE == GERMAN
const char* g_apszScoreExplanations[]	=
		{
		"",												// Standard.
		"Die meisten Totungen in %s",							// Timed.
		"Bestzeiten beim Toten von %d Feinden",	// Timed goal.
		"Bestzeiten beim Einnehmen der Flagge",	// Timed flag.
		"Bestzeiten beim Toten von %d Fienden",	// Goal.
		"Bestzeiten beim Einnehmen der Flagge",	// Capture the flag.
		"Meiste gesammelte Flaggen",						// Checkpoint.
		"Hochste %d Punktzahlen",								// Multiplayer timed.
		"Hochste %d Punktzahlen",								// Multiplayer frag.
		"Hochste %d Punktzahlen",								// Multiplayer last man standing.
		"Hochste %d Punktzahlen",								// Multiplayer capture the flag.
		"Hochste %d Punktzahlen",								// Multiplayer Timed capture the flag.
		"Hochste %d Punktzahlen",								// Multiplayer timed frags.
		"Hochste %d Punktzahlen",								// Multiplayer last man frag limited.
		"Hochste %d Punktzahlen",								// Multiplayer last man with time limit.
		"Hochste %d Punktzahlen",								// Multiplayer last man frag and time limited.
		};

#elif LOCALE == FRENCH
const char* g_apszScoreExplanations[]	=
		{
		"",												// Standard.
		"Maximum de victimes en %s",							// Timed.
		"Meilleurs temps pour tuer %d ennemis",	// Timed goal.
		"Meilleurs temps de capture des drapeaux",	// Timed flag.
		"Meilleurs temps pour tuer %d ennemis",	// Goal.
		"Meilleurs temps de capture des drapeaux",	// Capture the flag.
		"Nombre maximum de drapeaux amasses",						// Checkpoint.
		"%d Meilleurs Scores",								// Multiplayer timed.
		"%d Meilleurs Scores",								// Multiplayer frag.
		"%d Meilleurs Scores",								// Multiplayer last man standing.
		"%d Meilleurs Scores",								// Multiplayer capture the flag.
		"%d Meilleurs Scores",								// Multiplayer Timed capture the flag.
		"%d Meilleurs Scores",								// Multiplayer timed frags.
		"%d Meilleurs Scores",								// Multiplayer last man frag limited.
		"%d Meilleurs Scores",								// Multiplayer last man with time limit.
		"%d Meilleurs Scores",								// Multiplayer last man frag and time limited.
		};
#endif // ScoreExplanations


////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
