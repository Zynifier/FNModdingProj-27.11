// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Curie/FortCurieEntityStateBehavior.h"
#include "FortCurieEntityStateBehavior_Drying.generated.h"

UCLASS(Abstract)
class UFortCurieEntityStateBehavior_Drying : public UFortCurieEntityStateBehavior
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Balance")
	float DryingRate;

};

