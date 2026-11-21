// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "NiagaraComponent.h"
#include "FortCurieWorldNiagaraComponent.generated.h"

UCLASS(MinimalAPI, HideCategories=("Object", "Physics", "Collision", "Mobility", "VirtualTexture"))
class UFortCurieWorldNiagaraComponent : public UNiagaraComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient)
	int32 AssociatedControllerId;

	UPROPERTY(Transient)
	float LastSampleTimestamp;

	UPROPERTY(Transient)
	float LastAudioSampleTimestamp;

};

