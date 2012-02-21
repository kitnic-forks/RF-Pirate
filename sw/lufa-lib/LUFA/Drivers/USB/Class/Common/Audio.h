/*
             LUFA Library
     Copyright (C) Dean Camera, 2010.

  dean [at] fourwalledcubicle [dot] com
      www.fourwalledcubicle.com
*/

/*
  Copyright 2010  Dean Camera (dean [at] fourwalledcubicle [dot] com)

  Permission to use, copy, modify, distribute, and sell this
  software and its documentation for any purpose is hereby granted
  without fee, provided that the above copyright notice appear in
  all copies and that both that the copyright notice and this
  permission notice and warranty disclaimer appear in supporting
  documentation, and that the name of the author not be used in
  advertising or publicity pertaining to distribution of the
  software without specific, written prior permission.

  The author disclaim all warranties with regard to this
  software, including all implied warranties of merchantability
  and fitness.  In no event shall the author be liable for any
  special, indirect or consequential damages or any damages
  whatsoever resulting from loss of use, data or profits, whether
  in an action of contract, negligence or other tortious action,
  arising out of or in connection with the use or performance of
  this software.
*/

/** \file
 *  \brief Common definitions and declarations for the library USB Audio 1.0 Class driver.
 *
 *  Common definitions and declarations for the library USB Audio 1.0 Class driver.
 *
 *  \note This file should not be included directly. It is automatically included as needed by the class driver
 *        dispatch header located in LUFA/Drivers/USB/Class/Audio.h.
 */

/** \ingroup Group_USBClassAudio
 *  @defgroup Group_USBClassAudioCommon  Common Class Definitions
 *
 *  \section Module Description
 *  Constants, Types and Enum definitions that are common to both Device and Host modes for the USB
 *  Audio 1.0 Class.
 *
 *  @{
 */

