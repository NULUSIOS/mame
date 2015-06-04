// license:BSD-3-Clause
// copyright-holders:Olivier Galibert
/***************************************************************************

    m6504.h

    Mostek 6502, NMOS variant with reduced address bus

***************************************************************************/

#ifndef __M6504_H__
#define __M6504_H__

#include "m6502.h"

class m6504_device : public m6502_device {
public:
	m6504_device(const machine_config &mconfig, const char *tag, device_t *owner, UINT32 clock);

protected:
	class mi_6504_normal : public memory_interface {
	public:
		virtual ~mi_6504_normal() {}
		virtual UINT8 read(UINT16 adr);
		virtual UINT8 read_direct(UINT16 adr);
		virtual UINT8 read_decrypted(UINT16 adr);
		virtual void write(UINT16 adr, UINT8 val);
	};

	class mi_6504_nd : public mi_6504_normal {
	public:
		virtual ~mi_6504_nd() {}
		virtual UINT8 read_direct(UINT16 adr);
		virtual UINT8 read_decrypted(UINT16 adr);
	};

	virtual void device_start();
};


enum {
	M6504_IRQ_LINE = m6502_device::IRQ_LINE,
	M6504_NMI_LINE = m6502_device::NMI_LINE,
	M6504_SET_OVERFLOW = m6502_device::V_LINE,
};

extern const device_type M6504;

#endif