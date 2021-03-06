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

int BTRY_update(UPDATE_FUNC_ARGS)
{
	int r, rx, ry, rt;
	//if (parts[i].tmp)
	//	update_POWERED(UPDATE_FUNC_SUBCALL_ARGS);
	for (rx=-2; rx<3; rx++)
		for (ry=-2; ry<3; ry++)
			if (BOUNDS_CHECK && (rx || ry) && abs(rx)+abs(ry) < 4)
			{
				r = pmap[y+ry][x+rx];
				if (!r)
					continue;
				rt = (r&0xFF);
				if (parts_avg(i,r>>8,PT_INSL) != PT_INSL)
				{
					if (/*(parts[i].tmp == 0 || (parts[i].ctype != 0 && parts[i].life >= 10)) &&*/ (ptypes[rt].properties&PROP_CONDUCTS) /*&& !((rt==PT_METL||rt==PT_PSCN||rt==PT_NSCN)&&parts[i].tmp)*/ && !(rt==PT_WATR||rt==PT_SLTW||rt==PT_NTCT||rt==PT_PTCT||rt==PT_INWR) && parts[r>>8].life==0)
					{
						sim->spark_conductive(r>>8, x+rx, y+ry);
						//if (parts[i].ctype)
						//	parts[i].ctype--;
					}
					/*if (parts[i].ctype < parts[i].tmp && rt == PT_SPRK && parts[r>>8].ctype == PT_METL && parts[r>>8].life == 3)
					{
						parts[i].ctype++;
					}*/
				}
			}
	return 0;
}

void BTRY_init_element(ELEMENT_INIT_FUNC_ARGS)
{
	elem->Identifier = "DEFAULT_PT_BTRY";
	elem->Name = "BTRY";
	elem->Colour = COLPACK(0x858505);
	elem->MenuVisible = 1;
	elem->MenuSection = SC_ELEC;
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
	elem->Hardness = 1;

	elem->Weight = 100;

	elem->DefaultProperties.temp = R_TEMP+0.0f	+273.15f;
	elem->HeatConduct = 251;
	elem->Latent = 0;
	elem->Description = "Generates infinite electricity.";

	elem->State = ST_SOLID;
	elem->Properties = TYPE_SOLID;

	elem->LowPressureTransitionThreshold = IPL;
	elem->LowPressureTransitionElement = NT;
	elem->HighPressureTransitionThreshold = IPH;
	elem->HighPressureTransitionElement = NT;
	elem->LowTemperatureTransitionThreshold = ITL;
	elem->LowTemperatureTransitionElement = NT;
	elem->HighTemperatureTransitionThreshold = 2273.0f;
	elem->HighTemperatureTransitionElement = PT_PLSM;

	elem->Update = &BTRY_update;
	elem->Graphics = NULL;
	elem->Init = &BTRY_init_element;
}
