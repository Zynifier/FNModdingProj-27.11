// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "FortCurieDADAssetManager.generated.h"

class UCurieManagerComponentConfig;

UCLASS()
class UFortCurieDADAssetManager : public UGameInstanceSubsystem
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TArray<TObjectPtr<UCurieManagerComponentConfig>> DADAssets;

};

