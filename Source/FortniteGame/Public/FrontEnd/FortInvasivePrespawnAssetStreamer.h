// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/GameStateComponent.h"
#include "FortInvasivePrespawnAssetStreamer.generated.h"

class UObject;

UCLASS(HideCategories=("Trigger", "PhysicsVolume"))
class UFortInvasivePrespawnAssetStreamer : public UGameStateComponent
{
	GENERATED_BODY()

public:
	UFortInvasivePrespawnAssetStreamer(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

private:
	UPROPERTY()
	TArray<TObjectPtr<UObject>> PertinentObjectPtrs;

};

