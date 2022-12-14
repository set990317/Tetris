#include "stdafx.h"
#include "myTetris.h"

Point blockPattern[MY_PATTERN_NUM][4][4] = {
{	{0,1,1,0,1,1,2,1},
	{0,1,1,0,1,1,1,2},
	{0,0,1,0,1,1,2,0},
	{0,0,0,1,0,2,1,1}},

{	{0,0,1,0,2,0,2,1},
	{0,0,0,1,0,2,1,0},
	{0,0,0,1,1,1,2,1},
	{0,2,1,0,1,1,1,2}},

{	{0,0,1,0,2,0,3,0},
	{0,0,0,1,0,2,0,3},
	{0,0,1,0,2,0,3,0},
	{0,0,0,1,0,2,0,3}},

{	{0,0,0,1,1,0,1,1},
	{0,0,0,1,1,0,1,1},
	{0,0,0,1,1,0,1,1},
	{0,0,0,1,1,0,1,1}},

{	{0,0,0,1,1,0,2,0},
	{0,0,0,1,0,2,1,2},
	{0,1,1,1,2,0,2,1},
	{0,0,1,0,1,1,1,2}}, 
{	{0,0,0,0,0,0,0,0},
	{ 0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0 }
}

};

Point blockPattern2[MY_PATTERN_NUM][4][4] = {
	
{ { 0,1,1,0,1,1,2,1 },
{ 0,1,1,0,1,1,1,2 },
{ 0,0,1,0,1,1,2,0 },
{ 0,0,0,1,0,2,1,1 } },

{ { 0,0,1,0,2,0,2,1 },
{ 0,0,0,1,0,2,1,0 },
{ 0,0,0,1,1,1,2,1 },
{ 0,2,1,0,1,1,1,2 } },

{ { 0,0,1,0,2,0,3,0 },
{ 0,0,0,1,0,2,0,3 },
{ 0,0,1,0,2,0,3,0 },
{ 0,0,0,1,0,2,0,3 } },

{ { 0,0,0,1,1,0,1,1 },
{ 0,0,0,1,1,0,1,1 },
{ 0,0,0,1,1,0,1,1 },
{ 0,0,0,1,1,0,1,1 } },

{ { 0,0,0,1,1,0,2,0 },
{ 0,0,0,1,0,2,1,2 },
{ 0,1,1,1,2,0,2,1 },
{ 0,0,1,0,1,1,1,2 } }

};

