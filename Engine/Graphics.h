/******************************************************************************************
*	Chili DirectX Framework Version 16.07.20											  *
*	Graphics.h																			  *
*	Copyright 2016 PlanetChili <http://www.planetchili.net>								  *
*																						  *
*	This file is part of The Chili DirectX Framework.									  *
*																						  *
*	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
*	it under the terms of the GNU General Public License as published by				  *
*	the Free Software Foundation, either version 3 of the License, or					  *
*	(at your option) any later version.													  *
*																						  *
*	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
*	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
*	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
*	GNU General Public License for more details.										  *
*																						  *
*	You should have received a copy of the GNU General Public License					  *
*	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
******************************************************************************************/
#pragma once
#include <vector>
#include <d3d11.h>
#include <wrl.h>
#include "ChiliException.h"
#include "Colors.h"
#include "Surface.h"
#include "Rect.h"
//#include <iterator>



class Graphics
{
public:
	class Exception : public ChiliException
	{
	public:
		Exception( HRESULT hr,const std::wstring& note,const wchar_t* file,unsigned int line );
		std::wstring GetErrorName() const;
		std::wstring GetErrorDescription() const;
		virtual std::wstring GetFullMessage() const override;
		virtual std::wstring GetExceptionType() const override;
	private:
		HRESULT hr;
	};
private:
	// vertex format for the framebuffer fullscreen textured quad
	struct FSQVertex
	{
		float x,y,z;		// position
		float u,v;			// texcoords
	};
public:
	Graphics( class HWNDKey& key );
	Graphics( const Graphics& ) = delete;
	Graphics& operator=( const Graphics& ) = delete;
	void EndFrame();
	void BeginFrame();
	void PutPixel( int x,int y,int r,int g,int b )
	{
		PutPixel( x,y,{ unsigned char( r ),unsigned char( g ),unsigned char( b ) } );
	}
	void PutPixel( int x,int y,Color c );
	void DrawRect(int x0, int y0, int x1, int y1, Color c);
	void DrawRect(float x, float y, Vec2f min, Vec2f max,Rect clipping, Color c);
	void DrawRectDim(int x0, int y0, int width, int height, Color c)
	{
		DrawRect(x0, y0, x0 + width, y0 + height, c);
	}
	void DrawSprite(int x, int y, const Surface& s);
	void DrawSprite(int x, int y, const Surface& s, Color chroma);
	void DrawSprite(int x, int y,const Rect& rect, const Surface& s, Color chroma);
	void DrawLine(Vec2i lhs, Vec2i rhs, Color color);
	void DrawLine(Vec2f lhs, Vec2f rhs, Color color);
	void DrawClosedPolyline(const std::vector<Vec2f>& verts, Color c);
	void DrawSprite(int x, int y, Rect rect, const Rect& clipping, const Surface& s)
	{
		if (x + rect.GetWidth() > clipping.right)
		{
			//rect.left=rect.left + x;
			rect.right -= x + rect.GetWidth() - clipping.right;

		}
		if (x < clipping.left)
		{
			rect.left += clipping.left - x;
			x = clipping.left;
		}
		if (y < clipping.top)
		{
			rect.top += clipping.top - y;
			y = clipping.top;
		}
		if (y + rect.GetHeight() > clipping.bottom)
		{
			//rect.bottom = rect.GetHeight() -  (clipping.bottom-y);
			rect.bottom -= rect.GetHeight() + y - clipping.bottom;
		}
		for (int sy = rect.top; sy < rect.bottom; sy++)
		{
			for (int sx = rect.left; sx < rect.right; sx++)

			{
				PutPixel(
					x + sx - rect.left,
					y + sy - rect.top,
					s.GetPixel(sx, sy)

				);
			}
		}
	}
	template<typename E>
	void DrawSprite(int x, int y, Rect rect, const Rect& clipping, const Surface& s, E effect)
	{
		if (x + rect.GetWidth() > clipping.right)
		{
			//rect.left=rect.left + x;
			rect.right -= x + rect.GetWidth() - clipping.right;

		}
		if (x < clipping.left)
		{
			rect.left += clipping.left - x;
			x = clipping.left;
		}
		if (y < clipping.top)
		{
			rect.top += clipping.top - y;
			y = clipping.top;
		}
		if (y + rect.GetHeight() > clipping.bottom)
		{
			//rect.bottom = rect.GetHeight() -  (clipping.bottom-y);
			rect.bottom -= rect.GetHeight() + y - clipping.bottom;
		}
		for (int sy = rect.top; sy < rect.bottom; sy++)
		{
			for (int sx = rect.left; sx < rect.right; sx++)

			{
				effect(s.GetPixel(sx, sy),
					x + sx - rect.left,
					y + sy - rect.top,
					*this

				);
			}
		}
	}

	
	

	~Graphics();
private:
	Microsoft::WRL::ComPtr<IDXGISwapChain>				pSwapChain;
	Microsoft::WRL::ComPtr<ID3D11Device>				pDevice;
	Microsoft::WRL::ComPtr<ID3D11DeviceContext>			pImmediateContext;
	Microsoft::WRL::ComPtr<ID3D11RenderTargetView>		pRenderTargetView;
	Microsoft::WRL::ComPtr<ID3D11Texture2D>				pSysBufferTexture;
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView>	pSysBufferTextureView;
	Microsoft::WRL::ComPtr<ID3D11PixelShader>			pPixelShader;
	Microsoft::WRL::ComPtr<ID3D11VertexShader>			pVertexShader;
	Microsoft::WRL::ComPtr<ID3D11Buffer>				pVertexBuffer;
	Microsoft::WRL::ComPtr<ID3D11InputLayout>			pInputLayout;
	Microsoft::WRL::ComPtr<ID3D11SamplerState>			pSamplerState;
	D3D11_MAPPED_SUBRESOURCE							mappedSysBufferTexture;
	Color*                                              pSysBuffer = nullptr;
public:
	static constexpr int ScreenWidth = 800;
	static constexpr int ScreenHeight = 600;
};