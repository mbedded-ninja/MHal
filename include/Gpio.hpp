//!
//! @file				Gpio.h
//! @author				Geoffrey Hunter <gbmhunter@gmail.com> (www.mbedded.ninja)
//! @created			2014-08-18
//! @last-modified		2014-10-24
//! @brief 				Hardware abstraction layer (HAL) for a GPIO pin.
//! @details
//!

#ifndef __cplusplus
	#error Please build with C++ compiler
#endif

//===============================================================================================//
//======================================== HEADER GUARD =========================================//
//===============================================================================================//

#ifndef MHAL_GPIO_H
#define MHAL_GPIO_H

//===============================================================================================//
//==================================== FORWARD DECLARATION ======================================//
//===============================================================================================//

namespace MbeddedNinja
{
	namespace MHalNs
	{
		class Gpio;
	}
}

//===============================================================================================//
//========================================== INCLUDES ===========================================//
//===============================================================================================//

//===== SYSTEM LIBRARIES =====//
#include <cstdint>		// int8_t, int32_t e.t.c

//===== USER LIBRARIES =====//
// none

//===== USER SOURCE =====//
// none

//===============================================================================================//
//======================================== NAMESPACE ============================================//
//===============================================================================================//

namespace MbeddedNinja
{

	namespace MHalNs
	{
		
		//! @brief		Hardware abstraction layer (HAL) for a GPIO pin.
		//! @details	This class is abstract.
		class Gpio
		{
			
		public:

			//! @brief		Enumerates all possible drive modes for a GPIO pin.
			//! @details	Used by SetDriveMode(). Note that the available options will be very platform specific.
			//!				All drive modes supported by PSoC microcontrollers are present.
			enum class DriveMode
			{
				//! Typical output drive mode. Most microcontrollers will support this.
				STRONG_DRIVE,
				//! Good drive mode for variable voltage rail operation. I2C uses this.
				OPEN_DRAIN_DRIVE_LOW,
				//! Not commonly used.
				OPEN_DRAIN_DRIVE_HIGH,
				RES_PULL_UP,
				RES_PULL_DOWN,
				RES_PULL_UPDOWN,
				//! Good for digital inputs
				HIGH_Z_DIGITAL,
				//! Good for analog inputs
				HIGH_Z_ANALOG
			};

			//======================================================================================//
			//==================================== PUBLIC METHODS ==================================//
			//======================================================================================//

			//! @brief		Virtual destructor.
			virtual ~Gpio(){}

			//! @brief		Sets the GPIO low or high.
			//! @param[in]	lowHigh		The boolean value you want to set the GPIO pin to.
			virtual void Write(bool setHigh) = 0;

			//! @brief		Toggles the GPIO (when set as an output).
			//! @details	This is useful in times when you want to do things such as flash an LED. Calls the Write() method.
			void Toggle();

			//! @brief		Reads the value of the pin.
			virtual bool Read() = 0;

			//! @brief		Sets the GPIO pin to the specified drive mode.
			//! @details	Raises an assert if the drive mode is not supported for a
			//!				particular platform.
			virtual void SetDriveMode(DriveMode driveMode) = 0;

			//======================================================================================//
			//================================= PUBLIC VARIABLES ===================================//
			//======================================================================================//

			// none

		private:

			//======================================================================================//
			//=================================== PRIVATE METHODS ==================================//
			//======================================================================================//

			// none

			//======================================================================================//
			//================================== PRIVATE VARIABLES =================================//
			//======================================================================================//

			// none

		protected:

			//======================================================================================//
			//=================================== PROTECTED METHODS ================================//
			//======================================================================================//

			//! @brief		Destructor.
			//! @details	Protected to enforce inheritance.
			Gpio(){};

			//======================================================================================//
			//================================== PROTECTED VARIABLES ===============================//
			//======================================================================================//

			//! @brief		Keeps track of the output state of the GPIO pin.
			bool isHigh;
			
		}; // class Gpio

	} // namespace MHalNs
} // namespace MbeddedNinja

#endif	// #ifndef MHAL_GPIO_H

// EOF
