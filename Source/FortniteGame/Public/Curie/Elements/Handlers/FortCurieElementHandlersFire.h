// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/CurveTable.h"
#include "Curie/Elements/Handlers/FortCurieElementHandlers.h"
#include "FortCurieElementHandlersFire.generated.h"

UCLASS()
class UFortCurieElementAllocationHandlerFire : public UFortCurieElementAllocationHandler
{
	GENERATED_BODY()

};

UCLASS()
class FORTNITEGAME_API UFortCurieElementAttachConditionHandlerFire : public UFortCurieElementAttachConditionHandler
{
	GENERATED_BODY()

};

UCLASS()
class FORTNITEGAME_API UFortCurieElementAttachHandlerFire : public UFortCurieElementAttachHandler
{
	GENERATED_BODY()

};

UCLASS()
class UFortCurieElementInteractWithMaterialHandlerFire : public UFortCurieElementInteractWithMaterialHandler
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="Balance")
	FCurveTableRowHandle FireMagnitudeToWaterContentDecreaseCurve;

};

UCLASS()
class UFortCurieElementInteractWithSameElementHandlerFire : public UFortCurieElementInteractWithSameElementHandler
{
	GENERATED_BODY()

};

