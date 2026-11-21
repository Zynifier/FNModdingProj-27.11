// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FortPetManager.generated.h"

class AFortPlayerPetRepState;

UCLASS()
class UFortPetManager : public UObject
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TArray<TObjectPtr<AFortPlayerPetRepState>> RegisteredPets;

	UPROPERTY(Transient)
	TArray<TObjectPtr<AFortPlayerPetRepState>> PetsPendingUpdate;

};

