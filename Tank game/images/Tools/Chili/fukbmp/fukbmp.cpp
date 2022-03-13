#include <windows.h>
#include <gdiplus.h>
#include <stdio.h>

using namespace Gdiplus;

const wchar_t* name = L"poo";

int main()
{
	GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR           gdiplusToken;
	GdiplusStartup( &gdiplusToken,&gdiplusStartupInput,NULL );

	int pathlen = wcslen( name ) + 4;
	wchar_t* txtpath = new wchar_t[ pathlen + 1 ];
	wcscpy( txtpath,name );
	wcscat( txtpath,L".txt" );
	wchar_t* bmppath = new wchar_t[ pathlen + 1 ];
	wcscpy( bmppath,name );
	wcscat( bmppath,L".bmp" );
	
	FILE* sprite = _wfopen( txtpath,L"w" );
	Bitmap bitmap( bmppath );
	Color alphakey( 255,255,255 );
	Color pixel;

	for( int y = 0; y < bitmap.GetHeight(); y++ )
	{
		for( int x = 0; x < bitmap.GetWidth(); x++ )
		{
			bitmap.GetPixel( x,y,&pixel );
			if( pixel.GetValue() != alphakey.GetValue() )
			{
				fprintf( sprite,"gfx.PutPixel( %d + x,%d + y,%d,%d,%d );\n",x,y,pixel.GetR(),pixel.GetG(),pixel.GetB() );
			}
		}
	}

	fclose( sprite );

	return 0;
}
