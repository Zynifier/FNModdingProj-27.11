// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortSoundCueTemplateSettings.h"

UFortSoundCueTemplateDefaults* UFortSoundCueTemplateDefaultSettings::GetSettingsForTemplateType(TSubclassOf<UFortSoundCueTemplateBase> TemplateType)
{
	return nullptr;
}

UFortSoundCueTemplateDefaults* UFortSoundCueTemplateSettings::GetDefaultSettingsForTemplateType(TSubclassOf<UFortSoundCueTemplateBase> TemplateType) const
{
	return nullptr;
}
