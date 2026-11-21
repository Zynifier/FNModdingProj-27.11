// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortCreativePersistenceActorInterface.generated.h"

class AFortPlayerState;
class UObject;

UINTERFACE(BlueprintType, Blueprintable)
class UFortCreativePersistenceActorInterface : public UInterface
{
	GENERATED_BODY()
};

class IFortCreativePersistenceActorInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent)
	bool CanPlayerAutoSave(AFortPlayerState* FortPlayerState) const;

	UFUNCTION(BlueprintNativeEvent)
	UObject* GetObjectToAutoSaveForPlayer(AFortPlayerState* FortPlayerState);

	UFUNCTION(BlueprintNativeEvent)
	bool GetPersistenceRequiredState() const;

};

