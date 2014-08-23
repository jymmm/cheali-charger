/*
    Serial - wrapper for Hardware OR Software serial library (transmit only)
    Copyright (c) 2014 Sasa Mihajlovic.  All right reserved.

    cheali-charger - open source firmware for a variety of LiPo chargers
    Copyright (C) 2013  Paweł Stawicki. All right reserved.

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef Serial_H_
#define Serial_H_

#ifdef TX_HW_SERIAL
#include "TxHardSerial.h"
#else
#include "TxSoftSerial.h"
#endif

namespace Serial {
#ifdef TX_HW_SERIAL
    inline void  begin(unsigned long baud) { TxHardSerial::begin(baud); };
    inline void  write(uint8_t c) { TxHardSerial::write(c); }
    inline void  flush() { TxHardSerial::flush()}
    inline void  end() { TxHardSerial::end() }
    inline void  initialize() { TxHardSerial::initialize() }
#else
    inline void  begin(unsigned long baud) { TxSoftSerial::begin(baud); };
    inline void  write(uint8_t c) { TxSoftSerial::write(c); }
    inline void  flush() { TxSoftSerial::flush(); }
    inline void  end() { TxSoftSerial::end(); }
    inline void  initialize() { TxSoftSerial::initialize(); }
#endif
	} // namespace Serial

#endif //  Serial_H_

