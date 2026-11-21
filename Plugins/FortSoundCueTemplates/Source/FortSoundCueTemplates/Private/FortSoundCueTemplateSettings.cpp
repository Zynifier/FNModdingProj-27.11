// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortSoundCueTemplateSettings.h"
#include "FortSoundCueTemplateBase.h"

void UFortSoundCueTemplateDefaultSettings::PreSave(FObjectPreSaveContext ObjectSaveContext)
{
	Super::PreSave(ObjectSaveContext);
	SortTemplateDefaults();
}

void UFortSoundCueTemplateDefaultSettings::PostLoad()
{
	Super::PostLoad();
	SortTemplateDefaults();
}

UFortSoundCueTemplateDefaults* UFortSoundCueTemplateDefaultSettings::GetSettingsForTemplateType(TSubclassOf<UFortSoundCueTemplateBase> TemplateType)
{
	return TemplateDefaults.FindRef(TemplateType);
}

void UFortSoundCueTemplateDefaultSettings::SortTemplateDefaults()
{
	TemplateDefaults.Remove(nullptr);
	TemplateDefaults.KeySort([](const TSubclassOf<UFortSoundCueTemplateBase>& A, const TSubclassOf<UFortSoundCueTemplateBase>& B)
	{
		if (!*A || !*B)
		{
			return false;
		}

		return A->GetFName().LexicalLess(B->GetFName());
	});
}

UFortSoundCueTemplateDefaults::UFortSoundCueTemplateDefaults(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	VolumeMultiplier = 1.0f;
	PitchMultiplier = 1.0f;
}

UFortSoundCueTemplateDefaults* UFortSoundCueTemplateSettings::GetDefaultSettingsForTemplateType(TSubclassOf<UFortSoundCueTemplateBase> TemplateType) const
{
	if (UFortSoundCueTemplateDefaultSettings* DefaultSettings = DefaultTemplateSettings.LoadSynchronous())
	{
		return DefaultSettings->GetSettingsForTemplateType(TemplateType);
	}

	return nullptr;
}
