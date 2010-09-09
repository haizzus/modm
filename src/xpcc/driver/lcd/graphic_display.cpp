// coding: utf-8
// ----------------------------------------------------------------------------
/* Copyright (c) 2009, Roboterclub Aachen e.V.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the Roboterclub Aachen e.V. nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY ROBOTERCLUB AACHEN E.V. ''AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL ROBOTERCLUB AACHEN E.V. BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * $Id$
 */
// ----------------------------------------------------------------------------

#include "graphic_display.hpp"

void
xpcc::GraphicDisplay::drawLine(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2)
{
	// TODO: Bresenham
}

void
xpcc::GraphicDisplay::drawHorizontalLine(uint8_t x1, uint8_t y1, uint8_t length)
{
	this->drawLine(x1, y1, x1 + length, y1);
}

void
xpcc::GraphicDisplay::drawVerticalLine(uint8_t x1, uint8_t y1, uint8_t length)
{
	this->drawLine(x1, y1, x1, y1 + length);
}

void
xpcc::GraphicDisplay::drawRectangle(uint8_t x, uint8_t y,
		uint8_t width, uint8_t height)
{
	uint8_t x2 = x + width;
	uint8_t y2 = y + height;
	
	this->drawHorizontalLine(x, y,  width);
	this->drawHorizontalLine(x, y2, width);
	this->drawVerticalLine(x,  y, height);
	this->drawVerticalLine(x2, y, height);
}

void
xpcc::GraphicDisplay::drawRoundedRectangle(uint8_t x, uint8_t y,
		uint8_t width, uint8_t height)
{
	uint8_t x2 = x + width;
	uint8_t y2 = y + height;
	
	this->drawHorizontalLine(x + 2, y,  width - 4);
	this->drawHorizontalLine(x + 2, y2, width - 4);
	this->drawVerticalLine(x,  y + 2, height - 4);
	this->drawVerticalLine(x2, y + 2, height - 4);
	
	this->setPixel(x + 1,  y + 1);
	this->setPixel(x + 1,  y2 - 1);
	this->setPixel(x2 - 1, y + 1);
	this->setPixel(x2 - 1, y2 - 1);
}
