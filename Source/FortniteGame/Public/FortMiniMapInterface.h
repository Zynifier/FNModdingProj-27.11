// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortMiniMapInterface.generated.h"

class UMaterialInstanceDynamic;

UENUM()
enum class EFortMiniMapDrawCategory : uint8
{
	AthenaBackground = 0,
	MapLocation = 1,
	SafeZone = 2,
	BusPath = 3,
	SpecialActorIcon = 4,
	SquadPin = 5,
	MapIndicator = 6,
	MapCursor = 7,
	Elimination = 8,
	MAX = 9,
};

UINTERFACE(meta=(CannotImplementInterfaceInBlueprint))
class UFortMiniMapInterface : public UInterface
{
	GENERATED_BODY()
};

class IFortMiniMapInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	virtual UMaterialInstanceDynamic* GetMapMaskMaterialMID();

	UFUNCTION(BlueprintCallable)
	virtual UMaterialInstanceDynamic* GetMapMaterialMID();

};

