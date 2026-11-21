// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Cosmetics/FortCosmeticLoadout.h"
#include "FortApplyVarianceToInterfaceMaterialFlow.generated.h"

class UAthenaCosmeticItemDefinition;

UCLASS(MinimalAPI)
class UFortApplyVarianceToInterfaceMaterialFlow : public UObject
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TObjectPtr<UAthenaCosmeticItemDefinition> Cosmetic;

	UPROPERTY()
	FFortAthenaLoadout DummyLoadout;

};

