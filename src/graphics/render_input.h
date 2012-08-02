/************************************************************************/
/*                                                                      */
/* This file is part of VDrift.                                         */
/*                                                                      */
/* VDrift is free software: you can redistribute it and/or modify       */
/* it under the terms of the GNU General Public License as published by */
/* the Free Software Foundation, either version 3 of the License, or    */
/* (at your option) any later version.                                  */
/*                                                                      */
/* VDrift is distributed in the hope that it will be useful,            */
/* but WITHOUT ANY WARRANTY; without even the implied warranty of       */
/* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the        */
/* GNU General Public License for more details.                         */
/*                                                                      */
/* You should have received a copy of the GNU General Public License    */
/* along with VDrift.  If not, see <http://www.gnu.org/licenses/>.      */
/*                                                                      */
/************************************************************************/

#ifndef _RENDER_INPUT_H
#define _RENDER_INPUT_H

#include <ostream>

class GLSTATEMANAGER;
struct FRUSTUM;

/// supported blend modes
namespace BLENDMODE
{
enum BLENDMODE
{
	DISABLED,
	ADD,
	ALPHABLEND,
	PREMULTIPLIED_ALPHA,
	ALPHATEST
};
}

/// purely abstract base class
class RENDER_INPUT
{
public:
	virtual void Render(GLSTATEMANAGER & glstate, std::ostream & error_output) = 0;

	/// get frustum from current mjp matrix
	static void ExtractFrustum(FRUSTUM & frustum);

	/// transform the shadow matrices in texture4-6 by the inverse of the camera transform in texture3
	static void PushShadowMatrices();

	static void PopShadowMatrices();
};

#endif //_RENDER_INPUT_H