// Copyright Epic Games, Inc. All Rights Reserved.

#include "Modules/ModuleManager.h"
#include "Interfaces/ITextureFormatModule.h"

// Stub module. The engine's texture format manager loads every module whose name contains
// "TextureFormat" and treats it as an ITextureFormatModule, so this stub must implement that
// interface (returning no format) instead of using FDefaultModuleImpl, which crashes at startup.
class FOodleDXTTextureFormatStubModule : public ITextureFormatModule
{
public:
	virtual ITextureFormat* GetTextureFormat() override
	{
		return nullptr;
	}

	virtual bool CanCallGetTextureFormats() override
	{
		return false;
	}
};

IMPLEMENT_MODULE(FOodleDXTTextureFormatStubModule, OodleDXTTextureFormat);
