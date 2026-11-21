// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Tasks/TargetingFilterTask_BasicFilterTemplate.h"
#include "FortTeamEnum.h"
#include "TargetingFilterTask_Affiliation.generated.h"

UCLASS(BlueprintType, Blueprintable)
class UTargetingFilterTask_Affiliation : public UTargetingFilterTask_BasicFilterTemplate
{
	GENERATED_BODY()

public:
	UTargetingFilterTask_Affiliation(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	UPROPERTY(EditAnywhere, Category="Targeting Filter | Alignment")
	TEnumAsByte<EFortTeamAffiliation::Type> AffiliationType;

};

