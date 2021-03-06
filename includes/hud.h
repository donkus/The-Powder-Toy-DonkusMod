
#ifndef HUD_H
#define HUD_H

#include "graphics.h"

void HudDefaults();
void SetCurrentHud();

void SetRightHudText(int x, int y);
void SetLeftHudText(float FPSB2);
void DrawHud(int introTextAlpha, int qTipAlpha);
void DrawPhotonWavelengths(pixel *vid, int x, int y, int h, int wl);

void DrawRecordsInfo();

void DrawLuaLogs();

void GetTimeString(int currtime, char *string, int length);

struct hud
{
	const char *name;
	pixel color;
	int menunum;
	const char *description;
};
typedef struct hud hud;

const hud hud_menu[] =
{
	{"BACK",   PIXPACK(0xFF7F00), 0, "Go Back"},
	{"UI",     PIXPACK(0x20D8FF), 0, "Change the HUD on the left"},
	{"INFO",   PIXPACK(0xFFFFFF), 0, "Change the top right HUD with particle properties"},
	{"CORD",   PIXPACK(0xFFFFFF), 0, "Change the bottom right HUD with corrdinate info"},
	{"RSET",   PIXPACK(0xFF8A08), 0, "Resets the HUDs back to their default values"},

	{"VERS", PIXPACK(0x000000), 1, "The version number"},
	{"BLD",  PIXPACK(0x000000), 1, "The current build number"},
	{"FPS",  PIXPACK(0x000000), 1, "Show the current frames per second"},
	{"FPS#", PIXPACK(0x000000), 1, "Show FPS to "},
	{"PART", PIXPACK(0x000000), 1, "The number of particles on the screen"},
	{"GEN",  PIXPACK(0x000000), 1, "The current life generation"},
	{"GRAV", PIXPACK(0x000000), 1, "Shows the current gravity mode, changed by pressing w"},
	{"AIR",  PIXPACK(0x000000), 1, "Shows the current air mode, change it with y"},
	{"XTRA", PIXPACK(0x000000), 1, "Shows whether replace mode or specific delete are activated"},
	{"GRID", PIXPACK(0x000000), 1, "Adds the current grid mode to the end, when it's activated."},
	
	//10
	{"NAME", PIXPACK(0x000000), 2, "Why would you want to disable this?"},
	{"CTYP", PIXPACK(0x000000), 2, "Puts the ctype in parentheses"},
	{"CTP2", PIXPACK(0x000000), 2, "Display invalid ctypes as numbers instead of showing no ctype"},
	{"MOLT", PIXPACK(0x000000), 2, "Molten [NAME] instead of name & ctype, also special FILT mode info"},
	{"PIPE", PIXPACK(0x000000), 2, "PIPE ([NAME]) instead of name & not useful ctype"},
	{"CELC", PIXPACK(0x000000), 2, "Show temperatures in Celsius"},
	{"FARH", PIXPACK(0x000000), 2, "Show temperatures in Fahrenheit"},
	{"KELV", PIXPACK(0x000000), 2, "Show temperatures in Kelvin"},
	{"TEM#", PIXPACK(0x000000), 2, "Show all temperatures to "},
	{"LIFE", PIXPACK(0x000000), 2, "Show a particle's life value"},
	{"TMP",  PIXPACK(0x000000), 2, "Show a particle's tmp value"},
	{"TMP2", PIXPACK(0x000000), 2, "Show a particle's tmp2 value"},
	{"CORD", PIXPACK(0x000000), 2, "Show a particle's exact coordinates"},
	{"CRD#", PIXPACK(0x000000), 2, "Show x and y coordinates to "},
	{"VEL",  PIXPACK(0x000000), 2, "Show a particle's x and y velocities"},
	{"VEL#", PIXPACK(0x000000), 2, "Show x and y velocities to "},
	{"PRES", PIXPACK(0x000000), 2, "Show the pressure"},
	{"PRS#", PIXPACK(0x000000), 2, "Show pressure to "},
	
	//28
	{"INDX", PIXPACK(0x000000), 3, "The index of a particle"},
	{"MCRD", PIXPACK(0x000000), 3, "Shows the mouse coordinates"},
	{"GRAV", PIXPACK(0x000000), 3, "Shows the gravity at a spot if Newtonian gravity is enabled"},
	{"GRV#", PIXPACK(0x000000), 3, "Show gravity to "},
	{"PRES", PIXPACK(0x000000), 3, "Show the pressure"},
	{"PRS#", PIXPACK(0x000000), 3, "Show pressure to "},
	{"AMB",  PIXPACK(0x000000), 3, "Show the ambient heat"},
	{"AMB#", PIXPACK(0x000000), 3, "Show ambient heat to "},

	//36
	{"DAY",  PIXPACK(0x000000), 1, "Show the weekday, month, and day"},
	{"TIME", PIXPACK(0x000000), 1, "Show the time of day"},
	{"YEAR", PIXPACK(0x000000), 1, "Show the year"},
	{"TIME", PIXPACK(0x000000), 1, "The time played since The Powder Toy was started"},
	{"TTME", PIXPACK(0x000000), 1, "The total time played ever"},
	{"AFPS", PIXPACK(0x000000), 1, "Show the average FPS"},
	{"AFS#", PIXPACK(0x000000), 1, "Show the average FPS to "},
	//43
	{"VEL",	 PIXPACK(0x000000), 3, "Show the velocity"},
	{"VEL#", PIXPACK(0x000000), 3, "Show velocity to "},
	{"PHOT", PIXPACK(0x000000), 2, "Show the color of PHOT, FILT, and BIZR wavelengths"},
	{"DECO", PIXPACK(0x000000), 2, "Show the decoration color"},
	{"FLAG", PIXPACK(0x000000), 2, "Show the flags (mostly unused)"},
	{"WALL", PIXPACK(0x000000), 2, "Show wall names"},
	{"LIFE", PIXPACK(0x000000), 2, "Show the name of life particles instead of LIFE([NAME])"},
	{"FILT", PIXPACK(0x000000), 2, "Show FILT tmp modes in the HUD"},
	{"PAVG", PIXPACK(0x000000), 2, "Show pavg[0] and pavg[1], used by VIRS and PIPE to store extra info"},
	{"EMAP", PIXPACK(0x000000), 3, "Show the value of emap, used in conductive walls"},
};

#define HUD_START 400
#define HUD_REALSTART 405
#define HUD_NUM 58
#define HUD_OPTIONS 53

extern int currentHud[HUD_OPTIONS];
extern int normalHud[HUD_OPTIONS];
extern int debugHud[HUD_OPTIONS];

#endif
