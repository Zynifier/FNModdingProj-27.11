// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Curie/FortCurieElementContainerParamsGenerator.h"
#include "CurieManagerComponent.h"
#include "FortCurieFireTypes.generated.h"

UCLASS()
class UFortCurieElementContainerParamsGenerator_Fire : public UFortCurieElementContainerParamsGenerator
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="Curie", meta=(ClampMin="-1", UIMin="-1"))
	int32 PropagationFuel;

};

UINTERFACE(MinimalAPI)
class UFortCurieFirePropagationManagerInterface : public UCurieManagerComponentInterface
{
	GENERATED_BODY()
};

class FORTNITEGAME_API IFortCurieFirePropagationManagerInterface : public ICurieManagerComponentInterface
{
	GENERATED_BODY()

};

