// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "FortViewModelsManager.generated.h"

class UObject;

UENUM()
enum class EFortViewModelsDestructionType : int32
{
	AfterLastUsage = 0,
	Manual = 1,
};

UCLASS(MinimalAPI)
class UFortViewModelsManager : public UGameInstanceSubsystem
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TMap<TObjectPtr<UObject>, EFortViewModelsDestructionType> ViewModelCache;

};

