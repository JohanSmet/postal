////////////////////////////////////////////////////////////////////////////////
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
// HardwareSettings.h
// Project: Nostril (aka Postal)
//
// History:
//		18/11/23 JS		Started.
//
////////////////////////////////////////////////////////////////////////////////
#ifndef HARDWARESETTINGS_H
#define HARDWARESETTINGS_H

#include "RSPiX.h"
#ifdef PATHS_IN_INCLUDES
	#include "WishPiX/Prefs/prefs.h"
#else
	#include "prefs.h"
#endif

#include "settings.h"
#include "localize.h"

// Game settings
class CHardwareSettings : CSettings
	{
	public:
		int16_t m_sDeviceWidth;
		int16_t m_sDeviceHeight;
		int16_t	m_sUseCurrentDeviceDimensions;

		int16_t	m_sAudioSamplesPerSec;
		int16_t	m_sDeviceBitsPerSample;
		int16_t	m_sBufTime;
		int16_t	m_sMixBitsPerSample;

	public:
		// Set settings to default values
		CHardwareSettings(void);

		// Destructor
		~CHardwareSettings();

		// Read settings that are stored in preference file
		int16_t LoadPrefs(
			RPrefs* pPrefs);

		// Write settings that are stored in preference file
		int16_t SavePrefs(
			RPrefs* pPrefs);

		// Load settings that are stored in game file
		int16_t LoadGame(
			RFile* pFile);

		// Save settings that are stored in game file
		int16_t SaveGame(
			RFile* pFile);

		// Temporarily set settings for demo mode (file is for saving current settings)
		int16_t PreDemo(
			RFile* pFile);

		// Restore settings to what they were prior to demo mode
		int16_t PostDemo(
			RFile* pFile);
	};

#endif // HARDWARESETTINGS_H
////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
