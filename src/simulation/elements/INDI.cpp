/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "simulation/ElementsCommon.h"

void INDI_init_element(ELEMENT_INIT_FUNC_ARGS)
{
	elem->Identifier = "DEFAULT_PT_INDI";
	elem->Name = "INDI";
	elem->Colour = COLPACK(0xCCCCCC);
	elem->MenuVisible = 1;
	elem->MenuSection = SC_SPECIAL;
	elem->Enabled = 1;

	elem->Advection = 0.0f;
	elem->AirDrag = 0.00f * CFDS;
	elem->AirLoss = 0.90f;
	elem->Loss = 0.00f;
	elem->Collision = 0.0f;
	elem->Gravity = 0.0f;
	elem->Diffusion = 0.00f;
	elem->HotAir = 0.000f	* CFDS;
	elem->Falldown = 0;

	elem->Flammable = 0;
	elem->Explosive = 0;
	elem->Meltable = 0;
	elem->Hardness = 0;

	elem->Weight = 100;

	elem->DefaultProperties.temp = R_TEMP + 273.15f;
	elem->HeatConduct = 0;
	elem->Latent = 0;
	elem->Description = "Indestructible Insulator.";

	elem->State = ST_SOLID;
	elem->Properties = TYPE_SOLID|PROP_INDESTRUCTIBLE;

	elem->LowPressureTransitionThreshold = IPL;
	elem->LowPressureTransitionElement = NT;
	elem->HighPressureTransitionThreshold = 10.0f;
	elem->HighPressureTransitionElement = PT_BREL;
	elem->LowTemperatureTransitionThreshold = ITL;
	elem->LowTemperatureTransitionElement = NT;
	elem->HighTemperatureTransitionThreshold = 1273.0f;
	elem->HighTemperatureTransitionElement = PT_LAVA;

	elem->Update = NULL;
	elem->Graphics = NULL;
	elem->Init = &INDI_init_element;
}
