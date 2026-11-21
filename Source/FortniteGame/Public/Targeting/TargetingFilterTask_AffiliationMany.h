// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortTeamEnum.h"
#include "Targeting/TargetingFilterTask_Affiliation.h"
#include "TargetingFilterTask_AffiliationMany.generated.h"

UCLASS(BlueprintType, Blueprintable, HideCategories=("Targeting", "Filter", "|", "Alignment"))
class UTargetingFilterTask_AffiliationMany : public UTargetingFilterTask_Affiliation
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="Targeting Filter | Alignments")
	TArray<TEnumAsByte<EFortTeamAffiliation::Type>> AffiliationTypes;

};

