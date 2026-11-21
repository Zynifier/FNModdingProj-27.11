// Copyright Epic Games, Inc. All Rights Reserved.

#include "Modules/ModuleManager.h"
#include "Interfaces/ITextureFormat.h"
#include "Interfaces/ITextureFormatModule.h"

class FOodleDXTTextureFormatModule : public ITextureFormatModule
{
public:
	virtual ~FOodleDXTTextureFormatModule()
	{
		delete Singleton;
		Singleton = nullptr;
	}

	virtual void StartupModule() override
	{
	}

	virtual ITextureFormat* GetTextureFormat() override
	{
		return Singleton;
	}

	virtual bool CanCallGetTextureFormats() override
	{
		return false;
	}

private:
	ITextureFormat* Singleton = nullptr;
};

IMPLEMENT_MODULE(FOodleDXTTextureFormatModule, OodleDXTTextureFormat);
