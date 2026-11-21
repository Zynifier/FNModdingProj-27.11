// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/CurveTable.h"
#include "AI/NavAreas/FortNavArea.h"
#include "FortNavAreaAutomatic.generated.h"

UCLASS(BlueprintType, Blueprintable)
class UFortNavAreaAutomatic : public UFortNavArea
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="AI")
	FCurveTableRowHandle NavCostCurveHandle;

	UPROPERTY(EditDefaultsOnly, Category="AI")
	int32 NavAreaStrength;

	UPROPERTY(VisibleAnywhere, Transient, Category="AI")
	float AutomaticNavCost;

};

