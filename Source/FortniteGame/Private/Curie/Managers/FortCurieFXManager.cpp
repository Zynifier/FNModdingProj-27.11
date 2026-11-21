// Copyright Epic Games, Inc. All Rights Reserved.

#include "Curie/Managers/FortCurieFXManager.h"
#include "UObject/Class.h"

bool FFortCurieAmbientAudioLocationKey::operator==(const FFortCurieAmbientAudioLocationKey& Other) const
{
	return StaticStruct()->CompareScriptStruct(this, &Other, 0);
}

uint32 GetTypeHash(const FFortCurieAmbientAudioLocationKey& Value)
{
	return 0;
}

void UFortCurieFXManager::OnElectricityImpactFXComplete(UNiagaraComponent* InComponent)
{
}