#ifndef _AUDIO_CLASS_COMMON_H_
#define _AUDIO_CLASS_COMMON_H_

	/* Includes: */
		#include "../../USB.h"

		#include <string.h>

	/* Enable C linkage for C++ Compilers: */
		#if defined(__cplusplus)
			extern "C" {
		#endif

	/* Preprocessor Checks: */
		#if !defined(__INCLUDE_FROM_AUDIO_DRIVER)
			#error Do not include this file directly. Include LUFA/Drivers/Class/Audio.h instead.
		#endif

	/* Macros: */
		#if !defined(AUDIO_TOTAL_SAMPLE_RATES) || defined(__DOXYGEN__)
			/** Total number of discrete audio sample rates supported by the device. This value can be overridden by defining this
			 *  token in the project makefile to the desired value, and passing it to the compiler via the -D switch.
			 */
			#define AUDIO_TOTAL_SAMPLE_RATES    1
		#endif

		/** Supported channel mask for an Audio class terminal descriptor. See the Audio class specification for more details. */
		#define AUDIO_CHANNEL_LEFT_FRONT           (1 << 0)

		/** Supported channel mask for an Audio class terminal descriptor. See the Audio class specification for more details. */
		#define AUDIO_CHANNEL_RIGHT_FRONT          (1 << 1)

		/** Supported channel mask for an Audio class terminal descriptor. See the Audio class specification for more details. */
		#define AUDIO_CHANNEL_CENTER_FRONT         (1 << 2)

		/** Supported channel mask for an Audio class terminal descriptor. See the Audio class specification for more details. */
		#define AUDIO_CHANNEL_LOW_FREQ_ENHANCE     (1 << 3)

		/** Supported channel mask for an Audio class terminal descriptor. See the Audio class specification for more details. */
		#define AUDIO_CHANNEL_LEFT_SURROUND        (1 << 4)

		/** Supported channel mask for an Audio class terminal descriptor. See the Audio class specification for more details. */
		#define AUDIO_CHANNEL_RIGHT_SURROUND       (1 << 5)

		/** Supported channel mask for an Audio class terminal descriptor. See the Audio class specification for more details. */
		#define AUDIO_CHANNEL_LEFT_OF_CENTER       (1 << 6)

		/** Supported channel mask for an Audio class terminal descriptor. See the Audio class specification for more details. */
		#define AUDIO_CHANNEL_RIGHT_OF_CENTER      (1 << 7)

		/** Supported channel mask for an Audio class terminal descriptor. See the Audio class specification for more details. */
		#define AUDIO_CHANNEL_SURROUND             (1 << 8)

		/** Supported channel mask for an Audio class terminal descriptor. See the Audio class specification for more details. */
		#define AUDIO_CHANNEL_SIDE_LEFT            (1 << 9)

		/** Supported channel mask for an Audio class terminal descriptor. See the Audio class specification for more details. */
		#define AUDIO_CHANNEL_SIDE_RIGHT           (1 << 10)

		/** Supported channel mask for an Audio class terminal descriptor. See the Audio class specification for more details. */
		#define AUDIO_CHANNEL_TOP                  (1 << 11)

		/** Supported feature mask for an Audio class feature unit descriptor. See the Audio class specification for more details. */
		#define AUDIO_FEATURE_MUTE                 (1 << 0)

		/** Supported feature mask for an Audio class feature unit descriptor. See the Audio class specification for more details. */
		#define AUDIO_FEATURE_VOLUME               (1 << 1)

		/** Supported feature mask for an Audio class feature unit descriptor. See the Audio class specification for more details. */
		#define AUDIO_FEATURE_BASS                 (1 << 2)

		/** Supported feature mask for an Audio class feature unit descriptor. See the Audio class specification for more details. */
		#define AUDIO_FEATURE_MID                  (1 << 3)

		/** Supported feature mask for an Audio class feature unit descriptor. See the Audio class specification for more details. */
		#define AUDIO_FEATURE_TREBLE               (1 << 4)

		/** Supported feature mask for an Audio class feature unit descriptor. See the Audio class specification for more details. */
		#define AUDIO_FEATURE_GRAPHIC_EQUALIZER    (1 << 5)

		/** Supported feature mask for an Audio class feature unit descriptor. See the Audio class specification for more details. */
		#define AUDIO_FEATURE_AUTOMATIC_GAIN       (1 << 6)

		/** Supported feature mask for an Audio class feature unit descriptor. See the Audio class specification for more details. */
		#define AUDIO_FEATURE_DELAY                (1 << 7)

		/** Supported feature mask for an Audio class feature unit descriptor. See the Audio class specification for more details. */
		#define AUDIO_FEATURE_BASS_BOOST           (1 << 8)

		/** Supported feature mask for an Audio class feature unit descriptor. See the Audio class specification for more details. */
		#define AUDIO_FEATURE_BASS_LOUDNESS        (1 << 9)

		/** Terminal type constant for an Audio class terminal descriptor. See the Audio class specification for more details. */
		#define AUDIO_TERMINAL_UNDEFINED           0x0100

		/** Terminal type constant for an Audio class terminal descriptor. See the Audio class specification for more details. */
		#define AUDIO_TERMINAL_STREAMING           0x0101

		/** Terminal type constant for an Audio class terminal descriptor. See the Audio class specification for more details. */
		#define AUDIO_TERMINAL_VENDOR              0x01FF

		/** Terminal type constant for an Audio class terminal descriptor. See the Audio class specification for more details. */
		#define AUDIO_TERMINAL_IN_UNDEFINED        0x0200

		/** Terminal type constant for an Audio class terminal descriptor. See the Audio class specification for more details. */
		#define AUDIO_TERMINAL_IN_MIC              0x0201

		/** Terminal type constant for an Audio class terminal descriptor. See the Audio class specification for more details. */
		#define AUDIO_TERMINAL_IN_DESKTOP_MIC      0x0202

		/** Terminal type constant for an Audio class terminal descriptor. See the Audio class specification for more details. */
		#define AUDIO_TERMINAL_IN_PERSONAL_MIC     0x0203

		/** Terminal type constant for an Audio class terminal descriptor. See the Audio class specification for more details. */
		#define AUDIO_TERMINAL_IN_OMNIDIR_MIC      0x0204

		/** Terminal type constant for an Audio class terminal descriptor. See the Audio class specification for more details. */
		#define AUDIO_TERMINAL_IN_MIC_ARRAY        0x0205

		/** Terminal type constant for an Audio class terminal descriptor. See the Audio class specification for more details. */
		#define AUDIO_TERMINAL_IN_PROCESSING_MIC   0x0206

		/** Terminal type constant for an Audio class terminal descriptor. See the Audio class specification for more details. */
		#define AUDIO_TERMINAL_IN_OUT_UNDEFINED    0x0300

		/** Terminal type constant for an Audio class terminal descriptor. See the Audio class specification for more details. */
		#define AUDIO_TERMINAL_OUT_SPEAKER         0x0301

		/** Terminal type constant for an Audio class terminal descriptor. See the Audio class specification for more details. */
		#define AUDIO_TERMINAL_OUT_HEADPHONES      0x0302

		/** Terminal type constant for an Audio class terminal descriptor. See the Audio class specification for more details. */
		#define AUDIO_TERMINAL_OUT_HEAD_MOUNTED    0x0303

		/** Terminal type constant for an Audio class terminal descriptor. See the Audio class specification for more details. */
		#define AUDIO_TERMINAL_OUT_DESKTOP         0x0304

		/** Terminal type constant for an Audio class terminal descriptor. See the Audio class specification for more details. */
		#define AUDIO_TERMINAL_OUT_ROOM            0x0305

		/** Terminal type constant for an Audio class terminal descriptor. See the Audio class specification for more details. */
		#define AUDIO_TERMINAL_OUT_COMMUNICATION   0x0306

		/** Terminal type constant for an Audio class terminal descriptor. See the Audio class specification for more details. */
		#define AUDIO_TERMINAL_OUT_LOWFREQ         0x0307

		/** Convenience macro to fill a 24-bit \ref USB_Audio_SampleFreq_t structure with the given sample rate as a 24-bit number.
		 *
		 *  \param[in] freq  Required audio sampling frequency in HZ
		 */
		#define AUDIO_SAMPLE_FREQ(freq)           {((uint32_t)freq & 0x00FFFF), (((uint32_t)freq >> 16) & 0x0000FF)}

		/** Mask for the attributes parameter of an Audio class-specific Endpoint descriptor, indicating that the endpoint
		 *  accepts only filled endpoint packets of audio samples.
		 */
		#define AUDIO_EP_FULL_PACKETS_ONLY        (1 << 7)

		/** Mask for the attributes parameter of an Audio class-specific Endpoint descriptor, indicating that the endpoint
		 *  will accept partially filled endpoint packets of audio samples.
		 */
		#define AUDIO_EP_ACCEPTS_SMALL_PACKETS    (0 << 7)

	/* Enums: */
		/** Audio class specific interface description subtypes, for the Audio Control interface. */
		enum Audio_CSInterface_AC_SubTypes_t
		{
			AUDIO_DSUBTYPE_CSInterface_Header         = 0x01, /**< Audio class specific control interface header. */
			AUDIO_DSUBTYPE_CSInterface_InputTerminal  = 0x02, /**< Audio class specific control interface Input Terminal. */
			AUDIO_DSUBTYPE_CSInterface_OutputTerminal = 0x03, /**< Audio class specific control interface Output Terminal. */
			AUDIO_DSUBTYPE_CSInterface_Mixer          = 0x04, /**< Audio class specific control interface Mixer Unit. */
			AUDIO_DSUBTYPE_CSInterface_Selector       = 0x05, /**< Audio class specific control interface Selector Unit. */
			AUDIO_DSUBTYPE_CSInterface_Feature        = 0x06, /**< Audio class specific control interface Feature Unit. */
			AUDIO_DSUBTYPE_CSInterface_Processing     = 0x07, /**< Audio class specific control interface Processing Unit. */
			AUDIO_DSUBTYPE_CSInterface_Extension      = 0x08, /**< Audio class specific control interface Extension Unit. */
		};

		/** Audio class specific interface description subtypes, for the Audio Streaming interface. */
		enum Audio_CSInterface_AS_SubTypes_t
		{
			AUDIO_DSUBTYPE_CSInterface_General        = 0x01, /**< Audio class specific streaming interface general descriptor. */
			AUDIO_DSUBTYPE_CSInterface_FormatType     = 0x02, /**< Audio class specific streaming interface format type descriptor. */
			AUDIO_DSUBTYPE_CSInterface_FormatSpecific = 0x03, /**< Audio class specific streaming interface format information descriptor. */
		};

		/** Audio class specific endpoint description subtypes, for the Audio Streaming interface. */
		enum Audio_CSEndpoint_SubTypes_t
		{
			AUDIO_DSUBTYPE_CSEndpoint_General         = 0x01, /**< Audio class specific endpoint general descriptor. */
		};

	/* Type Defines: */
		/** \brief Audio class-specific Input Terminal Descriptor (LUFA naming conventions).
		 *
		 *  Type define for an Audio class-specific input terminal descriptor. This indicates to the host that the device
		 *  contains an input audio source, either from a physical terminal on the device, or a logical terminal (for example,
		 *  a USB endpoint). See the USB Audio specification for more details.
		 *
		 *  \see \ref USB_Audio_StdDescriptor_InputTerminal_t for the version of this type with standard element names.
		 */
		typedef struct
		{
			USB_Descriptor_Header_t Header; /**< Regular descriptor header containing the descriptor's type and length. */
			uint8_t                 Subtype; /**< Sub type value used to distinguish between audio class-specific descriptors,
			                                  *   must be \ref AUDIO_DSUBTYPE_CSInterface_InputTerminal.
			                                  */

			uint8_t                 TerminalID; /**< ID value of this terminal unit - must be a unique value within the device. */
			uint16_t                TerminalType; /**< Type of terminal, a TERMINAL_* mask. */
			uint8_t                 AssociatedOutputTerminal; /**< ID of associated output terminal, for physically grouped terminals
			                                                   *   such as the speaker and microphone of a phone handset.
			                                                   */
			uint8_t                 TotalChannels; /**< Total number of separate audio channels within this interface (right, left, etc.) */
			uint16_t                ChannelConfig; /**< CHANNEL_* masks indicating what channel layout is supported by this terminal. */

			uint8_t                 ChannelStrIndex; /**< Index of a string descriptor describing this channel within the device. */
			uint8_t                 TerminalStrIndex; /**< Index of a string descriptor describing this descriptor within the device. */
		} USB_Audio_Descriptor_InputTerminal_t;

		/** \brief Audio class-specific Input Terminal Descriptor (USB-IF naming conventions).
		 *
		 *  Type define for an Audio class-specific input terminal descriptor. This indicates to the host that the device
		 *  contains an input audio source, either from a physical terminal on the device, or a logical terminal (for example,
		 *  a USB endpoint). See the USB Audio specification for more details.
		 *
		 *  \see \ref USB_Audio_Descriptor_InputTerminal_t for the version of this type with non-standard LUFA specific
		 *       element names.
		 */
		typedef struct
		{
			uint8_t  bLength; /**< Size of the descriptor, in bytes. */
			uint8_t  bDescriptorType; /**< Type of the descriptor, either a value in \ref USB_DescriptorTypes_t or a value
			                           *   given by the specific class.
			                           */

			uint8_t  bDescriptorSubtype; /**< Sub type value used to distinguish between audio class-specific descriptors,
			                              *   must be \ref AUDIO_DSUBTYPE_CSInterface_InputTerminal.
			                              */
			uint8_t  bTerminalID; /**< ID value of this terminal unit - must be a unique value within the device. */
			uint16_t wTerminalType; /**< Type of terminal, a TERMINAL_* mask. */
			uint8_t  bAssocTerminal; /**< ID of associated output terminal, for physically grouped terminals
			                          *   such as the speaker and microphone of a phone handset.
			                          */
			uint8_t  bNrChannels; /**< Total number of separate audio channels within this interface (right, left, etc.) */
			uint16_t wChannelConfig; /**< CHANNEL_* masks indicating what channel layout is supported by this terminal. */

			uint8_t  iChannelNames; /**< Index of a string descriptor describing this channel within the device. */
			uint8_t  iTerminal; /**< Index of a string descriptor describing this descriptor within the device. */
		} USB_Audio_StdDescriptor_InputTerminal_t;

		/** \brief Audio class-specific Output Terminal Descriptor (LUFA naming conventions).
		 *
		 *  Type define for an Audio class-specific output terminal descriptor. This indicates to the host that the device
		 *  contains an output audio sink, either to a physical terminal on the device, or a logical terminal (for example,
		 *  a USB endpoint). See the USB Audio specification for more details.
		 *
		 *  \see \ref USB_Audio_StdDescriptor_OutputTerminal_t for the version of this type with standard element names.
		 */
		typedef struct
		{
			USB_Descriptor_Header_t Header; /**< Regular descriptor header containing the descriptor's type and length. */
			uint8_t                 Subtype; /**< Sub type value used to distinguish between audio class-specific descriptors,
			                                  *   must be \ref AUDIO_DSUBTYPE_CSInterface_OutputTerminal.
			                                  */

			uint8_t                 TerminalID; /**< ID value of this terminal unit - must be a unique value within the device. */
			uint16_t                TerminalType; /**< Type of terminal, a TERMINAL_* mask. */
			uint8_t                 AssociatedInputTerminal; /**< ID of associated input terminal, for physically grouped terminals
			                                                    *   such as the speaker and microphone of a phone handset.
			                                                    */
			uint8_t                 SourceID; /**< ID value of the unit this terminal's audio is sourced from. */

			uint8_t                 TerminalStrIndex; /**< Index of a string descriptor describing this descriptor within the device. */
		} USB_Audio_Descriptor_OutputTerminal_t;

		/** \brief Audio class-specific Output Terminal Descriptor (USB-IF naming conventions).
		 *
		 *  Type define for an Audio class-specific output terminal descriptor. This indicates to the host that the device
		 *  contains an output audio sink, either to a physical terminal on the device, or a logical terminal (for example,
		 *  a USB endpoint). See the USB Audio specification for more details.
		 *
		 *  \see \ref USB_Audio_Descriptor_OutputTerminal_t for the version of this type with non-standard LUFA specific
		 *       element names.
		 */
		typedef struct
		{
			uint8_t  bLength; /**< Size of the descriptor, in bytes. */
			uint8_t  bDescriptorType; /**< Sub type value used to distinguish between audio class-specific descriptors,
			                           *   must be \ref AUDIO_DSUBTYPE_CSInterface_OutputTerminal.
			                           */

			uint8_t  bDescriptorSubtype; /**< Sub type value used to distinguish between audio class-specific descriptors,
			                              *   a value from the \ref Audio_CSInterface_AC_SubTypes_t enum.
			                              */
			uint8_t  bTerminalID; /**< ID value of this terminal unit - must be a unique value within the device. */
			uint16_t wTerminalType; /**< Type of terminal, a TERMINAL_* mask. */
			uint8_t  bAssocTerminal; /**< ID of associated input terminal, for physically grouped terminals
			                          *   such as the speaker and microphone of a phone handset.
			                          */
			uint8_t  bSourceID; /**< ID value of the unit this terminal's audio is sourced from. */

			uint8_t  iTerminal; /**< Index of a string descriptor describing this descriptor within the device. */
		} USB_Audio_StdDescriptor_OutputTerminal_t;

		/** \brief Audio class-specific Interface Descriptor (LUFA naming conventions).
		 *
		 *  Type define for an Audio class-specific interface descriptor. This follows a regular interface descriptor to
		 *  supply extra information about the audio device's layout to the host. See the USB Audio specification for more
		 *  details.
		 *
		 *  \see \ref USB_Audio_StdDescriptor_Interface_AC_t for the version of this type with standard element names.
		 */
		typedef struct
		{
			USB_Descriptor_Header_t Header; /**< Regular descriptor header containing the descriptor's type and length. */
			uint8_t                 Subtype; /**< Sub type value used to distinguish between audio class-specific descriptors,
			                                  *   a value from the \ref Audio_CSInterface_AS_SubTypes_t enum.
			                                  */

			uint16_t                ACSpecification; /**< Binary coded decimal value, indicating the supported Audio Class specification version. */
			uint16_t                TotalLength; /**< Total length of the Audio class-specific descriptors, including this descriptor. */

			uint8_t                 InCollection; /**< Total number of Audio Streaming interfaces linked to this Audio Control interface (must be 1). */
			uint8_t                 InterfaceNumber; /**< Interface number of the associated Audio Streaming interface. */
		} USB_Audio_Descriptor_Interface_AC_t;

		/** \brief Audio class-specific Interface Descriptor (USB-IF naming conventions).
		 *
		 *  Type define for an Audio class-specific interface descriptor. This follows a regular interface descriptor to
		 *  supply extra information about the audio device's layout to the host. See the USB Audio specification for more
		 *  details.
		 *
		 *  \see \ref USB_Audio_Descriptor_Interface_AC_t for the version of this type with non-standard LUFA specific
		 *       element names.
		 */
		typedef struct
		{
			uint8_t  bLength; /**< Size of the descriptor, in bytes. */
			uint8_t  bDescriptorType; /**< Type of the descriptor, either a value in \ref USB_DescriptorTypes_t or a value
			                           *   given by the specific class.
			                           */

			uint8_t  bDescriptorSubtype;/**< Sub type value used to distinguish between audio class-specific descriptors,
			                             *   a value from the \ref Audio_CSInterface_AS_SubTypes_t enum.
			                             */

			uint16_t bcdADC; /**< Binary coded decimal value, indicating the supported Audio Class specification version. */
			uint16_t wTotalLength; /**< Total length of the Audio class-specific descriptors, including this descriptor. */

			uint8_t  bInCollection; /**< Total number of Audio Streaming interfaces linked to this Audio Control interface (must be 1). */
			uint8_t  bInterfaceNumbers; /**< Interface number of the associated Audio Streaming interface. */
		} USB_Audio_StdDescriptor_Interface_AC_t;

		/** \brief Audio class-specific Feature Unit Descriptor (LUFA naming conventions).
		 *
		 *  Type define for an Audio class-specific Feature Unit descriptor. This indicates to the host what features
		 *  are present in the device's audio stream for basic control, such as per-channel volume. See the USB Audio
		 *  specification for more details.
		 *
		 *  \see \ref USB_Audio_StdDescriptor_FeatureUnit_t for the version of this type with standard element names.
		 */
		typedef struct
		{
			USB_Descriptor_Header_t Header; /**< Regular descriptor header containing the descriptor's type and length. */
			uint8_t                 Subtype; /**< Sub type value used to distinguish between audio class-specific descriptors,
			                                  *   must be \ref AUDIO_DSUBTYPE_CSInterface_Feature.
			                                  */

			uint8_t                 UnitID; /**< ID value of this feature unit - must be a unique value within the device. */
			uint8_t                 SourceID; /**< Source ID value of the audio source input into this feature unit. */

			uint8_t                 ControlSize; /**< Size of each element in the ChanelControlls array. */
			uint8_t                 ChannelControls[3]; /**< Feature masks for the control channel, and each separate audio channel. */

			uint8_t                 FeatureUnitStrIndex; /**< Index of a string descriptor describing this descriptor within the device. */
		} USB_Audio_Descriptor_FeatureUnit_t;

		/** \brief Audio class-specific Feature Unit Descriptor (USB-IF naming conventions).
		 *
		 *  Type define for an Audio class-specific Feature Unit descriptor. This indicates to the host what features
		 *  are present in the device's audio stream for basic control, such as per-channel volume. See the USB Audio
		 *  specification for more details.
		 *
		 *  \see \ref USB_Audio_Descriptor_FeatureUnit_t for the version of this type with non-standard LUFA specific
		 *       element names.
		 */
		typedef struct
		{
			uint8_t bLength; /**< Size of the descriptor, in bytes. */
			uint8_t bDescriptorType; /**< Type of the descriptor, either a value in \ref USB_DescriptorTypes_t or a value
			                          *   given by the specific class.
			                          */

			uint8_t bDescriptorSubtype; /**< Sub type value used to distinguish between audio class-specific descriptors,
			                             *   must be \ref AUDIO_DSUBTYPE_CSInterface_Feature.
			                             */

			uint8_t bUnitID; /**< ID value of this feature unit - must be a unique value within the device. */
			uint8_t bSourceID; /**< Source ID value of the audio source input into this feature unit. */

			uint8_t bControlSize; /**< Size of each element in the ChanelControlls array. */
			uint8_t bmaControls[3]; /**< Feature masks for the control channel, and each separate audio channel. */

			uint8_t iFeature; /**< Index of a string descriptor describing this descriptor within the device. */
		} USB_Audio_StdDescriptor_FeatureUnit_t;

		/** \brief Audio class-specific Streaming Audio Interface Descriptor (LUFA naming conventions).
		 *
		 *  Type define for an Audio class-specific streaming interface descriptor. This indicates to the host
		 *  how audio streams within the device are formatted. See the USB Audio specification for more details.
		 *
		 *  \see \ref USB_Audio_StdDescriptor_Interface_AS_t for the version of this type with standard element names.
		 */
		typedef struct
		{
			USB_Descriptor_Header_t Header; /**< Regular descriptor header containing the descriptor's type and length. */
			uint8_t                 Subtype; /**< Sub type value used to distinguish between audio class-specific descriptors,
			                                  *   a value from the \ref Audio_CSInterface_AS_SubTypes_t enum.
			                                  */

			uint8_t                 TerminalLink; /**< ID value of the output terminal this descriptor is describing. */

			uint8_t                 FrameDelay; /**< Delay in frames resulting from the complete sample processing from input to output. */
			uint16_t                AudioFormat; /**< Format of the audio stream, see Audio Device Formats specification. */
		} USB_Audio_Descriptor_Interface_AS_t;

		/** \brief Audio class-specific Streaming Audio Interface Descriptor (USB-IF naming conventions).
		 *
		 *  Type define for an Audio class-specific streaming interface descriptor. This indicates to the host
		 *  how audio streams within the device are formatted. See the USB Audio specification for more details.
		 *
		 *  \see \ref USB_Audio_Descriptor_Interface_AS_t for the version of this type with non-standard LUFA specific
		 *       element names.
		 */
		typedef struct
		{
			uint8_t  bLength; /**< Size of the descriptor, in bytes. */
			uint8_t  bDescriptorType; /**< Type of the descriptor, either a value in \ref USB_DescriptorTypes_t or a value
			                           *   given by the specific class.
			                           */

			uint8_t  bDescriptorSubtype; /**< Sub type value used to distinguish between audio class-specific descriptors,
			                              *   a value from the \ref Audio_CSInterface_AS_SubTypes_t enum.
			                              */

			uint8_t  bTerminalLink; /**< ID value of the output terminal this descriptor is describing. */

			uint8_t  bDelay; /**< Delay in frames resulting from the complete sample processing from input to output. */
			uint16_t wFormatTag; /**< Format of the audio stream, see Audio Device Formats specification. */
		} USB_Audio_StdDescriptor_Interface_AS_t;

		/** \brief 24-Bit Audio Frequency Structure.
		 *
		 *  Type define for a 24bit audio sample frequency structure. GCC does not contain a built in 24bit datatype,
		 *  this this structure is used to build up the value instead. Fill this structure with the \ref AUDIO_SAMPLE_FREQ() macro.
		 */
		typedef struct
		{
			uint16_t LowWord; /**< Low 16 bits of the 24-bit value. */
			uint8_t  HighByte; /**< Upper 8 bits of the 24-bit value. */
		} USB_Audio_SampleFreq_t;

		/** \brief Audio class-specific Format Descriptor (LUFA naming conventions).
		 *
		 *  Type define for an Audio class-specific audio format descriptor. This is used to give the host full details
		 *  about the number of channels, the sample resolution, acceptable sample frequencies and encoding method used
		 *  in the device's audio streams. See the USB Audio specification for more details.
		 *
		 *  \see \ref USB_Audio_StdDescriptor_Format_t for the version of this type with standard element names.
		 */
		typedef struct
		{
			USB_Descriptor_Header_t Header; /**< Regular descriptor header containing the descriptor's type and length. */
			uint8_t                 Subtype; /**< Sub type value used to distinguish between audio class-specific descriptors,
			                                  *   must be \ref AUDIO_DSUBTYPE_CSInterface_FormatType.
			                                  */

			uint8_t                 FormatType; /**< Format of the audio stream, see Audio Device Formats specification. */
			uint8_t                 Channels; /**< Total number of discrete channels in the stream. */

			uint8_t                 SubFrameSize; /**< Size in bytes of each channel's sample data in the stream. */
			uint8_t                 BitResolution; /**< Bits of resolution of each channel's samples in the stream. */

			uint8_t                 SampleFrequencyType; /**< Total number of sample frequencies supported by the device. */
			USB_Audio_SampleFreq_t  SampleFrequencies[AUDIO_TOTAL_SAMPLE_RATES]; /**< Sample frequencies supported by the device (must be 24-bit). */
		} USB_Audio_Descriptor_Format_t;

		/** \brief Audio class-specific Format Descriptor (USB-IF naming conventions).
		 *
		 *  Type define for an Audio class-specific audio format descriptor. This is used to give the host full details
		 *  about the number of channels, the sample resolution, acceptable sample frequencies and encoding method used
		 *  in the device's audio streams. See the USB Audio specification for more details.
		 *
		 *  \see \ref USB_Audio_Descriptor_Format_t for the version of this type with non-standard LUFA specific
		 *       element names.
		 */
		typedef struct
		{
			uint8_t bLength; /**< Size of the descriptor, in bytes. */
			uint8_t bDescriptorType; /**< Sub type value used to distinguish between audio class-specific descriptors,
			                          *   must be \ref AUDIO_DSUBTYPE_CSInterface_FormatType.
			                          */

			uint8_t bDescriptorSubtype;/**< Sub type value used to distinguish between audio class-specific descriptors,
			                            *   a value from the \ref Audio_CSInterface_AS_SubTypes_t enum.
			                            */

			uint8_t bFormatType; /**< Format of the audio stream, see Audio Device Formats specification. */
			uint8_t bNrChannels; /**< Total number of discrete channels in the stream. */

			uint8_t bSubFrameSize; /**< Size in bytes of each channel's sample data in the stream. */
			uint8_t bBitResolution; /**< Bits of resolution of each channel's samples in the stream. */

			uint8_t bSampleFrequencyType; /**< Total number of sample frequencies supported by the device. */
			uint8_t SampleFrequencies[AUDIO_TOTAL_SAMPLE_RATES * 3]; /**< Sample frequencies supported by the device (must be 24-bit). */
		} USB_Audio_StdDescriptor_Format_t;

		/** \brief Audio class-specific Streaming Endpoint Descriptor (LUFA naming conventions).
		 *
		 *  Type define for an Audio class-specific endpoint descriptor. This contains a regular endpoint
		 *  descriptor with a few Audio-class-specific extensions. See the USB Audio specification for more details.
		 *
		 *  \see \ref USB_Audio_StdDescriptor_StreamEndpoint_Std_t for the version of this type with standard element names.
		 */
		typedef struct
		{
			USB_Descriptor_Endpoint_t Endpoint; /**< Standard endpoint descriptor describing the audio endpoint. */

			uint8_t                   Refresh; /**< Always set to zero for Audio class devices. */
			uint8_t                   SyncEndpointNumber; /**< Endpoint address to send synchronization information to, if needed (zero otherwise). */
		} USB_Audio_Descriptor_StreamEndpoint_Std_t;

		/** \brief Audio class-specific Streaming Endpoint Descriptor (USB-IF naming conventions).
		 *
		 *  Type define for an Audio class-specific endpoint descriptor. This contains a regular endpoint
		 *  descriptor with a few Audio-class-specific extensions. See the USB Audio specification for more details.
		 *
		 *  \see \ref USB_Audio_Descriptor_StreamEndpoint_Std_t for the version of this type with non-standard LUFA specific
		 *       element names.
		 */
		typedef struct
		{
			uint8_t  bLength; /**< Size of the descriptor, in bytes. */
			uint8_t  bDescriptorType; /**< Type of the descriptor, either a value in \ref USB_DescriptorTypes_t or a
			                           *   value given by the specific class.
			                           */
			uint8_t  bEndpointAddress; /**< Logical address of the endpoint within the device for the current
			                            *   configuration, including direction mask.
			                            */
			uint8_t  bmAttributes; /**< Endpoint attributes, comprised of a mask of the endpoint type (EP_TYPE_*)
			                        *   and attributes (ENDPOINT_ATTR_*) masks.
			                        */
			uint16_t wMaxPacketSize; /**< Size of the endpoint bank, in bytes. This indicates the maximum packet size
			                          *   that the endpoint can receive at a time.
			                          */
			uint8_t  bInterval; /**< Polling interval in milliseconds for the endpoint if it is an INTERRUPT or
			                     *   ISOCHRONOUS type.
			                     */

			uint8_t  bRefresh; /**< Always set to zero for Audio class devices. */
			uint8_t  bSynchAddress; /**< Endpoint address to send synchronization information to, if needed (zero otherwise). */
		} USB_Audio_StdDescriptor_StreamEndpoint_Std_t;

		/** \brief Audio class-specific Extended Endpoint Descriptor (LUFA naming conventions).
		 *
		 *  Type define for an Audio class-specific extended endpoint descriptor. This contains extra information
		 *  on the usage of endpoints used to stream audio in and out of the USB Audio device, and follows an Audio
		 *  class-specific extended endpoint descriptor. See the USB Audio specification for more details.
		 *
		 *  \see \ref USB_Audio_StdDescriptor_StreamEndpoint_Spc_t for the version of this type with standard element names.
		 */
		typedef struct
		{
			USB_Descriptor_Header_t Header; /**< Regular descriptor header containing the descriptor's type and length. */
			uint8_t                 Subtype; /**< Sub type value used to distinguish between audio class-specific descriptors,
			                                  *   a value from the \ref Audio_CSEndpoint_SubTypes_t enum.
			                                  */

			uint8_t                 Attributes; /**< Audio class-specific endpoint attributes, such as ACCEPTS_SMALL_PACKETS. */

			uint8_t                 LockDelayUnits; /**< Units used for the LockDelay field, see Audio class specification. */
			uint16_t                LockDelay; /**< Time required to internally lock endpoint's internal clock recovery circuitry. */
		} USB_Audio_Descriptor_StreamEndpoint_Spc_t;

		/** \brief Audio class-specific Extended Endpoint Descriptor (USB-IF naming conventions).
		 *
		 *  Type define for an Audio class-specific extended endpoint descriptor. This contains extra information
		 *  on the usage of endpoints used to stream audio in and out of the USB Audio device, and follows an Audio
		 *  class-specific extended endpoint descriptor. See the USB Audio specification for more details.
		 *
		 *  \see \ref USB_Audio_Descriptor_StreamEndpoint_Spc_t for the version of this type with non-standard LUFA specific
		 *       element names.
		 */
		typedef struct
		{
			uint8_t  bLength; /**< Size of the descriptor, in bytes. */
			uint8_t  bDescriptorType; /**< Type of the descriptor, either a value in \ref USB_DescriptorTypes_t or a value
			                           *   given by the specific class.
			                           */

			uint8_t  bDescriptorSubtype; /**< Sub type value used to distinguish between audio class-specific descriptors,
			                              *   a value from the \ref Audio_CSEndpoint_SubTypes_t enum.
			                              */

			uint8_t  bmAttributes; /**< Audio class-specific endpoint attributes, such as ACCEPTS_SMALL_PACKETS. */

			uint8_t  bLockDelayUnits; /**< Units used for the LockDelay field, see Audio class specification. */
			uint16_t wLockDelay; /**< Time required to internally lock endpoint's internal clock recovery circuitry. */
		} USB_Audio_StdDescriptor_StreamEndpoint_Spc_t;

	/* Disable C linkage for C++ Compilers: */
		#if defined(__cplusplus)
			}
		#endif

#endif

/** @} */

