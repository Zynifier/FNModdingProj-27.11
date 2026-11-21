// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/FortWalkableBaseInterface.h"
#include "Building/BuildingGameplayActor.h"
#include "FortAutoFireTargetInterface.h"
#include "FortLockOnTargetInterface.h"
#include "AthenaSuperDingo.generated.h"

UCLASS(BlueprintType, Blueprintable, HideCategories=("Game|Damage"), SparseClassDataType=BuildingGameplayActorClassData)
class AAthenaSuperDingo : public ABuildingGameplayActor, public IFortLockOnTargetInterface, public IFortAutoFireTargetInterface, public IFortWalkableBaseInterface
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="AutoFire")
	bool bIsAutoFireTarget;

protected:
	UFUNCTION(BlueprintPure, Category="Networking")
	bool ShouldUseClientInterpolation() const;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Character")
	uint8 bShouldIgnoreThisBaseRotation : 1;

	UPROPERTY(EditDefaultsOnly, Category="AthenaSuperDingo")
	uint8 bClientUseInterpolationOnly : 1;

};

