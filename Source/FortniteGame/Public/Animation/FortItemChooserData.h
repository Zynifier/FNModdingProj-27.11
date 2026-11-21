// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FortItemChooserData.generated.h"

class AFortPawn;
class AFortPlayerPawn;
class AFortWeapon;

UCLASS(Transient, MinimalAPI, BlueprintType, Blueprintable)
class UFortItemChooserData : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void BlueprintUpdateChooserData(float DeltaTime);

	UFUNCTION(BlueprintPure)
	AFortPawn* TryGetPawnOwner() const;

	UFUNCTION(BlueprintPure)
	AFortPlayerPawn* TryGetPlayerPawnOwner() const;

	UFUNCTION(BlueprintPure)
	AFortWeapon* TryGetWeapon() const;

};

