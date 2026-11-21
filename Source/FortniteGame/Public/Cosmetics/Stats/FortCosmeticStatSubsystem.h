// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "FortCosmeticStatSubsystem.generated.h"

class UFortCosmeticStatObject;

UCLASS()
class UFortCosmeticStatSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TArray<TObjectPtr<UFortCosmeticStatObject>> CosmeticStatObjects;

};

